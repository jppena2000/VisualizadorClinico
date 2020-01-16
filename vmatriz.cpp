//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "vmatriz.h"
#include "visor.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TverMatriz *verMatriz;
//---------------------------------------------------------------------------
__fastcall TverMatriz::TverMatriz(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TverMatriz::FormClose(TObject *Sender, TCloseAction &Action)
{
escribeColores = false;
}
//---------------------------------------------------------------------------

