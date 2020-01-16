//---------------------------------------------------------------------------

#ifndef FromBrilloH
#define FromBrilloH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TBrillo : public TForm
{
__published:	// IDE-managed Components
	TLabel *Brightness;
	TScrollBar *ScrollBar1;
	TScrollBar *ScrollBar2;
	TLabel *Contrast;
	TButton *Button2;
	TButton *Button1;
	TLabel *cantidadBrillo;
	TLabel *CantidadContraste;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ScrollBar1Change(TObject *Sender);
	void __fastcall ScrollBar2Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TBrillo(TComponent* Owner);
	  void brilloContraste(TImage *);

};
//---------------------------------------------------------------------------
extern PACKAGE TBrillo *Brillo;
//---------------------------------------------------------------------------
#endif
