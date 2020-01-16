//---------------------------------------------------------------------------


#pragma hdrstop
 #include <vcl.h>
 #include <math.h>
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
int **imagenR2=NULL;  //MATRIZ DE IMAGEN PIXELES ROJOS, se cargan en la funcion imagenAmatriz
int **imagenG2=NULL;  //MATRIZ DE IMAGEN PIXELES VERDES
int **imagenB2=NULL;  //MATRIZ DE IMAGEN PIXELES AZULES
Byte **auximage2=NULL; //MATRIZ DE IMAGEN COMPLETA, EN CADA INDICE TIENE UN VECTOR RGB



void FuncionRecorta(Graphics::TBitmap *temporal, int x1, int y1, int x2, int y2, Graphics::TBitmap *resultado, TImage *imagenTemporal)
{

 x1 = (x1 * temporal->Width) /  imagenTemporal->Width;
 x2 = (x2 * temporal->Width) /  imagenTemporal->Width;
 y1 = (y1 * temporal->Height) /  imagenTemporal->Height;
 y2 = (y2 * temporal->Height) /  imagenTemporal->Height;


   resultado->Width = x2-x1;
   resultado->Height = y2-y1;

  for (int x=x1;x<x2;x++)
  {
   for(int y=y1;y<y2;y++)
   {
		resultado->Canvas->Pixels[x-x1][y-y1]= temporal->Canvas->Pixels[x][y];
   }

 }
}

void FuncionBrilloContraste(TImage *image, int **auximage, float a,  int b)
{
     int x, y;
	 Byte *p;
	 int valor;
	 int hValor;
	 if(image->Picture->Bitmap->PixelFormat==pf24bit)
		hValor = 3*image->Picture->Bitmap->Width;
	 else
		hValor = image->Picture->Bitmap->Width;

	 if(auximage!=NULL)
		for (y = 0; y < image->Picture->Bitmap->Height; y++)
		{
				p = (Byte *) image->Picture->Bitmap->ScanLine[y];
				for (x = 0; x < hValor; x++)
				{
					 valor =auximage[y][x]*a + b;
					 if(valor>255)p[x]=255;
					 else if(valor<0)p[x]=0;
					 else p[x]=valor;
				}
		}

		image->Refresh();
}


void escalaGris(TImage *image) {
	int x,y;
	Byte *p;

	for(y=0;y<image->Picture->Bitmap->Height; y++)
	{
		p =  (byte *) image->Picture->Bitmap->ScanLine[y];
		for(x=0;x<image->Picture->Bitmap->Width*3-1;x+=3)
		{
			//p[x] - AZUL (RGB)
			//p[x+1] - VERDE (RGB)
			//p[x+2] - ROJO (RGB)

			p[x]=p[x+1]=p[x+2]= p[x]*0.11+p[x+1]*0.59+p[x+2]*0.3;
		}
	}
	image->Refresh();

}
/*COMPARA LA DISTANCIA ENTRE EL PIXEL VECINO Y EL PIXEL INFERIOR,
  SI EL LA DISTANCIA ES MAYOR O IGUAL QUE LA VARIABLE bb ENTONCES DEJA EL
  PIXEL RGB EN 255 DE LO CONTRARIO LO DEJA EL RGB EN 0 */
void detector(TImage *image) {
	int x,y,i;
	Byte *p, *pa, grayLevel;
	int r,g,b, r1,g1,b1,r2,g2,b2;
	int bb= 5;
	int contador = 0;

	for(y=0;y<image->Picture->Bitmap->Height-1; y++)
	{
		pa =  (byte *) image->Picture->Bitmap->ScanLine[y+1];
		p =  (byte *) image->Picture->Bitmap->ScanLine[y];
		for(x=0;x<image->Picture->Bitmap->Width*3-1;x+=3)
		{
			//PIXEL ACTUAL
			r=p[x+2];
			g=p[x+1];
			b=p[x];

			//PIXEL INFERIOR
			r1=pa[x+2];
			g1=pa[x+1];
			b1=pa[x];

			//PIXEL VECINO
				contador++;
			if(contador == image->Picture->Bitmap->Width){
				r2=0;
				g2=0;
				b2=0;
			}else{
			r2=p[x+3+2];
			g2=p[x+3+1];
			b2=p[x+3];
			}


		   //	ShowMessage(contador);
		  //	ShowMessage(r2);



			 if((sqrt((r-r1)*(r-r1)+(g-g1)*(g-g1)+(b-b1)*(b-b1))>=bb)||
				(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))>=bb)){
				p[x+2]=0;
				p[x+1]=0;
				p[x]=0;
			   /*
				p[x+2]=0;
				p[x+1]=0;
				p[x]=0;
					   */
				}
			else{
				p[x+2]=255;
				p[x+1]=255;
				p[x]=255;

			}

		}
		contador = 0;
	}
	image->Refresh();

}

