#include <iostream> 
#include <fstream>    
#include <vector>
#include <string>


void skroc(std::vector<int> tab);

void ileParzystych(std::vector<int> tab);

int main(int argc, char* argv[])
{
    std::fstream file;
    file.open("skrot_przyklad.txt", std::ios::in);
    if (!file.is_open()) {

        std::cout << "Error: Could not open the file." << std::endl;

        return 1;

    }
    std::vector<int> data;
    for (int i = 0; i < 20; ++i) {
        int v;
        file >> v;
        data.push_back(v);
    }
    file.close();

    std::cout << "Wczytane liczby:" << std::endl;
    for (int value : data) {
        std::cout << value << std::endl;
    }
    std::cout << "\b";

    ileParzystych(data);

    file.open("skrot2.txt", std::ios::in);
    if (!file.is_open()) {

        std::cout << "Error: Could not open the file." << std::endl;

        return 1;

    }
    std::vector<int> data;
    for (int i = 0; i < 20; ++i) {
        int v;
        file >> v;
        data.push_back(v);
    }
    file.close();

}
void skroc(int liczba1) {
    int tempval = liczba1;
    std::vector<int> liczba;
    while (tempval > 0) {
        int digit = tempval % 10;
        if (digit % 2 == 1) {
            liczba.push_back(digit);
        }
        tempval /= 10;
    }
    std::string liczbastr = "";
    for (int value : liczba) {
        liczbastr + std::to_string(value);
    }
    std::cout << liczbastr << std::endl;
   
}
void ileParzystych(std::vector<int> tab) {
    std::vector<int> parzyste;
    int ilosc = 0;
    for (int value : tab) {
        bool istnieje = false;
        if (value >= 10) {
            int tempval = value;
            while (tempval > 0) {

                int digit = tempval % 10;

                if (digit % 2 == 1) {

                    istnieje = true;

                    break;

                }
                tempval /= 10;
            }
        }

        if (!istnieje) {

            parzyste.push_back(value);

        }

    }

    std::cout << "Liczby bez skrotu: " <<std::endl;
    for (int value : parzyste) {
        std::cout << value << std::endl;
    }
    std::cout << "tyle liczb" << std::endl;
    std::cout << parzyste.size();
}
int euklides(int l1, int l2) {
    while (l2 != 0) {
        int temp = l2;
        l2 = l1 % l2;
        l1 = temp;
    }
    return l1;
}
void sprawdzDzielnik(std::vector<int> tab) {
    std::vector<int> parzyste;
    int ilosc = 0;
    for (int value : tab) {
        bool istnieje = false;
        if (value >= 10) {
            int tempval = value;
            while (tempval > 0) {

                int digit = tempval % 10;

                if (digit % 2 == 1) {

                    istnieje = true;

                    break;

                }
                tempval /= 10;
            }
        }

        if (!istnieje) {

            parzyste.push_back(value);

        }

    }
}