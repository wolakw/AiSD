#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node(int v, Node* l, Node* r, Node* p);
    int getValue();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setValue(int v);
    void setLeft(Node* l);
    void setRight(Node* r);
    void setParent(Node* p);
};

class BSTree {
private:
	Node* root;
public:
	BSTree();                        //tworzy puste drzewo
	Node* getRoot();            //zwraca wskażnik do root - metoda pomocnicza w testowaniu
	bool empty(Node* p);        //zwraca prawdę gdy drzewo jest puste
	void inorder(Node* p);
	void insert(int x);            //wstawia węzeł z wartością x
	Node* search(int x);         //zwraca wskaźnik do węzła z wartością x (lub NULL jeśli nie istnieje)
	Node* minimum();            //zwraca wskaźnik do węzła z minimalną wartością
	Node* maximum();            //zwraca wskaźnik do węzła z maksymalną wartością
	Node* successor(Node* p);    //zwraca wskaźnik do nastęnika p
	Node* predecessor(Node* p);    //zwraca wskaźnik do poprzednika p
	void del(Node* p);            //usuwa węzeł wskazywany przez p
	int size(Node* p);                  //zwraca rozmiar drzewa
	int hight(Node* p);              //zwraca wysokość drzewa
	void clear(Node* p);           //usuwa wszystkie węzły z drzewa
};

Node::Node(int v = -1, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr) : value(v), left(l), right(r), parent(p) {}

