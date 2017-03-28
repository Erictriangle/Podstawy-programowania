#include <iostream>
#include <fstream>
using namespace std;


void wpisz_do_pliku(string np, string tekst, unsigned int ile=10){
	ofstream plik(np.c_str(), ios::app);
	for(unsigned int i=0; i<ile; i++){
		plik << tekst << endl;
	}
	plik.close();
}

int main(){
	wpisz_do_pliku("a.txt","Hello World");
	return 0;
}