int **detector2(int val, int nlin, int ncol, int **m, int **r) {

	int i,j;

	for(i=0;i<=nlin-2;i++){
		for (j=0; j<=ncol-2; j++) {

			if((sqrt((m[i][j]-m[i+1][j])*(m[i][j]-m[i+1][j]))>=val)||
				(sqrt((m[i][j]-m[i][j+1])*(m[i][j]-m[i][j+1])))>=val){

				 r[i][j] = 0;


				}else{
				 r[i][j] = 255;
				}
		}
	}

	 return r;

}

int **detector3(int val, int nlin, int ncol, int **m1, int **m2, int **m3, int **r){

	int i,j;

	for(i=0;i<=nlin-2;i++){
		for (j=0; j<=ncol-2; j++) {

			if((sqrt(
			(m1[i][j]-m1[i+1][j])*(m1[i][j]-m1[i+1][j])+
			(m2[i][j]-m2[i+1][j])*(m2[i][j]-m2[i+1][j])+
			(m3[i][j]-m3[i+1][j])*(m3[i][j]-m3[i+1][j])
			 )>=val)||
			 (sqrt(
			(m1[i][j]-m1[i][j+1])*(m1[i][j]-m1[i][j+1])+
			(m2[i][j]-m2[i][j+1])*(m2[i][j]-m2[i][j+1])+
			(m3[i][j]-m3[i][j+1])*(m3[i][j]-m3[i][j+1])
			 )>=val)){

				 r[i][j] = 0;


				}else{
				 r[i][j] = 255;
				}
		}
	}

	 return r;

}



