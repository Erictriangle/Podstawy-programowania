#include <iostream>
#include <fstream>
using namespace std;


void wpisz_do_pliku(ofstream& plik, string tekst, unsigned int ile=10){
	for(unsigned int i=0; i<ile; i++){
		plik << tekst << endl;
	}
	plik.close();
}

int main(){
	ofstream plik("b.txt", ios::app);
	wpisz_do_pliku(plik,"Hello World");
	return 0;
}
