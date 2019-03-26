<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Progress.aspx.cs" Inherits="Progress" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:GridView ID="getHistory" runat="server" OnSelectedIndexChanged="GridView1_SelectedIndexChanged">
            </asp:GridView>
        </div>
        <asp:Button ID="Button1" runat="server" OnClick="GetProgressReport" Text="GetReport" />
    </form>
</body>
</html>
