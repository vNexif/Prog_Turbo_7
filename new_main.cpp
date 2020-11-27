// c++ szkola.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//NIE JEST MONDRZE BO VISUAL SSIE ;C

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include <array>
#include <fstream>
#include <random>
#include <iomanip>

float random_dev() {
	std::random_device rd;
	std::mt19937_64 mt(rd());
	std::uniform_real<float> dist(-10, 10);

	return dist(mt);
}

int main()
{
	int n{}, m{};
	float re{};
	std::string plik_zmienne{}, plik_A{};
	std::fstream los{};

	//    std::cout << "Wprowadz nazwe pliku: " << std::endl;

	std::cout << "Podaj sciezke pliku z ktorego ma zostac pobrana ilosc wierszy i kolumn do macierzy" << std::endl;

	std::cin >> plik_zmienne;

	los.open(plik_zmienne, std::ios::in);
	if (los.good())
	{
		while (!los.eof())
		{
			los >> n;
			los >> m;
		}
	}
	los.close();

	std::cout << "Podaj nazwe pliku w ktorym beda wyniki" << std::endl;

	std::cin >> plik_A;

	los.open(plik_A, std::ios::out);

	los << "n= " << n << " m= " << m << '\n';

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			re = random_dev();
			los.width(6);
			los.precision(1);
			los << std::fixed << re;
			if (j != m) los << " ";
		}
		los << '\n';
	}


	return 0;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
//OMG CZEMU