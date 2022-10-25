#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    string* t;
    int capacity;
    int size;
public:
    HashTable(int c) {                //konstruktor tworzący pustą tablicę o pojemności c
        t = new string[c];
        capacity = c;
        size = 0;
    }
    
    bool empty() {
        if (size == 0)return true;
        else return false;
    }

    bool full() {
        if (size == capacity) return true;
        else return false;
    }

    int hashFunction(string s) {        //funkcja haszująca dla klucza s
        unsigned int h = 0;

        for (int i = 0; i < s.length(); i++) {
            h = 2 * h + 1 - (s[i] & 1);
        }
        return h % 10;
    }

    int insert(string s) {            //wstawienie klucza s (zwraca liczbę prób przy wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła)
    
    }

    void del(string s);                //usuwa klucz s
    string search(string s);        //wyszukuje i zwraca s
    int search1(string s);            //wyszukuje s i zwraca liczbę prób przy wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła
    friend ostream& operator<<(ostream& out, HashTable& ht); //wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól
};

int main()
{
    
}