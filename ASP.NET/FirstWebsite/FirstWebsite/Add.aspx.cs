using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class Add : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void btnAdd_Click(object sender, EventArgs e)
    {
        int a, b, c;
        a = int.Parse(txtNum1.Text);
        b = int.Parse(txtNum2.Text);
        c = addFunction(a, b);
        lblRes.Text = c.ToString();

        //Database 
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-QV8ND1O;Initial Catalog=NCRDB;Integrated Security=True");
        con.Open();
       // string command = "INSERT INTO Addition values(30,50,80)";
        string command = "sp_insertmath";
        SqlCommand cmd = new SqlCommand(command, con);

        SqlParameter paramNum1 = new SqlParameter("@Num1", txtNum1.Text);
        cmd.Parameters.Add(paramNum1);
        SqlParameter paramNum2 = new SqlParameter("@Num2", txtNum2.Text);
        cmd.Parameters.Add(paramNum2);
        SqlParameter result = new SqlParameter("@res", lblRes.Text);
        cmd.Parameters.Add(result);

        cmd.CommandType = CommandType.StoredProcedure;
        cmd.ExecuteNonQuery();
        con.Close();
        
    }
    private int addFunction(int i,int j)
    {
        return i + j;
    }
}