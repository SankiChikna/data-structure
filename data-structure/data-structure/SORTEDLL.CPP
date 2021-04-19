#include <iostream>
using namespace std;

struct emp
{
	int empno;
	char name[20];
	int sal;
	struct emp *next;
};
typedef struct emp node;
node *head, *tail;

void input(node *p)
{
	cout << "\nEnter empno name salary:";
	cin >> p->empno >> p->name >> p->sal;
	p->next = NULL;
}
void myadd()
{
	int bulb = 0;
	node *t, *f;
	t = new node;
	input(t);
	if (head == NULL)
	{
		tail = t;
		head = t;
		return;
	}
	if (head->empno > t->empno)
	{
		t->next = head;
		head = t;
		return;
	}
	for (f = head; f->next != NULL; f = f->next)
	{
		if (f->next->empno > t->empno)
		{
			t->next = f->next;
			f->next = t;
			bulb = 1;
			break;
		}
	}
	if (bulb == 0)
	{
		tail->next = t;
		tail = t;
	}
}

void print(node *p)
{
	cout << "\nEmpno :" << p->empno
		 << "\nName :" << p->name
		 << "\nSalary :" << p->sal;
}

void mylist()
{
	node *t;
	if (head == NULL)
	{
		cout << "\nQueue is empty";
		return;
	}
	for (t = head; t != NULL; t = t->next)
		print(t);
}

void mydel()
{
	if (head == NULL)
	{
		cout << "\nQueue is empty";
		return;
	}
	node *t;
	t = head->next;
	delete head;
	head = t;
	cout << "\nElement deleted";
}

int main()
{
	node *x;
	int n;
	int ch;
	while (1)
	{
		cout << "\n1.Add"
			 << "\n2.List"
			 << "\n3.Delete"
			 << "\n4.Exit"
			 << "\nEnter choice :";
		cin >> ch;
		switch (ch)
		{
		case 1:
			myadd();
			break;
		case 2:
			mylist();
			break;
		case 3:
			mydel();
			break;
		case 4:
			exit(1);
		}
	}
}
