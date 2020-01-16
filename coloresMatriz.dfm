object formColores: TformColores
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'Matriz de Colores'
  ClientHeight = 150
  ClientWidth = 172
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object rojo: TCheckBox
    Left = 48
    Top = 16
    Width = 97
    Height = 17
    Caption = 'Rojo'
    Checked = True
    State = cbChecked
    TabOrder = 0
    OnClick = rojoClick
  end
  object verde: TCheckBox
    Left = 48
    Top = 48
    Width = 97
    Height = 17
    Caption = 'Verde'
    Checked = True
    State = cbChecked
    TabOrder = 1
    OnClick = verdeClick
  end
  object azul: TCheckBox
    Left = 48
    Top = 80
    Width = 97
    Height = 17
    Caption = 'Azul'
    Checked = True
    State = cbChecked
    TabOrder = 2
    OnClick = azulClick
  end
  object Button2: TButton
    Left = 89
    Top = 117
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 8
    Top = 117
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 4
    OnClick = Button3Click
  end
end
