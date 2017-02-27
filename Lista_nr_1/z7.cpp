#include <iostream>
using namespace std;

unsigned int n;
unsigned long wynik = 0;

void pobierz(){
	cout << "Podaj n:" << endl;
	cin >> n;
}

unsigned long fib_r(unsigned int n){
	
	if(n == 1 || n == 2) return 1;
	return (fib_r(n-1)+(n-2));
}

unsigned long suma(unsigned int n){
	for(unsigned int i=2; i<=n; i++){
		wynik = wynik + fib_r(i);
		
	}
	return wynik;
}

int main(){
	pobierz();
	cout << "Suma:" << suma(n) << endl;
	return 0;

}
