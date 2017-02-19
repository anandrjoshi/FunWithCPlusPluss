<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Example
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Current_Str = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Prev_Str = New System.Windows.Forms.Label()
        Me.Count_Int_Prev_Str = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'Current_Str
        '
        Me.Current_Str.Location = New System.Drawing.Point(98, 35)
        Me.Current_Str.Name = "Current_Str"
        Me.Current_Str.Size = New System.Drawing.Size(188, 20)
        Me.Current_Str.TabIndex = 0
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 35)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(62, 13)
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "Enter String"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(15, 109)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(106, 27)
        Me.Button1.TabIndex = 2
        Me.Button1.Text = "Check for Integers"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(12, 70)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(78, 13)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Previous String"
        '
        'Prev_Str
        '
        Me.Prev_Str.AutoSize = True
        Me.Prev_Str.Location = New System.Drawing.Point(103, 71)
        Me.Prev_Str.Name = "Prev_Str"
        Me.Prev_Str.Size = New System.Drawing.Size(0, 13)
        Me.Prev_Str.TabIndex = 4
        '
        'Count_Int_Prev_Str
        '
        Me.Count_Int_Prev_Str.AutoSize = True
        Me.Count_Int_Prev_Str.Location = New System.Drawing.Point(135, 110)
        Me.Count_Int_Prev_Str.Name = "Count_Int_Prev_Str"
        Me.Count_Int_Prev_Str.Size = New System.Drawing.Size(151, 13)
        Me.Count_Int_Prev_Str.TabIndex = 5
        Me.Count_Int_Prev_Str.Text = "Previous String had 0 integers."
        '
        'Example
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(300, 148)
        Me.Controls.Add(Me.Count_Int_Prev_Str)
        Me.Controls.Add(Me.Prev_Str)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Current_Str)
        Me.Name = "Example"
        Me.Text = "Check Integers"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Current_Str As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Prev_Str As System.Windows.Forms.Label
    Friend WithEvents Count_Int_Prev_Str As System.Windows.Forms.Label

End Class
