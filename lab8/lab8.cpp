#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void print(int* S, int n) {     //wyświetla dane
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
}

void init(int* S, int n) {      //generuje losowe dane
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        S[i] = rand() % n + 1;
    }
}

void insertionSort(int* S, int n) {
    int aux, j;
    for (int i = 1; i < n; i++) {
        aux = S[i];
        j = i - 1;
        while (j >= 0 && S[j] > aux) {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = aux;
    }
}

void selectionSort(int* S, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (S[j] < S[min])
                min = j;
        }
        swap(S[i], S[min]);
    }
}

void bubbleSort(int* S, int n) {
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n; j++) {
            if (S[j - 1] > S[j])
                swap(S[j - 1], S[j]);
        }
    }
}

void quickSort(int* S, int left, int right)
{
    if (right <= left) return;
    
    int i = left - 1, j = right + 1,
    pivot = S[(left + right) / 2]; 

    while (1)
    {
        while (pivot > S[++i]);

        while (pivot < S[--j]);

        if (i <= j)
            swap(S[i], S[j]);
        else
            break;
    }

    if (j > left)
        quickSort(S, left, j);
    if (i < right)
        quickSort(S, i, right);
}

//int main()
//{
//    cout << "Zadanie 1 - test" << endl;
//    int n = 100;
//    int* S = new int[n];
//
//    init(S, n);
//    print(S, n);
//    cout << endl;
//    cout << endl;
//    //insertionSort(S, n);
//    //selectionSort(S, n);
//    //bubbleSort(S, n);
//    quickSort(S, 0, n - 1);
//    print(S, n);
//    delete[] S;
//}

int main()
{
    cout << "Zadanie 2 - test" << endl;
    int n = 20000;
    int* S = new int[n];
    int* S2 = new int[n];
    int* S3 = new int[n];
    int* S4 = new int[n];
    init(S, n);

    for (int i = 0; i < n; i++) {
        S2[i] = S[i];
    }

    for (int i = 0; i < n; i++) {
        S3[i] = S[i];
    }

    for (int i = 0; i < n; i++) {
        S4[i] = S[i];
    }

    //print(S, n);

    clock_t start = clock();
    insertionSort(S, n);
    clock_t end = clock();
    double result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl << "Czas inserionSort " << result_time << " s" << endl;

    start = clock();
    selectionSort(S2, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl << "Czas selectionSort: " << result_time << " s" << endl;

    start = clock();
    bubbleSort(S3, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl << "Czas bubbleSort: " << result_time << " s" << endl;

    start = clock();
    quickSort(S, 0, n - 1);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    //print(S, n);
    cout << endl << "Czas quickSort: " << result_time << " s" << endl;

    delete[] S;
    delete[] S2;
    delete[] S3;
    delete[] S4;
}