void convolucion3x3( Graphics::TBitmap *I, int k[3][3] )
{
	int x,y,result,u,v, result2;
	RGBQUAD *A11, *A12, *A13,
			*A21, *A22, *A23,
			*A31, *A32, *A33;
	RGBQUAD *O,*pp;;
	int H = I->Height;
	int W = I->Width;
	int a,b,c,d;
	int Bytes_per_Row = W*4;
	RGBQUAD **ImageBuffer = (RGBQUAD **)malloc ((unsigned)H * sizeof(RGBQUAD *));

	I->PixelFormat = pf32bit;

	int total= 0;

   //SUMA LOS COEFICIENTES DEL KERNEL, SI ES MENOR A 1 LE ASIGNA EL VALOR 1
	 for(int p=0;p<3;p++){
	   for(int pp=0;pp<3;pp++) {
		  total = total + k[p][pp];
	   }
	 }
	 if(total < 1){
		total = 1;
	 }

	//EN EL VECTOR ImageBuffer RESERVA MEMORIA
	for (y=0; y<H; y++)
		ImageBuffer[y] = (RGBQUAD *)malloc (Bytes_per_Row);


  //VECTORES DE COLORES
  RGBQUAD *colo1, *colo2, *colo3;

  //ASIGNA LA IMAGEN ACTUAL A LA MATRIZ DE COLORES "O", SE TRABAJARÁ SOBRE LA MATRIZ "O"
   for (y=0; y<H; y++)
	{
	colo1 = (RGBQUAD *)I->ScanLine[y];
	O = ImageBuffer[y];
	 for (v=1; v<=W; v++,pp++,O++,colo1++){

		O->rgbRed = colo1->rgbRed;
		O->rgbGreen = colo1->rgbGreen;
		O->rgbBlue = colo1->rgbBlue;

	 }
   }


   //COMIENZA LA CONVOLUCION

	for (y=1; y<H-1; y++)
	 {
	  //ASIGNA LOS VALORES POR COLUMNA
	   A13 = (RGBQUAD *)I->ScanLine[y-1];   A12 = A13++;  A11 = A12++;
	   A23 = (RGBQUAD *)I->ScanLine[y];     A22 = A23++;  A21 = A22++;
	   A33 = (RGBQUAD *)I->ScanLine[y+1];   A32 = A33++;  A31 = A32++;

		O=ImageBuffer[y];
		//SE AVANZA A LA POSICIÓN DEL CENTRO
		O++;

	   for (x=1; x<W-1; x++,O++,A13++,A12++,A11++,A23++,A22++,A21++,A33++,A32++,A31++)
	   {

		  //SE AVANZA A LA POSICIÓN DEL CENTRO
		  A13++;
		  A23++;
		  A33++;

		 /*SE MULTIPLICAN LOS COEFICIENTES DE LA MATRIZ CON LOS DEL KERNEL
		  A11 TIENE LA POSICIÓN DE LA MATRIZ ORIGINAL[0][0]*/
		 result =
		 k[0][0]*A11->rgbRed +
		 k[0][1]*A12->rgbRed +
		 k[0][2]*A13->rgbRed +

		 k[1][0]*A21->rgbRed +
		 k[1][1]*A22->rgbRed +
		 k[1][2]*A23->rgbRed +

		 k[2][0]*A31->rgbRed +
		 k[2][1]*A32->rgbRed +
		 k[2][2]*A33->rgbRed;


		 //VALIDA UNA MAXIMO DE 255 Y MINIMO DE 0
		 result = result / total;
		 result = MIN(255,MAX(result,0));

		 /*DIVIDE EL TOTAL DE LA SUMATORIA DE MULTIPLICACIONES DE LOS COEFICIENTES
		 DEL KERNEL CON LA MATRIZ DE IMAGEN Y LOS DIVIDE POR LA SUMA DE LOS
		 COEFICIENTES DEL KERNEL*/
		 /*SE ASIGNA AL PIXEL CORRESPONDIENTE EL RESULTADO */
		 O->rgbRed =  result;

		//SE REPITE TODA LA OPERACION ANTERIOR PARA LOS PIXELES VERDES Y AZULES
		result =
		k[0][0]*A11->rgbGreen +
		k[0][1]*A12->rgbGreen +
		k[0][2]*A13->rgbGreen +

		k[1][0]*A21->rgbGreen +
		k[1][1]*A22->rgbGreen +
		k[1][2]*A23->rgbGreen +

		k[2][0]*A31->rgbGreen +
		k[2][1]*A32->rgbGreen +
		k[2][2]*A33->rgbGreen;

		  result = result / total;
		  result = MIN(255,MAX(result,0));
		  O->rgbGreen = result;



		 result =
		 k[0][0]*A11->rgbBlue +
		 k[0][1]*A12->rgbBlue +
		 k[0][2]*A13->rgbBlue +

		 k[1][0]*A21->rgbBlue +
		 k[1][1]*A22->rgbBlue +
		 k[1][2]*A23->rgbBlue +

		 k[2][0]*A31->rgbBlue +
		 k[2][1]*A32->rgbBlue +
		 k[2][2]*A33->rgbBlue;

		   result = result / total;
		  result = MIN(255,MAX(result,0));
		 O->rgbBlue = result;



		  A13--;
		  A23--;
		  A33--;
		}

	 }



	/* Copia el resultado*/
	for (y=0; y<H; y++)
	 Move (ImageBuffer[y], I->ScanLine[y], Bytes_per_Row);

	 /* Limpia buffer */
	for (y=0; y<H; y++)
		free(ImageBuffer[y]);

	free (ImageBuffer);


}


void imagenAmatriz(TImage *image)
{
//TImage *Image = NULL;
//Image = image;

auximage2=NULL;
imagenR2=NULL;
imagenG2=NULL;
imagenB2=NULL;


	int contadorColores = 0;
	int contadorR=0, contadorG=0, contadorB=0;
	int x, y;
	Byte *p;

	int hValues; //Number of values the image have in each line (3 x width for colour images)
	if(image->Picture->Bitmap->PixelFormat==pf24bit)
		hValues = 3*image->Picture->Bitmap->Width;
	else
		hValues = image->Picture->Bitmap->Width;


		 int nlin = image->Picture->Bitmap->Height;
		 int ncol = image->Picture->Bitmap->Width;


		 imagenB2 = memoriaMatriz(imagenB2, nlin, ncol);
		 imagenG2 = memoriaMatriz(imagenG2, nlin, ncol);
		 imagenR2 = memoriaMatriz(imagenR2, nlin, ncol);
		// auximage2 = memoriaMatriz(auximage2, nlin, ncol);


for(int a = 0; a<image->Picture->Bitmap->Height;a++){
for(int aa = 0; aa<image->Picture->Bitmap->Width;aa++){
   imagenR2[a][aa] = 0;
   imagenG2[a][aa] = 0;
   imagenB2[a][aa] = 0;
}

}

		 for (y = 0; y < image->Picture->Bitmap->Height; y++)
		 {
				p = (byte *) image->Picture->Bitmap->ScanLine[y];
				for (x = 0; x < hValues; x++)
				{
				 contadorColores++;
					if(contadorColores == 1){
						 imagenB2[y][contadorB++]=p[x];
				   }
					if(contadorColores == 2){
						 imagenG2[y][contadorG++]=p[x];
					}
					if(contadorColores == 3){

						 imagenR2[y][contadorR++]=p[x];
					}
					//	auximage2[y][x]=p[x];
					if(contadorColores==3){
					contadorColores=0;
					}
				}
				contadorR=0;
				contadorG=0;
				contadorB=0;

		 }


}



