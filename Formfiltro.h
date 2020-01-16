//---------------------------------------------------------------------------

#ifndef FormfiltroH
#define FormfiltroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormConvolucion : public TForm
{
__published:	// IDE-managed Components
	TEdit *ed03;
	TEdit *ed13;
	TEdit *ed14;
	TEdit *ed15;
	TEdit *ed35;
	TEdit *ed25;
	TEdit *ed34;
	TEdit *ed30;
	TEdit *ed24;
	TEdit *ed20;
	TEdit *ed43;
	TEdit *ed05;
	TEdit *ed04;
	TEdit *ed23;
	TEdit *ed45;
	TEdit *ed44;
	TEdit *ed40;
	TEdit *ed00;
	TEdit *ed02;
	TEdit *ed01;
	TEdit *ed53;
	TEdit *ed33;
	TEdit *ed55;
	TEdit *ed54;
	TEdit *ed50;
	TEdit *ed63;
	TEdit *ed65;
	TEdit *ed64;
	TEdit *ed60;
	TEdit *ed32;
	TEdit *ed22;
	TEdit *ed42;
	TEdit *ed12;
	TEdit *ed52;
	TEdit *ed62;
	TEdit *ed31;
	TEdit *ed21;
	TEdit *ed11;
	TEdit *ed41;
	TEdit *ed10;
	TEdit *ed51;
	TEdit *ed61;
	TEdit *ed16;
	TEdit *ed36;
	TEdit *ed26;
	TEdit *ed06;
	TEdit *ed46;
	TEdit *ed56;
	TEdit *ed66;
	TGroupBox *GroupBox1;
	TRadioButton *Radio33;
	TRadioButton *Radio55;
	TRadioButton *Radio77;
	TButton *ButtonCargar;
	TButton *ButtonGuardar;
	TButton *ButtonProcesar;
	TButton *ButtonCancelar;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TLabel *Label1;
	void __fastcall Radio33Click(TObject *Sender);
	void __fastcall Radio55Click(TObject *Sender);
	void __fastcall Radio77Click(TObject *Sender);
	void __fastcall ButtonCancelarClick(TObject *Sender);
	void __fastcall ButtonProcesarClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonCargarClick(TObject *Sender);
	void __fastcall ButtonGuardarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormConvolucion(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConvolucion *FormConvolucion;
//---------------------------------------------------------------------------
#endif
