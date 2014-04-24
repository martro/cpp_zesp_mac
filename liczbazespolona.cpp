#include "liczbazespolona.h"

LiczbaZespolona::LiczbaZespolona(double x, double y): re(x), im(y)
{
}

LiczbaZespolona::~LiczbaZespolona()
{

}

void LiczbaZespolona::wyswietl()
{
    std::cout<<re<<"+"<<im<<"i ("<<modul()<<")"<<std::endl;
}

double LiczbaZespolona::modul()
{
    return sqrt(pow(this->re,2)+pow(this->im,2));
}

void LiczbaZespolona::setRe(double re)
{
    this->re=re;
}

double LiczbaZespolona::getRe()
{
    return re;
}

void LiczbaZespolona::setIm(double im)
{
    this->im=im;
}

double LiczbaZespolona::getIm()
{
    return im;
}


LiczbaZespolona LiczbaZespolona:: operator +(LiczbaZespolona &dodawana)
{
    return LiczbaZespolona(re+dodawana.re,im+dodawana.im);
}

LiczbaZespolona LiczbaZespolona:: operator -(LiczbaZespolona &odejmowana)
{
    return LiczbaZespolona(re-odejmowana.re,im-odejmowana.im);
}

ostream &operator<< (ostream &str, const LiczbaZespolona &a)
{
    if (a.im>=0)
        str<<a.re<<"+"<<a.im<<"i";
    else
        str<<a.re<<a.im<<"i";
    return str;
}

istream &operator >> (istream &str,LiczbaZespolona &a)
{
    str>>a.re>>a.im;
    str.ignore();

    return str;
}
