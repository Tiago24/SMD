#ifndef PONTOFIXO_H
#define PONTOFIXO_H


class PontoFixo
{
    public:
        PontoFixo();
        PontoFixo(int, int);
        virtual ~PontoFixo();
        int getParteInteira();
        void setParteInteira(int);
        int getParteFracionaria();
        void setParteFracionaria(int);
        PontoFixo operator +(PontoFixo, PontoFixo);
        PontoFixo operator -(PontoFixo, PontoFixo);
        toString();

    protected:

    private:
        int parteInteira;
        int parteFracionaria;
};

#endif // PONTOFIXO_H
