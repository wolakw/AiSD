#include <iostream>
using namespace std;

class Element {
private:
    int v;
    Element* next;
public:
    Element(int x, Element* next) {
        this->v = x;
        this->next = next;
    }

    int getValue() {
        return this->v;
    }

    Element* getNext() {
        return this->next;
    }

    void setNext(Element* p) {
        this->next = p;
    }
};

class LinkedStack {
private:
    Element* top;
public:
    LinkedStack() {        //tworzy pusty stos
        this->top = nullptr;
    }
    
    bool empty() {
        if (top == nullptr)
            return true;
        return false;
    }

    bool push(int x) {
        Element* e = new Element(x, top);
        this->top = e;
        return true;
    }

    int peek() {            //zwraca daną ze stosu
        if (this->empty()) {
            cout << "stos pusty";
            return NULL;
        }
        return this->top->getValue();
    }
    
    bool pop() {            //usuwa element ze stosu
        if (this->empty()) {
            cout << "lista pusta";
            return false;
        }
        Element* e = top;
        top = top->getNext();
        delete e;
        return true;
    }
    
    void clear() {
        if (this->empty()) {
            cout << "stos pusty";
            return;
        }
        Element* temp = this->top;
        while (this->top) {
            temp = this->top;
            this->top = this->top->getNext();
            delete temp;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, LinkedStack* s) { //wyświetla zawartość całego stosu
        Element* temp = s->top;
        while (temp) {
            out << temp->getValue() << " ";
            temp = temp->getNext();
        }
        return out;
    }
    
    ~LinkedStack() {

    }
};

int main()
{
    
}