int **Convolution(int **a, int nlin, int ncol, int nk, int **r, int **k) {



/*
  nlin   numero lineas matriz a
  ncol   numero columnas matriz a
  nk     numero filas y columnas matriz cuadrada k
  a      matriz original imagen
  k      matriz cuadrada kernel
  r      matriz imagen resultado

  rutina retorna rr = 0 si proceso es normal
				 rr = 1 si proceso tiene error


*/


int rr, i, i1, i2, ii, iii, j, j1, j2, jj, jjj, m, n, sum, sumk, mm;

rr = 0;

// se validan parametros de entrada

if (nlin == 0 || ncol == 0 || nk == 0 || nk > nlin || nk > ncol)
   {
   rr = 1;
  // return (rr);
   }

// se suman coeficientes de matriz k en sumk


m    = 0;
n    = 0;

sumk = 0;

while (m < nk)
   {
   n = 0;

   while (n < nk)
	  {
	  sumk = sumk + k[m][n];
	  n    = n+1;
	  }

   m = m + 1;
   }

if (sumk < 1)
   {
   sumk = 1;
   }
/*
se determina mm, que es (nk - 1) / 2
corresponde a numero de filas y columnas
a cada lado de elemento central de
matriz k.
Por ej. si k es matriz 5*5, mm=2
*/

mm = nk - 1;
mm = mm / 2;

/*
se inicializan en 0 las dos primeras y
ultimas filas y columnas de matriz r,
ya que ellas no se transforman
*/

/*
se inicializan primeras y ultimas mm filas
*/

i = 0;

while (i < mm)
   {
   i1       = i;
   i2       = nlin - i - 1;
   j = 0;

   while (j < ncol)
	  {
	  r[i1][j] = 0;
	  r[i2][j] = 0;

	  j = j + 1;
	  }

   i = i + 1;
   }
/*
se inicializan primeras y ultimas mm columnas
se comienza desde fila mm hasta fila nlin - mm -1
iii es ultima fila que se inicializa;
las posteriores ya estan inicializadas en ciclo anterior
*/


j   = 0;
iii = nlin - mm - 1;

while (j < mm)
   {
   j1 = j;
   j2 = ncol - j - 1;

   i = mm;

   while (i <= iii)
	  {

	  r[i][j1] = 0;
	  r[i][j2] = 0;

	  i = i + 1;
	  }

   j = j + 1;
   }


/*

proceso de convolucion
elemento central que se transforma en cada iteracion es a[ii][jj]
primer elemento de a que se transforma es a[mm][mm]
ultimo elemento de a que se transforma es a[iii][jjj]
iii, jjj indices de ultimo elemento que se transforma
m,n indices de matriz k
i,j indices de matriz a en cada iteracion

*/

ii  = mm;
 int resultado;
iii = nlin - mm - 1;
jjj = ncol - mm - 1;

while (ii <= iii)
   {

   jj = mm;

   while (jj <= jjj)
	  {
	  i   = ii - mm;
	  m   = 0;
	  sum = 0;
	  while (m < nk)
		 {
		 j = jj - mm;
		 n = 0;
		 while (n < nk)
			{

			sum = sum + k[m][n] * a[i][j];

			n   = n + 1;
			j   = j + 1;
			}
		 m = m + 1;
		 i = i + 1;
		 }

	  r[ii][jj] = sum / sumk;

	  jj        = jj + 1;
	  }
   ii = ii + 1;
   }

	  return r;
}


