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

    void Macierz:: wypelnijJedynkami()
    {
        this->wypelnij(1);
    }

    void Macierz:: wypelnijZerami()
    {
        this->wypelnij(0);
    }

    void Macierz:: wypelnijLosowo()
    {
        srand(time(NULL));
        for (int m=0;m<this->m;m++)
            for(int n=0;n<this->n;n++)
                this->tablica[m][n] = rand()%10;
    }

    void Macierz:: macierzJednostkowa()//trzeba dodac akcje w wypadku macierzy niekwadratowej
    {
        wypelnijZerami();
        for (int m=0;m<this->m;m++)
            this->tablica[m][m] = 1;
    }

    void Macierz:: usun()
    {
        for (int m=0;m<this->m;m++)
            delete [] tablica[m];
        delete [] tablica;
    }

    void Macierz:: alokuj()
    {
        tablica = new int* [this->m];
        for(int m=0;m<this->m;m++)
            tablica[m] = new int[this->n];
    }

    Macierz Macierz:: operator + (const Macierz &dodawana)
    {
        Macierz temp(this->m,this->n);

        for (int m=0; m<temp.m;m++)
            for(int n=0;n<temp.n;n++)
                temp.tablica[m][n]=tablica[m][n]+dodawana.tablica[m][n];

        return temp;
    }

    Macierz Macierz:: operator = (const Macierz &kopiowana)
    {
        this->usun();




        return 0;
    }
