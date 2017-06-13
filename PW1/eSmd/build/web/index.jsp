<%-- 
    Document   : index
    Created on : 03/06/2017, 23:17:33
    Author     : tiago
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head lang="pt-br">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>eSmd</title>
        <link rel="stylesheet" type="text/css" href="CSS/eSmd.css"/>
    </head>
    <body>
       <div id="interface"> 
        <header>
            <hgroup>
                <h1>Games e-SMD</h1>
                <h2>Entre você também para os Sem Medo de Derrota</h2>
                <h3>Com o melhor preço do mercado</h3>
            </hgroup>
            <%--<img src="IMG/carrinho.png" alt="carrinho de compras"/>--%>
            <nav id="menu-principal">
                <ul>
                    <li><a href="login.jsp">Entre</a></li>
                    <li><a href="cadastro.jsp">Inscreva-se</a></li>
                    <li><a href="#">Promoções</a></li>
                    <li><a href="#">Meus Pedidos</a></li>
                    <li><a href="#">Carrinho</a></li>
                </ul>
            </nav>
        </header>
        <aside>
            <nav id="menu-categoria">
                <ul>
                    <li><a href="#">Ação</a></li>
                    <li><a href="#">Aventura</a></li>
                    <li><a href="#">Esporte</a></li>
                    <li><a href="#">Corrida</a></li>
                    <li><a href="#">Guerra</a></li>
                    <li><a href="#">Plataforma</a></li>
                    <li><a href="#">Estratégia</a></li>
                    <li><a href="#">Luta</a></li>
                </ul>
            </nav>
        </aside>
        <section>
            <ul id="categoria">
                <li id="categoria01"><span>Ação<span></li>
                <li id="categoria02"><span>Aventura<span></li>
                <li id="categoria03"><span>Esporte</span></li>
                <li id="categoria04"><span>Corrida</span></li>
                <li id="categoria05"><span>Guerra</span></li>
                <li id="categoria06"><span>Plataforma</span></li>
                <li id="categoria07"><span>Estratégia</span></li>
                <li id="categoria08"><span>Luta</span></li>
            </ul>
        </section>
        <footer>
            <p>Copyright 2017 &copy - <a href="https://www.facebook.com/tiago.fontenele.5" target="_blank">Tiago Fontenele</a></p><br/>
        </footer>
       </div>    
    </body>
</html>
