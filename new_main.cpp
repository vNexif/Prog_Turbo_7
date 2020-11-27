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

    std::cin >> plikA;

    los.open("plikA.txt", std::ofstream::out | std::ofstream::app);

//    void open ( const std::string& plikA, std::ios_base::openmode mode = std::ios_base::out);

    std::cout << "Podaj ile turbo wierszy pokazac" << std::endl;

    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        std::cout << i << ": " ;
        for (int j = 1; j <= m ; ++j) {
           re = random_dev();
           std::cout << j << ": " << std::endl;
           los.width(6);
           std::cout << re << std::endl;
        }
    }
    los.close();

    return 0;

}