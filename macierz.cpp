#include "macierz.h"


    ostream &operator<< (ostream &str, const Macierz &a)
    {
        for(int m=0;m<a.m;m++){
            for(int n=0;n<a.n;n++){
                str<<a.tablica[m][n]<<" ; ";
            }
            str<<endl;
        }

    return str;
    }

    void Macierz:: wypelnij(int a)
    {
        for (int m=0;m<this->m;m++)
            for(int n=0;n<this->n;n++)
                this->tablica[m][n]=a;
    }

    void Macierz:: usun()
    {
        for (int m=0;m<this->m;m++)
            delete [] tablica[m];
        delete [] tablica;
    }
