//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "Formfiltro.h"
#include "visor.h"
#include "vectoresMatricesEnteros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConvolucion *FormConvolucion;
//---------------------------------------------------------------------------
__fastcall TFormConvolucion::TFormConvolucion(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::Radio33Click(TObject *Sender)
{

ed00->Visible= true;ed01->Visible= true;ed02->Visible= true;ed03->Visible= false;
ed04->Visible= false;ed05->Visible= false;ed06->Visible= false;

ed10->Visible= true;ed11->Visible= true;ed12->Visible= true;ed13->Visible= false;
ed14->Visible= false;ed15->Visible= false;ed16->Visible= false;

ed20->Visible= true;
ed21->Visible= true;
ed22->Visible= true;
ed23->Visible= false;
ed24->Visible= false;
ed25->Visible= false;
ed26->Visible= false;

ed30->Visible= false;
ed31->Visible= false;
ed32->Visible= false;
ed33->Visible= false;
ed34->Visible= false;
ed35->Visible= false;
ed36->Visible= false;

ed40->Visible= false;
ed41->Visible= false;
ed42->Visible= false;
ed43->Visible= false;
ed44->Visible= false;
ed45->Visible= false;
ed46->Visible= false;

ed50->Visible= false;
ed51->Visible= false;
ed52->Visible= false;
ed53->Visible= false;
ed54->Visible= false;
ed55->Visible= false;
ed56->Visible= false;

ed60->Visible= false;
ed61->Visible= false;
ed62->Visible= false;
ed63->Visible= false;
ed64->Visible= false;
ed65->Visible= false;
ed66->Visible= false;

}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::Radio55Click(TObject *Sender)
{
ed00->Visible= true;
ed01->Visible= true;
ed02->Visible= true;
ed03->Visible= true;
ed04->Visible= true;
ed05->Visible= false;
ed06->Visible= false;

ed10->Visible= true;
ed11->Visible= true;
ed12->Visible= true;
ed13->Visible= true;
ed14->Visible= true;
ed15->Visible= false;
ed16->Visible= false;

ed20->Visible= true;
ed21->Visible= true;
ed22->Visible= true;
ed23->Visible= true;
ed24->Visible= true;
ed25->Visible= false;
ed26->Visible= false;

ed30->Visible= true;
ed31->Visible= true;
ed32->Visible= true;
ed33->Visible= true;
ed34->Visible= true;
ed35->Visible= false;
ed36->Visible= false;

ed40->Visible= true;
ed41->Visible= true;
ed42->Visible= true;
ed43->Visible= true;
ed44->Visible= true;
ed45->Visible= false;
ed46->Visible= false;

ed50->Visible= false;
ed51->Visible= false;
ed52->Visible= false;
ed53->Visible= false;
ed54->Visible= false;
ed55->Visible= false;
ed56->Visible= false;

ed60->Visible= false;
ed61->Visible= false;
ed62->Visible= false;
ed63->Visible= false;
ed64->Visible= false;
ed65->Visible= false;
ed66->Visible= false;
}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::Radio77Click(TObject *Sender)
{
ed00->Visible= true;
ed01->Visible= true;
ed02->Visible= true;
ed03->Visible= true;
ed04->Visible= true;
ed05->Visible= true;
ed06->Visible= true;

ed10->Visible= true;
ed11->Visible= true;
ed12->Visible= true;
ed13->Visible= true;
ed14->Visible= true;
ed15->Visible= true;
ed16->Visible= true;

ed20->Visible= true;
ed21->Visible= true;
ed22->Visible= true;
ed23->Visible= true;
ed24->Visible= true;
ed25->Visible= true;
ed26->Visible= true;

ed30->Visible= true;
ed31->Visible= true;
ed32->Visible= true;
ed33->Visible= true;
ed34->Visible= true;
ed35->Visible= true;
ed36->Visible= true;

ed40->Visible= true;
ed41->Visible= true;
ed42->Visible= true;
ed43->Visible= true;
ed44->Visible= true;
ed45->Visible= true;
ed46->Visible= true;

ed50->Visible= true;
ed51->Visible= true;
ed52->Visible= true;
ed53->Visible= true;
ed54->Visible= true;
ed55->Visible= true;
ed56->Visible= true;

ed60->Visible= true;
ed61->Visible= true;
ed62->Visible= true;
ed63->Visible= true;
ed64->Visible= true;
ed65->Visible= true;
ed66->Visible= true;
}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::ButtonCancelarClick(TObject *Sender)
{
Form1->Enabled=true;
FormConvolucion->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::ButtonProcesarClick(TObject *Sender)
{
Form1->Enabled=true;
FormConvolucion->Hide();


	  int dimension;
	  if (Radio33->Checked) dimension=3;
	  if (Radio55->Checked) dimension=5;
	  if (Radio77->Checked) dimension=7;

	  int **k = MemMatrizEnt(dimension,dimension,k);

	  k[0][0]=ed00->Text.ToInt();
	  k[0][1]=ed01->Text.ToInt();
	  k[0][2]=ed02->Text.ToInt();
	  k[1][0]=ed10->Text.ToInt();
	  k[1][1]=ed11->Text.ToInt();
	  k[1][2]=ed12->Text.ToInt();
	  k[2][0]=ed20->Text.ToInt();
	  k[2][1]=ed21->Text.ToInt();
	  k[2][2]=ed22->Text.ToInt();

	  if (dimension>3) {


		  k[0][3]=ed03->Text.ToInt();
		  k[0][4]=ed04->Text.ToInt();
		  k[1][3]=ed13->Text.ToInt();
		  k[1][4]=ed14->Text.ToInt();
		  k[2][3]=ed23->Text.ToInt();
		  k[2][4]=ed24->Text.ToInt();
		  k[3][0]=ed30->Text.ToInt();
		  k[3][1]=ed31->Text.ToInt();
		  k[3][2]=ed32->Text.ToInt();
		  k[3][3]=ed33->Text.ToInt();
		  k[3][4]=ed34->Text.ToInt();
		  k[4][0]=ed40->Text.ToInt();
		  k[4][1]=ed41->Text.ToInt();
		  k[4][2]=ed42->Text.ToInt();
		  k[4][3]=ed43->Text.ToInt();
		  k[4][4]=ed44->Text.ToInt();

		  if (dimension>5) {
					 k[0][5]=ed05->Text.ToInt();
					 k[0][6]=ed06->Text.ToInt();
					 k[1][5]=ed15->Text.ToInt();
					 k[1][6]=ed16->Text.ToInt();
					 k[2][5]=ed25->Text.ToInt();
					 k[2][6]=ed26->Text.ToInt();
					 k[3][5]=ed35->Text.ToInt();
					 k[3][6]=ed36->Text.ToInt();
					 k[4][5]=ed45->Text.ToInt();
					 k[4][6]=ed46->Text.ToInt();
					 k[5][0]=ed50->Text.ToInt();
					 k[5][1]=ed51->Text.ToInt();
					 k[5][2]=ed52->Text.ToInt();
					 k[5][3]=ed53->Text.ToInt();
					 k[5][4]=ed54->Text.ToInt();
					 k[5][5]=ed55->Text.ToInt();
					 k[5][6]=ed56->Text.ToInt();
					 k[6][0]=ed60->Text.ToInt();
					 k[6][1]=ed61->Text.ToInt();
					 k[6][2]=ed62->Text.ToInt();
					 k[6][3]=ed63->Text.ToInt();
					 k[6][4]=ed64->Text.ToInt();
					 k[6][5]=ed65->Text.ToInt();
					 k[6][6]=ed66->Text.ToInt();
					 }
		}


Form1->ProcesaFiltro(k);
}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::FormClose(TObject *Sender, TCloseAction &Action)

{
Form1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormConvolucion::ButtonCargarClick(TObject *Sender)
{
AnsiString      Archivo,UCArchivo;

if( OpenDialog1->Execute() )
  {

	   Archivo = OpenDialog1->FileName;
	   UCArchivo = Archivo.UpperCase();
	   TIniFile *Parametros = new TIniFile (Archivo);
	   if (Parametros) {
					 int dimension = Parametros->ReadInteger("matriz","dim",0);
					 if (dimension==3)    Radio33->Checked = true;
					 if (dimension==5)    Radio55->Checked = true;
					 if (dimension==7)    Radio77->Checked = true;

					 ed00->Text = Parametros->ReadInteger("matriz","d00",0);
					 ed01->Text = Parametros->ReadInteger("matriz","d01",0);
					 ed02->Text = Parametros->ReadInteger("matriz","d02",0);
					 ed10->Text = Parametros->ReadInteger("matriz","d10",0);
					 ed11->Text = Parametros->ReadInteger("matriz","d11",0);
					 ed12->Text = Parametros->ReadInteger("matriz","d12",0);
					 ed20->Text = Parametros->ReadInteger("matriz","d20",0);
					 ed21->Text = Parametros->ReadInteger("matriz","d21",0);
					 ed22->Text = Parametros->ReadInteger("matriz","d22",0);

					 if (dimension>3){
					 ed03->Text = Parametros->ReadInteger("matriz","d03",0);
					 ed04->Text = Parametros->ReadInteger("matriz","d04",0);
					 ed13->Text = Parametros->ReadInteger("matriz","d13",0);
					 ed14->Text = Parametros->ReadInteger("matriz","d14",0);
					 ed23->Text = Parametros->ReadInteger("matriz","d23",0);
					 ed24->Text = Parametros->ReadInteger("matriz","d24",0);
					 ed30->Text = Parametros->ReadInteger("matriz","d30",0);
					 ed31->Text = Parametros->ReadInteger("matriz","d31",0);
					 ed32->Text = Parametros->ReadInteger("matriz","d32",0);
					 ed33->Text = Parametros->ReadInteger("matriz","d33",0);
					 ed34->Text = Parametros->ReadInteger("matriz","d34",0);
					 ed40->Text = Parametros->ReadInteger("matriz","d40",0);
					 ed41->Text = Parametros->ReadInteger("matriz","d41",0);
					 ed42->Text = Parametros->ReadInteger("matriz","d42",0);
					 ed43->Text = Parametros->ReadInteger("matriz","d43",0);
					 ed44->Text = Parametros->ReadInteger("matriz","d44",0);
					 }
					 if (dimension>5){
					 ed05->Text = Parametros->ReadInteger("matriz","d05",0);
					 ed06->Text = Parametros->ReadInteger("matriz","d06",0);
					 ed15->Text = Parametros->ReadInteger("matriz","d15",0);
					 ed16->Text = Parametros->ReadInteger("matriz","d16",0);
					 ed25->Text = Parametros->ReadInteger("matriz","d25",0);
					 ed26->Text = Parametros->ReadInteger("matriz","d26",0);
					 ed35->Text = Parametros->ReadInteger("matriz","d35",0);
					 ed36->Text = Parametros->ReadInteger("matriz","d36",0);
					 ed45->Text = Parametros->ReadInteger("matriz","d45",0);
					 ed46->Text = Parametros->ReadInteger("matriz","d46",0);
					 ed50->Text = Parametros->ReadInteger("matriz","d50",0);
					 ed51->Text = Parametros->ReadInteger("matriz","d51",0);
					 ed52->Text = Parametros->ReadInteger("matriz","d52",0);
					 ed53->Text = Parametros->ReadInteger("matriz","d53",0);
					 ed54->Text = Parametros->ReadInteger("matriz","d54",0);
					 ed55->Text = Parametros->ReadInteger("matriz","d55",0);
					 ed56->Text = Parametros->ReadInteger("matriz","d56",0);
					 ed60->Text = Parametros->ReadInteger("matriz","d60",0);
					 ed61->Text = Parametros->ReadInteger("matriz","d61",0);
					 ed62->Text = Parametros->ReadInteger("matriz","d62",0);
					 ed63->Text = Parametros->ReadInteger("matriz","d63",0);
					 ed64->Text = Parametros->ReadInteger("matriz","d64",0);
					 ed65->Text = Parametros->ReadInteger("matriz","d65",0);
					 ed66->Text = Parametros->ReadInteger("matriz","d66",0);
                     }
	   }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormConvolucion::ButtonGuardarClick(TObject *Sender)
{
AnsiString      Archivo,UCArchivo;
if (SaveDialog1->Execute() ) {
	  Archivo = SaveDialog1->FileName;
	  UCArchivo = Archivo.UpperCase();
	  TIniFile *Parametros = new TIniFile (Archivo);
	  int dimension;
	  if (Radio33->Checked) dimension=3;
	  if (Radio55->Checked) dimension=5;
	  if (Radio77->Checked) dimension=7;

	  Parametros->WriteInteger("matriz","dim",dimension);


	  Parametros->WriteInteger("matriz","d00",ed00->Text.ToInt());
	  Parametros->WriteInteger("matriz","d01",ed01->Text.ToInt());
	  Parametros->WriteInteger("matriz","d02",ed02->Text.ToInt());
	  Parametros->WriteInteger("matriz","d10",ed10->Text.ToInt());
	  Parametros->WriteInteger("matriz","d11",ed11->Text.ToInt());
	  Parametros->WriteInteger("matriz","d12",ed12->Text.ToInt());
	  Parametros->WriteInteger("matriz","d20",ed20->Text.ToInt());
	  Parametros->WriteInteger("matriz","d21",ed21->Text.ToInt());
	  Parametros->WriteInteger("matriz","d22",ed22->Text.ToInt());

	  if (dimension>3) {


		  Parametros->WriteInteger("matriz","d03",ed03->Text.ToInt());
		  Parametros->WriteInteger("matriz","d04",ed04->Text.ToInt());
		  Parametros->WriteInteger("matriz","d13",ed13->Text.ToInt());
		  Parametros->WriteInteger("matriz","d14",ed14->Text.ToInt());
		  Parametros->WriteInteger("matriz","d23",ed23->Text.ToInt());
		  Parametros->WriteInteger("matriz","d24",ed24->Text.ToInt());
		  Parametros->WriteInteger("matriz","d30",ed30->Text.ToInt());
		  Parametros->WriteInteger("matriz","d31",ed31->Text.ToInt());
		  Parametros->WriteInteger("matriz","d32",ed32->Text.ToInt());
		  Parametros->WriteInteger("matriz","d33",ed33->Text.ToInt());
		  Parametros->WriteInteger("matriz","d34",ed34->Text.ToInt());
		  Parametros->WriteInteger("matriz","d40",ed40->Text.ToInt());
		  Parametros->WriteInteger("matriz","d41",ed41->Text.ToInt());
		  Parametros->WriteInteger("matriz","d42",ed42->Text.ToInt());
		  Parametros->WriteInteger("matriz","d43",ed43->Text.ToInt());
		  Parametros->WriteInteger("matriz","d44",ed44->Text.ToInt());

		  if (dimension>5) {
					 Parametros->WriteInteger("matriz","d05",ed05->Text.ToInt());
					 Parametros->WriteInteger("matriz","d06",ed06->Text.ToInt());
					 Parametros->WriteInteger("matriz","d15",ed15->Text.ToInt());
					 Parametros->WriteInteger("matriz","d16",ed16->Text.ToInt());
					 Parametros->WriteInteger("matriz","d25",ed25->Text.ToInt());
					 Parametros->WriteInteger("matriz","d26",ed26->Text.ToInt());
					 Parametros->WriteInteger("matriz","d35",ed35->Text.ToInt());
					 Parametros->WriteInteger("matriz","d36",ed36->Text.ToInt());
					 Parametros->WriteInteger("matriz","d45",ed45->Text.ToInt());
					 Parametros->WriteInteger("matriz","d46",ed46->Text.ToInt());
					 Parametros->WriteInteger("matriz","d50",ed50->Text.ToInt());
					 Parametros->WriteInteger("matriz","d51",ed51->Text.ToInt());
					 Parametros->WriteInteger("matriz","d52",ed52->Text.ToInt());
					 Parametros->WriteInteger("matriz","d53",ed53->Text.ToInt());
					 Parametros->WriteInteger("matriz","d54",ed54->Text.ToInt());
					 Parametros->WriteInteger("matriz","d55",ed55->Text.ToInt());
					 Parametros->WriteInteger("matriz","d56",ed56->Text.ToInt());
					 Parametros->WriteInteger("matriz","d60",ed60->Text.ToInt());
					 Parametros->WriteInteger("matriz","d61",ed61->Text.ToInt());
					 Parametros->WriteInteger("matriz","d62",ed62->Text.ToInt());
					 Parametros->WriteInteger("matriz","d63",ed63->Text.ToInt());
					 Parametros->WriteInteger("matriz","d64",ed64->Text.ToInt());
					 Parametros->WriteInteger("matriz","d65",ed65->Text.ToInt());
					 Parametros->WriteInteger("matriz","d66",ed66->Text.ToInt());
					 }
		}
      }
}
//---------------------------------------------------------------------------


