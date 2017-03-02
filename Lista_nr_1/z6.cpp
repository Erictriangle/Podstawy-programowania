#include <iostream>
using namespace std;

int* wypelnij(int n){
	tab = new int[n];
	int supp1 = 1;
	int supp2;
	int fib;

	for(int i =0; i<n; i++){
		if(n == 0){
			fib = 0;
			tab[i] = fib;
		}
		if(n == 1 || n ==2){
			fib = 1;
			tab[i] = fib;
		}
		supp2 = fib + supp1;
		supp1 = fib;
		fib = supp2;
		tab[i] = fib; 
	}
	return tab;
}

int main(){
	int n;

	cout << "Podaj n:" << endl;
	cin >> n;
	cout << wypelnij(n) << endl;
	return 0;
}