int *Histograma (int **a, int ncol, int nlin){
 int x,y;
 int *Histogramas;
  int pixel;

   //Histogramas = (int *) calloc (256,sizeof(int *));
	 Histogramas = memoriaVector(Histogramas, 256);
	  //	 int *Histogramas = new int[256];


	for (x = 0; x <= 255; x++) {
		Histogramas[x]=0;
	}

   for(y=0; y<nlin; y++){
		for(x=0;x<ncol;x++){
		   pixel = a[x][y];
		   Histogramas[pixel]++;
		}
   }

   return Histogramas;
   freeVector (Histogramas,  256);
}



int **ConvolutionHV(int **a, int nlin, int ncol, int nk, int **r, int **k, int **k1) {

		r = (int **) calloc (ncol*3,sizeof(int *));

		for(int y = 0; y < nlin; y++)
		{
			 r[y] = (int *) calloc (ncol*3,sizeof(int *));

		 }

/*
  nlin   numero lineas matriz a
  ncol   numero columnas matriz a
  nk     numero filas y columnas matriz cuadrada k
  a      matriz original imagen
  k      matriz cuadrada kernel
  r      matriz imagen resultado

  rutina retorna rr = 0 si proceso es normal
				 rr = 1 si proceso tiene error


*/



int rr, i, i1, i2, ii, iii, j, j1, j2, jj, jjj, m, n, sum, sum1, sumk, sumk1, mm, sumTotal;

rr = 0;

// se validan parametros de entrada

if (nlin == 0 || ncol == 0 || nk == 0 || nk > nlin || nk > ncol)
   {
   rr = 1;
  // return (rr);
   }

// se suman coeficientes de matriz k en sumk


m    = 0;
n    = 0;

sumk = 0;
sumk1 = 0;

while (m < nk)
   {
   n = 0;

   while (n < nk)
	  {
	  sumk = sumk + k[m][n];
	  sumk1 = sumk1 + k1[m][n];
	  n    = n+1;
	  }

   m = m + 1;
   }

if (sumk < 1)
   {
   sumk = 1;
   }
if (sumk1 < 1)
   {
   sumk1 = 1;
   }
/*
se determina mm, que es (nk - 1) / 2
corresponde a numero de filas y columnas
a cada lado de elemento central de
matriz k.
Por ej. si k es matriz 5*5, mm=2
*/

mm = nk - 1;
mm = mm / 2;

/*
se inicializan en 0 las dos primeras y
ultimas filas y columnas de matriz r,
ya que ellas no se transforman
*/

/*
se inicializan primeras y ultimas mm filas
*/

i = 0;

while (i < mm)
   {
   i1       = i;
   i2       = nlin - i - 1;
   j = 0;

   while (j < ncol)
	  {
	  r[i1][j] = 0;
	  r[i2][j] = 0;

	  j = j + 1;
	  }

   i = i + 1;
   }
/*
se inicializan primeras y ultimas mm columnas
se comienza desde fila mm hasta fila nlin - mm -1
iii es ultima fila que se inicializa;
las posteriores ya estan inicializadas en ciclo anterior
*/


j   = 0;
iii = nlin - mm - 1;

while (j < mm)
   {
   j1 = j;
   j2 = ncol - j - 1;

   i = mm;

   while (i <= iii)
	  {

	  r[i][j1] = 0;
	  r[i][j2] = 0;

	  i = i + 1;
	  }

   j = j + 1;
   }


/*

proceso de convolucion
elemento central que se transforma en cada iteracion es a[ii][jj]
primer elemento de a que se transforma es a[mm][mm]
ultimo elemento de a que se transforma es a[iii][jjj]
iii, jjj indices de ultimo elemento que se transforma
m,n indices de matriz k
i,j indices de matriz a en cada iteracion

*/

ii  = mm;
 int resultado;
iii = nlin - mm - 1;
jjj = ncol - mm - 1;

while (ii <= iii)
   {

   jj = mm;

   while (jj <= jjj)
	  {
	  i   = ii - mm;
	  m   = 0;
	  sum = 0;
	  sum1 = 0;
	  while (m < nk)
		 {
		 j = jj - mm;
		 n = 0;
		 while (n < nk)
			{

			sum 	= sum 	+ k[m][n] 	* a[i][j];
			sum1 	= sum1 	+ k1[m][n] 	* a[i][j];

			n   = n + 1;
			j   = j + 1;
			}
		 m = m + 1;
		 i = i + 1;
		 }
	  sumTotal = sqrt((sum/sumk)*(sum/sumk)+(sum1/sumk1)*(sum1/sumk1));
	  r[ii][jj] = sumTotal;

	  jj        = jj + 1;
	  }
   ii = ii + 1;
   }

	  return r;
}


