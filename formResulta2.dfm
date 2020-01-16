object resulta2: Tresulta2
  Left = 0
  Top = 0
  Caption = 'resulta2'
  ClientHeight = 563
  ClientWidth = 808
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 12
  object Label4: TLabel
    Left = 498
    Top = 172
    Width = 64
    Height = 12
    Caption = 'Total Objetos:'
  end
  object Label5: TLabel
    Left = 8
    Top = 176
    Width = 142
    Height = 13
    Caption = 'Citoplasmas Encontrados'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 8
    Top = 10
    Width = 116
    Height = 13
    Caption = 'N'#250'cleos Encontrados'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 498
    Top = 338
    Width = 64
    Height = 12
    Caption = 'Total Objetos:'
  end
  object GridMatriz: TStringGrid
    Left = 8
    Top = 29
    Width = 683
    Height = 137
    ColCount = 12
    DefaultColWidth = 55
    DefaultRowHeight = 20
    RowCount = 12
    TabOrder = 0
    OnDblClick = GridMatrizDblClick
    RowHeights = (
      20
      20
      20
      20
      20
      20
      20
      20
      20
      20
      20
      20)
  end
  object GroupBox1: TGroupBox
    Left = 63
    Top = 364
    Width = 597
    Height = 158
    Caption = 'Aplicar Filtro'
    TabOrder = 1
    object Label1: TLabel
      Left = 23
      Top = 32
      Width = 49
      Height = 12
      Caption = 'Filtrar Por:'
    end
    object Label2: TLabel
      Left = 23
      Top = 71
      Width = 62
      Height = 12
      Caption = 'Valor M'#237'nimo:'
    end
    object Label3: TLabel
      Left = 250
      Top = 71
      Width = 64
      Height = 12
      Caption = 'Valor M'#225'ximo:'
    end
    object ComboBox1: TComboBox
      Left = 102
      Top = 32
      Width = 143
      Height = 20
      TabOrder = 0
      Items.Strings = (
        'Distancia N'
        'Distancia M'
        'Tama'#241'o')
    end
    object Edit1: TEdit
      Left = 102
      Top = 71
      Width = 119
      Height = 24
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 322
      Top = 71
      Width = 118
      Height = 24
      TabOrder = 2
    end
    object Button1: TButton
      Left = 171
      Top = 118
      Width = 89
      Height = 25
      Caption = 'Filtrar'
      TabOrder = 3
    end
    object Button2: TButton
      Left = 322
      Top = 118
      Width = 89
      Height = 25
      Caption = 'Limpiar Filtro'
      TabOrder = 4
      OnClick = Button2Click
    end
    object CheckBox1: TCheckBox
      Left = 322
      Top = 32
      Width = 95
      Height = 16
      Caption = 'N'#250'cleos'
      TabOrder = 5
    end
    object CheckBox2: TCheckBox
      Left = 436
      Top = 32
      Width = 94
      Height = 16
      Caption = 'Citoplasmas'
      TabOrder = 6
    end
  end
  object Button3: TButton
    Left = 297
    Top = 528
    Width = 111
    Height = 24
    Caption = 'Cerrar'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Edit3: TEdit
    Left = 572
    Top = 172
    Width = 119
    Height = 25
    TabOrder = 3
    Text = 'Edit3'
  end
  object GridMatriz2: TStringGrid
    Left = 8
    Top = 195
    Width = 683
    Height = 137
    ColCount = 12
    DefaultColWidth = 55
    DefaultRowHeight = 20
    RowCount = 12
    TabOrder = 4
    RowHeights = (
      20
      20
      20
      20
      20
      20
      20
      20
      20
      20
      20
      20)
  end
  object Edit4: TEdit
    Left = 572
    Top = 338
    Width = 119
    Height = 25
    TabOrder = 5
    Text = 'Edit4'
  end
end
