using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

public partial class Register : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void submit_btn_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-QV8ND1O;Initial Catalog=NCRDB;Integrated Security=True");
        con.Open();
        string command = "sp_student_registerForm";
        SqlCommand cmd = new SqlCommand(command, con);

        SqlParameter paramStudentId = new SqlParameter("@Sid", student_id.Text);
        cmd.Parameters.Add(paramStudentId);
        SqlParameter paramStudentName = new SqlParameter("@Sname", student_name.Text);
        cmd.Parameters.Add(paramStudentName);
        SqlParameter paramPhone = new SqlParameter("@Phone", phone_no.Text);
        cmd.Parameters.Add(paramPhone);
        SqlParameter paramEmail = new SqlParameter("@Email", email_id.Text);
        cmd.Parameters.Add(paramEmail);
        SqlParameter paramAddress = new SqlParameter("@Address", address.Text);
        cmd.Parameters.Add(paramAddress);

        cmd.CommandType = CommandType.StoredProcedure;
        cmd.ExecuteNonQuery();
        con.Close();

    }

    protected void reset_btn_Click(object sender, EventArgs e)
    {
        student_id.Text = "";
        student_name.Text = "";
        phone_no.Text = "";
        email_id.Text = "";
        address.Text = "";
    }
}