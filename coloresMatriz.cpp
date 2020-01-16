//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "visor.h"
#include "coloresMatriz.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformColores *formColores;
TImage *ImageCompleta = NULL;
int **auximageColores=NULL;
int **imagenRColores=NULL;  //MATRIZ DE IMAGEN PIXELES ROJOS
int **imagenGColores=NULL;  //MATRIZ DE IMAGEN PIXELES VERDES
int **imagenBColores=NULL;  //MATRIZ DE IMAGEN PIXELES AZULES
//---------------------------------------------------------------------------
__fastcall TformColores::TformColores(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void loadAuxImageColores()
{
auximageColores=NULL;
imagenRColores=NULL;
imagenGColores=NULL;
imagenBColores=NULL;
	int contadorColores = 0;
	int contadorR=0, contadorG=0, contadorB=0;
	int x, y;
	Byte *p;
	int hValues; //Number of values the image have in each line (3 x width for colour images)
	if(ImageCompleta->Picture->Bitmap->PixelFormat==pf24bit)
		hValues = 3*ImageCompleta->Picture->Bitmap->Width;
	else
		hValues = ImageCompleta->Picture->Bitmap->Width;

	  int nlin = ImageCompleta->Picture->Bitmap->Height;
	  int ncol = ImageCompleta->Picture->Bitmap->Width;

	 auximageColores = memoriaMatriz(auximageColores, nlin, ncol*3);
	 imagenBColores = memoriaMatriz(imagenBColores, nlin, ncol);
	 imagenGColores = memoriaMatriz(imagenGColores, nlin, ncol);
	 imagenRColores = memoriaMatriz(imagenRColores, nlin, ncol);


		 for (y = 0; y < ImageCompleta->Picture->Bitmap->Height; y++)
		 {
				p = (Byte *) ImageCompleta->Picture->Bitmap->ScanLine[y];
				for (x = 0; x < hValues; x++)
				{
				 contadorColores++;
					if(contadorColores == 1){
					   imagenBColores[y][contadorB++]=p[x];
				   }
					if(contadorColores == 2){
						 imagenGColores[y][contadorG++]=p[x];
					}
					if(contadorColores == 3){

						 imagenRColores[y][contadorR++]=p[x];
					}
						auximageColores[y][x]=p[x];
					if(contadorColores==3){
					contadorColores=0;
					}
				}
				contadorR=0;
				contadorG=0;
				contadorB=0;

		 }

	  //	 ShowMessage(imagenR[2][1]);


}
//---------------------------------------------------------------------------
void recibeImagen(TImage *ImageSelected)
{
	ImageCompleta = ImageSelected;
	loadAuxImageColores();
   formColores->Show();


}
//---------------------------------------------------------------------------


void cambiaColor(int Crojo, int Cverde, int Cazul){

int nlin = ImageCompleta->Picture->Bitmap->Height;
int ncol = ImageCompleta->Picture->Bitmap->Width;



 int contadorColores=0;
	Byte *p;
	int otro = 3*ImageCompleta->Picture->Bitmap->Width;

 for (int yy = 0; yy < ImageCompleta->Picture->Bitmap->Height; yy++)
		 {
		   p = (Byte *) ImageCompleta->Picture->Bitmap->ScanLine[yy];
				for (int xx = 0; xx < otro; xx++)
				{
				 contadorColores++;

					if(contadorColores == 1){
					if(Cazul == 1){
					   p[xx] = MIN(255,MAX(imagenBColores[yy][xx/3],0));
					}else{
					 p[xx]=0;
					}
					}
					if(contadorColores == 2 ){
					if(Cverde == 1){
					   p[xx] = MIN(255,MAX(imagenGColores[yy][xx/3],0));
					}else{
					   p[xx]=0;
					}
					}
					if(contadorColores == 3 ){
					if(Crojo == 1){
					   p[xx] = MIN(255,MAX(imagenRColores[yy][xx/3],0));
					}else{
						  p[xx]=0;
                    }
					}

					if(contadorColores==3){
					contadorColores=0;
					}
				}


}

  ImageCompleta->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TformColores::rojoClick(TObject *Sender)
{
int Crojo=0;
int Cverde=0;
int Cazul = 0;
if (rojo->Checked) {
	Crojo = 1;
}
if (verde->Checked) {
	Cverde = 1;
}
if (azul->Checked) {
	Cazul = 1;
}

cambiaColor(Crojo, Cverde, Cazul);
}
//---------------------------------------------------------------------------

void __fastcall TformColores::verdeClick(TObject *Sender)
{
int Crojo=0;
int Cverde=0;
int Cazul = 0;
if (rojo->Checked) {
	Crojo = 1;
}
if (verde->Checked) {
	Cverde = 1;
}
if (azul->Checked) {
	Cazul = 1;
}

cambiaColor(Crojo, Cverde, Cazul);
}
//---------------------------------------------------------------------------

void __fastcall TformColores::azulClick(TObject *Sender)
{
int Crojo=0;
int Cverde=0;
int Cazul = 0;
if (rojo->Checked) {
	Crojo = 1;
}
if (verde->Checked) {
	Cverde = 1;
}
if (azul->Checked) {
	Cazul = 1;
}

cambiaColor(Crojo, Cverde, Cazul);
}
//---------------------------------------------------------------------------

void __fastcall TformColores::Button1Click(TObject *Sender)
{
cambiaColor(1, 1, 1);
int nlin = ImageCompleta->Picture->Bitmap->Height;
int ncol = ImageCompleta->Picture->Bitmap->Width;
	freeMatriz (imagenRColores, nlin, ncol);
	freeMatriz (imagenGColores, nlin, ncol);
	freeMatriz (imagenBColores, nlin, ncol);
	freeMatriz (auximageColores, nlin, ncol);
formColores->Close();
}
//---------------------------------------------------------------------------

void __fastcall TformColores::Button3Click(TObject *Sender)
{
int nlin = ImageCompleta->Picture->Bitmap->Height;
int ncol = ImageCompleta->Picture->Bitmap->Width;
	freeMatriz (imagenRColores, nlin, ncol);
	freeMatriz (imagenGColores, nlin, ncol);
	freeMatriz (imagenBColores, nlin, ncol);
	freeMatriz (auximageColores, nlin, ncol);
formColores->Close();
}
//---------------------------------------------------------------------------

