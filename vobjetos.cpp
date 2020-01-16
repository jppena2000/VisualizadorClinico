//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "vobjetos.h"
#include "visor.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVerObjetos *VerObjetos;
//---------------------------------------------------------------------------
__fastcall TVerObjetos::TVerObjetos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TVerObjetos::FormClose(TObject *Sender, TCloseAction &Action)
{

escribeObjetos = false;
}
//---------------------------------------------------------------------------



