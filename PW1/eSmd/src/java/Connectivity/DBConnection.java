/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Connectivity;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author William Ribeiro
 */
public class DBConnection {
    public static Connection connect(String s) {
        java.sql.Connection c = null;
        String db = null, url = null, username, password;
        try {
            switch(s) {
                case "mysql":
                    db = "com.mysql.jdbc.Driver";
                    url = "jdbc:mysql://localhost:3306/eSmd";
                    break;
                case "postgresql":
                    db = "org.postgresql.Driver";
                    url = "jdbc:postgresql://localhost:5432/eSmd";
                    break;
                case "odbc":
                    db = "sun.jdbc.odbc.JdbcOdbcDriver";
                    url = "jdbc:odbc:eSmd";
                    break;
            }

            username = "admin";
            password = "admin";
            
            Class.forName(db);
            
            c = DriverManager.getConnection(url, username, password);
            
        } catch(ClassNotFoundException | SQLException e) {
            Logger.getLogger(DBConnection.class.getName()).log(Level.SEVERE, null, e);
        }
        return c;
    }
}
