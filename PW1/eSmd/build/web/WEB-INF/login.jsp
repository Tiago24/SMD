<%-- 
    Document   : login
    Created on : 06/06/2017, 21:49:57
    Author     : tiago
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>eSmd</title>
        <link rel="stylesheet" type="text/css" href="CSS/login.css">
    </head>
    <body>
        <table id="acesso">
            <tr><th colspan="2">e-Smd</th></tr>
            <form method="post" action="loginServlet">
                <tr><td><label for="login">Login</label></td> <td><input type="text" id="login" name="login" placeholder="Digite seu login" size="13" length="20"></td></tr></br>
                <tr><td><label for="senha">Senha</label></td> <td><input type="password" id="senha" name="senha" placeholder="Digite sua senha" size="13" length="20"></td></tr></br>
                <tr><td colspan="2"><input type="submit" value="Entrar"></td> <td></td></tr>
            </form>
        </table>
    </body>
</html>
