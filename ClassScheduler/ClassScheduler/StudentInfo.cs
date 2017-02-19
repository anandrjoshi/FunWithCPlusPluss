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
    public partial class StudentInfo : Form
    {
        public StudentInfo()
        {
            InitializeComponent();
        }

        public StudentInfo(string userID)
        {
            InitializeComponent();

            SqlConnection connect = new SqlConnection(
               "Data source = (local); Initial Catalog = Student DB; Integrated Security = True");

            SqlDataReader rdr = null;
            SqlDataAdapter adp = null;

            try
            {
                // 2. Open the connection
                connect.Open();

                SqlCommand cmd = new SqlCommand("select * from userInfo where id = '" + userID + "'", connect);
                SqlCommand cmd1 = new SqlCommand("select * from registration where id = '" + userID + "'", connect);

                rdr = cmd.ExecuteReader();

                while (rdr.Read())
                {
                    Console.WriteLine(rdr[0]);
                    UserID.Text = userID;
                    UserName.Text = rdr[1].ToString();
                    Address.Text = rdr[2].ToString();
                    PhoneNo.Text = rdr[3].ToString();
                    EmailID.Text = rdr[4].ToString();
                }

                rdr.Close();

                adp = new SqlDataAdapter(cmd1);
                DataSet ds = new DataSet();
                adp.Fill(ds);

                ClassSchedule.DataSource = ds.Tables[0];
         
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

        private void StudentInfo_Load(object sender, EventArgs e)
        {

        }
    }
}
