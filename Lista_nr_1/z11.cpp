#include <iostream>
using namespace std;

int* tablica(int size){
	int *tab = new int[size];
	for(int i=0; i<size; ++i){
		tab[i] = (i*i*i); 
	}
	return tab;
}

int main(){
	int n;
	cin >> n;
	int* tab = tablica(n);
	for(int i=0; i<n; ++i){
		cout << tab[i] << endl;
	}		
	delete[] tab;
	return 0;
}
