#include<iostream>
using namespace std;

class MinHeap
{
private:
	int* kopiec; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int size; // Current number of elements in min heap
public:
	MinHeap(int c) {	//tworzy pusty kopiec o pojemności c
		kopiec = new int[c];
		capacity = c;
		size = 0;
	}

	bool empty() {
		return size == 0;
	}

	bool full() {
		return size == capacity;
	}

	int getLeft(int i) {		//zwraca pozycję lewego syna
		return (2 * i + 1);
	}

	int getRight(int i) {		//zwraca pozycję prawego syna
		return (2 * i + 2);
	}

	int getParent(int i) {		//zwraca pozycję ojca
		return (i - 1) / 2; 
	}

	int getSize() {			//zwraca rozmiar kopca
		return size;
	}

	void setSize(int s) {		//ustawia rozmiar kopca na s
		size = s;
	}

	int getValue(int i) {		//zwraca wartość z pozycji i
		if (i < 0 && i > size) {
			return -1;
		}

		else {
			return kopiec[i];
		}
	}

	void setValue(int i, int x) {		//ustawia wartość x na pozycji i
		if (i > 0 && i < size) {
			kopiec[i] = x;
		}
	}

	void bottomUp(int i) {		//przywraca własność kopca metodą wynurzania
		if (i > 0 && i <= size) {
			int p = getParent(i);
			if (kopiec[i] < kopiec[p]) {
				swap(kopiec[i], kopiec[p]);
				bottomUp(p);
			}
		}
	}

	void topDown(int i) {		//przywraca własność kopca metodą zatapiania
		int l = getLeft(i);
		int r = getRight(i);
		int g = i;
		if (l < size && kopiec[l] < kopiec[i]) g = l;
		if (r < size && kopiec[r] < kopiec[g]) g = r;
		if (g != i) {
			swap(kopiec[i], kopiec[g]);
			topDown(g);
		}
	}

	void insert(int x) {		//wstawia element z priorytetem x
		if (full()) {
			cout << x << " nie mozna dodac, kopiec jest pelny" << endl;
			return;
		}
		kopiec[size] = x;
		bottomUp(size);
		size++;
	}

	void deleteMin() {		//usuwa element z minimalną wartością
		if (empty()) cout << "Kopiec jest pusty" << endl;
		size--;
		swap(kopiec[0], kopiec[size]);
		topDown(0);
	}

	int minimum() {		//zwraca minimalną wartość	
		int min = INT_MAX;
		for (int i = 0; i < size; i++) {
			if (kopiec[i] < min) min = kopiec[i];
		}
		return min;
	}

	void del(int i) {		//usuwa element na pozycji i
		if (empty()) cout << "Kopiec jest pusty" << endl;
		size--;
		swap(kopiec[i], kopiec[size]);
		topDown(i);
		bottomUp(i);
	}

	void decreaseKey(int i, int x) {		//zmniejsza wartość na pozycji i, ustawia x   
		kopiec[i] = x;
		int pom = i;
		while (i != 0 && kopiec[getParent(i) > kopiec[i]]) {
			swap(kopiec[i], kopiec[getParent(i)]);
			i = getParent(i);
		}
		bottomUp(0);
		topDown(0);
	}

	friend std::ostream& operator<<(std::ostream& out, MinHeap& h) {
		cout << endl << "Kopiec: [ ";
		for (int i = 0; i <= h.getSize() - 1; i++) {
			out << h.getValue(i) << " ";
		}
		cout << "]" << endl;
		return out;
	}
};

int main(int argc, char** argv)
{
	MinHeap h(8);

	cout << endl << "Zadanie 1 - test" << endl;

	cout << endl << "empty() - " << h.empty();
	cout << endl << "full() - " << h.full();
	cout << endl << "insert 21 "; h.insert(21);
	cout << endl << "insert 5 "; h.insert(5);
	cout << endl << "insert 16 "; h.insert(16);
	cout << endl << "insert 9 "; h.insert(9);
	cout << endl << "insert 8 "; h.insert(8);
	cout << endl << "insert 6 "; h.insert(6);
	cout << endl << "insert 19 "; h.insert(19);
	cout << endl << "insert 12 "; h.insert(12);
	cout << endl << "empty() - " << h.empty();
	cout << endl << "full() - " << h.full();
	cout << h;

	cout << endl << "Wartosc minimalna - " << h.minimum();

	cout << endl << "Ustawienie wartosci 1 na indeksie 0"; h.decreaseKey(0, 1);
	cout << endl << "Wartosc minimalna - " << h.minimum();
	cout << h;

	cout << endl << "Usuniecie najmniejszej wartosci"; h.deleteMin();
	cout << h;

	cout << endl << "Usuniecie najmniejszej wartosci"; h.deleteMin();
	cout << h;

	cout << endl << "insert 3 "; h.insert(3);
	cout << endl << "insert 10 "; h.insert(10);
	cout << h;

	cout << endl << "Usuniecie wartosci na indeksie 7"; h.del(7);
	cout << h;

	cout << endl << "insert 7 "; h.insert(7);
	cout << h;

	return 0;
}