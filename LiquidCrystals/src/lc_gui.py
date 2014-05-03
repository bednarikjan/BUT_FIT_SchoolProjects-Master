# -*- coding: utf-8 -*- 

###########################################################################
## Python code generated with wxFormBuilder (version Feb 26 2014)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import wx
import wx.xrc
import result_panel

###########################################################################
## Class MainFrame
###########################################################################

class MainFrame ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Liquid Crystals", pos = wx.DefaultPosition, size = wx.Size( 950,700 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.Size( 900,700 ), wx.Size( 1000,700 ) )
		
		sizerMain = wx.BoxSizer( wx.HORIZONTAL )
		
		sizerControlsAndVisu = wx.BoxSizer( wx.VERTICAL )
		
		sizerRed = wx.BoxSizer( wx.HORIZONTAL )
		
		sizerControlsRed = wx.BoxSizer( wx.VERTICAL )
		
		self.staticTextRed = wx.StaticText( self, wx.ID_ANY, u"Red", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticTextRed.Wrap( -1 )
		sizerControlsRed.Add( self.staticTextRed, 0, wx.ALL, 5 )
		
		bSizer12 = wx.BoxSizer( wx.VERTICAL )
		
		fgSizer6 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer6.SetFlexibleDirection( wx.BOTH )
		fgSizer6.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText7 = wx.StaticText( self, wx.ID_ANY, u"Intensity", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText7.Wrap( -1 )
		fgSizer6.Add( self.m_staticText7, 0, wx.ALL, 5 )
		
		self.m_staticText6 = wx.StaticText( self, wx.ID_ANY, u"", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText6.Wrap( -1 )
		fgSizer6.Add( self.m_staticText6, 0, wx.ALL, 5 )
		
		self.sliderValueRed = wx.Slider( self, wx.ID_ANY, 60, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		fgSizer6.Add( self.sliderValueRed, 0, wx.ALL, 5 )
		
		self.textValueRed = wx.TextCtrl( self, wx.ID_ANY, u"0.6", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		fgSizer6.Add( self.textValueRed, 0, wx.ALL, 5 )
		
		
		bSizer12.Add( fgSizer6, 1, wx.EXPAND, 5 )
		
		fgSizer7 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer7.SetFlexibleDirection( wx.BOTH )
		fgSizer7.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText8 = wx.StaticText( self, wx.ID_ANY, u"Voltage", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText8.Wrap( -1 )
		fgSizer7.Add( self.m_staticText8, 0, wx.ALL, 5 )
		
		self.m_staticText9 = wx.StaticText( self, wx.ID_ANY, u"[V]", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText9.Wrap( -1 )
		fgSizer7.Add( self.m_staticText9, 0, wx.ALL, 5 )
		
		self.sliderVoltageRed = wx.Slider( self, wx.ID_ANY, 40, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		fgSizer7.Add( self.sliderVoltageRed, 0, wx.ALL, 5 )
		
		self.textVoltageRed = wx.TextCtrl( self, wx.ID_ANY, u"0.4", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		fgSizer7.Add( self.textVoltageRed, 0, wx.ALL, 5 )
		
		
		bSizer12.Add( fgSizer7, 1, wx.EXPAND, 5 )
		
		
		sizerControlsRed.Add( bSizer12, 1, wx.EXPAND, 5 )
		
		
		sizerRed.Add( sizerControlsRed, 0, wx.EXPAND, 5 )
		
		self.m_staticline3 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_VERTICAL )
		sizerRed.Add( self.m_staticline3, 0, wx.EXPAND |wx.ALL, 5 )
		
		self.panelLayersRed = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		self.panelLayersRed.SetMinSize( wx.Size( 300,200 ) )
		
		sizerRed.Add( self.panelLayersRed, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.m_staticline4112 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_VERTICAL )
		sizerRed.Add( self.m_staticline4112, 0, wx.EXPAND |wx.ALL, 5 )
		
		
		sizerControlsAndVisu.Add( sizerRed, 1, wx.EXPAND, 5 )
		
		self.m_staticline1 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_HORIZONTAL )
		sizerControlsAndVisu.Add( self.m_staticline1, 0, wx.EXPAND |wx.ALL, 5 )
		
		sizerGreen = wx.BoxSizer( wx.HORIZONTAL )
		
		sizerControlsGreen = wx.BoxSizer( wx.VERTICAL )
		
		self.staticTextGreen = wx.StaticText( self, wx.ID_ANY, u"Green", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticTextGreen.Wrap( -1 )
		sizerControlsGreen.Add( self.staticTextGreen, 0, wx.ALL, 5 )
		
		fgSizer8 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer8.SetFlexibleDirection( wx.BOTH )
		fgSizer8.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText10 = wx.StaticText( self, wx.ID_ANY, u"Intensity", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText10.Wrap( -1 )
		fgSizer8.Add( self.m_staticText10, 0, wx.ALL, 5 )
		
		self.m_staticText11 = wx.StaticText( self, wx.ID_ANY, u"", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText11.Wrap( -1 )
		fgSizer8.Add( self.m_staticText11, 0, wx.ALL, 5 )
		
		self.sliderValueGreen = wx.Slider( self, wx.ID_ANY, 60, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		fgSizer8.Add( self.sliderValueGreen, 0, wx.ALL, 5 )
		
		self.textValueGreen = wx.TextCtrl( self, wx.ID_ANY, u"0.6", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		fgSizer8.Add( self.textValueGreen, 0, wx.ALL, 5 )
		
		
		sizerControlsGreen.Add( fgSizer8, 1, wx.EXPAND, 5 )
		
		fgSizer9 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer9.SetFlexibleDirection( wx.BOTH )
		fgSizer9.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText12 = wx.StaticText( self, wx.ID_ANY, u"Voltage", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText12.Wrap( -1 )
		fgSizer9.Add( self.m_staticText12, 0, wx.ALL, 5 )
		
		self.m_staticText13 = wx.StaticText( self, wx.ID_ANY, u"[V]", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText13.Wrap( -1 )
		fgSizer9.Add( self.m_staticText13, 0, wx.ALL, 5 )
		
		self.sliderVoltageGreen = wx.Slider( self, wx.ID_ANY, 40, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		fgSizer9.Add( self.sliderVoltageGreen, 0, wx.ALL, 5 )
		
		self.textVoltageGreen = wx.TextCtrl( self, wx.ID_ANY, u"0.4", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		fgSizer9.Add( self.textVoltageGreen, 0, wx.ALL, 5 )
		
		
		sizerControlsGreen.Add( fgSizer9, 1, wx.EXPAND, 5 )
		
		
		sizerGreen.Add( sizerControlsGreen, 0, wx.EXPAND, 5 )
		
		self.m_staticline4 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_VERTICAL )
		sizerGreen.Add( self.m_staticline4, 0, wx.EXPAND |wx.ALL, 5 )
		
		self.panelLayersGreen = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		self.panelLayersGreen.SetMinSize( wx.Size( 300,200 ) )
		
		sizerGreen.Add( self.panelLayersGreen, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_staticline4111 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_VERTICAL )
		sizerGreen.Add( self.m_staticline4111, 0, wx.EXPAND |wx.ALL, 5 )
		
		
		sizerControlsAndVisu.Add( sizerGreen, 1, wx.EXPAND, 5 )
		
		self.m_staticline2 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_HORIZONTAL )
		sizerControlsAndVisu.Add( self.m_staticline2, 0, wx.EXPAND |wx.ALL, 5 )
		
		sizerBlue = wx.BoxSizer( wx.HORIZONTAL )
		
		sizerControlsBlue = wx.BoxSizer( wx.VERTICAL )
		
		self.staticTextBlue = wx.StaticText( self, wx.ID_ANY, u"Blue", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticTextBlue.Wrap( -1 )
		sizerControlsBlue.Add( self.staticTextBlue, 0, wx.ALL, 5 )
		
		sizerSlidersTextBlue = wx.FlexGridSizer( 2, 2, 0, 0 )
		sizerSlidersTextBlue.SetFlexibleDirection( wx.BOTH )
		sizerSlidersTextBlue.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		
		sizerControlsBlue.Add( sizerSlidersTextBlue, 1, wx.EXPAND, 5 )
		
		fgSizer10 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer10.SetFlexibleDirection( wx.BOTH )
		fgSizer10.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText14 = wx.StaticText( self, wx.ID_ANY, u"Intensity", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText14.Wrap( -1 )
		fgSizer10.Add( self.m_staticText14, 0, wx.ALL, 5 )
		
		self.m_staticText15 = wx.StaticText( self, wx.ID_ANY, u"", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText15.Wrap( -1 )
		fgSizer10.Add( self.m_staticText15, 0, wx.ALL, 5 )
		
		self.sliderValueBlue = wx.Slider( self, wx.ID_ANY, 60, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		fgSizer10.Add( self.sliderValueBlue, 0, wx.ALL, 5 )
		
		self.textValueBlue = wx.TextCtrl( self, wx.ID_ANY, u"0.6", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		fgSizer10.Add( self.textValueBlue, 0, wx.ALL, 5 )
		
		
		sizerControlsBlue.Add( fgSizer10, 1, wx.EXPAND, 5 )
		
		fgSizer11 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer11.SetFlexibleDirection( wx.BOTH )
		fgSizer11.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText16 = wx.StaticText( self, wx.ID_ANY, u"Voltage", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText16.Wrap( -1 )
		fgSizer11.Add( self.m_staticText16, 0, wx.ALL, 5 )
		
		self.m_staticText17 = wx.StaticText( self, wx.ID_ANY, u"[V]", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText17.Wrap( -1 )
		fgSizer11.Add( self.m_staticText17, 0, wx.ALL, 5 )
		
		self.sliderVoltageBlue = wx.Slider( self, wx.ID_ANY, 40, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.SL_HORIZONTAL )
		fgSizer11.Add( self.sliderVoltageBlue, 0, wx.ALL, 5 )
		
		self.textVoltageBlue = wx.TextCtrl( self, wx.ID_ANY, u"0.4", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		fgSizer11.Add( self.textVoltageBlue, 0, wx.ALL, 5 )
		
		
		sizerControlsBlue.Add( fgSizer11, 1, wx.EXPAND, 5 )
		
		
		sizerBlue.Add( sizerControlsBlue, 0, wx.EXPAND, 5 )
		
		self.m_staticline41 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_VERTICAL )
		sizerBlue.Add( self.m_staticline41, 0, wx.EXPAND |wx.ALL, 5 )
		
		self.panelLayersBlue = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		self.panelLayersBlue.SetMinSize( wx.Size( 300,200 ) )
		
		sizerBlue.Add( self.panelLayersBlue, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_staticline411 = wx.StaticLine( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LI_VERTICAL )
		sizerBlue.Add( self.m_staticline411, 0, wx.EXPAND |wx.ALL, 5 )
		
		
		sizerControlsAndVisu.Add( sizerBlue, 1, wx.EXPAND, 5 )
		
		
		sizerMain.Add( sizerControlsAndVisu, 5, wx.EXPAND, 5 )
		
# 		self.panelResultColors = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		self.panelResultColors = result_panel.ResultPanel(self, -1)
# 		self.panelResultColors.SetMinSize( wx.Size( 150,-1 ) )
# 		self.panelResultColors.SetMaxSize( wx.Size( 200,-1 ) )
		self.panelResultColors.SetSize( wx.Size( 200,-1 ) )
		
		sizerMain.Add( self.panelResultColors, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		self.SetSizer( sizerMain )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.sliderValueRed.Bind( wx.EVT_SCROLL, self.sliderValueRedChanged )
		self.textValueRed.Bind( wx.EVT_TEXT_ENTER, self.textValueRedChanged )
		self.sliderVoltageRed.Bind( wx.EVT_SCROLL, self.sliderVoltageRedChanged )
		self.textVoltageRed.Bind( wx.EVT_TEXT_ENTER, self.textVoltageRedChanged )
		self.sliderValueGreen.Bind( wx.EVT_SCROLL, self.sliderValueGreenChanged )
		self.textValueGreen.Bind( wx.EVT_TEXT_ENTER, self.textValueGreenChanged )
		self.sliderVoltageGreen.Bind( wx.EVT_SCROLL, self.sliderVoltageGreenChanged )
		self.textVoltageGreen.Bind( wx.EVT_TEXT_ENTER, self.textVoltageGreenChanged )
		self.sliderValueBlue.Bind( wx.EVT_SCROLL, self.sliderValueBlueChanged )
		self.textValueBlue.Bind( wx.EVT_TEXT_ENTER, self.textValueBlueChanged )
		self.sliderVoltageBlue.Bind( wx.EVT_SCROLL, self.sliderVoltageBlueChanged )
		self.textVoltageBlue.Bind( wx.EVT_TEXT_ENTER, self.textVoltageBlueChanged )
		self.panelResultColors.Bind(wx.EVT_PAINT, self.OnPaintResult)
		self.panelResultColors.Bind(wx.EVT_MOUSE_EVENTS, self.OnMouse)		
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def sliderValueRedChanged( self, event ):
		event.Skip()
	
	def textValueRedChanged( self, event ):
		event.Skip()
	
	def sliderVoltageRedChanged( self, event ):
		event.Skip()
	
	def textVoltageRedChanged( self, event ):
		event.Skip()
	
	def sliderValueGreenChanged( self, event ):
		event.Skip()
	
	def textValueGreenChanged( self, event ):
		event.Skip()
	
	def sliderVoltageGreenChanged( self, event ):
		event.Skip()
	
	def textVoltageGreenChanged( self, event ):
		event.Skip()
	
	def sliderValueBlueChanged( self, event ):
		event.Skip()
	
	def textValueBlueChanged( self, event ):
		event.Skip()
	
	def sliderVoltageBlueChanged( self, event ):
		event.Skip()
	
	def textVoltageBlueChanged( self, event ):
		event.Skip()
		
	def OnPaintResult(self, evt):
		evt.Skip()
		
	def OnMouse(self, event):
		event.Skip()
	

