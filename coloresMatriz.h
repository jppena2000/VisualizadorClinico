//---------------------------------------------------------------------------

#ifndef coloresMatrizH
#define coloresMatrizH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TformColores : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *rojo;
	TCheckBox *verde;
	TCheckBox *azul;
	TButton *Button2;
	TButton *Button3;
	void __fastcall rojoClick(TObject *Sender);
	void __fastcall verdeClick(TObject *Sender);
	void __fastcall azulClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformColores(TComponent* Owner);
	 void recibeImagen(TImage *);
	 void cambiaColores(int x , int y , int z );
};
//---------------------------------------------------------------------------
extern PACKAGE TformColores *formColores;
//---------------------------------------------------------------------------
#endif
