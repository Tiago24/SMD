/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smd0050;

import java.net.MalformedURLException;
import java.net.URL;

/**
 *
 * @author William Ribeiro
 */
public class Film {
    private int id;
    private String title;
    private int year;
    private int rating;
    private URL trailer;
//    private ArrayList<Film> related;

    public Film() {}

    public Film(int id, String title, int year, int rating, String trailer) {
        this.id = id;
        this.title = title;
        this.year = year;
        this.rating = rating;
        try {
            this.trailer = new URL(trailer);
        } catch (MalformedURLException ex) {
            System.out.println("Error: invalid URL.");;
        }
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public URL getTrailer() {
        return trailer;
    }

    public void setTrailer(URL trailer) {
        this.trailer = trailer;
    }

//    public List<Film> getRelated() {
//        return related;
//    }
//
//    public void setRelated(ArrayList<Film> related) {
//        this.related = related;
//    }

    @Override
    public String toString() {
        return "Film{" + "id=" + id + ", title=" + title + ", "
                + "year=" + year + ", rating=" + rating + ", "
                + "trailer=" + trailer + "}";
    }
}
