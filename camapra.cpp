//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "visor.h"
#include "camapra.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TpanelCamara *panelCamara;

HWND hWndC;
CAPDRIVERCAPS CapDrvCaps;
CAPSTATUS CapStatus;
//---------------------------------------------------------------------------
__fastcall TpanelCamara::TpanelCamara(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TpanelCamara::FormCreate(TObject *Sender)
{
/*  CAPDRIVERCAPS gCapDrvCaps;
//int sizef,sizetemp,jd;
   HWND capWin=capCreateCaptureWindow((LPSTR)"Video Windows",WS_CHILD|WS_VISIBLE,Panel1->Left,Panel1->Top,Panel1->Width,Panel1->Height,(HWND)Handle,1);
  // capDriverConnect(capWin,0);
	if(capDriverConnect(capWin,0))
	  {
		capDriverGetCaps(capWin,&gCapDrvCaps,sizeof(CAPDRIVERCAPS));
		if(gCapDrvCaps.fCaptureInitialized)
		  {
			capPreviewRate(capWin,66);
			capPreview(capWin,TRUE);
		  }
		else
		  {
			 NULL;
		  } } */
}
//---------------------------------------------------------------------------
void __fastcall TpanelCamara::Conectar1Click(TObject *Sender)
{
   CAPDRIVERCAPS gCapDrvCaps;
//int sizef,sizetemp,jd;
   HWND capWin=capCreateCaptureWindow((LPSTR)"Video Windows",WS_CHILD|WS_VISIBLE,Panel1->Left,Panel1->Top,Panel1->Width,Panel1->Height,(HWND)Handle,1);
  // capDriverConnect(capWin,0);
	if(capDriverConnect(capWin,0))
	  {
		capDriverGetCaps(capWin,&gCapDrvCaps,sizeof(CAPDRIVERCAPS));
		if(gCapDrvCaps.fCaptureInitialized)
		  {
			capPreviewRate(capWin,66);
			capPreview(capWin,TRUE);
		  }
		else
		  {
		   // StatusBar1->SimpleText="ÉãÏñÍ·³õÊ¼»¯Ê§°Ü";
		   NULL;
		  } }

}
//---------------------------------------------------------------------------
void __fastcall TpanelCamara::CapturarImagen1Click(TObject *Sender)
{
Graphics::TBitmap *Bitmap=new Graphics::TBitmap;
 TJPEGImage *jmp=new  TJPEGImage;
 Bitmap->Width= panelCamara->Panel1->Width;
 Bitmap->Height=panelCamara->Panel1->Height;
 Bitmap->PixelFormat=pf32bit;
 ::BitBlt (Bitmap->Canvas->Handle,panelCamara->Panel1->Left,Form1->Panel1->Top,panelCamara->Panel1->Width,panelCamara->Panel1->Height,panelCamara->Canvas->Handle,0,0,SRCCOPY);
 jmp->Assign(Bitmap);
 jmp->Compress();
 jmp->SaveToFile("ent.jpg");
 //Image1->Picture->Assign(jmp);
 //////////////////
	   TJPEGImage      *pJPegImage;
	   pJPegImage = new TJPEGImage();
	   pJPegImage->LoadFromFile("ent.jpg");
	   pJPegImage->DIBNeeded();
		Form1->Image1->Width = jmp->Width;
		Form1->Image1->Height = jmp->Height;

	  Form1->Image1->Picture->Bitmap->Assign(pJPegImage);

	   //Image1->Top = 0;
	  // Image1->Left = 0;
	 //  Image1->Width = Image1->Picture->Bitmap->Width;
	  // Image1->Height = Image1->Picture->Bitmap->Height;


 ///////////////////

  Form1->Panel1->Visible = true;

	   Form1->largo->Caption = Form1->Image1->Width;
	   Form1->alto->Caption = Form1->Image1->Height;
	   Form1->largo->Visible = true;
	   Form1->alto->Visible = true;
	   Form1->nombreXX->Visible = true;
	   //SE ADAPTA EL SCROLL DE LA IMAGEN A LA PANTALLA
	   if(Form1->Image1->Width < Screen->Width)
	   {
	   Form1->Panel1->Width = Form1->Image1->Width;
	   }else{
	   Form1->Panel1->Width = Screen->Width-2;
		}

 delete jmp;
 delete Bitmap;

 panelCamara->Close();
}
//---------------------------------------------------------------------------

