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

void input(node *k)
{
    cout << "\nEnter emono :";
    cin >> k->eno;
}
void fadd()
{
    node *k;
    k = new node;
    input(k);
    k->next = head;
    head->prev = k;
    head = k;
    head->prev = NULL;
}

void badd()
{
    node *k;
    k = new node;
    input(k);
    tail->next = k;
    k->prev = tail;
    tail = k;
    tail->next = NULL;
}
void myadd()
{
    int i;
    if (head == NULL)
    {
        node *p;
        p = new node;
        input(p);
        head = p;
        tail = p;
        head->next = NULL;
        tail->next = NULL;
        return;
    }
    cout << "\n1.Front add"
         << "\n2.Back add"
         << "\nEnter choice";
    cin >> i;
    if (i == 1)
    {
        fadd();
        return;
    }
    else
    {
        badd();
        return;
    }
}

void print(node *t)
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
