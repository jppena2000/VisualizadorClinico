object panelCamara: TpanelCamara
  Left = 0
  Top = 0
  Caption = 'panelCamara'
  ClientHeight = 386
  ClientWidth = 671
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 640
    Height = 480
    Align = alCustom
    AutoSize = True
    Caption = 'Panel1'
    Color = clBackground
    ParentBackground = False
    PopupMenu = PopupMenu1
    TabOrder = 0
  end
  object PopupMenu1: TPopupMenu
    Left = 248
    Top = 176
    object Conectar1: TMenuItem
      Caption = 'Conectar'
      OnClick = Conectar1Click
    end
    object CapturarImagen1: TMenuItem
      Caption = 'Capturar Imagen'
      OnClick = CapturarImagen1Click
    end
    object Cerrar1: TMenuItem
      Caption = 'Cerrar'
    end
  end
end
