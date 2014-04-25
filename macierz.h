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
        tablica = new int* [m];
        for(int i=0;i<m;i++)
            tablica[i] = new int[n];
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


    friend ostream &operator<< (ostream &str, const Macierz &r);
};

#endif // MACIERZ_H_INCLUDED
