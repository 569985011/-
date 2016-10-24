Public Class Form1

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Label1.Text = "输入文本"
        Label2.Text = "复制效果"
        Button3.Text = "复制 =>"
        Button1.Text = "隶书 25磅"
        Button2.Text = "幼圆 15磅"

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        TextBox1.Font = New Font("隶书", 25)
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        TextBox1.Font = New Font("幼圆", 15)
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        TextBox2.Text = TextBox1.SelectedText
        TextBox2.Font = TextBox1.Font
    End Sub
End Class
