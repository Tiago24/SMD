<%-- 
    Document   : listBooks
    Created on : Jun 1, 2017, 4:23:34 PM
    Author     : William Ribeiro
--%>

<%@page import="java.util.List"%>
<%@page import="model.Book"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Booklist</h1>
        <%
            List<Book> books = (List<Book>) request.getAttribute("books");
            if(books != null && books.size() > 0) {
        %>
        <table border="1">
            <tr>
                <td>ISBN</td>
                <td>Title</td>
                <td>Author</td>
                <td>Category</td>
            </tr>
            <% for(Book b : books) { %>
            <tr>
                <td><%= b.isbn() %></td>
                <td><%= b.title() %></td>
                <td><%= b.author() %></td>
                <td><%= b.category() %></td>
            </tr>
            <% } %>
        </table>
        <% } else { %>
        <b>No books listed.</b>
    </body>
</html>
