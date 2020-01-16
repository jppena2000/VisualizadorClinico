object Histogramas: THistogramas
  Left = 0
  Top = 55
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Histogramas'
  ClientHeight = 566
  ClientWidth = 454
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 344
    Top = 40
    Width = 36
    Height = 13
    Caption = 'Inferior'
  end
  object Label2: TLabel
    Left = 344
    Top = 64
    Width = 40
    Height = 13
    Caption = 'Superior'
  end
  object Label3: TLabel
    Left = 344
    Top = 208
    Width = 36
    Height = 13
    Caption = 'Inferior'
  end
  object Label4: TLabel
    Left = 344
    Top = 232
    Width = 40
    Height = 13
    Caption = 'Superior'
  end
  object Label5: TLabel
    Left = 349
    Top = 400
    Width = 40
    Height = 13
    Caption = 'Superior'
  end
  object Label6: TLabel
    Left = 349
    Top = 376
    Width = 36
    Height = 13
    Caption = 'Inferior'
  end
  object GroupBox1: TGroupBox
    Left = 3
    Top = 8
    Width = 337
    Height = 540
    Caption = 'Hitograma RGB'
    TabOrder = 0
    object graficoRojo: TChart
      Left = 24
      Top = 34
      Width = 281
      Height = 151
      Margins.Left = 0
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Border.Style = psClear
      Border.Width = 0
      Border.EndStyle = esRound
      Legend.Visible = False
      MarginBottom = 0
      MarginLeft = 0
      MarginRight = 0
      MarginTop = 0
      Title.Text.Strings = (
        '')
      Title.Visible = False
      DepthAxis.Automatic = False
      DepthAxis.AutomaticMaximum = False
      DepthAxis.AutomaticMinimum = False
      DepthAxis.Maximum = 0.169999999999999800
      DepthAxis.Minimum = -0.830000000000000300
      DepthTopAxis.Automatic = False
      DepthTopAxis.AutomaticMaximum = False
      DepthTopAxis.AutomaticMinimum = False
      DepthTopAxis.Maximum = 0.169999999999999800
      DepthTopAxis.Minimum = -0.830000000000000300
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Axis.Color = clRed
      LeftAxis.Maximum = 625.200000000000500000
      LeftAxis.Minimum = 65.200000000000700000
      RightAxis.Automatic = False
      RightAxis.AutomaticMaximum = False
      RightAxis.AutomaticMinimum = False
      View3D = False
      TabOrder = 0
      OnMouseDown = graficoRojoMouseDown
      OnMouseMove = graficoRojoMouseMove
      PrintMargins = (
        15
        26
        15
        26)
      ColorPaletteIndex = 13
      object Series1: TAreaSeries
        Marks.Arrow.Visible = True
        Marks.Callout.Brush.Color = clBlack
        Marks.Callout.Arrow.Visible = True
        Marks.Emboss.Color = 8487297
        Marks.Shadow.Color = 8487297
        Marks.Visible = False
        SeriesColor = clRed
        Title = 'serieRojo'
        OnClick = Series1Click
        AreaChartBrush.Color = clBlack
        AreaLinesPen.Color = clRed
        DrawArea = True
        Pointer.Brush.Gradient.EndColor = clRed
        Pointer.Gradient.EndColor = clRed
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        Pointer.Visible = False
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
  end
  object graficoAzul: TChart
    Left = 27
    Top = 378
    Width = 281
    Height = 151
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Border.Style = psClear
    Border.Width = 0
    Border.EndStyle = esRound
    Legend.Visible = False
    MarginBottom = 0
    MarginLeft = 0
    MarginRight = 0
    MarginTop = 0
    Title.Text.Strings = (
      '')
    Title.Visible = False
    View3D = False
    TabOrder = 2
    OnMouseDown = graficoAzulMouseDown
    OnMouseMove = graficoAzulMouseMove
    PrintMargins = (
      15
      26
      15
      26)
    ColorPaletteIndex = 13
    object Series3: TAreaSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      SeriesColor = clBlue
      AreaLinesPen.Color = clBlue
      DrawArea = True
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object graficoVerde: TChart
    Left = 27
    Top = 210
    Width = 281
    Height = 151
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Border.Style = psClear
    Border.Width = 0
    Border.EndStyle = esRound
    Legend.Visible = False
    MarginBottom = 0
    MarginLeft = 0
    MarginRight = 0
    MarginTop = 0
    Title.Text.Strings = (
      '')
    Title.Visible = False
    DepthAxis.Automatic = False
    DepthAxis.AutomaticMaximum = False
    DepthAxis.AutomaticMinimum = False
    DepthAxis.Maximum = 0.650000000000000100
    DepthAxis.Minimum = -0.349999999999999900
    DepthTopAxis.Automatic = False
    DepthTopAxis.AutomaticMaximum = False
    DepthTopAxis.AutomaticMinimum = False
    DepthTopAxis.Maximum = 0.650000000000000100
    DepthTopAxis.Minimum = -0.349999999999999900
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 1331.749999999999000000
    LeftAxis.Minimum = 936.750000000000300000
    RightAxis.Automatic = False
    RightAxis.AutomaticMaximum = False
    RightAxis.AutomaticMinimum = False
    View3D = False
    TabOrder = 1
    OnMouseDown = graficoVerdeMouseDown
    OnMouseMove = graficoVerdeMouseMove
    PrintMargins = (
      15
      26
      15
      26)
    ColorPaletteIndex = 13
    object Series2: TAreaSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      SeriesColor = clLime
      AreaLinesPen.Color = clLime
      DrawArea = True
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Button3: TButton
    Left = 360
    Top = 496
    Width = 86
    Height = 25
    Caption = 'Ver en Imagen'
    TabOrder = 3
    OnClick = Button3Click
  end
  object rojoSuperior: TEdit
    Left = 386
    Top = 61
    Width = 55
    Height = 21
    TabOrder = 4
    Text = '0'
  end
  object rojoInferior: TEdit
    Left = 386
    Top = 34
    Width = 55
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object verdeInferior: TEdit
    Left = 386
    Top = 202
    Width = 55
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object verdeSuperior: TEdit
    Left = 386
    Top = 229
    Width = 55
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object azulSuperior: TEdit
    Left = 391
    Top = 397
    Width = 55
    Height = 21
    TabOrder = 8
    Text = '0'
  end
  object azulInferior: TEdit
    Left = 391
    Top = 370
    Width = 55
    Height = 21
    TabOrder = 9
    Text = '0'
  end
  object valRest: TEdit
    Left = 391
    Top = 469
    Width = 55
    Height = 21
    TabOrder = 10
    Text = '0'
  end
  object Button1: TButton
    Left = 360
    Top = 525
    Width = 86
    Height = 25
    Caption = 'Deshacer'
    TabOrder = 11
    OnClick = Button1Click
  end
end
