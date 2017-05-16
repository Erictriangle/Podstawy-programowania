

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum opcja{

};


struct SProdukt{
	unsigned int numer;
	string nazwa;
	ETyp typ;
	unsigned int cena; 
};

unsigned int menu(){
	unsigned int numer;
	
	cout << "-=[ Sklep internetowy ]=-" << endl;
	cout << endl;
	cout << "Wybierz numer opcji: " << endl;
	cout << endl;
	
	cin >> numer;
	return numer;
}

int main(int argc,char** argv){
	
	
	return 0;
}