int Node::getValue()
{
	return value;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

Node* Node::getParent()
{
	return parent;
}

void Node::setValue(int v)
{
	value = v;
}

void Node::setLeft(Node* l)
{
	left = l;
}

void Node::setRight(Node* r)
{
	right = r;
}

void Node::setParent(Node* p)
{
	parent = p;
}

BSTree::BSTree() :root(nullptr) {}		//tworzy puste drzewo

Node* BSTree::getRoot()		//zwraca wskażnik do root - metoda pomocnicza w testowaniu
{
	return root;
}

bool BSTree::empty(Node* p)		//zwraca prawdę gdy drzewo jest puste
{
	if (p == nullptr) return true;
	return false;
}

void BSTree::inorder(Node* p)
{
	if (!empty(p))
	{
		inorder(p->getLeft());
		cout << p->getValue() << " ";
		inorder(p->getRight());
	}
}

void BSTree::insert(int x)		 //wstawia węzeł z wartością x
{
	Node* e = new Node{ x };
	Node* p = root;
	if (empty(root))
	{
		root = e;
		return;
	}
	else
	{
		bool cont = true;

		while (cont)
		{
			if (p->getValue() > x)
			{
				if (!empty(p->getLeft()))
				{
					p = p->getLeft();
				}
				else
				{
					p->setLeft(e);
					e->setParent(p);
					cont = false;
				}
			}
			else if (p->getValue() < x)
			{
				if (!empty(p->getRight()))
				{
					p = p->getRight();
				}
				else
				{
					p->setRight(e);
					e->setParent(p);
					cont = false;
				}
			}
		}
	}
}

Node* BSTree::search(int x)		//zwraca wskaźnik do węzła z wartością x (lub NULL jeśli nie istnieje)
{
	if (root->getValue() == x)
	{
		return root;
	}

	Node* e = root;

	while (!empty(e))
	{
		if (e->getValue() > x)
		{
			e = e->getLeft();
		}
		else
		{
			e = e->getRight();
		}
		if (!empty(e))
		{
			if (e->getValue() == x)
			{
				return e;
			}
		}
	}
	return nullptr;
}

Node* BSTree::minimum()		//zwraca wskaźnik do węzła z minimalną wartością
{

	Node* e = root;
	while (!empty(e->getLeft()))
	{
		e = e->getLeft();
	}
	return e;
}

Node* BSTree::maximum()		//zwraca wskaźnik do węzła z maksymalną wartością
{
	Node* e = root;
	while (!empty(e->getRight()))
	{
		e = e->getRight();
	}
	return e;
}

Node* BSTree::successor(Node* p)		//zwraca wskaźnik do nastęnika p
{
	Node* e = p;

	if (!empty(e))
	{
		if (!empty(e->getRight()))
		{
			e = e->getRight();
			while (!empty(e->getLeft()))
			{
				e = e->getLeft();
			}
			return e;
		}
		else
		{
			Node* n = e->getParent();
			while (!empty(n) && e == n->getRight())
			{
				e = n;
				n = n->getParent();
			}
			return n;
		}
	}
	else
	{
		return nullptr;
	}
}

Node* BSTree::predecessor(Node* p)		 //zwraca wskaźnik do poprzednika p
{
	Node* e = p;

	if (!empty(e))
	{
		if (!empty(e->getLeft()))
		{
			e = e->getLeft();
			while (!empty(e->getRight()))
			{
				e = e->getRight();
			}
			return e;
		}
		else
		{
			Node* n = e->getParent();
			while (!empty(n) && e == n->getLeft())
			{
				e = n;
				n = n->getParent();
			}
			return n;
		}
	}
	else
	{
		return nullptr;
	}
}

void BSTree::del(Node* p)		//usuwa węzeł wskazywany przez p
{

	if (!empty(p))
	{
		if (empty(p->getLeft()) && empty(p->getRight())) // węzeł jest liściem
		{
			Node* e = p->getParent();
			if (empty(e))
			{
				root = nullptr;
			}
			else
			{
				if (e->getLeft() == p)
				{
					e->setLeft(nullptr);
				}
				else
				{
					e->setRight(nullptr);
				}
			}
			delete p;
			p = nullptr;
		}
		
		else if ((empty(p->getLeft()) && !empty(p->getRight())) || (!empty(p->getLeft()) && empty(p->getRight()))) // węzeł ma jedno dziecko
		{
			Node* r;
			if (empty(p->getLeft()))
			{
				r = p->getRight();
			}
			else
			{
				r = p->getLeft();
			}
			Node* e = p->getParent();
			if (empty(e))
			{
				root = r;
			}
			else
			{
				if (e->getLeft() == p)
				{
					e->setLeft(r);
				}
				else
				{
					e->setRight(r);
					r->setParent(e);
				}
			}
			delete p;
			p = nullptr;
		}
		
		else if (!empty(p->getLeft()) && !empty(p->getRight())) // węzel ma 2 dzieci
		{

			Node* pre = predecessor(p);
			p->setValue(pre->getValue());
			Node* parent = pre->getParent();

			if (parent->getLeft() == pre)
			{
				parent->setLeft(pre->getLeft());
			}
			else 
			{
				parent->setRight(pre->getLeft());
			}

			delete pre;
			pre = nullptr;
		}
	}
}

int BSTree::size(Node* p)		//zwraca rozmiar drzewa
{
	if (empty(p))
	{
		return 0;
	}
	else
	{
		return (1 + size(p->getLeft()) + size(p->getRight()));
	}
}

int BSTree::hight(Node* p)		//zwraca wysokość drzewa
{
	if (empty(p))
	{
		return -1;
	}
	else
	{
		return (1 + (max(hight(p->getLeft()), hight(p->getRight()))));
	}
}

void BSTree::clear(Node* p)		//usuwa wszystkie węzły z drzewa

{
	if (!empty(p))
	{
		clear(p->getLeft());
		clear(p->getRight());
		del(p);
		if (!empty(p->getLeft()))
		{
			p->setLeft(nullptr);
		}
		if (!empty(p->getRight()))
		{
			p->setRight(nullptr);
		}
		p = nullptr;
	}
}

int main()
{
	cout << endl << "Zadanie 1 - test" << endl;

	BSTree* t = new BSTree();
	Node* parent;
	Node* pom;

	cout << endl;
	t->inorder(t->getRoot());
	cout << "insert(7)" << endl; t->insert(7);
	parent = t->getRoot();
	cout << "inorder: "; t->inorder(parent); cout << endl;
	cout << "insert(1)" << endl; t->insert(1);
	cout << "insert(6)" << endl; t->insert(6);
	cout << "insert(5)" << endl; t->insert(5);
	cout << "inorder: "; t->inorder(parent); cout << endl;
	cout << "search(7):"; pom = t->search(7); cout << pom->getValue() << endl;
	cout << "search(10): "; pom = t->search(10); cout << pom << endl;
	cout << "minimum(): "; pom = t->minimum(); cout << pom->getValue() << endl;
	cout << "maximum(): "; pom = t->maximum(); cout << pom->getValue() << endl;
	cout << "insert(12)" << endl; t->insert(12);
	cout << "insert(3)" << endl; t->insert(3);
	cout << "insert(21)" << endl; t->insert(21);
	cout << "inorder: "; t->inorder(parent); cout << endl;
	cout << "successor(3): "; pom = t->successor(t->search(3)); cout << pom->getValue() << endl;
	cout << "successor(10): "; pom = t->successor(t->search(10)); cout << pom << endl;
	cout << "predecessor(21): "; pom = t->predecessor(t->search(21)); cout << pom->getValue() << endl;
	cout << "predecessor(30): "; pom = t->predecessor(t->search(30)); cout << pom << endl;
	cout << "del(12)"; t->del(t->search(12)); cout << endl;
	cout << "inorder: "; t->inorder(parent); cout << endl;
	cout << "del(1)"; t->del(t->search(1)); cout << endl;
	cout << "inorder: "; t->inorder(parent); cout << endl;
	cout << "size: " << t->size(t->getRoot()) << endl;
	cout << "inorder: "; t->inorder(t->getRoot()); cout << endl;
	cout << "height: " << t->hight(parent) << endl;
	cout << "clear"; t->clear(t->getRoot()); cout << endl;

	return 0;
}