int **EcualizaHistograma (int Nlin, int Ncol, int Nhi, int Nhf, int **M, int **R){


/*
Nlin y Ncol es número de líneas y columnas de matriz imagen
M es matriz imagen original
R es matriz ecualizada
Nhi es numero de intensidades posibles en histograma original (rango de 0 a Nhi-1)
Nhf es numero de intensidades posibles en histograma final (rango de 0 a Nhf-1)
Hf es histograma ecualizado uniforme

Nlin, Ncol, Nhi, Nhf, M son datos de entrada a la rutina

R y Hf son resultados de la rutina

Habitualmente Nhi = Nhf = 256

*/



int i, j, k, aa;

int * Hi, * Ha, *Tab;
 int *Hf;

 //RESERVA ESPACIO DE VECTORES Y MATRIZ RESULTADO
 Hi = 	(int *) calloc (256,sizeof(int *));
 Ha = 	(int *) calloc (256,sizeof(int *));
 Tab = 	(int *) calloc (256,sizeof(int *));
 Hf = 	(int *) calloc (256,sizeof(int *));

 R = (int **) calloc (Ncol*3,sizeof(int *));

		for(int y = 0; y < Nlin; y++)
		{
			 R[y] = (int *) calloc (Ncol*3,sizeof(int *));

		 }
/*
Hi es histograma inicial
Ha es histograma acumulado inicial
Tab es tabla de transformacion de intensidades de matriz original, de dimension Nhi (0 - Nhi-1)
*/

// inicializa Hi, Ha y Hf


i = 0;

while (i < Nhi)

   {
   Hi[i] = 0;
   Ha[i] = 0;
   i     = i + 1;
   }

i = 0;

while (i < Nhf)

   {
   Hf[i] = 0;
   i     = i + 1;
   }

// inicializa R

i = 0;

while (i < Nlin)

   {
   j       = 0;

   while (j < Ncol)
	  {
	  R[i][j] = 0;
	  j       = j + 1;
	  }
   i = i + 1;
   }


//  Calcula histograma inicial Hi
i = 0;
while (i < Nlin)

   {
   j       = 0;

   while (j < Ncol)
      {
	  k     = M[i][j];
      Hi[k] = Hi[k] + 1;
      j     = j + 1;
	  }
   i = i + 1;
   }

// Calcula histograma inicial acumulado Ha

i = 0;
j = 1;
Ha[0] = Hi[0];

while (j < Nhi)
   {
   Ha[j] = Ha[i] + Hi[j];
   i = i + 1;
   j = j + 1;
   }

/*
Construye tabla Tab de transformacion de intensidades
La tabla tiene Nhi filas (de 0 a Nhi-1)

El indice corresponde al valor de intensidad de histograma original
El valor corresponde a la intensidad de nuevo histograma ecualizado
*/

// aa es el numero de pixels por intensidad en histograma ecualizado


aa = (Nlin * Ncol) / Nhf;
if(aa < 1){aa=1;}
i = 0;
j = 1;

Tab[0]= 0;


while (j < Nhi)
   {
   Tab[j] = (Ha[i] + Hi[j] / 2) / aa;
   i      = i + 1;
   j      = j + 1;
   }

// Se ecualiza matriz

i = 0;

while (i < Nlin)
   {
   j = 0;
   while (j < Ncol)
      {
      aa      = M[i][j];
      R[i][j] = Tab[aa];
      j       = j + 1;
	  }

   i = i + 1;
   }

// Calcula nuevo histograma

i = 0;
while (i < Nlin)

   {
   j       = 0;

   while (j < Ncol)
	  {
	  k     = M[i][j];
	  Hf[k] = Hf[k] + 1;
	  j     = j + 1;
	  }
   i = i + 1;
   }
		return R;
}



int **Negativo (int **a, int nlin, int ncol, int **r){
 int x,y;
  int pixel = 0;
  /*  r = (int **) calloc (ncol*3,sizeof(int *));

		for(int y = 0; y < nlin; y++)
		{
			 r[y] = (int *) calloc (ncol*3,sizeof(int *));

		 }
   */

   for(y=0; y<ncol; y++){
		for(x=0;x<nlin;x++){
		   pixel = 255-a[x][y];
		   r[x][y] = pixel;
		}
   }

   return r;

}

