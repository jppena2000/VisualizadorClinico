object FormGamma: TFormGamma
  Left = 0
  Top = -1
  BorderStyle = bsDialog
  Caption = 'Correcci'#243'n Gamma'
  ClientHeight = 211
  ClientWidth = 381
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 92
    Top = 56
    Width = 72
    Height = 13
    Caption = 'Valor Potencia:'
  end
  object EditValor: TEdit
    Left = 184
    Top = 53
    Width = 121
    Height = 21
    MaxLength = 5
    TabOrder = 0
    Text = '1'
  end
  object Button1: TButton
    Left = 92
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Aplicar'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = Button2Click
  end
end
