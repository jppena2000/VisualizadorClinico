//---------------------------------------------------------------------------

#ifndef formResulta2H
#define formResulta2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class Tresulta2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TStringGrid *GridMatriz;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TComboBox *ComboBox1;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TButton *Button3;
	TEdit *Edit3;
	TStringGrid *GridMatriz2;
	TEdit *Edit4;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall GridMatrizDblClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tresulta2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tresulta2 *resulta2;
//---------------------------------------------------------------------------
#endif
