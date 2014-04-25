#ifndef MACIERZ_H_INCLUDED
#define MACIERZ_H_INCLUDED

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
        cout<<"dupdup";
    }

    void wyswietl()
    {
        cout<<"asdasda";
    }

    friend ostream &operator<< (ostream &str, const Macierz &r)
    {
        for(int i=0;i<r.m;i++){
            for(int j=0;j<r.n;j++){
                str<<r.tablica[i][j]<<"\t";
            }
            str<<endl;
        }

    return str;
    }
};

#endif // MACIERZ_H_INCLUDED
