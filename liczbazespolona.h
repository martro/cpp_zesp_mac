#ifndef LICZBAZESPOLONA_H_INCLUDED
#define LICZBAZESPOLONA_H_INCLUDED

#include <iostream>
#include <cmath>

using namespace std;

class LiczbaZespolona
{
private:
    double re,im;
public:
    LiczbaZespolona(double x=0, double y=0);
    virtual ~LiczbaZespolona();

    void wyswietl();
    double modul();

    void setRe(double re);
    double getRe();
    void setIm(double im);
    double getIm();



    LiczbaZespolona operator +(const LiczbaZespolona &dodawana);
    LiczbaZespolona & operator +=(const LiczbaZespolona & dodawana);

    LiczbaZespolona operator -(const LiczbaZespolona &odejmowana);
    LiczbaZespolona & operator -=(const LiczbaZespolona &odejmowana);

    LiczbaZespolona operator *(const LiczbaZespolona &mnoznik);
    LiczbaZespolona & operator *=(const LiczbaZespolona & mnoznik);

    LiczbaZespolona operator /(const LiczbaZespolona &dzielnik);
    LiczbaZespolona operator /(const double &dzielnik);
    LiczbaZespolona & operator /=(const LiczbaZespolona &dzielnik);

    friend ostream & operator << (ostream &str, const LiczbaZespolona &a);
    friend istream & operator >> (istream & str,LiczbaZespolona &a);
};

#endif // LICZBAZESPOLONA_H_INCLUDED
