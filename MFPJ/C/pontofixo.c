#include "pontofixo.h"
#include <string.h>

void zero(PontoFixo p) {
    p.parteInteira = 0;
    p.parteFracionaria = 0;
}

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

char* toString(PontoFixo p) {
    char string[10];
    int n = sprintf(string, "%d.%d", p.parteInteira, p.parteFracionaria);
    return string;
}
