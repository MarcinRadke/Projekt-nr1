#include <iostream>
#include <time.h>

#include "Sorting.h"

using namespace std;



int main()
{
    int liczbaElementow, liczbaTablic = 100;
    clock_t start,stop;
    double czas;
    char koniec = 'n';
    int **tablica;

    //inicjowanie generatora liczba losowych ("ziarna")
    srand(time(NULL));

    cout << "Program sortujacy zadanej wielkosci tablice wybranym algorytmem\n";

    while(koniec == 'n') {
        cout << "\nIle elementow w tablic: ";
        cin >> liczbaElementow;

        tablica = new int*[liczbaTablic];

        //dynamiczna alokacja tablic o zadanej wielkosci
        for(int i = 0; i < liczbaTablic; i++){
            tablica[i] = new int [liczbaElementow];
            //wygenerowanie losowych elementow tablicy
            for(int j = 0; j< liczbaElementow; j++)
                tablica[i][j] = rand() % 1000000 + 1;
        }
        cout << "Podaj liczbe (od 0 do 1; 1 tworzy tablice posortowana malejaco) posortowania tablic: \n";
        double czescPosortowana;
        cin >> czescPosortowana;
        if(czescPosortowana == 1){
            for(int i=0; i<liczbaTablic; i++){
                Sorting::quicksort(tablica[i], 0, liczbaElementow - 1);
                Sorting::odwracanie(tablica[i], liczbaElementow);
            }
        }
        else if(czescPosortowana>0 || czescPosortowana<1){
            for(int i=0; i<liczbaTablic; i++)
                Sorting::quicksortCzesci(tablica[i], 0, liczbaElementow - 1, czescPosortowana);
        }
        int opcja;
        cout << "Wybierz sortowanie: \n"
                "1. quicksort\n"
                "2. mergesort\n"
                "3. introsort\n";
        cin >> opcja;
        if(opcja == 1) {
            start = clock();
            for(int i = 0; i < liczbaTablic; i++) {
                Sorting::quicksort(tablica[i], 0, liczbaElementow - 1);
            }
            stop = clock();
        }
        else if(opcja == 2) {
            start = clock();
            for(int i = 0; i < liczbaTablic; i++) {
                Sorting::mergesort(tablica[i], 0, liczbaElementow - 1);
            }
            stop = clock();
        }
        else if(opcja == 3) {
            start = clock();
            for(int i = 0; i < liczbaTablic; i++) {
                Sorting::introsort(tablica[i], liczbaElementow);
            }
            stop = clock();
        }

        bool sortowaniaDzialaja = true;
        for(int i = 0; i < liczbaTablic; i++) {
            if(!Sorting::posortowane(tablica[i], liczbaElementow))
                sortowaniaDzialaja = false;
        }

        if(!sortowaniaDzialaja) {
            cout << "Sortowanie nie powiodlo sie !!!!";
        }
        else {
            czas = (double)(stop-start) / CLOCKS_PER_SEC;
            cout<<"\nCzas sortowania: "<<czas<<" s"<<endl;

        }
        // zwolnienie tablic dynamicznych
        for(int i = 0; i < liczbaTablic; i++)
            delete [] tablica[i];
        delete [] tablica;

        cout << "Czy zakonczyc program? [t/n] ";
        cin >> koniec;
    }
    return 0;
}
