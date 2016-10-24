Public Class Form1
    '我没见过老师所说的那个示例（没有教材），所以没有讲到的细节方面都是自由发挥的，请见谅
    '当label1右端移除窗体，我希望的效果时在窗体左端进入，类似于多年前理发店门前的那个旋转彩柱
    '实现方法就是再造一个孪生label2,拉开距离，搭配使用

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Label1.Text = "欢迎使用VB.NET"
        Label2.Text = "欢迎使用VB.NET"
        Me.Text = "引例"
        Button1.Text = "自动"
        Button2.Text = "手动"
        Button1.TextAlign = ContentAlignment.MiddleLeft
        Button1.ImageAlign = ContentAlignment.MiddleRight
        Button2.TextAlign = ContentAlignment.MiddleLeft
        Button2.ImageAlign = ContentAlignment.MiddleRight
        Timer1.Interval = 200
    End Sub
    Private Sub MoveLabel1()
        Label1.Left += 20
        Label2.Left += 20
        If (Label1.Left > Me.Width) Then
            Label1.Left = 0 - Me.Width
        End If
        If (Label2.Left > Me.Width) Then
            Label2.Left = 0 - Me.Width
        End If
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        MoveLabel1()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If (Timer1.Enabled = False) Then
            Timer1.Start()
            Button1.Text = "暂停"
        Else
            Timer1.Stop()
            Button1.Text = "继续"
        End If

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        MoveLabel1()
        If (Timer1.Enabled = True) Then
            Timer1.Stop()
            Button1.Text = "继续"
        End If
    End Sub
End Class
