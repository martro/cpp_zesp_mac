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


LiczbaZespolona LiczbaZespolona:: operator +(const LiczbaZespolona &dodawana)
{
    return LiczbaZespolona(re+dodawana.re,im+dodawana.im);
}

LiczbaZespolona& LiczbaZespolona:: operator +=(const LiczbaZespolona &dodawana)
{
    re+=dodawana.re;
    im+=dodawana.im;
    return *this;
}

LiczbaZespolona LiczbaZespolona:: operator -( const LiczbaZespolona &odejmowana)
{
    return LiczbaZespolona(re-odejmowana.re,im-odejmowana.im);
}

LiczbaZespolona& LiczbaZespolona:: operator -=(const LiczbaZespolona &odejmowana)
{
    re+=odejmowana.re;
    im+=odejmowana.im;
    return *this;
}

LiczbaZespolona LiczbaZespolona:: operator *(const LiczbaZespolona &mnoznik)
{
    LiczbaZespolona temp;

    double temp_re,temp_im;

    temp_re=(this->re*mnoznik.re) - (this->im*mnoznik.im);
    temp_im=(this->im*mnoznik.re) + (this->re*mnoznik.im);

    temp.setRe(temp_re);
    temp.setIm(temp_im);

    return temp;
}

LiczbaZespolona& LiczbaZespolona:: operator *=(const LiczbaZespolona &mnoznik)
{
    return *this;
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
