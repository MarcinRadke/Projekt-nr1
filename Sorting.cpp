#include <cmath>

using namespace std;

#include "Sorting.h"

bool Sorting::posortowane(int *tablica, int liczbaElementow) {
    for(int i = 0; i < liczbaElementow - 1; i++)
        if(tablica[i] > tablica[i+1])
            return false;
    return true;
}

void Sorting::quicksort(int *tablica, int lewy, int prawy) {
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do{
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}

void Sorting::mergesort(int tablica[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(tablica, l, m);
        mergesort(tablica, m + 1, r);
        merge(tablica, l, m, r);
    }
}

void Sorting::merge(int tablica[], int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int k=l;

    int ile=(r-1)+1;
    int temp[ile];

    while(i<=m && j<=r)
    {
        if(tablica[i] <= tablica[j])
        {
            temp[k]=tablica[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=tablica[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=tablica[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=tablica[j];
        j++;
        k++;
    }
    for(int s=l;s<=r;s++)
    {
        tablica[s]=temp[s];
    }
}

void Sorting::quicksortCzesci(int *tablica, int lewy, int prawy, double czesc)
{
    quicksort(tablica, lewy, prawy * czesc);
}

int Sorting::Partition(int* tablica, int lewy, int prawy) {
    int pivot = tablica[prawy];
    int temp;
    int i = lewy;

    for (int j = lewy; j < prawy; ++j)
    {
        if (tablica[j] <= pivot)
        {
            temp = tablica[j];
            tablica[j] = tablica[i];
            tablica[i] = temp;
            i++;
        }
    }

    tablica[prawy] = tablica[i];
    tablica[i] = pivot;

    return i;
}

void Sorting::maxheapify(int* tablica, int kopiec, int cos) {
    int lewy = (cos + 1) * 2 - 1;
    int prawy = (cos + 1) * 2;
    int wiekszy = 0;

    if (lewy < kopiec && tablica[lewy] > tablica[cos])
        wiekszy = lewy;
    else
        wiekszy = cos;

    if (prawy < kopiec && tablica[prawy] > tablica[wiekszy])
        wiekszy = prawy;

    if (wiekszy != cos)
    {
        int temp = tablica[cos];
        tablica[cos] = tablica[wiekszy];
        tablica[wiekszy] = temp;

        maxheapify(tablica, kopiec, wiekszy);
    }
}

void Sorting::heapsort(int* tablica, int liczbaElementow) {
    int kopiec = liczbaElementow;

    for (int p = (kopiec - 1) / 2; p >= 0; --p)
        maxheapify(tablica, kopiec, p);

    for (int i = liczbaElementow - 1; i > 0; --i)
    {
        int temp = tablica[i];
        tablica[i] = tablica[0];
        tablica[0] = temp;

        --kopiec;
        maxheapify(tablica, kopiec, 0);
    }
}

void Sorting::insertionsort(int* tablica, int liczbaElementow) {
    for (int i = 1; i < liczbaElementow; ++i)
    {
        int j = i;

        while ((j > 0))
        {
            if (tablica[j - 1] > tablica[j])
            {
                tablica[j - 1] ^= tablica[j];
                tablica[j] ^= tablica[j - 1];
                tablica[j - 1] ^= tablica[j];

                --j;
            }
            else
            {
                break;
            }
        }
    }
}

void Sorting::introsort(int* tablica, int liczbaElementow) {
    int rozmiar = Partition(tablica, 0, liczbaElementow - 1);

    if (rozmiar < 16)
    {
        insertionsort(tablica, liczbaElementow);
    }
    else if (rozmiar >(2 * log(liczbaElementow)))
    {
        heapsort(tablica, liczbaElementow);
    }
    else
    {
        Sorting::quicksort(tablica, 0, liczbaElementow - 1);
    }
}

void Sorting::odwracanie(int *tablica, int liczbaElementow)
{
    for (int i = 0; i < liczbaElementow / 2; i++)
    {
        int tmp = tablica[i];
        tablica[i] = tablica[liczbaElementow - i - 1];
        tablica[liczbaElementow - i - 1] = tmp;
    }
}