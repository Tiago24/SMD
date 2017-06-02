/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author William Ribeiro
 */
public class BookDAO {
    public List<Book> getAll() {
        List<Book> result = new ArrayList<>();
        
        try {
            Class.forName("org.postgresql.Driver");
            
            String url = "jdbc:postgresql://localhost:5432/smdDB";
            String username = "admin";
            String password = "admin";
            
            try (Connection c = DriverManager.getConnection(url, username, password)) {
                String query = "SELECT * FROM pw1_verif5";
                try (PreparedStatement ps = c.prepareStatement(query);
                        ResultSet rs = ps.executeQuery(query)) {
                    while(rs.next()) {
                        Book b = new Book()
                                .isbn(rs.getInt("isbn"))
                                .title(rs.getString("title]"))
                                .author(rs.getString("author"))
                                .category(rs.getString("category"));
                        result.add(b);
                    }
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            Logger.getLogger(BookDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        return result;
    }

    public void setOne(Book b) {
        try {
            Class.forName("org.postgresql.Driver");
            
            String url = "jdbc:postgresql://localhost.5432/smdDB";
            String username = "admin";
            String password = "admin";
            
            try (Connection c = DriverManager.getConnection(url, username, password)) {
                String query = "INSERT INTO pw1_verif5 (isbn, title, author, category) "
                        + "VALUES (?, ?, ?, ?)";
                
                try (PreparedStatement ps = c.prepareStatement(query)) {
                    ps.setInt(1, b.isbn());
                    ps.setString(2, b.title());
                    ps.setString(3, b.author());
                    ps.setString(4, b.category());
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            Logger.getLogger(BookDAO.class.getName()).log(Level.SEVERE, null, e);
        }
    }
}
