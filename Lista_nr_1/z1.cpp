#include <iostream>
using namespace std;
void pobierz();
int wyznaczMax(int a, int b, int c);
int a, b, c;

int main(){
	pobierz();
	cout << "Najwieksza wartosc ma zmienna:" << wyznaczMax(a, b, c) << endl;
	return 0;
}

void pobierz(){
	cout << "Podaj wartosc a:" << endl;
	cin >> a;
	cout << "Podaj wartosc b:" << endl;
	cin >> b;
	cout << "Podaj wartosc c:" << endl;
	cin >> c;
}

int wyznaczMax(int a, int b, int c){
	if(a > b){
		if(a > c) return a;
	}
	else{
		if(b > c) return b;
	}
	return c;
}
