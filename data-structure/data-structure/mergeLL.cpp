#include <iostream>
using namespace std;

struct emp{
    int empno;
    struct emp *next;
};

typedef emp *node;
node *head,*tail;

void input(node *p)
{
    cout<<"\nEnter a empno ;";
    cin>>p->empno;
    p->next=NULL;
}

void myadd()
{
    node *t;
    int f;
    int bulb=0;
    t=new node;
    input(t);
    if(head==NULL)
    {
        tail[i]=t;
        head[i]=t;
        return;
    }
    if(head[i]->empno>t->empno)
    {
        t->next=head[i];
        head[i]=t;
        return;
    }
    for(f=head[i];f->next!=NULL;f=f->next)
    {
        if(f->next->empno>t->empno)
        {
            t->next=f->next;
            f->next=t;
            bulb=1;
            break;
        }
    }
    if(bulb==0)
    {
        f->next=t;
        return;
    }
}

void merge()
{
    int o;
    node *n,*m,*p;
    m=head[0];
    n=head[1];
    if(m->empno<n->empno)
    {p=m;m=m->next;}
    else
    {p=n;n=n->next;}
    
    while(m!=NULL&&n!=NULL)
    {
        if(m->empno<n->empno)
        {
            p->next=m;
            p=p->next;
            m=m->next;
        }
        else{
            p->next=n;
            p=p->next;
            n=n->next;
        }
    }
    p->next=NULL;
    if(m!=NULL)
    p->next=m;
    if(n!=NULL)
    p->next=n;
    
}

int main()
{
    int ch;
    myadd();
    merge();
}