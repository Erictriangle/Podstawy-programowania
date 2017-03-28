#include <iostream>
#include <cstring>
using namespace std;

char* wstaw(char* &zrodlo,char symbol){
	unsigned int size = strlen(zrodlo);
	for(unsigned int i=1; i<size; i++){
		if(i%3==0) zrodlo[i]=symbol;
	}
	return zrodlo;
}


int main(int argc, char* argv[]){
	char symbol = 75;
	
	char* tablica = wstaw(argv[1],symbol);
	for(unsigned int i=0; i<strlen(tablica);i++){
		cout << tablica[i];
	}
	delete[] tablica;
	return 0;
}
