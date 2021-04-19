#include <iostream>
using namespace std;

struct emp
{
    int empno;
    struct emp *next;
};
typedef struct emp node;
node *head, *tail;

void input(node *p)
{
    cout << "\nEnter empno:";
    cin >> p->empno;
    p->next = NULL;
}

void myadd()
{
    node *t;
    t = new node;
    input(t);
    if (head == NULL)
        head = t;
    else
        tail->next = t;
    tail = t;
}

void print(node *p)
{
    cout << " " << p->empno;
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

void reverse()
{
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    node *p, *prev, *next;
    p = head;
    prev = NULL;
    next = NULL;
    while (p != NULL)
    {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    head = prev;
    for (p = head; p != NULL; p = p->next)
        print(p);
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
             << "\n4.Reverse"
             << "\n5.Exit"
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
            reverse();
            break;
        case 5:
            exit(1);
        }
    }
}
