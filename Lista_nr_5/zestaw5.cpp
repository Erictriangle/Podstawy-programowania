//Andrzej Wlodarczyk || Grupa lab. 6

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

//Funkcje przeciazone do sprawdzania liczby hasel 
unsigned int checkSize(string* &tab){
	return atoi(tab[0].c_str());
}

unsigned int checkSize(fstream& plik){
	string str;
	getline(plik,str);
	return atoi(str.c_str());
}

//Wczytywanie bazy danych
string* load(){
	fstream iPlik;
	iPlik.open("iPlikZ5.txt",ios::in);

	unsigned int size = checkSize(iPlik);
	string* tab = new string[size+1];
	
	tab[0] = to_string(size);
	for(unsigned int i=1; i<size+1; i++){
		getline(iPlik,tab[i]);
	}
	iPlik.close();
	return tab;
}

//Odczytania hasel z tablicy(nie z pliku!)
void read(string* &tab){
	unsigned int size = checkSize(tab);
	cout << size << endl;
	for(unsigned int i=1; i<size+1; i++){
		cout << tab[i] << endl;
	}
}

//Dodanie hasla na koniec tablicy
string* add(string* &tab,string text){
	unsigned int size = checkSize(tab);
	string* nTab = new string[size+2];
	
	nTab[0] = to_string(size+1);
	for(unsigned int i=1; i<size+1; i++){
		nTab[i] = tab[i];
	}
	nTab[size+1] = text;
	
	delete[] tab;
	return nTab;
}

//Usuniecie hasla z konca tablicy
string* remove(string* tab){
	unsigned int size =checkSize(tab);
	string* nTab = new string[size];
	
	nTab[0] = to_string(size-1);
	for(unsigned int i=1; i<size; i++){
		nTab[i] = tab[i];
	}
	
	delete[] tab;
	return nTab;
}

//Sprawdzenie obecnosci hasla w tablicy
void find(string* &tab,string text){
		unsigned int size = checkSize(tab);
		string spr = "Nie znaleziono!";
		
		for(unsigned int i=1; i<size+1; i++){
			if(!text.compare(tab[i])) spr = tab[i];
		}
		cout << spr << endl;
}

//Zapisanie aktualnej zawartosci tablicy do pliku
void save(string* &tab){
	fstream oPlik;
	oPlik.open("iPlikZ5.txt",ios::out);
	unsigned int size =checkSize(tab);
	
	oPlik << size << endl;
	for(unsigned int i=1; i<size+1; i++){
		oPlik << tab[i] << endl;
	}
	oPlik.close();
}

int main(){
	char chose = 'e';
	string *tab;
	string text;
	
	do{
	
	cout << endl;
	cout << "Witam w bazie danych hasel z internetu." << endl;
	cout << "Wybierz jedna z ponizszych opcji:" << endl;
	cout << "i - wczytaj baze danych" << endl;
	cout << "o - wypisz zawartosc bazy danych" << endl;
    cout << "a - dodaj nowe haslo" << endl;
	cout << "d - usun ostatnie haslo" << endl;
	cout << "f - znajdz haslo" << endl;
	cout << "s - zapisz zmiany" << endl;
	cout << "e - opusc program" << endl;	
	cin >> chose;

	switch(chose){
		case 'i':
			tab = load();
			break;
	
		case 'o':
			read(tab);
			break;
		
		case 'a':
				cout << "Wpisz nowe haslo:" << endl;
				cin >> text;
				tab = add(tab,text);
			break;
		
		case 'd':
				tab = remove(tab);
			break;
		
		case 'f':
			cout << "Wpisz szukane haslo:" << endl;
			cin >> text;
			find(tab,text);
			break;
		
		case 's':
			save(tab);
			break;
		
		case 'e':
			break;
			
		default:
			chose = 'z';
			cout << "Opcja nieistnieje!" << endl;
			break;
	}
	} while(chose != 'e');

	delete[] tab;
	return 0;
}
