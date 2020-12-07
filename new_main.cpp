#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <random>

float random_dev() {
	std::random_device rd;                                       // Utworzenie generatora liczb losowych.
	std::mt19937_64 mt(rd());                                   // Generator Mersenna 64 bitowy.
	std::uniform_real<float> dist(-10, 10);        // Ograniczenie zakresu.

	return dist(mt);
}

int main()
{
	int n{}, m{};                                             //Deklaracja i inicjalizacja zmiennych. Domyślna wartośc = 0.
	float re{};
	std::string plik_zmienne{}, plik_A{};
	std::fstream los{};                                      //Zmienna typu fstream.

	std::cout << "Podaj sciezke pliku z ktorego ma zostac pobrana ilosc wierszy i kolumn do macierzy" << std::endl;

	std::cin >> plik_zmienne;

	los.open(plik_zmienne, std::ios::in);
	if (los.good())                                         //Sprawdzenie czy strumien danych jest dobry.
	{
		while (!los.eof())                                  //Sprawdzenie czy koniec pliku.
		{
			los >> n;                                       //Pobranie zmiennej n z pliku.
			los >> m;                                       //Pobranie zmiennej m z pliku.
		}
	}
	los.close();                                           //Zamkniecie strumienia danych.

	std::cout << "Podaj nazwe pliku w ktorym beda wyniki" << std::endl;

	std::cin >> plik_A;

	los.open(plik_A, std::ios::out);

	los << "n= " << n << " m= " << m << '\n';

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			re = random_dev();
			los.width(6);           // Ustawienie nowej szerokości pola dla strumienia.
			los.precision(1);    // Ustawienie precyzji dla liczb zmiennoprzecinkowych.
			los << std::fixed << re;        // Ustawienie notacji dla liczb zmiennoprzecinkowych.
			if (j != m) los << " ";
		}
		los << '\n';
	}

	los.close();

	return 0;

}