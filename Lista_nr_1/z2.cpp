#include <iostream>
using namespace std;

void pobierz();
float oblicz(float a, float b);

float a, b, x;

int main(){
	pobierz();
	cout << oblicz(a, b) << endl;
	return 0;
}

void pobierz(){
	cout << "Podaj parametr a: " << endl;
	cin >> a;
	cout << "Podaj parametr b: " << endl;
	cin >> b;
}

float oblicz(float a, float b){
	return (-b/a);
}
