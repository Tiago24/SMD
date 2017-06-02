/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import model.Book;
import model.BookDAO;

/**
 *
 * @author William Ribeiro
 */
@WebServlet(name = "InsertDataServlet", urlPatterns = {"/InsertDataServlet"})
public class InsertDataServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        BookDAO dao = new BookDAO();
        Book book = new Book()
                .isbn(Integer.parseInt(request.getParameter("isbn")))
                .title(request.getParameter("title"))
                .author(request.getParameter("author"));
        dao.setOne(book);
        request.getRequestDispatcher("listBooks.jsp").forward(request, response);
    }
}
