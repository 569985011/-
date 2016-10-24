Public Class Form1

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Button1.Text = "产生"
        Button2.Text = "逆序"

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim a As Integer
        a = Format(Rnd() * 1000, "0")
        If (a < 100) Then
            a *= 10
        End If
        TextBox1.Text = a
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim a As Integer
        a = Val(TextBox1.Text)
        TextBox2.Text = ((a Mod 10) * 100) + (a \ 10 Mod 10) * 10 + (a \ 100)
    End Sub
End Class
