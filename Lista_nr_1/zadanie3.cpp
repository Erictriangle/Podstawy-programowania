#include <iostream>
#include <cmath>
using namespace std;

double wyliczDelta(double a, double b, double c){
	if(b==0){
		if((a>0 && c>0)||(a<0 && c<0)||(a==0)) return -1;
		if(c == 0) return 0;
		return sqrt(-4*a*c);
	}
	return sqrt(b*b-4*a*c);
}

double wyliczX1(double a, double b, double delta){
	return (-b+delta)/(2*a);
}

double wyliczX2(double a, double c, double x1){
	return (-c/a)/x1;
}

int main(){
	double a, b, c, delta, x1;
	
	cout << "Podaj wartosci wielomianu:" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	delta = wyliczDelta(a, b, c);	
	if(delta>=0){
		x1 = wyliczX1(a,b, delta);
		if(delta == 0) cout << "Pierwiastek wielomianu: " << x1 << endl;
		else cout << "Pierwiastki wielomianu: " << x1 <<" " << wyliczX2(a,b,x1) << endl;
	}
	else cout << "Brak pierwiastkow wielomianu!" << endl;
}
