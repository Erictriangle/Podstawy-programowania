#include <iostream>
#include <cmath>
using namespace std;

float a, b, c, x1, x2, delta;

void pobierz(){
	
	cout << "Podaj wartosc parametru a:" << endl;
	cin >> a;
	cout << "Podaj wartosc parametru b:" << endl;
	cin >> b;
	cout << "Podaj wartosc parametru c:" << endl;
	cin >> c;
}

float wyliczDelte(float a, float b, float c){
	return sqrt(b*b-4*a*c);
}

float wyliczX1(float a, float b, float delta){
	return ((-b+delta)/(2*a));
}

float wyliczX2(float a, float b, float x1){
	return ((-c/a)/x1);
}

int main(){
	pobierz();
	delta = wyliczDelte(a, b, c);
	if(delta >=  0){
		x1 = wyliczX1(a, b, delta);
		if(delta == 0){
			cout << "Pierwiastek wielomianu: " << x1 << endl;
		}
		else{
			x2 = wyliczX2(a, b, x1);
			cout << "Pierwiatski wielomianu: " << x1 << " i " << x2 << endl;
		}
	}
	else cout << "Brak pierwiastkow wielomianu!" << endl;
	
	return 0;
}



