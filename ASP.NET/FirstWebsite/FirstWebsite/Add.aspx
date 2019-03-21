<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Add.aspx.cs" Inherits="Add" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr>
                    <td><asp:Label id="lblNum1" runat="server" Text="Number1"></asp:Label></td>
                    <td><asp:TextBox ID="txtNum1" runat="server"></asp:TextBox></td>
                </tr>
                <tr>
                    <td><asp:Label ID="lblNum3" runat="server" Text="Number3"></asp:Label></td>
                    <td><asp:TextBox ID="txtNum2" runat="server"></asp:TextBox></td>
                </tr>
                <tr>
                    <td><asp:Button ID="btnAdd" runat="server" Text="Add" OnClick="btnAdd_Click" /></td>
                    <td><asp:Label ID="lblRes" runat="server"></asp:Label></td>

                </tr>
                
            </table>
        </div>
    </form>
</body>
</html>
