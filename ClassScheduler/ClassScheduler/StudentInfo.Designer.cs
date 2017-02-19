namespace ClassScheduler
{
    partial class StudentInfo
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.UserID = new System.Windows.Forms.TextBox();
            this.UserName = new System.Windows.Forms.TextBox();
            this.EmailID = new System.Windows.Forms.TextBox();
            this.PhoneNo = new System.Windows.Forms.TextBox();
            this.Address = new System.Windows.Forms.TextBox();
            this.ClassSchedule = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.ClassSchedule)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(43, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "User ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(25, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Address";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 47);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(35, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Name";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(25, 130);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(46, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Email ID";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(25, 100);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(58, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Phone No.";
            // 
            // UserID
            // 
            this.UserID.ForeColor = System.Drawing.SystemColors.MenuBar;
            this.UserID.Location = new System.Drawing.Point(101, 17);
            this.UserID.Name = "UserID";
            this.UserID.ReadOnly = true;
            this.UserID.Size = new System.Drawing.Size(86, 20);
            this.UserID.TabIndex = 5;
            // 
            // UserName
            // 
            this.UserName.Location = new System.Drawing.Point(101, 40);
            this.UserName.Name = "UserName";
            this.UserName.ReadOnly = true;
            this.UserName.Size = new System.Drawing.Size(86, 20);
            this.UserName.TabIndex = 6;
            // 
            // EmailID
            // 
            this.EmailID.Location = new System.Drawing.Point(101, 127);
            this.EmailID.Name = "EmailID";
            this.EmailID.ReadOnly = true;
            this.EmailID.Size = new System.Drawing.Size(86, 20);
            this.EmailID.TabIndex = 7;
            // 
            // PhoneNo
            // 
            this.PhoneNo.Location = new System.Drawing.Point(101, 100);
            this.PhoneNo.Name = "PhoneNo";
            this.PhoneNo.ReadOnly = true;
            this.PhoneNo.Size = new System.Drawing.Size(86, 20);
            this.PhoneNo.TabIndex = 8;
            // 
            // Address
            // 
            this.Address.Location = new System.Drawing.Point(101, 66);
            this.Address.Name = "Address";
            this.Address.ReadOnly = true;
            this.Address.Size = new System.Drawing.Size(195, 20);
            this.Address.TabIndex = 9;
            // 
            // ClassSchedule
            // 
            this.ClassSchedule.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ClassSchedule.Location = new System.Drawing.Point(28, 155);
            this.ClassSchedule.Name = "ClassSchedule";
            this.ClassSchedule.ReadOnly = true;
            this.ClassSchedule.Size = new System.Drawing.Size(325, 150);
            this.ClassSchedule.TabIndex = 10;
            // 
            // StudentInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(374, 317);
            this.Controls.Add(this.ClassSchedule);
            this.Controls.Add(this.Address);
            this.Controls.Add(this.PhoneNo);
            this.Controls.Add(this.EmailID);
            this.Controls.Add(this.UserName);
            this.Controls.Add(this.UserID);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "StudentInfo";
            this.Text = "StudentInfo";
            this.Load += new System.EventHandler(this.StudentInfo_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ClassSchedule)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox UserID;
        private System.Windows.Forms.TextBox UserName;
        private System.Windows.Forms.TextBox EmailID;
        private System.Windows.Forms.TextBox PhoneNo;
        private System.Windows.Forms.TextBox Address;
        private System.Windows.Forms.DataGridView ClassSchedule;
    }
}