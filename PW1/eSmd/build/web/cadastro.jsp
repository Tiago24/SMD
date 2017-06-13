<%-- 
    Document   : cadastro
    Created on : 06/06/2017, 21:51:26
    Author     : tiago
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>eSmd</title>
        <link rel="stylesheet" type="text/css" href="CSS/cadastro.css"/>
    </head>
    <body>
        <div id="interface">
            <form method="post" action="ServletDao">
                <span id="logo">e-Smd</span>
                <fieldset class="setCampo">
                    <table>
                        <legend>Dados Pessoais</legend>
                        <tr><td><label for="nome">Nome</label></td> <td><input type="text" name="nome" id="nome" placeholder="Digite seu nome completo" required=""/></td></tr></br>
                        <tr><td><label for="email">E-mail</label></td> <td><input type="email" name="email" id="email" placeholder="Digite seu email principal" required=""/></td></tr></br>
                        <tr><td><label for="celular">Celular</label></td> <td><input type="tel" name="celular" id="celular" placeholder="Digite seu número para contato" required=""/></td></tr><br/>
                    </table>
                </fieldset>
                </br>
                <fieldset class="setCampo">
                    <table>
                        <legend>Endereço de entrega</legend>
                        <tr><td><label for="cep">CEP</label></td> <td><input type="number" name="cep" id="cep" placeholder="Digite seu CEP"/></td></tr></br>
                        <tr><td><label for="endereco">Endereço</label></td> <td><input type="text" name="endereco" id="endereco" placeholder="Digite nome da rua, avenida..." required=""/></td></tr></br>
                        <tr><td><label for="cidade">Cidade</label></td> <td><input type="text" name="cidade" id="cidade" placeholder="Digite nome da cidade" required=""/></td></tr><br/>
                    </table>
                </fieldset>
                </br>
                <fieldset class="setCampo">
                     <table>
                        <legend>Acesso no e-Smd</legend>
                        <tr><td><label for="login">login</label></td> <td><input type="text" name="login" id="login" placeholder="Digite seu login de acesso" required=""/></td></tr></br>
                        <tr><td><label for="senha">Senha</label></td> <td><input type="password" name="senha" id="senha" placeholder="Digite sua senha de acesso" required=""/></td></tr></br>       
                    </table>
                </fieldset>
                </br></br>
                <input type="submit" value="Cadastrar" class="botao"/>
            </form>
        </div>
    </body>
</html>
