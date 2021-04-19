#include <iostream>
using namespace std;

struct emp
{
    struct emp *prev;
    int eno;
    struct emp *next;
};

typedef struct emp node;
node *head, *tail;

void myadd()
{
    node *t;
    t = new node;
    cout << "\nEnter empno :";
    cin >> t->eno;
    if (head == NULL)
    {
        t->next = t;
        t->prev = t;
        head = t;
    }
    else
    {
        tail->next = t;
        t->prev = tail;
        t->next = head;
        t->prev = tail;
    }
    tail = t;
}

void print(node *p)
{
    cout << " " << p->eno;
}

void anti(node *r, node *p)
{
    do
    {
        print(p);
        p = p->prev;
    } while (p != r);
}

void clock(node *r, node *p)
{
    do
    {
        print(p);
        p = p->next;
    } while (p != r);
}

void find()
{
    node *p, *r;
    int ch, bulb = 0, find;
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    cout << "\nEnter a no to find :";
    cin >> find;
    p = head;
    do
    {
        if (p->next->eno == find)
        {
            bulb = 1;
            break;
        }
        p = p->next;
    } while (p != head);

    if (bulb == 0)
    {
        cout << "\nEmployee no not found :";
        return;
    }

    r = p;

    cout << "\n1.Anti clockwise"
         << "\n2.Clockwise"
         << "\nEnter choice :";
    cin >> ch;
    if (ch == 1)
        anti(r, p);
    else
        clock(r, p);
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
             << "\n3.Exit"
             << "\nEnter choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
            myadd();
            break;
        case 2:
            find();
            break;
        case 3:
            exit(1);
        }
    }
}
