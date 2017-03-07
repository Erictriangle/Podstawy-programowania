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

void wypisz(int* &tab, unsigned int size){
	for(unsigned int i=0; i<size; i++){
		cout << tab[i] << " ";
	}
	cout << endl;
}

int main(){
	unsigned int n;
	
	cout << "Podaj n:" << endl;
	cin >> n;
	int* tab=wypelnij(n);
	wypisz(tab,n);
	delete[] tab;	
	return 0;
}

