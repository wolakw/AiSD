//Wojciech Wolak 22i

#include <iostream>
using namespace std;

class ArrayList {
    private:
        int* items;
        int head;            //pozycja pierwszego elementu
        int tail;           //pozycja ostatniego elementu
        int capacity;       //rozmiar tablicy
        int size;            //długość listy (liczba elementów w liście)

    public:
        ArrayList(int c) {      //tworzy pustą listę o pojemności c
            items = new int[c];
            capacity = c;
            head = 0;
            tail = 0;
            size = 0;
        }

        bool empty() {          //zwraca prawdę jeśli lista pusta, fałsz w przeciwnym przypadku
            return tail == 0;
        }

        bool full() {           //zwraca prawdę jeśli lista jest pełna, fałsz w przeciwnym przypadku
            return getSize() == getCapacity();
        }

        int getSize() {         //zwraca wielkość listy (liczbę elementów w liście)
            return size;
        }

        int getCapacity() {         //zwraca pojemnośc listy (rozmiar tablicy)
            return capacity;
        }

        int getFirst() {        //zwraca pozycję pierwszego elementu
            if (empty())
                return -1;
            else
                return head;
        }

        int getLast() {         //zwraca pozycję ostatniego elementu
            if (empty())
                return -1;
            else
                return tail - 1;
        }

        int getNext(int p) {       //zwraca pozycję elementu następnego za p
            if (empty() || p < getFirst() || p >= getLast())
                return -1;
            else
                return items[p + 1];
        }

        int getPrev(int p) {        //zwraca pozycję elementu poprzedzającego p
            if (empty() || p <= getFirst() || p > getLast())
                return -1;
            else
                return items[p - 1];
        }

        int retrieve(int p) {       //zwraca element (wartość) z pozycji p
            if (empty() || p < getFirst() || p > getLast())
                return -1;
            else
                return items[p];
        }

        void append(int x) {        //wstawia element x na końcu listy
            if (full() != 1) {

                items[tail] = x;
                tail++;
                size++;
            }
        }

        void preppend(int x) {      //wstawia element x na początku listy
            if (full() != 1) {
                int l = getLast() + 1;
                while (l >= 1) {
                    items[l] = items[l - 1];
                    l--;
                }
                tail++;
                size++;
                items[0] = x;
            }
        }

        bool insert(int p, int x) {     //wstawia element x na pozycję p, zwraca false jeśli p nie jest legalną pozycją
            if (p<getFirst() || p>getLast() || full() == 1)
                return false;
            else {
                tail++;
                size++;

                for (int i = getLast(); i > p; i--)
                    items[i] = items[i - 1];

                items[p] = x;
                return true;
            }
        }

        bool del(int p) {       //usuwa element z pozycji p, zwraca false jeśli p nie jest legalną pozycją 
            if (p<getFirst() || p>getLast())
                return false;
            else {
                for (int i = p; i < getLast(); i++)
                    items[i] = items[i + 1];

                tail--;
                size--;
                return true;
            }
        }     

        void clear() {      //usuwa całą zawartość listy
            for (int i = getFirst(); i <= getLast(); i++)
                items[i] = 0;
            
            head = 0;
            tail = 0;
            size = 0;
        }

        friend ostream& operator<<(ostream& out, ArrayList& l) {
            cout << "Lista: ";
            for (int i = 0; i <= l.getLast(); i++) {
                out << l.retrieve(i) << " ";
            }
            cout << endl;
            return out;
        }

        int locate(int x) {         //zwrac pozycję pierwszego wystąpienia elementu x, -1 jeśli x nie występuje
            for (int i = 0; i < size; i++)
                if (items[i] == x)
                    return i;
            return -1;
        }

        bool deleteX(int x) {        //usuwa pierwsze wystąpienie elementu o wartości x i zwraca true jeśli element istniał, false jeśli nie
            for (int i = 0; i < size; i++)
                if (items[i] == x) {
                    del(i);
                    return true;
                }
            return false;
        }

        int deleteAllX(int x) {      //usuwa wszystkie wystąpienia elementu o wartości x i zwraca ich liczbę
            int counter = 0;
            for (int i = 0; i < size; i++)
                if (items[i] == x) {
                    del(i);
                    counter++;
                }
            return counter;
        }

        bool concat(ArrayList& l) {  // na końcu bieżącej listy dołącza zawartość listy l, zwraca false jeśli dołączenie nie jest możliwe
            if (size + l.getSize() <= capacity) {
                for (int i = 0; i < l.getSize(); i++)
                    append(l.retrieve(i));
                return true;
            }
            else
                return false;
        }

