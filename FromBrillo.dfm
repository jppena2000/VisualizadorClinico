object Brillo: TBrillo
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'Brillo/Contraste'
  ClientHeight = 158
  ClientWidth = 248
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Brightness: TLabel
    Left = 16
    Top = 9
    Width = 22
    Height = 13
    Caption = 'Brillo'
  end
  object Contrast: TLabel
    Left = 16
    Top = 57
    Width = 48
    Height = 13
    Caption = 'Contraste'
  end
  object cantidadBrillo: TLabel
    Left = 207
    Top = 32
    Width = 33
    Height = 13
    Caption = '0'
  end
  object CantidadContraste: TLabel
    Left = 208
    Top = 80
    Width = 32
    Height = 13
    Caption = '0'
  end
  object ScrollBar1: TScrollBar
    Left = 16
    Top = 28
    Width = 185
    Height = 17
    Max = 255
    Min = -255
    PageSize = 0
    TabOrder = 0
    OnChange = ScrollBar1Change
  end
  object ScrollBar2: TScrollBar
    Left = 17
    Top = 76
    Width = 185
    Height = 17
    Max = 400
    Min = -400
    PageSize = 0
    TabOrder = 1
    OnChange = ScrollBar2Change
  end
  object Button2: TButton
    Left = 112
    Top = 115
    Width = 90
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button1: TButton
    Left = 16
    Top = 115
    Width = 90
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 3
    OnClick = Button1Click
  end
end
