#include "pontofixo.h"
#include <string.h>

void zero(PontoFixo p) {
    p.parteInteira = 0;
    p.parteFracionaria = 0;
}

PontoFixo soma(PontoFixo a, PontoFixo b) {
    PontoFixo c;
    int x, y;
    x = juntarPartes(a);
    y = juntarPartes(b);
    x += y;
    c = separarPartes(x, 1000);
    return c;
}

PontoFixo subtracao(PontoFixo a, PontoFixo b) {
    PontoFixo c;
    int x, y;
    x = juntarPartes(a);
    y = juntarPartes(b);
    x -= y;
    c = separarPartes(x, 1000);
    return c;
}

PontoFixo produto(PontoFixo a, PontoFixo b) {
    PontoFixo c;
    int x, y;
    x = (juntarPartes(a)) * 1000;
    y = (juntarPartes(b)) * 1000;
    x *= y;
    c = separarPartes(x, 1000000);
    return c;
}

int juntarPartes(PontoFixo p) {
    return (p.parteInteira * 1000 + p.parteFracionaria);
}

PontoFixo separarPartes(int i, int divisor) {
    PontoFixo p;
    p.parteInteira = i / divisor;
    p.parteFracionaria = i % divisor;
    return p;
}

char* toString(PontoFixo p) {
    char string[10];
    int n = sprintf(string, "%d.%d", p.parteInteira, p.parteFracionaria);
    return string;
}
