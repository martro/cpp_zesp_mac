#include "macierz.h"

void Macierz:: wypelnij(int a)
{
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
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
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n] = rand()%10;
}

void Macierz:: macierzJednostkowa()//trzeba dodac akcje w wypadku macierzy niekwadratowej
{
    wypelnijZerami();
    for (int m=0; m<this->m; m++)
        this->tablica[m][m] = 1;
}

void Macierz:: usun()
{
    for (int m=0; m<this->m; m++)
        delete [] tablica[m];
    delete [] tablica;
}

void Macierz:: alokuj()
{
    tablica = new int* [this->m];
    for(int m=0; m<this->m; m++)
        tablica[m] = new int[this->n];
}

Macierz Macierz:: operator + (const Macierz &dodawana)
{
    if((this->m != dodawana.m) || (this->n != dodawana.n))
        throw "Blad dodawania. Macierze nie maja tych samych wymiarow";
    Macierz temp(this->m,this->n);

    for (int m=0; m<temp.m; m++)
        for(int n=0; n<temp.n; n++)
            temp.tablica[m][n]=tablica[m][n]+dodawana.tablica[m][n];

    return temp;
}

Macierz& Macierz:: operator += (const Macierz &dodawana)
{
    if((this->m != dodawana.m) || (this->n != dodawana.n))
        throw "Blad dodawania. Macierze nie maja tych samych wymiarow";
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n]=this->tablica[m][n]+dodawana.tablica[m][n];

    return *this;
}

Macierz Macierz:: operator - (const Macierz &odejmowana)
{
    if((this->m != odejmowana.m) || (this->n != odejmowana.n))
        throw "Blad odejmowania. Macierze nie maja tych samych wymiarow";
    Macierz temp(this->m,this->n);

    for (int m=0; m<temp.m; m++)
        for(int n=0; n<temp.n; n++)
            temp.tablica[m][n]=tablica[m][n]-odejmowana.tablica[m][n];

    return temp;
}

Macierz& Macierz:: operator -= (const Macierz &odejmowana)
{
    if((this->m != odejmowana.m) || (this->n != odejmowana.n))
        throw "Blad odejmowania. Macierze nie maja tych samych wymiarow";
    for (int m=0; m<this->m; m++)
        for(int n=0; n<this->n; n++)
            this->tablica[m][n]=this->tablica[m][n]-odejmowana.tablica[m][n];

    return *this;
}

Macierz Macierz:: operator * (const Macierz &mnoznik)
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

Macierz& Macierz:: operator *= (const Macierz &mnoznik)
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

Macierz& Macierz:: operator = (const Macierz &kopiowana)
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

ostream &operator<< (ostream &str, const Macierz &a)
{
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

