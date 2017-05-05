#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* creatTab(const unsigned int size){
    int* tab = new int[size];
    for(unsigned int i=0; i<size; i++ ){
        tab[i] = (rand()%100);
    }

      for(unsigned int i=0; i<size; i++){
         cout << tab[i] << endl;
     }
    return tab;
}

int comparator(int a, int b){
    if(a>b) return 1;
    if(a<b) return -1;
    return 0;
}

void sortuj(int (*comparator)(int,int), int* &tab, const unsigned size){
    unsigned int key;

     for(unsigned int i=1; i<size; i++){
         key = tab[i];
         for(int j=i; j>-1; --j){
             if((*comparator)(key,tab[j]) == -1){
                 tab[j+1] = tab[j];
                 tab[j] = key;
             }
         }
     }
     for(unsigned int i=0; i<size; i++){
         cout << tab[i] << endl; 
     }
}

int main(){
    unsigned int size;

     //Random config
    srand(time(NULL));

    //Creat tab
    cout << "Set the size of the array " << endl;
    cin >> size;
    int* tab = creatTab(size);
    sortuj((*comparator),tab,size);
    
  

    delete[] tab;
    return 0;
}