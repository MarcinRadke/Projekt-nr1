#ifndef TESTS_SORTING_H
#define TESTS_SORTING_H


class Sorting {
public:
    bool static posortowane(int *tablica, int liczbaElementow);
    void static quicksort(int *tablica, int lewy, int prawy);
    void static mergesort(int tablica[], int l, int r);
    void static quicksortCzesci(int *tablica, int lewy, int prawy, double czesc);
    void static introsort(int *tablica, int liczbaElementow);
    void static odwracanie(int *tablica, int liczbaElementow);
private:
    static int Partition(int *tablica, int lewy, int prawy);
    void static maxheapify(int *tablica, int kopiec, int cos);
    void static heapsort(int *tablica, int liczbaElementow);
    void static insertionsort(int *tablica, int liczbaElementow);
    void static merge(int tablica[], int l, int m, int r);
};


#endif //TESTS_SORTING_H
