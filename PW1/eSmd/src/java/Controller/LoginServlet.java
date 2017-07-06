/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import Model.Cliente;
import DAO.ClienteDAO;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author tiago
 */
@WebServlet(name = "LoginServlet", urlPatterns = {"/LoginServlet"})
public class LoginServlet extends HttpServlet {
    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        String login = request.getParameter("login");
        String senha = request.getParameter("senha");
        
        ClienteDAO dao = new ClienteDAO();
        List<Cliente> clientes = dao.getAll();
        HttpSession sessao = request.getSession(true);
        //System.out.println(clientes.size());
        for(int i = 0; i<clientes.size(); i++){
            if(login.equals(clientes.get(i).getLogin()) && senha.equals(clientes.get(i).getSenha())){
                sessao.setAttribute("login",login);
                request.getRequestDispatcher("index.jsp").forward(request,response);
            }else{
                request.getRequestDispatcher("/WEB-INF/View/logout.jsp").forward(request,response);
            }
        }
        //List<Cliente> usuario = new ArrayList<>();
        //usuario
        //if(){}
    }
}
