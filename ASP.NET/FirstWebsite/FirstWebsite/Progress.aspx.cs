using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class Progress : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }

    protected void GetProgressReport(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-QV8ND1O;Initial Catalog=NCRDB;Integrated Security=True");
        con.Open();
        string command = "gethistory";
        SqlCommand cmd = new SqlCommand(command, con);
        cmd.CommandType = CommandType.StoredProcedure;
        SqlDataReader dr = cmd.ExecuteReader();
       
        getHistory.DataSource = dr;
        getHistory.DataBind();
        con.Close();

    }
}