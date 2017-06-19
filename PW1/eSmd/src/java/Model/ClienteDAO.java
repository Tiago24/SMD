/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

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
public class ClienteDAO {
    public List<Cliente> getAll() {
        List<Cliente> resultado = new ArrayList<>();
        
        try {
            Class.forName("com.mysql.jdbc.Driver");
            
            String url = "jdbc:mysql://localhost:3306/eSmd";
            String username = "admin";
            String password = "admin";
            
            Connection c = DriverManager.getConnection(url, username, password);
            
            String query = "SELECT * FROM Cliente";
            
            PreparedStatement ps = c.prepareStatement(query);
            ResultSet rs = ps.executeQuery(query);
            while(rs.next()) {
                Cliente cl;
                cl = new Cliente();
                cl.setIdCliente(rs.getInt("idCliente"));
                cl.setNome(rs.getString("nome"));
                cl.setLogin(rs.getString("login"));
                cl.setSenha(rs.getString("senha"));
                cl.setEndereco(rs.getString("endereco"));
                cl.setEmail(rs.getString("email"));
                cl.setTelefone(rs.getString("telefone"));
                cl.setCidade(rs.getString("cidade"));
                resultado.add(cl);
            }
        } catch(ClassNotFoundException | SQLException e) {
            Logger.getLogger(ClienteDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        return resultado;
    }
    
    public void setTuple(Cliente cl) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            
            String url = "jdbc:mysql://localhost:3306/eSmd";
            String username = "admin";
            String password = "admin";
            
            Connection c = DriverManager.getConnection(url, username, password);
            
            String query = "INSERT INTO e-Smd "
                    + "(idCliente, nome, login, senha, endereco, email, telefone, cidade) "
                    + "VALUE (?, ?, ?, ?, ?, ?, ?, ?)";
            
            PreparedStatement ps = c.prepareStatement(query);
            ps.setInt(1, cl.getIdCliente());
            ps.setString(2, cl.getNome());
            ps.setString(3, cl.getLogin());
            ps.setString(4, cl.getSenha());
            ps.setString(5, cl.getEndereco());
            ps.setString(6, cl.getEmail());
            ps.setString(7, cl.getTelefone());
            ps.setString(8, cl.getCidade());
            ps.executeUpdate();
        } catch (ClassNotFoundException | SQLException e) {
            Logger.getLogger(ClienteDAO.class.getName()).log(Level.SEVERE, null, e);
        }
        
    }
}
