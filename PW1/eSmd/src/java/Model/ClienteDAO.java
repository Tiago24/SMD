/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author William Ribeiro
 */
public class ClienteDAO {
    public List<Cliente> getAll() {
        List<Cliente> resultado = new ArrayList<>();
        
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch(ClassNotFoundException e) {
            
        }
        return resultado;
    }
}
