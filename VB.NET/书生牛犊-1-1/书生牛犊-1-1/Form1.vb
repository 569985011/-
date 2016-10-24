Public Class Form1

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Label1.AutoSize = False
        Label2.Text = "请输入你的姓名"
        Label3.AutoSize = False
        Label3.BorderStyle = BorderStyle.Fixed3D
        Label3.Text = ""
        Label3.Width = 100
        Label3.Height = 21

    End Sub

   
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Label3.Text = TextBox1.Text
    End Sub
End Class
