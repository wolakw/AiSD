//Wojciech Wolak 22i

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(int* S, int n) {              
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
}

int linearSearch1(int* S, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (S[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch1(int* S, int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
            mid = (left + right) / 2;
            if (S[mid] == x)
                return mid;
            if (S[mid] > x)
                right = mid - 1;
            else
                left = mid + 1;
    }
    return -1;
}

int linearSearch2(int* S, int n, int x) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        counter++;
        if (S[i] == x) {
            return counter;
        }
    }
    return counter;
}

int binarySearch2(int* S, int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;
    int counter = 0;
    while (left <= right) {
        counter++;
        mid = (left + right) / 2;
        if (S[mid] == x)
            return counter;
        if (S[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return counter;
}

void init(int* S, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        S[i] = rand() % n;
    }
}

void initSorted(int* S, int n) {
    init(S, n);
    for (int i = 0; i < n; i++) {
        int key = S[i];
        int j = i - 1;
        while (j >= 0 && S[j] > key) {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = key;
    }
}

int interpolationSearch1(int* S, int n, int x) { 
    int left = 0;
    int right = n - 1;
    int mid;
    while ((left <= right) && (x >= S[left]) && (x <= S[right])) {
        mid = left + (x - S[left]) * (right - left) / (S[right] - S[left]);
        if (S[mid] == x)
            return mid;
        if (S[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int interpolationSearch2(int* S, int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;
    int counter = 0;
    while ((left <= right) && (x >= S[left]) && (x <= S[right])) {
        counter++;
        mid = left + (x - S[left]) * (right - left) / (S[right] - S[left]);
        if (S[mid] == x)
            return counter;
        if (S[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return counter;
}

int main()
{
    // Zadanie 1 - test

    /*cout << "Zadanie 1 - test" << endl;        
    int n = 10;
    int* S = new int[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    print(S, n);

    x = 1;
    cout << endl << "Przypadek 1: x na pozycji 0 - " << linearSearch1(S, n, x);
    x = 10;
    cout << endl << "Przypadek 2: x na ostaniej pozycji - " << linearSearch1(S, n, x);
    x = 4;
    cout << endl << "Przypadek 3: x na dowolnej pozycji - " << linearSearch1(S, n, x);
    x = 21;
    cout << endl << "Przypadek 4: x nie wystepuje - " << linearSearch1(S, n, x);*/

    // Zadanie 2 - test

    /*cout << "Zadanie 2 - test" << endl;
    int n = 10;
    int* S = new int[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    print(S, n);

    x = 5;
    cout << endl << "Przypadek 1: x znalezione w pierwszym kroku - " << binarySearch1(S, n, x);
    x = 7;
    cout << endl << "Przypadek 2: x znalezione w ostatnim kroku - " << binarySearch1(S, n, x);
    x = 9;
    cout << endl << "Przypadek 3: x znalezione w dowolnym kroku - " << binarySearch1(S, n, x);
    x = -3;
    cout << endl << "Przypadek 4: x nie wystepuje - " << binarySearch1(S, n, x);*/

    // Zadanie 3 - test

    /*cout << "Zadanie 3 - test" << endl;
    int n = 10;
    int* S = new int[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    print(S, n);
    cout << endl;
    cout << endl << "Testowanie funkcji linearSearch2(int* S, int n, int x) wedlug schematu dla zadania 1" << endl;

    x = 1;
    cout << endl << "Przypadek 1: x na pozycji 0 - " << linearSearch2(S, n, x);
    x = 10;
    cout << endl << "Przypadek 2: x na ostaniej pozycji - " << linearSearch2(S, n, x);
    x = 4;
    cout << endl << "Przypadek 3: x na dowolnej pozycji - " << linearSearch2(S, n, x);
    x = 21;
    cout << endl << "Przypadek 4: x nie wystepuje - " << linearSearch2(S, n, x);

    cout << endl;
    cout << endl << "Testowanie funkcji binarySearch2(int* S, int n, int x) wedlug schematu dla zadania 1" << endl;

    x = 5;
    cout << endl << "Przypadek 1: x znalezione w pierwszym kroku - " << binarySearch2(S, n, x);
    x = 7;
    cout << endl << "Przypadek 2: x znalezione w ostatnim kroku - " << binarySearch2(S, n, x);
    x = 9;
    cout << endl << "Przypadek 3: x znalezione w dowolnym kroku - " << binarySearch2(S, n, x);
    x = -3;
    cout << endl << "Przypadek 4: x nie wystepuje - " << binarySearch2(S, n, x);*/

    // Zadanie 4 - test

    //cout << "Zadanie 4 - test" << endl;
    //
    //int low = 10;           //minimalny rozmiar danych
    //int high = 100000;       //maksymalny rozmiar danych
    //int cnt = 100;          //liczba powtórzeń wyszukiwania dla jednego rozmiaru danych
    //int sum = 0;

    //for (low; low <= high; low *= 10) {
    //    int* S = new int[low];
    //    init(S, low);

    //    for (int i = 0; i < cnt; i++) {
    //        int x = rand() % low;
    //        sum += linearSearch2(S, low, x);
    //    }

    //    int average = sum / cnt;
    //    cout << "Wielkosc tablicy: " << low << "   Srednia ilosc krokow: " << average << endl;
    //    delete S;
    //}

    // Zadanie 5 - test

    /*cout << "Zadanie 5 - test" << endl;
    int n = 10;
    int* S = new int[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    print(S, n);

    x = 1;
    cout << endl << "Przypadek 1: x na pozycji 0 - " << interpolationSearch1(S, n, x);
    x = 10;
    cout << endl << "Przypadek 2: x na ostaniej pozycji - " << interpolationSearch1(S, n, x);
    x = 4;
    cout << endl << "Przypadek 3: x na dowolnej pozycji - " << interpolationSearch1(S, n, x);
    x = 21;
    cout << endl << "Przypadek 4: x nie wystepuje - " << interpolationSearch1(S, n, x);*/

     //Zadanie 6 - test

    cout << "Zadanie 6 - test" << endl;
    int n = 1000;
    int* S = new int[n];
    int x;
    
    cout << endl << "n = " << n << endl;
    
    initSorted(S, n);
    print(S, n);
    cout << endl;
    x = rand() % n;
    cout << "x = " << x;
    cout << endl;
    cout << "Liczba krokow dla wyszukiwania binarnego: " << binarySearch2(S, n, x) << endl;
    cout << "Liczba krokow dla wyszukiwania interpolacyjnego: " << interpolationSearch2(S, n, x) << endl;

    return 0;
}