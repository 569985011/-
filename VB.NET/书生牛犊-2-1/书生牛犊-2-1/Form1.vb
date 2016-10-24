Public Class Form1

    Private Sub Form1_Click(sender As Object, e As EventArgs) Handles Me.Click
        Me.Text = "单击窗体"
        Me.Size = New Size(264 + 15, 256 + 30)
        Me.BackgroundImage = Image.FromFile(Application.StartupPath & "\Resources\Tongji-2.bmp")
    End Sub

    Private Sub Form1_DoubleClick(sender As Object, e As EventArgs) Handles Me.DoubleClick
        Me.Text = "双击窗体"
        Me.MinimizeBox = False
        Me.MaximizeBox = False
        Me.Cursor = Cursors.Default
        Me.BackgroundImage = Nothing
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.Text = "装入窗体"
        Me.Icon = New Icon(Application.StartupPath & "\Resources\MISC34.ICO")
        Me.Cursor = New Cursor(Application.StartupPath & "\Resources\KEY04.ICO")
        Me.BackgroundImage = Image.FromFile(Application.StartupPath & "\Resources\tongji0.bmp")
    End Sub


    
End Class
