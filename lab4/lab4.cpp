#include <iostream>
using namespace std;

class Element {
    private:
        int v;
        Element* next;
        Element* prev;

    public:
        Element() {    //tworzy pusty element
            this->v = 0;
            this->next = NULL;
            this->prev = NULL;
        }

        Element(int x, Element* next, Element* prev) { //tworzy element przechowujący x
            this->v = x;
            this->next = next;
            this->prev = prev;
        }

        int getValue() { //zwraca wartość
            return this->v;
        }

        void setValue(int v) { //ustawia wartość v
            this->v = v;
        }

        Element* getNext() { //zwraca pozycję następnego elementu
            return this->next;
        }

        Element* getPrev() { //zwraca pozycję poprzedniego elementu
            return this->prev;
        }

        void setNext(Element* p) { //ustawia p jako następny element
            this->next = p;
        }

        void setPrev(Element* p) { //ustawia p jako poprzedni element
            this->prev = p;
        }
};

class LinkedList {
    private:
        Element* head;
        Element* tail;
        int size;

    public:
        LinkedList() { //tworzy pustą listę
            for (int i = 1; i < size; i++) 
                new Element();
        }

        bool empty() { //zwraca prawdę jeśli lista pusta, fałsz w przeciwnym przypadku
            if (head == NULL) return true;
            else return false;
        }

        int getSize() { //zwraca wielkość listy (liczbę elementów w liście)
            return size;
        }

        Element* getFirst() { //zwraca pozycję (wskaźnik do) pierwszego elementu listy
            if (empty()) error: "Lista jest pusta";
            return head;
        }

        Element* getLast() { //zwraca pozycję (wskaźnik do) ostatniego elementu listy
            if (empty()) error: "Lista jest pusta";
            return tail;
        }

        Element* getNext(Element* p) { //zwraca pozycję (wskaźnik do) następniego elementu listy
            if (empty()) error: "Lista jest pusta";
            return getNext(p);
        }

        Element* getPrev(Element* p) { //zwraca pozycję (wskaźnik do) poprzedniego elementu listy
            if (empty()) error: "Lista jest pusta";
            return getPrev(p);
        }

        int retrive(Element* p) { //zwraca element (wartość) z pozycji (wskazywanej przez) p
            if (empty()) error: "Lista jest pusta";
            p = head;
        }

        void append(int x) { //wstawia element z x na końcu listy
            Element* newElement = new Element();
            newElement->setValue(x);
            if (this->empty())
                this->head = newElement;
            else {
                this->tail->setNext(newElement);
                newElement->setPrev(this->tail);
            }
            this->tail = newElement;
            this->size++;
        }

        void preppend(int x) { //wstawia element z x na początku listy
            Element* newElement = new Element();
            newElement->setValue(x);
            if (this->empty())
                this->tail = newElement;
            else {
                newElement->setPrev(this->head);
                this->tail->setNext(newElement);
            }
            this->head = newElement;
            this->size++;
        }

        //void insert(Element* p, int x) {              //wstawia element z wartością x na pozycję (wskazywaną przez) p
        //    p = head;
        //    while (getNext(p) != p)
        //}

        //void del(Element* p) {                            //usuwa element z pozycji (wskazywaniej przez) p 
        //    if (p == getFirst()) {
        //        head = head->n
        //    }

        //}

        void clear() {                    //usuwa całą listę
        
        }

        //friend ostream& operator<<(ostream& out, LinkedList* l) { //wypisuje elementu listy
        //    for (int i = 0; i < l->getSize(); i++) {
        //        out << l->retrive(i) << " ";
        //    cout << endl;
        //    return out;
        //    }
        //}

        /*void show() {
            for (int i = 0; i < getSize(); i++) {
                cout << retrive(i) << " ";
            }
        }*/

        ~LinkedList() {

        }
};

int main()
{
    //Zadanie 1 - test
    cout << endl << "Zadanie 1 - test" << endl;
    {
        LinkedList* a = new LinkedList();
        cout << endl << "empty(): 1 - " << a->empty();
        cout << endl << "getSize():  0 - " << a->getSize();
        /*cout << endl << "append(4): 4 - "; a->append(4); cout << " " << *a;*/
        
    }
}