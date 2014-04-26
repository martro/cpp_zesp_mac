#ifndef MACIERZ_H_INCLUDED
#define MACIERZ_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


template <class T>
class Macierz;

template <class T>
ostream &operator<< (ostream &str, const Macierz<T> &);


template <class T>
class Macierz
{
private:
    int m,n;
    T** tablica;

public:
    Macierz(int m=1, int n=1):m(m), n(n)
    {
        if ((m<=0)||(n<=0))
            throw "Blad. Tworzona macierz musi miec wymiary dodatnie.";
        this->alokuj();
    }

    ~Macierz()
    {
        usun();
        cout<<"Usunieto macierz.";
    }

    void wypelnij(T a);
    void wypelnijJedynkami();
    void wypelnijZerami();
    void wypelnijLosowo();
    void macierzJednostkowa();
    void alokuj();
    void usun();

    Macierz operator + (const Macierz &dodawana);
    Macierz& operator += (const Macierz &dodawana);
    Macierz operator - (const Macierz &odejmowana);
    Macierz& operator -= (const Macierz &odejmowana);
    Macierz operator * (const Macierz &mnoznik);
    Macierz& operator *= (const Macierz &mnoznik);
    Macierz& operator = (const Macierz &kopiowana);


    friend ostream &operator<< <>(ostream &str, const Macierz<T> &r);
};



template <class T>
void Macierz<T>:: wypelnij(T a)
{
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n]=a;
}
template <class T>
void Macierz<T>:: wypelnijJedynkami()
{
    this->wypelnij(1);
}
template <class T>
void Macierz<T>:: wypelnijZerami()
{
    this->wypelnij(0);
}
template <class T>
void Macierz<T>:: wypelnijLosowo()
{
    srand(time(NULL));
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n] = rand()%10;
}
template <class T>
void Macierz<T>:: macierzJednostkowa()//trzeba dodac akcje w wypadku macierzy niekwadratowej
{
    if(this->m != this->n)
        throw "Blad. Macierz jednostkowa musi byc kwadratowa.";
    wypelnijZerami();
    for (int m=0; m<this->m; m++)
        this->tablica[m][m] = 1;
}
template <class T>
void Macierz<T>:: usun()
{
    for (int m=0; m<this->m; m++)
        delete [] tablica[m];
    delete [] tablica;
}
template <class T>
void Macierz<T>:: alokuj()
{
    tablica = new T* [this->m];
    for(int m=0; m<this->m; m++)
        tablica[m] = new T[this->n];
}
template <class T>
Macierz<T> Macierz<T>:: operator + (const Macierz &dodawana)
{
    if((this->m != dodawana.m) || (this->n != dodawana.n))
        throw "Blad dodawania. Macierze nie maja tych samych wymiarow";
    Macierz temp(this->m,this->n);

    for (int m=0; m<temp.m; m++)
        for(int n=0; n<temp.n; n++)
            temp.tablica[m][n]=tablica[m][n]+dodawana.tablica[m][n];

    return temp;
}
template <class T>
Macierz<T>& Macierz<T>:: operator += (const Macierz &dodawana)
{
    if((this->m != dodawana.m) || (this->n != dodawana.n))
        throw "Blad dodawania. Macierze nie maja tych samych wymiarow";
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n]=this->tablica[m][n]+dodawana.tablica[m][n];

    return *this;
}
template <class T>
Macierz<T> Macierz<T>:: operator - (const Macierz &odejmowana)
{
    if((this->m != odejmowana.m) || (this->n != odejmowana.n))
        throw "Blad odejmowania. Macierze nie maja tych samych wymiarow";
    Macierz temp(this->m,this->n);

    for (int m=0; m<temp.m; m++)
        for(int n=0; n<temp.n; n++)
            temp.tablica[m][n]=tablica[m][n]-odejmowana.tablica[m][n];

    return temp;
}
template <class T>
Macierz<T>& Macierz<T>:: operator -= (const Macierz &odejmowana)
{
    if((this->m != odejmowana.m) || (this->n != odejmowana.n))
        throw "Blad odejmowania. Macierze nie maja tych samych wymiarow";
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n]=this->tablica[m][n]-odejmowana.tablica[m][n];

    return *this;
}
template <class T>
Macierz<T> Macierz<T>:: operator * (const Macierz &mnoznik)
{
    if(this->n != mnoznik.m )
        throw "Blad mnozenia. Wymiary macierzy musza byc w postaci: MxN i NxM";
    Macierz temp(this->m,mnoznik.n);
    temp.wypelnijZerami();

    for(int y=0; y<temp.m; y++)
        for(int x=0; x<temp.n; x++)
            for(int i=0; i<mnoznik.m; i++)
                temp.tablica[y][x] += (this->tablica[y][i] * mnoznik.tablica[i][x]);
    return temp;
}
template <class T>
Macierz<T>& Macierz<T>:: operator *= (const Macierz &mnoznik)
{
    if(this->n != mnoznik.m )
        throw "Blad mnozenia. Wymiary macierzy musza byc w postaci: MxN i NxM";
    Macierz temp(this->m,mnoznik.n);
    temp.wypelnijZerami();

    for(int y=0; y<temp.m; y++)
        for(int x=0; x<temp.n; x++)
            for(int i=0; i<mnoznik.m; i++)
                temp.tablica[y][x] += (this->tablica[y][i] * mnoznik.tablica[i][x]);
    this->usun();
    this->m=temp.m;
    this->n=temp.n;
    this->alokuj();

    *this=temp;

    return *this;
}
template <class T>
Macierz<T>& Macierz<T>:: operator = (const Macierz &kopiowana)
{
    this->usun();
    this->m=kopiowana.m;
    this->n=kopiowana.n;
    this->alokuj();

    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n]=kopiowana.tablica[m][n];

    return *this;
}
template <class T>
ostream &operator<< (ostream &str, const Macierz<T> &a)
{
    str<<endl;
    for(int m=0; m<a.m; m++)
    {
        for(int n=0; n<a.n; n++)
        {
            str<<a.tablica[m][n]<<" ; ";
        }
        str<<endl;
    }

    return str;
}


#endif // MACIERZ_H_INCLUDED
