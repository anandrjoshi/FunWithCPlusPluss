Public Class Example

    Private Sub Label1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label1.Click

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If (Current_Str.Text.Length = 0) Then
            MsgBox("No Text entered in text box", MsgBoxStyle.Critical)

        Else

            Dim numOfIntergers As Integer
            Dim intCount As Integer
            Dim charStr As Char() = Current_Str.Text.ToCharArray()

            For intCount = 0 To (charStr.Length - 1)
                If (charStr(intCount) = "1") Or
                    (charStr(intCount) = "2") Or
                    (charStr(intCount) = "3") Or
                    (charStr(intCount) = "4") Or
                    (charStr(intCount) = "5") Or
                    (charStr(intCount) = "6") Or
                    (charStr(intCount) = "7") Or
                    (charStr(intCount) = "8") Or
                    (charStr(intCount) = "9") Or
                    (charStr(intCount) = "0") Then
                    
                    numOfIntergers = numOfIntergers + 1
                End If
            Next

            Prev_Str.Text = Current_Str.Text
            Current_Str.Text = ""
            Count_Int_Prev_Str.Text = " Previous String Had " & numOfIntergers.ToString & " Integers."

        End If

    End Sub
End Class
