#include <cstdlib>
using namespace std;
//nie trzeba poprzedzac cin cout specyfikatorem std::
#include <iostream>
//biblioteka dla strumienia na standardowe wejscie/wyjscie
#include <fstream>
//biblioteka dla klas ofstream, ifstream, fstream (oba wczesniejsze) -
//pochodne klas ostream, istream
//time stara biblioteka lol
#include <string>
// dla funkcji time()

int main()
{
    int i, j, n, m;
    float re;
    string plikA;
    string s;
    ofstream los; // --> fstream ()? ./o operand.
//otput file stream (deklaracja strumnienia wyprowadzanego do pliku)
    cout << "Wprowadz nazwe pliku wynikowego..\n";
// string (ciag znakow) wyprowadzany na standardowe wyjscie (ekran)
    cin >> plikA;
    los.open(plikA.c_str(),ios::ate);
    cout << "Wprowadz po sobie liczbe wierszy i kolumn macierzy w oddzielnych liniach..\n";
// strumien (ciag znakow) wyprowadzany na standardowe wyjscie (ekran)
    cin >> n >> m;
// strumien (ciag znakow) wprowadzany ze standardowego wejscia (klawiatura - console)
    s = "n="; los << s; los << n;
    s = " m="; los << s; los << m;
    los << '\n';
//string (znaki) lub liczby wyprowadzane do strumienia
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
        {
            re = ((rand() % 200)-100)/ 10.0;
            los.width(6);
            los << re;
            if (j!=m) los << " ";
        }
        los << '\n';
    }
    los.close();
    return 0;
}
