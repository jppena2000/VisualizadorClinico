//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frmgamma.h"
#include "visor.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGamma *FormGamma;
//---------------------------------------------------------------------------
__fastcall TFormGamma::TFormGamma(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGamma::Button2Click(TObject *Sender)
{
Form1->Enabled=true;
FormGamma->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormGamma::Button1Click(TObject *Sender)
{

Form1->Enabled=true;
FormGamma->Hide();
float valor = EditValor->Text.ToDouble();
Form1->aplicaGamma(valor);
}

void fnGamma(TImage *ImageSelected)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormGamma::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Enabled=true;
}
//---------------------------------------------------------------------------
