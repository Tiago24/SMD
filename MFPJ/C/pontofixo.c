#include "pontofixo.h"

PontoFixo soma(PontoFixo a, PontoFixo b) {
    PontoFixo c;
    c.parteInteira = 0;
    c.parteFracionaria = a.parteFracionaria + b.parteFracionaria;
    while(c.parteFracionaria >= 1000) {
        c.parteFracionaria -= 1000;
        c.parteInteira++;
    }
    c.parteInteira += a.parteInteira + b.parteInteira;
    return c;
}

PontoFixo subtracao(PontoFixo a, PontoFixo b) {
    PontoFixo c;
    c.parteInteira = 0;
    c.parteFracionaria = a.parteFracionaria - b.parteFracionaria;
    while(c.parteFracionaria <= -1000) {
        c.parteFracionaria += 1000;
        c.parteInteira--;
    }
    c.parteInteira += a.parteInteira - b.parteInteira;
    return c;
}
