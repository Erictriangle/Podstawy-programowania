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

int* sortowanie(int* &tab,unsigned int size){
	
}

int main(){
	unsigned int size;
	
	cout << "Podaj n:" << endl;
	cin >> size;
	int* tab=wypelnij(size);
	
	
	delete[] tab;	
	return 0;
}