int **memoriaMatriz (int **m, int nlin, int ncol){

	 m = new int*[nlin];
	 for (int i=0; i < nlin; i++) {
	   m[i] = new int[ncol];
	 }
	 return m;

}

void **freeMatriz (int **m, int nlin, int ncol){

	 for (int i=0; i < nlin; i++) {
		delete []m[i];
	 }
	 delete []m;

}

int *memoriaVector (int *v, int ncol){

	 v = new int[ncol];
	 return v;

}

void *freeVector (int *v, int ncol){

	 delete []v;

}


void detectorNucleo(TImage *image) {

	int x,y,i;
	Byte *p, *pa, grayLevel;
	int r,g,b, r1,g1,b1,r2,g2,b2;
	int bb= 80;
	int contador = 0;

	for(y=0;y<image->Picture->Bitmap->Height-1; y++)
	{
		pa =  (byte *) image->Picture->Bitmap->ScanLine[y+1];
		p =  (byte *) image->Picture->Bitmap->ScanLine[y];
		for(x=0;x<image->Picture->Bitmap->Width*3-1;x+=3)
		{
			//PIXEL ACTUAL
			r=p[x+2];
			g=p[x+1];
			b=p[x];

			//PIXEL INFERIOR
			r1=pa[x+2];
			g1=pa[x+1];
			b1=pa[x];

			//PIXEL VECINO
				contador++;
			if(contador == image->Picture->Bitmap->Width){
				r2=0;
				g2=0;
				b2=0;
			}else{
			r2=p[x+3+2];
			g2=p[x+3+1];
			b2=p[x+3];
			}


		   //	ShowMessage(contador);
		  //	ShowMessage(r2);

int prom = (r+g+b)/3;
			 if(prom < 30){
				//if(r2 == r && g2 == g && b2==b){
				p[x+2]=240;
				p[x+1]=25;
				p[x]=120;
			   //}
			 }
			/* if((sqrt((r-r1)*(r-r1)+(g-g1)*(g-g1)+(b-b1)*(b-b1))>=bb)||
				(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))>=bb)){
				p[x+2]=255;
				p[x+1]=255;
				p[x]=255;

				}
			else{
				p[x+2]=0;
				p[x+1]=0;
				p[x]=0;

			}   */

		}
		contador = 0;
	}
	image->Refresh();

}

void FuncionUnSoloColor(TImage *image, int **auximage, int color)
{

}

int *RestaVectoresEnt (int M, int *V1, int *V2, int *V3)

/*
Esta rutina resta los vectores V1 - V2; el resultado es V3
V1, V2, V3, vectores de enteros
M es largo de vectores

*/

{
int i;
i = 0;
while (i < M)
   {
   V3 [i] = V1 [i] - V2 [i];
   i      = i + 1;
   }

return V3;

}

int *SumaVectoresEnt (int M, int *V1, int *V2, int *V3)

/*
Esta rutina suma los vectores V1 + V2; el resultado es V3

V1, V2, V3, vectores de enteros

M es largo de vectores

*/

{
int i;
i = 0;
while (i < M)
   {
   V3 [i] = V1 [i] + V2 [i];
   i      = i + 1;
   }

return V3;

}

float media(int M, int *V1, float R)
{
/*
M tamaño del vector
V1 vector con los datos
R resultado
*/
 int suma=0;
	for (int i = 0; i< M; i++) {
		suma = suma + V1[i];
	}
 R=(float)suma/(float)M;
 return R;

}

float desviacionEstandar(int M, int *V1, float R){
/*
M tamaño del vector
V1 vector con los datos
R resultado
*/
	float X = media(M,V1,X);
	float suma = 0;

	for(int i = 0; i<M;i++){
	  suma = suma + ((V1[i]-X)*(V1[i]-X));
	}
	 R = sqrt((float)suma/(float)(M-1));
return R;
}


int **dibujaHistograma(int nlin, int ncol, int **m, int **r, int linf, int lsup, int valRest){
	int i,j;

	for(i=0;i<=nlin-2;i++){
		for (j=0; j<=ncol-2; j++) {
			if(m[i][j] >= linf && m[i][j] <= lsup){
				r[i][j] = m[i][j];
                }else{
				 r[i][j] = valRest;
				}
		}
	}

	 return r;

}

