#include <iostream> 
#include <fstream>    
#include <vector>
#include <string>

void funkcja0col(std::string nazwa);
void funkcja0row(std::string nazwa);
void funkcja1col(std::string nazwa);
void funkcja1row(std::string nazwa);
void funkcja2(std::string nazwa);
void funkcja3(std::string nazwa);
void funkcja4(std::string nazwa);
void funkcja5(std::string nazwa);

int main( int argc, char* argv[] )
{
    funkcja0col("task0_col_data.txt");
    funkcja0row("task0_row_data.txt");
    funkcja1col("task1_col_data.txt");
    funkcja1row("task1_row_data.txt");
    funkcja2("task2_data.txt");
    funkcja3("task3_matrix_data.txt");
    funkcja4("task4_custom_data.txt");
    funkcja5("task5_data.txt");
    
}
void funkcja0col(std::string nazwa) {


    std::fstream file;
    file.open(nazwa, std::ios::in);

    std::vector<int> data;
    for (int i = 0; i < 10; ++i) {
        int v;
        file >> v;
        data.push_back(v);
    }
    file.close();
    std::cout << "Wczytane liczby:" << std::endl;
    for (int value : data) {
        std::cout << value << std::endl;
    }
}
void funkcja1col(std::string nazwa) {


    std::fstream file;
    file.open(nazwa, std::ios::in);

    std::vector<std::string> data;
    for (int i = 0; i < 10; ++i) {
        std::string v;
        file >> v;
        data.push_back(v);
    }
    file.close();
    for (std::string value : data) {
        std::cout << value << std::endl;
    }
}
void funkcja0row(std::string nazwa) {


    std::fstream file;
    file.open(nazwa, std::ios::in);

    std::vector<int> data;
    for (int i = 0; i < 10; ++i) {
        int v;
        file >> v;
        data.push_back(v);
    }
    file.close();
    std::cout << "Wczytane liczby:" << std::endl;
    for (int value : data) {
        std::cout << value << std::endl;
    }
}
void funkcja1row(std::string nazwa) {


    std::fstream file;
    file.open(nazwa, std::ios::in);

    std::vector<std::string> data;
    for (int i = 0; i < 10; ++i) {
        std::string v;
        file >> v;
        data.push_back(v);
    }
    file.close();
    for (std::string value : data) {
        std::cout << value << std::endl;
    }
}
void funkcja2(std::string nazwa) {
    std::fstream file;
    file.open(nazwa, std::ios::in);
    std::vector<std::string> data;
    for (int i = 0; i < 10; ++i) {
        std::string v;
        std::getline(file, v);
        data.push_back(v);
    }
    for (std::string value : data) {
        std::cout << value << std::endl;
    }
}
void funkcja3(std::string nazwa) {
    std::fstream file;
    file.open(nazwa, std::ios::in);
    std::vector<std::vector<int>> data;
    for (int j = 0; j < 7; ++j) {
        std::vector<int> row;
        for (int i = 0; i < 7; ++i) {
            int v;
            file >> v;
            row.push_back(v);
        }
        data.push_back(row);
    }
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void funkcja4(std::string nazwa) {
    std::fstream file;
    file.open(nazwa, std::ios::in);
    struct data_t {
        int number;
        std::string text;
        std::string line;
        std::vector<int> array_numbers;
    };
    data_t data;
    file >> data.number;
    file >> data.text;
    file >> std::ws; //usuwa spacje przed pierwsza litera linijki tekstu
    std::getline(file, data.line);
    for (int i = 0; i < 10; ++i) {
        int num;
        file >> num;
        data.array_numbers.push_back(num);
    }
    for (int i = 0; i < data.array_numbers.size(); i++) {
        std::cout << std::endl;
    }
}
void funkcja5(std::string nazwa) {
    struct data_t {
        int number;
        std::string text;
        std::string line;
        std::vector<int> array_numbers;
    };
    data_t data;
    std::fstream file;
    file.open(nazwa, std::ios::in);
    std::vector<std::string> data;
    
    for (int i = 0; i < 10; ++i) {
        int num;
        file >> num;
        data.array_numbers.push_back(num);
    }

    
}