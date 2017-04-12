#ifndef PONTOFIXO_H_INCLUDED
#define PONTOFIXO_H_INCLUDED

typedef struct {
    unsigned short parteInteira;
    unsigned short parteFracionaria;
} PontoFixo;

PontoFixo soma(PontoFixo a, PontoFixo b);
PontoFixo subtracao(PontoFixo a, PontoFixo b);
PontoFixo produto(PontoFixo a, PontoFixo b);

#endif // PONTOFIXO_H_INCLUDED
