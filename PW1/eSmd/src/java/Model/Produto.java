/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

import java.io.Serializable;
import java.util.Date;

/**
 *
 * @author William Ribeiro
 */
public class Produto implements Serializable {
    private int idProduto;
    private String nome;
    private double preco;
    private String descricao;
    private Date dataAtualizacao;
    private int categoria;

    public Produto() {
    }

    public void setIdProduto(int idProduto) {
        this.idProduto = idProduto;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setDataAtualizacao(Date dataAtualizacao) {
        this.dataAtualizacao = dataAtualizacao;
    }

    public void setCategoria(int categoria) {
        this.categoria = categoria;
    }

    public int getIdProduto() {
        return idProduto;
    }

    public String getNome() {
        return nome;
    }

    public double getPreco() {
        return preco;
    }

    public String getDescricao() {
        return descricao;
    }

    public Date getDataAtualizacao() {
        return dataAtualizacao;
    }

    public int getCategoria() {
        return categoria;
    }
}
