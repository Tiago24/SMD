/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import Connectivity.DBConnection;
import Model.Produto;
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
public class ProdutoDAO {
    public List<Produto> getAll() {
        List<Produto> resultado = new ArrayList<>();
        
        try {
//            Class.forName("com.mysql.jdbc.Driver");
//            
//            String url = "jdbc:mysql://localhost:3306/eSmd";
//            String username = "admin";
//            String password = "admin";
//            
//            Connection c = DriverManager.getConnection(url, username, password);
            Connection c = DBConnection.connect("mysql");
            
            String query = "SELECT * FROM Produto";
            
            PreparedStatement ps = c.prepareStatement(query);
            ResultSet rs = ps.executeQuery(query);
            while(rs.next()) {
                Produto p;
                p = new Produto();
                p.setIdProduto(rs.getInt("idProduto"));
                p.setNome(rs.getString("nome"));
                p.setPreco(rs.getDouble("preco"));
                p.setDescricao(rs.getString("descricao"));
                p.setDataAtualizacao(rs.getDate("dataAtualizacao"));
                p.setCategoria(rs.getInt("categoria"));
                resultado.add(p);
            }
        } catch (SQLException e) {
            Logger.getLogger(ProdutoDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        
        return resultado;
    }
}
