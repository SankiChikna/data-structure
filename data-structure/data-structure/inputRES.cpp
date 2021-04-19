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

// void input(node *k)
// {
//     cout << "\nEnter emono :";
//     cin >> k->eno;
// }

void myadd()
{
    node *t;
    t = new node;
    cout << "\nEnter empno :";
    cin >> t->eno;
    if (head == NULL)
    {
        head = t;
        t->next = NULL;
        t->prev = NULL;
    }
    else
    {
        tail->next = t;
        t->prev = tail;
        t->next = head;
    }
    tail = t;
}

void print(emp *t)
{
    cout << " " << t->eno;
}

void flist()
{
    node *t;
    for (head = t; t != NULL; t = t->next)
        print(t);
}

void blist()
{
    node *t;
    for (tail = t; t != NULL; t = t->prev)
        print(t);
}

void mylist()
{
    node *p;
    int i;
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    cout << "\n1.Front list"
         << "\n2.Back list"
         << "\nEnter choice";
    cin >> i;
    if (i == 1)
    {
        flist();
        return;
    }
    else
    {
        blist();
        return;
    }
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
            mylist();
            break;
        case 3:
            exit(1);
        }
    }
}
