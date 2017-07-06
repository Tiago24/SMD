/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DAO;

import Connectivity.DBConnection;
import Model.Cliente;
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
public class ClienteDAO {
    public List<Cliente> getAll() {
        List<Cliente> resultado = new ArrayList<>();
        
        try {
//            Class.forName("com.mysql.jdbc.Driver");
//            
//            String url = "jdbc:mysql://localhost:3306/eSmd";
//            String username = "admin";
//            String password = "admin";
//            
//            Connection con = DriverManager.getConnection(url, username, password);
            Connection con = DBConnection.connect("mysql");
            
            String query = "SELECT * FROM Cliente";
            
            PreparedStatement ps = con.prepareStatement(query);
            ResultSet rs = ps.executeQuery(query);
            while(rs.next()) {
                Cliente c;
                c = new Cliente();
                c.setIdCliente(rs.getInt("idCliente"));
                c.setNome(rs.getString("nome"));
                c.setLogin(rs.getString("login"));
                c.setSenha(rs.getString("senha"));
                c.setEndereco(rs.getString("endereco"));
                c.setEmail(rs.getString("email"));
                c.setTelefone(rs.getString("telefone"));
                c.setCidade(rs.getString("cidade"));
                resultado.add(c);
            }
            rs.close(); ps.close(); con.close();
        } catch(SQLException e) {
            Logger.getLogger(ClienteDAO.class.getName())
                    .log(Level.SEVERE, null, e);
        }
        return resultado;
    }

    public Cliente getTuple(int i) {
        Cliente c = new Cliente();
        
        try {
            Connection con = DBConnection.connect("mysql");
            
            String query = "SELECT * FROM Cliente WHERE idCliente = " + i;
            
            PreparedStatement ps = con.prepareStatement(query);
            ResultSet rs = ps.executeQuery(query);
            while(rs.next()) {
                c.setIdCliente(rs.getInt("idCliente"));
                c.setNome(rs.getString("nome"));
                c.setLogin(rs.getString("login"));
                c.setSenha(rs.getString("senha"));
                c.setEndereco(rs.getString("endereco"));
                c.setEmail(rs.getString("email"));
                c.setTelefone(rs.getString("telefone"));
                c.setCidade(rs.getString("cidade"));
            }
            rs.close(); ps.close(); con.close();
        } catch(SQLException e) {
            Logger.getLogger(ClienteDAO.class.getName())
                    .log(Level.SEVERE, null, e);
        }
        return c;
    }
    
    public void setTuple(Cliente c) {
        try {
            try (Connection con = DBConnection.connect("mysql")) {
                String query = "INSERT INTO Cliente "
                        + "(idCliente, nome, login, senha, endereco, email, "
                        + "telefone, cidade) VALUE (?, ?, ?, ?, ?, ?, ?, ?)";
                
                try (PreparedStatement ps = con.prepareStatement(query)) {
                    ps.setInt(1, c.getIdCliente());
                    ps.setString(2, c.getNome());
                    ps.setString(3, c.getLogin());
                    ps.setString(4, c.getSenha());
                    ps.setString(5, c.getEndereco());
                    ps.setString(6, c.getEmail());
                    ps.setString(7, c.getTelefone());
                    ps.setString(8, c.getCidade());
                    ps.executeUpdate();
                }
            }
        } catch (SQLException e) {
            Logger.getLogger(ClienteDAO.class.getName())
                    .log(Level.SEVERE, null, e);
        }
    }

    public void updateTuple(Cliente c2) {
        try {
            Cliente c1 = getTuple(c2.getIdCliente());
            
            try (Connection con = DBConnection.connect("mysql")) {
                String query = "UPDATE Cliente "
                        + "SET nome = ?, login = ?, senha = ?, "
                        + "endereco = ?, email = ?, telefone = ?, cidade = ? "
                        + "WHERE idCliente = ?";
                
                try (PreparedStatement ps = con.prepareStatement(query)) {
                    ps.setInt(8, c1.getIdCliente());
                    if(c1.getNome().equalsIgnoreCase(c2.getNome()))
                        ps.setString(1, c1.getNome());
                    else ps.setString(1, c2.getNome());
                    if(c1.getLogin().equalsIgnoreCase(c2.getLogin()))
                        ps.setString(2, c1.getLogin());
                    else ps.setString(2, c2.getLogin());
                    if(c1.getSenha().equalsIgnoreCase(c2.getSenha()))
                        ps.setString(3, c1.getSenha());
                    else ps.setString(3, c2.getSenha());
                    if(c1.getEndereco().equalsIgnoreCase(c2.getEndereco()))
                        ps.setString(4, c1.getEndereco());
                    else ps.setString(4, c2.getEndereco());
                    if(c1.getEmail().equalsIgnoreCase(c2.getEmail()))
                        ps.setString(5, c1.getEmail());
                    else ps.setString(5, c2.getEmail());
                    if(c1.getTelefone().equalsIgnoreCase(c2.getTelefone()))
                        ps.setString(6, c1.getTelefone());
                    else ps.setString(6, c2.getTelefone());
                    if(c1.getCidade().equalsIgnoreCase(c2.getCidade()))
                        ps.setString(7, c1.getCidade());
                    else ps.setString(7, c2.getCidade());
                    ps.executeUpdate();
                }
            }
        } catch (SQLException e) {
            Logger.getLogger(ClienteDAO.class.getName())
                    .log(Level.SEVERE, null, e);
        }
    }
}
