import wx

# The right-most panel of the GUI. It contains the colored rectangle
# diaplaying the resulting color. It can be clicked and the color
# can be changed
class ResultPanel(wx.Panel):
    def __init__(self, parent, id):            
        wx.Panel.__init__(self, parent, id)
        self.SetBackgroundColour("white")
                
        self.rectColor = wx.Colour(51, 51, 51, 0)
        
        self.rectSize = 100
        self.rectX = 150 / 2 - self.rectSize / 2
        self.rectY = 680 / 2 - self.rectSize / 2        
        
        self.id = wx.NewId()
        
        self.pdc = wx.PseudoDC()
        self.pen_cache = {}
        self.brush_cache = {}
                
        self.drawResult()                

    def drawResult(self):
        self.pdc.Clear()
        self.pdc.BeginDrawing()
        
        self.pdc.ClearId(self.id)
        self.pdc.RemoveId(self.id)
        self.pdc.SetId(self.id)
        
        pen = wx.Pen("black",style=wx.SOLID, width=5)
        self.pdc.SetPen(pen)
        self.pdc.SetBrush(wx.Brush(self.rectColor, wx.SOLID))
                
        self.pdc.DrawRectangle(self.rectX, self.rectY, self.rectSize, self.rectSize)
        
        r = wx.Rect(self.rectX, self.rectY, self.rectSize, self.rectSize)
        r.Inflate(pen.GetWidth(),pen.GetWidth())
        self.pdc.SetIdBounds(self.id,r)
        
        self.pdc.EndDrawing()            

    def OnPaintResult(self, evt):
        evt.Skip()
        
    def OnMouse(self, event):        
        event.Skip()