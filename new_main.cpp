#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <random>

float random_dev(){
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_real<float> dist(-10, 10);

    return dist(mt);
}

int main()
{
    int n{},m{};
    float re{};
    std::string plikA{};
    std::fstream los{};

//    std::cout << "Wprowadz nazwe pliku: " << std::endl;

	std::cout << "Podaj sciezke pliku z ktorego ma zostac pobrana ilosc wierszy i kolumn do macierzy" << std::endl;

    std::cin >> plikA;

	los.open(plikA, std::ios::in | std::ios::out);
	if (los.good())
	{
		while (!plik.eof())
		{
			los >> n;
			los >> m;
		}
	}

//    void open ( const std::string& plikA, std::ios_base::openmode mode = std::ios_base::out);

 /*   for (int i = 1; i <= n; ++i) {
        std::cout << i << ": " ;
        for (int j = 1; j <= m ; ++j) {
           re = random_dev();
           std::cout << j << ": " << std::endl;
           los.width(6);
           std::cout << re << std::endl;
        }
    }*/
	std::cout << n << " " << m;
    los.close();

    return 0;

}