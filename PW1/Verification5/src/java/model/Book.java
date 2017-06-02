/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

/**
 *
 * @author William Ribeiro
 */
public class Book {
    private int isbn;
    private String title;
    private String author;
    private String category;

    public Book() {
    }

    public int isbn() {
        return isbn;
    }

    public String title() {
        return title;
    }

    public String author() {
        return author;
    }

    public String category() {
        return category;
    }

    public Book isbn(int isbn) {
        this.isbn = isbn;
        return this;
    }

    public Book title(String title) {
        this.title = title;
        return this;
    }

    public Book author(String author) {
        this.author = author;
        return this;
    }

    public Book category(String category) {
        this.category = category;
        return this;
    }
}
