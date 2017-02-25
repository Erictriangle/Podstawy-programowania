#include <iostream>
using namespace std;

void pobierz();
unsigned long fib_n(unsigned int n);
unsigned long wynik;
unsigned int n;

int main(){
	pobierz();
	cout << n << " wyraz ciagu Fibonacciego: " << fib_n(n) << endl;
	return 0;
}

void pobierz(){
	cout << "Podaj n:" << endl;
	cin >> n;
}

unsigned long fib_n(unsigned int n){
	unsigned long supp1 = 1;
	unsigned long supp2;

	for(unsigned int i = 0; i < n; i++){
		if(n == 0) wynik = 0;
		if(n == 1 || n == 2) wynik = 1;
		supp2 = wynik + supp1;
		supp1 = wynik;
		wynik = supp2;

	}
	
	return (wynik);
}
