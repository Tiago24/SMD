/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smd0050;

import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author William Ribeiro
 */
public class Receipt {
    private static Film film;
    
    public static void XML2Java() {
        // to do
    }

    public static void Java2JSON(File file, Film film) {
        ObjectMapper mapper = new ObjectMapper();
        try {
            mapper.writeValue(file, film);
            System.out.println("JSON file successfully created.");
        } catch (IOException ex) {
            System.out.println("Error: input stream not available.");
        }
    }
    
    public static void JSON2Java(String filepath) {
        ObjectMapper mapper = new ObjectMapper();
        mapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        try {
            film = mapper.readValue(new FileInputStream(filepath), Film.class);
            System.out.println("Java object successfully created.");
        } catch (FileNotFoundException ex) {
            System.out.println("Error: JSON file not available.");
        } catch (IOException ex) {
            System.out.println("Error: input stream not available.");
        }
    }
    
    public void YAML2Java() {
        // to do
    }
    
    public void ProtocolBuffer2Java() {
        // to do
    }
    
    public static void main(String[] args) throws IOException {
        JSON2Java("test/json/film.json");
        System.out.println(film.toString());
        // testing
        Java2JSON(new File("test/json/test1.json"), 
                    new Film(3498820, "Captain America: Civil War", 2016, 8, 
                            "https://www.youtube.com/watch?v=dKrVegVI0Us"));
        Java2JSON(new File("test/json/test2.json"), 
                    new Film(2395427, "Avengers: Age of Ultron", 2015, 7, 
                            "https://www.youtube.com/watch?v=JAUoeqvedMo"));
        Java2JSON(new File("test/json/test3.json"), 
                    new Film(2250912, "Spider-Man: Homecoming", 2017, 8, 
                            "https://www.youtube.com/watch?v=U0D3AOldjMU"));
        // to do: find a way for the ArrayList of related films to work out
    }
}
