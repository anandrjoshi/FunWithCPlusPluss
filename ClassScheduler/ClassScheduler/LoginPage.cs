using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;


namespace ClassScheduler
{
    public partial class LoginPage : Form
    {
        public LoginPage()
        {
            InitializeComponent();
        }

        private void LoginBtn_Click(object sender, EventArgs e)
        {
             SqlConnection connect = new SqlConnection(
                "Data source = (local); Initial Catalog = Student DB; Integrated Security = True");

                  SqlDataReader rdr = null;

            try
            {
                // 2. Open the connection
                connect.Open();

                //int error = 0;

                string userName = "";
                string password = "";

                // 3. Pass the connection to a command object
                if( UserNameText.TextLength != 0)
                    userName = UserNameText.Text;


                if( PasswordText.TextLength != 0)
                    password = PasswordText.Text;
                    
                SqlCommand cmd = new SqlCommand("select * from loginInfo where id = '" + userName + "' and studentPwd = '" + password + "'" , connect);

                rdr = cmd.ExecuteReader();

                if (!rdr.HasRows)
                {
                    MessageBox.Show("Invalid UserName or Password.");
                }
                else
                {
                    while (rdr.Read())
                    {
                        // Console.WriteLine(rdr[0]);
                        // Console.WriteLine(rdr[1]);
                        StudentInfo stud = new StudentInfo(rdr[0].ToString());
                        stud.Show();
                    }
                }
            }
            finally
            {
                // close the reader
                if (rdr != null)
                {
                    rdr.Close();
                }

                // 5. Close the connection
                if (connect != null)
                {
                    connect.Close();
                }
            }
        }
    }
}
