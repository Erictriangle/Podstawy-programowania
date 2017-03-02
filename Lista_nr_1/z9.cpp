#include <iostream>
using namespace std;

unsigned int n;

void pobierz(){
	cout << "Podaj n:" << endl;
	cin >> n;
}

unsigned long sil_i(unsigned int n){
	long silnia = n;
	for(int i=(n-1); i>0; i--){
		silnia = silnia*i;
	}
	return silnia;
}

int main(){
	pobierz();
	cout << "Silnia: " << sil_i(n) << endl;
	return 0;
}
