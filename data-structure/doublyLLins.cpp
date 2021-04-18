/*changes required */


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

void input(node *p)
{
    cout << "\nEnter empno to insert:";
    cin >> p->eno;
}

void myins(node *p)
{
    node *k;
    k = new node;
    k->next = p->next;
    k->prev = p;
    k->next->prev = k;
    if (k->next == NULL)
        tail = k;
}

void insert()
{
    node *t, *p, *m;
    int i, ch, bulb = 0;
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    cout << "\nEnter a no to find :";
    cin >> i;
    if (i == head->eno)
    {
        cout << "\n1.Before"
             << "\n2.After"
             << "\nEnter choice :";
        cin >> ch;
        if (ch == 1)
        {
            t = new node;
            input(t);
            t->next = head;
            head->prev = t;
            head = t;
            head->prev = NULL;
            return;
        }
        t->next = head;
        t = head->prev;
    }
    else
    {
        myins(head);
        return;
    }
    for (p = head; p->next != NULL; p = p->next)
    {
        if (p->next->eno == i)
        {
            cout << "\n1.Before"
                 << "\n2.After"
                 << "\nEnter choice :";
            cin >> ch;
            if (ch == 1)
                myins(p);
            else
                myins(p->next);
            bulb = 1;
            cout << "\nOne record added";
            break;
        }
    }
    if (bulb == 0)
        cout << "\nRecord not found";
}

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

void mylist()
{
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    node *t;
    cout << "\nFront list";
    //for (t = head; t != NULL; t = t->next)
    //    cout << " " << t->eno;
    for (t = tail; t != NULL; t = t->prev)
        cout << " " << t->eno;
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
             << "\n3.Insert"
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
            insert();
            break;
        case 4:
            exit(1);
        }
    }
}
