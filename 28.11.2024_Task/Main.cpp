#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

int main(){
	std::vector<int> tablica;
	tablica.resize(100);
	tablica.push_back(100);
	tablica[0] = 100;
	tablica.insert(tablica.begin()+3, 100);
	tablica.size();
}