int divideMatriz(){
 /*

int CCOL = 3;
int NCOL = 14;
int NLIN = 11;


 int npixel = (NCOL/CCOL);  // parte entera... redondea hacia abajo)

 int colresto = NCOL - (npixel * CCOL);

 int CFIL = NLIN/npixel; // parte entera... redondea hacia abajo)

 int filaresto = NLIN - (npixel * CFIL);

//int **mcoord   = MemMatrizEnt (NLIN, NCOL, mcoord);
int **mcoord;
int oo;
mcoord = new int*[NLIN];
for (oo = 0; oo < NLIN; oo++)
	{
	mcoord[oo] = new char[NCOL];
	}

// Se recorren matrices cuadradas

 int contmat = 0;
 int i, j;
 for (i = 1 ; i <= CFIL ; i ++) {

	 for (j = 1 ; j <= CCOL ; j ++) {

		 mcoord[contmat]["xsi"] = (j-1)*npixel;
		 mcoord[contmat]["ysi"] = (i-1)*npixel;
		 mcoord[contmat]["xsd"] = j*npixel - 1;
		 mcoord[contmat]["ysd"] = (i-1)*npixel;
		 mcoord[contmat]["xii"] = (j-1)*npixel;
		 mcoord[contmat]["yii"] = i*npixel - 1;
		 mcoord[contmat]["xid"] = j*npixel - 1;
		 mcoord[contmat]["yid"] = i*npixel - 1;

		 contmat = contmat + 1;
	  }
 }

// Columna que sobra a la derecha

if (colresto > 0){

 for (i = 1 ; i <= CFIL ; i ++) {

		 mcoord[contmat]["xsi"] = CCOL*npixel;
		 mcoord[contmat]["ysi"] = (i-1)*npixel;
		 mcoord[contmat]["xsd"] = CCOL*npixel + (colresto - 1);
		 mcoord[contmat]["ysd"] = (i-1)*npixel;
		 mcoord[contmat]["xii"] = CCOL*npixel;
		 mcoord[contmat]["yii"] = i*npixel - 1;
		 mcoord[contmat]["xid"] = CCOL*npixel + (colresto - 1);
		 mcoord[contmat]["yid"] = i*npixel - 1;

		 contmat = contmat + 1;
 }
}


// Fila que sobra abajo

if (filaresto > 0){

 for (j = 1 ; j <= CCOL ; j ++) {

		 mcoord[contmat]["xsi"] = (j-1)*npixel;
		 mcoord[contmat]["ysi"] = CFIL*npixel;
		 mcoord[contmat]["xsd"] = j*npixel - 1;
		 mcoord[contmat]["ysd"] = CFIL*npixel;
		 mcoord[contmat]["xii"] = (j-1)*npixel;
		 mcoord[contmat]["yii"] = CFIL*npixel + (filaresto - 1);
		 mcoord[contmat]["xid"] = j*npixel - 1;
		 mcoord[contmat]["yid"] = CFIL*$npixel + (filaresto - 1);

		 contmat = contmat + 1;
 }
}

// Cuadro chico que sobra en extremo inferior derecho

if (filaresto > 0 && colresto > 0){

		 mcoord[contmat]["xsi"] = CCOL*npixel;
		 mcoord[contmat]["ysi"] = CFIL*npixel;
		 mcoord[contmat]["xsd"] = CCOL*npixel + (colresto - 1);
		 mcoord[contmat]["ysd"] = CFIL*npixel;
		 mcoord[contmat]["xii"] = CCOL*npixel;
		 mcoord[contmat]["yii"] = CFIL*npixel + (filaresto - 1);
		 mcoord[contmat]["xid"] = CCOL*npixel + (colresto - 1);
		 mcoord[contmat]["yid"] = CFIL*npixel + (filaresto - 1);
}

  */
}
void printVector(int *vector, int largo, char nombre[10]){
  FILE *fichero;
  unsigned int i;

   fichero = fopen( nombre, "w" );

   for( i=1; i<=largo; i++ ){
   fprintf( fichero, "%d\n", vector[i]);
   }
	 fclose(fichero);


   ShellExecute(NULL,"open",nombre,NULL,"",SW_SHOWNORMAL);

}


int **gamma(float val, int nlin, int ncol, int **m, int **r) {

	int i,j;

		for(i=0;i<=nlin-2;i++){
			for (j=0; j<=ncol-2; j++) {
				r[i][j] = 255 * (pow((((float)m[i][j])/255), (1/val)));
			}
		}

	 return r;

}
