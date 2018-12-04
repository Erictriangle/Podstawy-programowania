#include <iostream>
#include <string>


class Przedmiot{
	std::string nazwa;
};

class Adres{
	std::string ulica;
	std::string miasto;
};

class Osoba{
	Adres* adres;
	std::string imie, nazwisko;
	
};

class Student : Osoba{
	Przedmioty *przedmioty;
};



int main(){
	Student s;
	Student s1(s);


}
