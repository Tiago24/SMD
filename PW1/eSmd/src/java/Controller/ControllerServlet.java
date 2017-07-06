/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author tiago
 */
@WebServlet(name = "ControllerServlet", urlPatterns = {"/cadastro","/categoria", "/verCart", "/addCart", "/atualizarCart", "/confira", "/compra","/login"})
public class ControllerServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       
        String caminho = request.getServletPath();
        
        if(caminho.equals("/categoria")){
            
        }else if(caminho.equals("/verCart")){
            caminho = "/carrinho";
        }else if(caminho.equals("/addCart")){
            caminho = "/carrinho";
        }else if(caminho.equals("/atualizarCart")){
            caminho = "/carrinho";
        }else if(caminho.equals("/cadastro")){
            
        }else if(caminho.equals("/login")){
        
        }
        
        String url = "/WEB-INF/View/"+caminho+".jsp";
        
        try{
            request.getRequestDispatcher(url).forward(request,response);
        }catch(Exception erro){
            erro.printStackTrace();
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        String caminho = request.getServletPath();
        
        if(caminho.equals("/confira")){
            caminho = "/checkout";
        }else if(caminho.equals("/compra")){
            caminho = "/confirmacao";
        }else if(caminho.equals("/logout")){
            caminho = "/logout";
        }
    }

}
