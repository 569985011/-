Public Class Form1

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Label1.Text = "输入字符串"
        Label2.Text = "结果"
        Button1.Text = "Len"
        Button2.Text = "Chr"
        Button3.Text = "LCase"
        Button4.Text = "StrDup"
        Button5.Text = "InStr"
        Button6.Text = "Mid"
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        TextBox2.Text = Len(TextBox1.Text)
        Label2.Text = Button1.Text & "函数的结果"
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        TextBox2.Text = Chr(TextBox1.Text)
        Label2.Text = Button2.Text & "函数的结果"
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Label2.Text = Button3.Text & "函数的结果"
        TextBox2.Text = LCase(TextBox1.Text)
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Label2.Text = Button4.Text & "函数的结果"
        Dim a As Integer
        a = InputBox("输入重复次数", , 3, , )
        TextBox2.Text = StrDup(a, TextBox1.Text)
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Label2.Text = Button5.Text & "函数的结果"
        Dim s1$
        s1 = InputBox("请输入查找子串s1")
        TextBox2.Text = InStr(TextBox1.Text, s1)
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        Label2.Text = Button6.Text & "函数的结果"
        Dim a As Integer

        a = InputBox("输入开始位置", , 1, , )

        TextBox2.Text = Mid(TextBox1.Text, a)
    End Sub
End Class
