#ifndef PONTOFIXO_H_INCLUDED
#define PONTOFIXO_H_INCLUDED

typedef struct {
    int parteInteira;
    int parteFracionaria;
} PontoFixo;

void zero(PontoFixo);
PontoFixo soma(PontoFixo, PontoFixo);
PontoFixo subtracao(PontoFixo, PontoFixo);
char* toString(PontoFixo);

#endif // PONTOFIXO_H_INCLUDED
