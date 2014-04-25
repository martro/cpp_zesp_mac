#ifndef MACIERZ_H_INCLUDED
#define MACIERZ_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Macierz
{
private:
    int m,n;
    int** tablica;

public:
    Macierz(int m=1, int n=1):m(m), n(n)
    {
        tablica = new int* [this->m];
        for(int m=0;m<this->m;m++)
            tablica[m] = new int[this->n];
    }

    ~Macierz()
    {
        usun();
        cout<<"Usunieto macierz.";
    }

    void wypelnij(int a);
    void wypelnijJedynkami();
    void wypelnijZerami();
    void wypelnijLosowo();
    void macierzJednostkowa();
    void usun();

    Macierz operator + (const Macierz &dodawana);


    friend ostream &operator<< (ostream &str, const Macierz &r);
};

#endif // MACIERZ_H_INCLUDED
