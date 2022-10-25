#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//Zadanie 1
int divSum(int liczba) {
    int suma=0;
    for (int i = 1; i < liczba; i++) {
        if (liczba % i == 0)
            suma += i;
    }
    return suma;
}

//Zadanie 2
bool isPerfect(int liczba) {
    if (divSum(liczba) == liczba)
        return true;
    else
        return false;
}

//Zadanie 3
void allPerfect(int low, int high) {
    if (low > high) swap(low, high);
    for (int i = low; i <= high; i++) {
        if (isPerfect(i)) cout << i << "\n";
    }
}

//Zadanie 4
bool areAmicable(int n, int m) {
    if (divSum(n) == m && divSum(m) == n)
        return true;
    else
        return false;
}

//Zadanie 5
void allAmicable(int low, int high) {
    if (low > high) swap(low, high);
    for (int i = low; i <= high; i++) {
        for (int j = i + 1; j <= high; j++) {
            if (areAmicable(i, j))
                cout << endl << i << " " << j;
        }
    }
}

int main(int argc, char** argv) {
    cout << endl << "Zadanie 1 - test" << endl;
    cout << endl << "suma dzielnikow 15 = " << divSum(15) << endl;
    cout << endl << "suma dzielnikow 17 = " << divSum(17) << endl;
    cout << endl << "Zadanie 2 - test" << endl << isPerfect(6) << endl;
    cout << endl;
    cout << endl << areAmicable(220,284) << endl;
    cout << endl;
    cout << endl << areAmicable(1185, 1209) << endl;
    cout << endl;
    cout << endl << areAmicable(1184, 1210) << endl;
    cout << endl;
    allPerfect(1, 8196);
    clock_t poczatek = clock();
    allAmicable(200, 2000);
    clock_t koniec = clock();
    double wynik = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
    cout << endl;
    cout << endl << wynik << endl;
    return 0;
}