#include <iostream>
 
typedef unsigned long long ll;
double result = 0.0;

double serie_harmonica(ll n) {
	if (n == 1) { return 1; }
	return 1.0 / n + serie_harmonica(n-1);
}

int main() {
	/*
	Faça uma função recursiva para resolver o problema da série harmônica matemática. A função deve receber um número n e fazer a soma até 1/n.
	*/
	ll n;
	std::cin >> n;
	std::cout << serie_harmonica(n) << '\n';

	return 0;
}