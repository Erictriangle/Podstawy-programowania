#include <iostream>
using namespace std;

void nieparzyste_fib(unsigned int n){
	unsigned long wynik = 1;
	unsigned long supp1 = 1;
	unsigned long supp2;

	for(unsigned int i = 1; i<n; i++){
		if(i == 1 || i == 2) cout << 1 << endl;
		else{
			supp2 = wynik + supp1;
			supp1 = wynik;
			wynik = supp2;
			if(wynik%2 != 0) cout << wynik << endl;
		}
	}
}

int main(){
	unsigned int n;

	cout << "Podaj n:" << endl;
        cin >> n;	
	nieparzyste_fib(n);
	return 0;
}
