#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>

std::vector<int> generateLuckyNumbers(int n) {
    std::vector<bool> isLucky(n + 1, true);
    int i = 2;

    while (i <= n) {
        if (isLucky[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isLucky[j] = false;
            }
        }
        i++;
    }

    std::vector<int> luckyNumbers;
    for (int k = 1; k <= n; k++) {
        if (isLucky[k]) {
            luckyNumbers.push_back(k);
        }
    }

    return luckyNumbers;
}

std::vector<int> generatePrimeNumbers(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::vector<int> primeNumbers;
    for (int k = 2; k <= n; k++) {
        if (isPrime[k]) {
            primeNumbers.push_back(k);
        }
    }

    return primeNumbers;
}

int main() {
    std::ifstream f("dane.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string s;
    std::vector<int> allnums;
    while (std::getline(f, s)) {
        try {
            allnums.push_back(std::stoi(s));
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number in file: " << s << std::endl;
        }
    }
    f.close();

    if (allnums.empty()) {
        std::cerr << "No valid numbers found in the file." << std::endl;
        return 1;
    }

    int n = *std::max_element(allnums.begin(), allnums.end());

    std::vector<int> luckyNumbers = generateLuckyNumbers(n);
    std::vector<int> primeNumbers = generatePrimeNumbers(n);


    std::unordered_set<int> luckySet(luckyNumbers.begin(), luckyNumbers.end());
    std::unordered_set<int> primeSet(primeNumbers.begin(), primeNumbers.end());


    int luckyCount = 0;
    for (int num : allnums) {
        if (luckySet.count(num)) {
            luckyCount++;
        }
    }

    int maxStreak = 0;
    int currentStreak = 0;
    int currentNumber = -1; 
    int longestLuckyNumber = -1;

    for (int num : allnums) {
        if (luckySet.count(num)) {
            if (num == currentNumber) {
                currentStreak++;
            }
            else {
                if (currentStreak > maxStreak) {
                    maxStreak = currentStreak;
                    longestLuckyNumber = currentNumber;
                }
                currentNumber = num;
                currentStreak = 1;
            }
        }
        else {
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
                longestLuckyNumber = currentNumber;
            }
            currentNumber = -1;
            currentStreak = 0;
        }
    }

    if (currentStreak > maxStreak) {
        maxStreak = currentStreak;
        longestLuckyNumber = currentNumber;
    }

    int luckyPrimeCount = 0;
    for (int num : luckyNumbers) {
        if (primeSet.count(num)) {
            luckyPrimeCount++;
        }
    }

    std::cout << "Count of lucky numbers in the input list: " << luckyCount << std::endl;
    if (longestLuckyNumber != -1) {
        std::cout << "Longest streak of lucky number " << longestLuckyNumber
            << " repeated " << maxStreak << " times." << std::endl;
    }
    else {
        std::cout << "No lucky numbers streak found in consecutive order." << std::endl;
    }
    std::cout << "Count of lucky numbers that are also prime: " << luckyPrimeCount << std::endl;

    return 0;
}

