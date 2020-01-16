//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "formResulta2.h"
//---------------------------------------------------------------------------
#include "visor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tresulta2 *resulta2;
//---------------------------------------------------------------------------
__fastcall Tresulta2::Tresulta2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
/*void __fastcall Tresulta2::Button1Click(TObject *Sender)
{
double valmin, valmax;
valmin =-9999999999;
valmax =9999999999;
if (Edit1->Text != "") valmin = Edit1->Text.ToDouble();
if (Edit2->Text != "") valmax = Edit2->Text.ToDouble();


 // filtro nucleos
if (CheckBox1->Checked==true) {
	int datosfiltrados=0;
	if (ComboBox1->Text == "Distancia M")
		{
		for (int i = 1; i < GridMatriz->RowCount; i++) {
			if (GridMatriz->Cells[9][i].ToDouble() >= valmin && GridMatriz->Cells[9][i].ToDouble() <= valmax) {
				GridMatriz->RowHeights[i] = 20;
				datosfiltrados++;
				}
			else
				{
				GridMatriz->RowHeights[i] = -1;
				}
			}
		}
	if (ComboBox1->Text == "Distancia N")
		{
		for (int i = 1; i < GridMatriz->RowCount; i++) {
			if (GridMatriz->Cells[10][i].ToDouble() >= valmin  && GridMatriz->Cells[10][i].ToDouble() <= valmax) {
				GridMatriz->RowHeights[i] = 20;
				datosfiltrados++;
				}
			else
				{
				GridMatriz->RowHeights[i] = -1;
				}
			}
		}

	if (ComboBox1->Text == "Tamaño")
		{
		for (int i = 1; i < GridMatriz->RowCount; i++) {
			if (GridMatriz->Cells[11][i].ToDouble() >= valmin  && GridMatriz->Cells[10][i].ToDouble() <= valmax) {
				GridMatriz->RowHeights[i] = 20;
				datosfiltrados++;
			}
			else
				{
				GridMatriz->RowHeights[i] = -1;
				}
			}
		}

	Edit3->Text = datosfiltrados;
	}

	// filtro citoplasmas
	if (CheckBox2->Checked==true) {
	int datosfiltrados=0;
	if (ComboBox1->Text == "Distancia M")
		{
		for (int i = 1; i < GridMatriz2->RowCount; i++) {
			if (GridMatriz2->Cells[9][i].ToDouble() >= valmin && GridMatriz2->Cells[9][i].ToDouble() <= valmax) {
				GridMatriz2->RowHeights[i] = 20;
				datosfiltrados++;
				}
			else
				{
				GridMatriz2->RowHeights[i] = -1;
				}
			}
		}
	if (ComboBox1->Text == "Distancia N")
		{
		for (int i = 1; i < GridMatriz2->RowCount; i++) {
			if (GridMatriz2->Cells[10][i].ToDouble() >= valmin  && GridMatriz2->Cells[10][i].ToDouble() <= valmax) {
				GridMatriz2->RowHeights[i] = 20;
				datosfiltrados++;
				}
			else
				{
				GridMatriz2->RowHeights[i] = -1;
				}
			}
		}

	if (ComboBox1->Text == "Tamaño")
		{
		for (int i = 1; i < GridMatriz2->RowCount; i++) {
			if (GridMatriz2->Cells[11][i].ToDouble() >= valmin  && GridMatriz2->Cells[10][i].ToDouble() <= valmax) {
				GridMatriz2->RowHeights[i] = 20;
				datosfiltrados++;
			}
			else
				{
				GridMatriz2->RowHeights[i] = -1;
				}
			}
		}

	Edit4->Text = datosfiltrados;
	}
} */
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall Tresulta2::GridMatrizDblClick(TObject *Sender)
{

int col, row;
  col=GridMatriz->Col;
  row=GridMatriz->Row;
  if (row==0 || GridMatriz->Cells[1][row]=="") {
	  return;
  }
  int Y=GridMatriz->Cells[1][row].ToInt();
  int X=GridMatriz->Cells[6][row].ToInt();

  int Y2=GridMatriz->Cells[3][row].ToInt();
  int X2=GridMatriz->Cells[8][row].ToInt();

  Form1->ScrollBox1->VertScrollBar->Position  = (Form1->Image1->Height-100) - (Form1->Image1->Height+80-Y);
  Form1->ScrollBox1->HorzScrollBar->Position  = (Form1->Image1->Width-100) - (Form1->Image1->Width+80-X);

	Form1->PaintBoxSelect->Refresh();
  Form1->PaintBoxSelect->Canvas->Brush->Style = bsClear;
  Form1->PaintBoxSelect->Canvas->Pen->Color = clYellow;
  Form1->PaintBoxSelect->Canvas->Rectangle(X, Y, X2, Y2);


}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall Tresulta2::Button3Click(TObject *Sender)
{
resulta2->Close();
}
//---------------------------------------------------------------------------
/*void __fastcall Tresulta2::GridMatrizDblClick(TObject *Sender)
{
   int col, row;
  col=GridMatriz2->Col;
  row=GridMatriz2->Row;
  if (row==0 || GridMatriz2->Cells[1][row]=="") {
	  return;
  }
  int Y=GridMatriz2->Cells[1][row].ToInt();
  int X=GridMatriz2->Cells[6][row].ToInt();

  int Y2=GridMatriz2->Cells[3][row].ToInt();
  int X2=GridMatriz2->Cells[8][row].ToInt();

  Form1->ScrollBox1->VertScrollBar->Position  = (Form1->Image1->Height-100) - (Form1->Image1->Height+80-Y);
  Form1->ScrollBox1->HorzScrollBar->Position  = (Form1->Image1->Width-100) - (Form1->Image1->Width+80-X);

	Form1->PaintBoxSelect->Refresh();
  Form1->PaintBoxSelect->Canvas->Brush->Style = bsClear;
  Form1->PaintBoxSelect->Canvas->Pen->Color = clYellow;
  Form1->PaintBoxSelect->Canvas->Rectangle(X, Y, X2, Y2);
}
*/
//---------------------------------------------------------------------------
void __fastcall Tresulta2::Button2Click(TObject *Sender)
{
resulta2->ComboBox1->ItemIndex = 1;
	resulta2->Edit1->Text="";
	resulta2->Edit2->Text="";
	int datosfiltrados=0;
	for (int i = 1; i < GridMatriz->RowCount; i++) {
		  GridMatriz->RowHeights[i] = 20;
		  datosfiltrados++;
	}
	Edit3->Text = datosfiltrados;
}
//---------------------------------------------------------------------------
