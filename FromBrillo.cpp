//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "FromBrillo.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBrillo *Brillo;
TImage *Image = NULL;
int **auximage=NULL;
int **imagenR=NULL;  //MATRIZ DE IMAGEN PIXELES ROJOS
int **imagenG=NULL;  //MATRIZ DE IMAGEN PIXELES VERDES
int **imagenB=NULL;  //MATRIZ DE IMAGEN PIXELES AZULES
//---------------------------------------------------------------------------
__fastcall TBrillo::TBrillo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBrillo::Button1Click(TObject *Sender)
{
Brillo->Close();

	 int nlin = Image->Picture->Bitmap->Height;
	 int ncol = Image->Picture->Bitmap->Width;
	freeMatriz (imagenR, nlin, ncol);
	freeMatriz (imagenG, nlin, ncol);
	freeMatriz (imagenB, nlin, ncol);
	freeMatriz (auximage, nlin, ncol);
}
//---------------------------------------------------------------------------

void loadAuxImageBC()
{
auximage=NULL;
imagenR=NULL;
imagenG=NULL;
imagenB=NULL;
	int contadorColores = 0;
	int contadorR=0, contadorG=0, contadorB=0;
	int x, y;
	Byte *p;
	int hValues; //Number of values the image have in each line (3 x width for colour images)
	if(Image->Picture->Bitmap->PixelFormat==pf24bit)
		hValues = 3*Image->Picture->Bitmap->Width;
	else
		hValues = Image->Picture->Bitmap->Width;

	  int nlin = Image->Picture->Bitmap->Height;
	  int ncol = Image->Picture->Bitmap->Width;

	 auximage = memoriaMatriz(auximage, nlin, ncol*3);
	 imagenB = memoriaMatriz(imagenB, nlin, ncol);
	 imagenG = memoriaMatriz(imagenG, nlin, ncol);
	 imagenR = memoriaMatriz(imagenR, nlin, ncol);


		 for (y = 0; y < Image->Picture->Bitmap->Height; y++)
		 {
				p = (Byte *) Image->Picture->Bitmap->ScanLine[y];
				for (x = 0; x < hValues; x++)
				{
				 contadorColores++;
					if(contadorColores == 1){
					   imagenB[y][contadorB++]=p[x];
				   }
					if(contadorColores == 2){
						 imagenG[y][contadorG++]=p[x];
					}
					if(contadorColores == 3){

						 imagenR[y][contadorR++]=p[x];
					}
						auximage[y][x]=p[x];
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
void __fastcall TBrillo::ScrollBar1Change(TObject *Sender)
{
cantidadBrillo->Caption =  ScrollBar1->Position;
//FuncionBrilloContraste(Image, auximage, float(ScrollBar2->Position)/400,ScrollBar1->Position);
FuncionBrilloContraste(Image, auximage, float(1+(float(2*ScrollBar2->Position)/800)),ScrollBar1->Position);
//  brillo(Form1->Image1,auximage, 1, 50);
}

void brilloContraste(TImage *ImageSelected)
{
	Image = ImageSelected;
	loadAuxImageBC();
   //	imagenAmatriz(Image);
	Brillo->ScrollBar1->Position = 0;
	Brillo->ScrollBar2->Position = 0;  //400;
	Brillo->Visible = true;
}
//---------------------------------------------------------------------------

void cancelarBC()
{

	 int x, y;
	 Byte *p;
	 int newValue;
	 int hValues; //Number of values the image have in each line (3 x width for colour images)
	 if(Image->Picture->Bitmap->PixelFormat==pf24bit)
		hValues = 3*Image->Picture->Bitmap->Width;
	 else
		hValues = Image->Picture->Bitmap->Width;

		for (y = 0; y < Image->Picture->Bitmap->Height; y++)
		{
				p = (byte *) Image->Picture->Bitmap->ScanLine[y];
				for (x = 0; x < hValues; x++)
				{
					 p[x]=auximage[y][x];
				}
		}

		Brillo->Close();
		Image->Refresh();

}

void __fastcall TBrillo::ScrollBar2Change(TObject *Sender)
{
CantidadContraste->Caption =  ScrollBar2->Position;
 FuncionBrilloContraste(Image, auximage, float(1+(float(2*ScrollBar2->Position)/800)),ScrollBar1->Position);
//FuncionBrilloContraste(Image, auximage, float(ScrollBar2->Position/400),ScrollBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TBrillo::Button2Click(TObject *Sender)
{
cancelarBC();
	  int nlin = Image->Picture->Bitmap->Height;
	  int ncol = Image->Picture->Bitmap->Width;
	freeMatriz (imagenR, nlin, ncol);
	freeMatriz (imagenG, nlin, ncol);
	freeMatriz (imagenB, nlin, ncol);
	freeMatriz (auximage, nlin, ncol);
}
//---------------------------------------------------------------------------





void __fastcall TBrillo::FormActivate(TObject *Sender)
{
CantidadContraste->Caption =  ScrollBar2->Position;
}
//---------------------------------------------------------------------------

