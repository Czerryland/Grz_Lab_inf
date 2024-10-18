#include <iostream>

float ObliczPraca(float sila, float przemieszczenie) {

	return sila * przemieszczenie;

}

float ObliczMoc(float praca, float czas) {

	return praca / czas;

}


int main(int argc, char* argv) {

	int a = 12;

	int poleKwadratu = pow(a, 2);

	int x = 4;
	int h = 10;

	float poleTrojkat = x * h * 0.5;

	int E = 10;
	int F = 14;

	float poleRomb = E * F * 0.5;

	std::cout << "Pole kwadratu: " << poleKwadratu << std::endl;
	std::cout << "Pole trojkatu: " << poleTrojkat << std::endl;
	std::cout << "Pole rombu: " << poleRomb << std::endl;

	std::cout << "Praca: " << ObliczPraca(140.5, 2) << std::endl;
	std::cout << "Moc: " << ObliczMoc(ObliczPraca(140.5, 2), 5.3) << std::endl;

	return 0;
}

