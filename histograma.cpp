//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "histograma.h"
#include "visor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "Series"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
THistogramas *Histogramas;
bool rojoUno = false;
bool rojoCero = false;
bool rojoDos = false;
bool verdeUno = false;
bool verdeCero = false;
bool verdeDos = false;
bool azulUno = false;
bool azulCero = false;
bool azulDos = false;
int rojoA 	= 0;
int rojoB 	= 0;
int verdeA 	= 0;
int verdeB 	= 0;
int azulA 	= 0;
int azulB 	= 0;
//---------------------------------------------------------------------------
__fastcall THistogramas::THistogramas(TComponent* Owner)

	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THistogramas::histogramaColorChange(TObject *Sender)
{
//ShowMessage(histogramaColor->Text);

}

//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoRojoClick(TObject *Sender)
{

	   //Button1->Caption = Series1->XValues->ToString();
   //	ShowMessage(Series1->GetYValueList(10));

}
//---------------------------------------------------------------------------



void __fastcall THistogramas::Series1Click(TChartSeries *Sender, int ValueIndex, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
//Button1->Caption = Sender->GetCursorValueIndex();
//ShowMessage(X);
}
//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoAzulMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{

int a = int(Series3->XScreenToValue(X));
if(!azulUno){
	azulInferior->Text = a;
	azulA = a;
	azulUno = true;
	azulDos = false;
	azulCero = true;
	} else{
	azulSuperior->Text = a;
	azulA = a;
	azulUno = false;
	azulUno = false;
	azulCero = false;
	azulDos = true;
	azulInferior->Color = clAqua;
	azulSuperior->Color = clWhite;

	}
}
//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoRojoMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
rojoCero = true;
int a = int(Series1->XScreenToValue(X));
if(!rojoUno){
	rojoInferior->Text = a;
	rojoA = a;
	rojoUno = true;
	rojoDos = false;
} else{
	rojoSuperior->Text = a;
	rojoB = a;
	rojoUno = false;
	rojoCero = false;
	rojoDos = true;
	rojoInferior->Color = clAqua;
	rojoSuperior->Color = clWhite;
	}
}
//---------------------------------------------------------------------------

void __fastcall THistogramas::Button3Click(TObject *Sender)
{

   Form1->llamadoDesdeHistograma(rojoInferior->Text.ToInt(),rojoSuperior->Text.ToInt(),verdeInferior->Text.ToInt(),verdeSuperior->Text.ToInt(),azulInferior->Text.ToInt(),azulSuperior->Text.ToInt(), valRest->Text.ToInt());

}
//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoVerdeMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
int a = int(Series2->XScreenToValue(X));

if(!verdeUno){
	verdeInferior->Text = a;
	verdeA = a;
	verdeUno = true;
	verdeDos = false;
	verdeCero = true;
} else{
	verdeSuperior->Text = a;
	verdeB = a;
	verdeUno = false;
	verdeCero = false;
	verdeDos = true;
	verdeInferior->Color = clAqua;
	verdeSuperior->Color = clWhite;
	}
}
//---------------------------------------------------------------------------

void __fastcall THistogramas::Button1Click(TObject *Sender)
{
TObject *Senderh;
Form1->Deshacer1Click(Senderh);
}
//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoRojoMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{

int a = int(Series1->XScreenToValue(X));
if(!rojoUno && !rojoDos){
	rojoInferior->Text = a;
	rojoInferior->Color = clAqua;
	rojoSuperior->Color = clWhite;

}
	if(rojoCero){
		rojoSuperior->Text = a;
		rojoSuperior->Color = clAqua;
		rojoInferior->Color = clWhite;
	}

}
//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoVerdeMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
int a = int(Series2->XScreenToValue(X));
if(!verdeUno && !verdeDos){
	verdeInferior->Text = a;
	verdeInferior->Color = clAqua;
	verdeSuperior->Color = clWhite;

}
	if(verdeCero){
		verdeSuperior->Text = a;
		verdeSuperior->Color = clAqua;
		verdeInferior->Color = clWhite;
	}

}
//---------------------------------------------------------------------------

void __fastcall THistogramas::graficoAzulMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
int a = int(Series3->XScreenToValue(X));
if(!azulUno && !azulDos){
	azulInferior->Text = a;
	azulInferior->Color = clAqua;
	azulSuperior->Color = clWhite;

}
	if(azulCero){
		azulSuperior->Text = a;
		azulSuperior->Color = clAqua;
		azulInferior->Color = clWhite;
	}

}
//---------------------------------------------------------------------------