        ~ArrayList() {
            delete[] items;
        }
};

class SortedArrayList : ArrayList {
    public:
        SortedArrayList(int c) : ArrayList(c) {};

        void insertSorted(int x) {
            if (!empty()) {
                for (int i = 0; i < getSize(); i++) {
                    if (x <= retrieve(i)) {
                        insert(i, x);
                        return;
                    }
                }
                append(x);
            }
            else
                append(x);
            return;
        }

        friend ostream& operator<<(ostream& out, SortedArrayList& l) {
            cout << "Lista: ";
            for (int i = 0; i <= l.getLast(); i++)
                out << l.retrieve(i) << " ";
            cout << endl;
            return out;
        }
};

int main() {
    cout << "Zadanie 1 - test" << endl;
    {
        ArrayList a(5);
        cout << endl << "Czy pusta?: " << a.empty() << endl;
        cout << endl << a;
        a.append(3);
        cout << endl << "Czy pusta?: " << a.empty() << endl;
        cout << endl << a;
        cout << endl << "Czy pelna?: " << a.full() << endl;
        cout << endl << "Rozmiar: " << a.getSize() << endl;
        a.preppend(8);
        a.append(7);
        a.append(9);
        a.preppend(2);
        a.append(5);
        cout << endl << a;
        cout << endl << "Czy pelna?: " << a.full() << endl;
        cout << endl << "Rozmiar: " << a.getSize() << endl;
        cout << endl << "Pojemnosc: " << a.getCapacity() << endl;
        cout << endl << "Pierwszy: " << a.getFirst() << endl;
        cout << endl << "Ostatni: " << a.getLast() << endl;
        cout << endl << "Nastepny po 0: " << a.getNext(0) << endl;
        cout << endl << "Poprzedni przed 1: " << a.getPrev(1) << endl;
        cout << endl << "Wartosc z 3: " << a.retrieve(3) << endl;
        a.del(3);
        cout << endl << a;
        a.insert(3, 21);
        cout << endl << a;
        cout << endl << "Wartosc z 3: " << a.retrieve(3) << endl;
        cout << endl << "Nastepny po 2: " << a.getNext(2) << endl;
        a.clear();
        cout << endl << "Pojemnosc: " << a.getCapacity() << endl;
        cout << endl << "Rozmiar: " << a.getSize() << endl;
        cout << endl << "Czy pusta?: " << a.empty() << endl;
        cout << endl;
    }

    cout << endl << "Zadanie 2 - test" << endl;
    {
        ArrayList b(6);
        b.append(9);
        b.append(3);
        b.append(1);
        /*b.append(5);*/
        b.append(4);
        b.append(1);
        cout << endl << b;
        cout << endl << "Pierwsze wystapienie x jest na pozycji: " << b.locate(1) << endl;
        cout << endl << "Usuniecie pierwszego wystepujacego 1 - " << b.deleteX(1) << endl;
        cout << endl << b;
        cout << endl << "Wstawienie 1 na pozycje 1 - " << b.insert(1, 1) << endl;
        cout << endl << b;
        cout << endl << "Wstawienie 1 na pozycje 1 - " << b.insert(1, 1) << endl;
        cout << endl << b;
        cout << endl << "Usuniecie wszytkich 1 - " << b.deleteAllX(1) << endl;
        cout << endl << b;
    
        ArrayList lista1(2);
        lista1.append(34);
        lista1.append(56);
        cout << endl << "nr.1 " << lista1;

        ArrayList lista2(5);
        lista2.append(2);
        lista2.append(1);
        lista2.append(6);
        cout << endl << "nr.2 " << lista2 << endl;
        cout << "Dodanie listy 1 do listy 2 - " << lista2.concat(lista1) << endl;
        cout << endl << "nr.2 " << lista2;

        ArrayList lista3(3);
        lista3.append(21);
        lista3.append(13);
        cout << endl << "nr.3: " << lista3 << endl;
        cout << "Dodanie listy 1 do listy 3 - " << lista3.concat(lista1) << endl;
        cout << endl << "nr.3: " << lista3 << endl;
    }

    cout << endl << "Zadanie 3 - test" << endl;
    {
        SortedArrayList c(5);
        c.insertSorted(10);
        cout << endl << c ;
        c.insertSorted(2);
        cout << endl << c;
        c.insertSorted(15);
        cout << endl << c;
        c.insertSorted(11);
        cout << endl << c;
        c.insertSorted(5);
        cout << endl << c;
    }
}