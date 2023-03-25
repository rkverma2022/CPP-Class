#include <iostream>
using namespace std;

class Node
{
public:
	int degree;
	int coef;
	Node *next;

	Node()
	{
		degree = 0;
		coef = 0;
		next = NULL;
	}

	Node(int coef, int degree)
	{
		this->coef = coef;
		this->degree = degree;
		this->next = NULL;
	}
};

class linkedlist
{
	Node *head;

public:
	linkedlist() { head = NULL; }

	void insert(int coef, int degree)
	{
		Node *newnode = new Node(coef, degree);
		if (head == NULL)
		{
			head = newnode;
			return;
		}
		Node *ptr = head;

		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;

		return;
	}

	linkedlist operator+(linkedlist &poly2)
	{
		linkedlist poly;
		Node *ptr1 = head;
		Node *ptr2 = poly2.head;

		while (ptr1 != NULL && ptr2 != NULL)
		{
			if (ptr1->degree == ptr2->degree)
			{
				poly.insert(ptr1->coef + ptr2->coef, ptr1->degree);
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			else
			{
				if (ptr1->degree > ptr2->degree)
				{
					ptr2 = ptr2->next;
				}
				else
				{
					ptr1 = ptr1->next;
				}
			}
		}

		while(ptr1 != NULL)
		{
			poly.insert(ptr1->coef, ptr1->degree);
			ptr1 = ptr1->next;
		}
		while(ptr2 != NULL)
		{
			poly.insert(ptr2->coef, ptr2->degree);
			ptr2 = ptr2->next;
		}

		return poly;
	}

	void printLL()
	{
		if (head == NULL)
		{
			cout << "----- No polynomial ------" << endl;
		}
		Node *ptr = head;
		while (ptr != NULL)
		{
			cout << ptr->coef << ".x^" << ptr->degree << " +  ";
			ptr = ptr->next;
		}
		cout << endl;
	}
};

int main()
{
	linkedlist poly1;
	bool flag = true;
	while (flag)
	{
		flag = false;
		int coef, degree;
		cout << "Enter the coef and degree: " << endl;
		cin >> coef >> degree;
		poly1.insert(coef, degree);

		cout << "Press 0: Stop add, 1: Add more node" << endl;
		cin >> flag;
	}

	linkedlist poly2;

	bool flag2 = true;
	while (flag2)
	{
		flag2 = false;
		int coef, degree;
		cout << "Enter the coef and degree: " << endl;
		cin >> coef >> degree;
		poly2.insert(coef, degree);

		cout << "Press 0: Stop add, 1: Add more node" << endl;
		cin >> flag2;
	}

	linkedlist poly = poly1 + poly1;

	poly1.printLL();
	poly2.printLL();
	cout<<"      ------ Sum of Polynomials ----------"<<endl;
	poly.printLL();

	return 0;
}
