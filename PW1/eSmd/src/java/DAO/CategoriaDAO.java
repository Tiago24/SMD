/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import Connectivity.DBConnection;
import Model.Categoria;
import java.sql.Connection;
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
public class CategoriaDAO {
    public List<Categoria> getAll() {
        List<Categoria> resultado = new ArrayList<>();
        
        try {
//            Class.forName("com.mysql.jdbc.Driver");
//            
//            String url = "jdbc:mysql://localhost:3306/eSmd";
//            String username = "admin";
//            String password = "admin";
//            
//            Connection c = DriverManager.getConnection(url, username, password);
            Connection c = DBConnection.connect("mysql");
            
            String query = "SELECT * FROM Categoria";

            PreparedStatement ps = c.prepareStatement(query);
            ResultSet rs = ps.executeQuery(query);
            while(rs.next()) {
                Categoria ctg;
                ctg = new Categoria();
                ctg.setIdCategoria(rs.getInt("idCategoria"));
                ctg.setNome(rs.getString("nome"));
                resultado.add(ctg);
            }
        } catch (SQLException e) {
            Logger.getLogger(CategoriaDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        
        return resultado;
    }
}
