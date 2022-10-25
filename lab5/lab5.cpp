#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* items;
    int capacity;        //pojemność stosu
    int top;                //wierzchołek stosu
public:
    ArrayStack(int c) {    //tworzy pusty stos o pojemności c
        items = new int[c];
        capacity = c;
        top = -1;
    }

    bool empty() {
        if (top == -1) return true;
        else return false;
    }

    bool full() {
        if (top == capacity - 1) return true;
        else return false;
    }

    bool push(int x) {
        if (top < capacity - 1) {
            top++;
            items[top] = x;
            return true;
        }
        else return false;
    }

    int peek() {            //zwraca daną ze stosu
        return items[top];
    }

    bool pop() {            //usuwa daną ze stosu
        if (top == -1) {
            return false;
        }
        else {
            items[top] = 0;
            top--;
            return true;
        }
    }

    void clear() {
        do {
            items[top] = 0;
            top--;
        } while (top != -1);
    }

    friend ostream& operator<<(ostream& out, ArrayStack& s) {  //wyświetla całą zawartość stosu
        for (int i = 0; i <= s.top; i++) {
            out << s.items[i] << " ";
        }
        return out;
    }

    ~ArrayStack() {
        delete[] items;
    }
};

int main()
{
    ArrayStack s(6);
    cout << "empty(): 1 - " << s.empty() << endl;
    //cout << "push(4): 4 - " << endl;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(1);
    s.push(7);
    cout << s;

    cout << "empty(): 1 - " << s.empty() << endl;
    s.pop();
    s.pop();
    s.push(10);
    s.push(21);
    cout << s;

    s.clear();
    cout << s;

    return 0;
}