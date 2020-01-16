//---------------------------------------------------------------------------

#ifndef camapraH
#define camapraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include <jpeg.hpp>
#include <vfw.h>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TpanelCamara : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Conectar1;
	TMenuItem *CapturarImagen1;
	TMenuItem *Cerrar1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Conectar1Click(TObject *Sender);
	void __fastcall CapturarImagen1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TpanelCamara(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TpanelCamara *panelCamara;
//---------------------------------------------------------------------------
#endif
