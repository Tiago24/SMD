/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model;

import java.util.Date;

/**
 *
 * @author William Ribeiro
 */
public class PedidoCliente {
    private int idPedido;
    private double valor;
    private int quantidade;
    private Date data;
    private int cliente;

    public PedidoCliente() {
    }

    public void setIdPedido(int idPedido) {
        this.idPedido = idPedido;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public void setCliente(int cliente) {
        this.cliente = cliente;
    }

    public int getIdPedido() {
        return idPedido;
    }

    public double getValor() {
        return valor;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public Date getData() {
        return data;
    }

    public int getCliente() {
        return cliente;
    }
}
