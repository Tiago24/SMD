#include "PontoFixo.h"

PontoFixo::PontoFixo()
{
    setParteInteira(0);
    setParteFracionaria(0);
}

PontoFixo::PontoFixo(int i, int f)
{
    setParteInteira(i);
    setParteFracionaria(f);
}

int PontoFixo::getParteInteira()
{
    return this.parteInteira;
}

void PontoFixo::setParteInteira(int i)
{
    this.parteInteira = i;
}

int PontoFixo::getParteFracionaria()
{
    return this.parteFracionaria;
}

void PontoFixo::setParteFracionaria(int i)
{
    this.parteFracionaria = i;
}

PontoFixo operator +(PontoFixo a, PontoFixo b)
{
    PontoFixo c = new PontoFixo();
    c.parteFracionaria = a.parteFracionaria + b.parteFracionaria;
    while(c.parteFracionaria >= 1000)
    {
        c.parteFracionaria -= 1000;
        c.parteInteira++;
    }
    c.parteInteira += a.parteInteira + b.parteInteira;
    return c;
}

PontoFixo operator -(PontoFixo a, PontoFixo b)
{
    PontoFixo c = new PontoFixo();
    c.parteFracionaria = a.parteFracionaria - b.parteFracionaria;
    while(c.parteFracionaria <= -1000)
    {
        c.parteFracionaria += 1000;
        c.parteInteira--;
    }
    c.parteInteira += a.parteInteira - b.parteInteira;
    return c;
}

void toString()
{
    String p = new String();
}

PontoFixo::~PontoFixo()
{
    //dtor
}
