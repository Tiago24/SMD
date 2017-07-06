/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import Connectivity.DBConnection;
import Model.PedidoCliente;
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
public class PedidoClienteDAO {
    List<PedidoCliente> getAll() {
        List<PedidoCliente> resultado = new ArrayList<>();
        
        try {
//            Class.forName("com.mysql.jdbc.Driver");
//            
//            String url = "jdbc:mysql://localhost:3306/eSmd";
//            String username = "admin";
//            String password = "admin";
//            
//            Connection c = DriverManager.getConnection(url, username, password);
            Connection c = DBConnection.connect("mysql");
            
            String query = "SELECT * FROM Cliente";
            
            PreparedStatement ps = c.prepareStatement(query);
            ResultSet rs = ps.executeQuery(query);
            while(rs.next()) {
                PedidoCliente pc;
                pc = new PedidoCliente();
                pc.setIdPedido(rs.getInt("idPedido"));
                pc.setValor(rs.getDouble("valor"));
                pc.setQuantidade(rs.getInt("quantidade"));
                pc.setData(rs.getDate("data"));
                pc.setCliente(rs.getInt("cliente"));
                resultado.add(pc);
            }
        } catch (SQLException e) {
            Logger.getLogger(PedidoClienteDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        
        return resultado;
    }
}
