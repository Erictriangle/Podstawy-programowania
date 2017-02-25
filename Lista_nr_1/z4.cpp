#include <iostream>
using namespace std;

void pobierz();
unsigned long fib_r(const unsigned int n);

unsigned int n;


int main(){
	pobierz();
	cout << n + " wyraz ciagu Fibonacciego: " << fib_r(n) << endl ;
	return 0;
}

void pobierz(){
	cout << "Podaj n: " << endl;
	cin >> n;
	
}

unsigned long fib_r(unsigned int n){
	if(n == 1) return 1;
	if(n == 2) return 1;
	return (fib_r(n-1)+fib_r(n-2));
}
