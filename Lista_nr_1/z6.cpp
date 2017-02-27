#include <iostream>
using namespace std;
unsigned int n;

void pobierz(){
	cout << "Podaj n:" << endl;
	cin >> n;
}

unsigned long fib_r(unsigned int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;
	return (fib_r(n-1)+fib_r(n-2));
}

void wypisz(unsigned int n){
	for(unsigned int i=0; i<n; i++){
		cout << fib_r(i) << endl;
	}	
}

int main(){
	pobierz();
	wypisz(n);
	return 0;
}
