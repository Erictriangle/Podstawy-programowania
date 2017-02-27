#include <iostream>
using namespace std;

unsigned int n;

void pobierz(){
	cout << "Podaj n:" << endl;
	cin >> n;	
}

unsigned long sil_r(unsigned int n){
	if(n==0 || n==1) return 1;
	return ((sil_r(n))*(sil_r(n-1)));
}

int main(){
	pobierz();
	cout << "Wynik:" << sil_r(n) << endl;
	return 0;
}
