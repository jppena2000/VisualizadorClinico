//---------------------------------------------------------------------------

#ifndef FrmgammaH
#define FrmgammaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormGamma : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditValor;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGamma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGamma *FormGamma;
//---------------------------------------------------------------------------
#endif
