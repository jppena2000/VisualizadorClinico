//---------------------------------------------------------------------------

#ifndef vobjetosH
#define vobjetosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <DBXMySQL.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TVerObjetos : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *EtiqImag;
	TLabel *EtiqBorde1;
	TLabel *Label9;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TStringGrid *GridMatriz;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TVerObjetos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVerObjetos *VerObjetos;
//---------------------------------------------------------------------------
#endif
