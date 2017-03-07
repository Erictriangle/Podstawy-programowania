#include <iostream>
using namespace std;

int* wypelnij(unsigned int size){
	int* tab = new int[size];
	for(unsigned int i=0; i<size; i++){
		if(i%2 == 0) tab[i]=i*i;
		else tab[i]=i-1;
	}
	return tab;
}

double sredniaArytmetyczna(int* &tab, unsigned int size){
	double srednia = 0;
	for(unsigned int i=0; i<size; i++){
		srednia = srednia + tab[i];
	}
	srednia = srednia/size;
	return srednia;
}

int main(){
	unsigned int n;
	
	cout << "Podaj n:" << endl;
	cin >> n;
	int* tab = wypelnij(n);
	cout << "Srednia arytmetyczna wynosi: " << sredniaArytmetyczna(tab,n) << endl;
	
	delete[] tab;
	return 0;
}
