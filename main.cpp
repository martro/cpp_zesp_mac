#include <iostream>
#include "macierz.h"
#include "liczbazespolona.h"

using namespace std;

int main()
{

    Macierz a(3,3);
    Macierz b(3,3);
    Macierz c(3,3);

    a.wypelnij(2);
    b.wypelnij(5);
    c.wypelnij(8);




    cout<<endl;
    cout<<a<<endl<<"________________________"<<endl;
    cout<<b<<endl<<"________________________"<<endl;
    cout<<a+b<<endl<<"________________________"<<endl;

    /*try{
        LiczbaZespolona a(1,2);
        LiczbaZespolona b(0);
        LiczbaZespolona c(-1,-1);
        try{
            cout<<a/b<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        cout<<a+b<<endl;
        cout<<a*b<<endl;
        cout<<a*c<<endl;
        c/=a;
        cout<<c<<endl;
        c*=a;
        cout<<c<<endl;
        c+=a;
        cout<<c<<endl;
        c-=a;
        cout<<c<<endl;


        Macierz<double> i(2,3);
        Macierz<double> j(2,3);
        Macierz<double> k(3,2);
        try{
            Macierz<double> macierz(-1,0);
            cout<<macierz<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        i.wypelnijJedynkami();
        j.wypelnijJedynkami();
        k.wypelnijJedynkami();
        cout<<i+j<<endl;
        cout<<i-j+i<<endl;
        i=j;
        j+=i;
        cout<<j<<endl;
        cout<<i<<endl;
        cout<<i*k<<endl;
        try{
            cout<<k*k<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        i.wypelnijLosowo();
        cout<<i;
	Macierz<LiczbaZespolona> l(3,3);
	l.wypelnijJedynkami();
	Macierz<LiczbaZespolona> m(3,3);
	m.macierzJednostkowa();
	l+=l;
	cout<<l*m<<endl;
    }catch(const char * err)
    {
        cout<<err<<endl;
    }
    */
    cout<<"Program zakonczyl prace poprawnie. Trwa usuwanie zmiennych.\n";
    return 0;
}


