#include <iostream>
using namespace std;

struct emp
  {
    int empno;
    int sal;
    char name[20];
    struct emp *next;
  };
typedef struct emp node;
  node *head,*tail;

void input(node *p)
   {
      cout<<"\nEnter empno name salary:";
      cin>>p->empno>>p->name>>p->sal;
      p->next=head;
   }

void myins(node *m)
  {
    node *n,*f;
    n=new node;
    input(n);
    n->next=m->next;
    if(n->next==head)
      tail=n;
    f=m;
    if(f!=m)
      {
	tail->next=n;
	tail=n;
      }
  }

void insert()
  {
    node *t,*p;
    int i,bulb=0,j;
    cout<<"\nEnter a no to find :";
    cin>>j;
    if(j==head->empno)
      {
	cout<<"\n1.Before"
	    <<"\n2.After";
	cin>>i;
	if(i==1)
	  {
	    t=new node;
	    input(t);
	    t->next=head;
	    head=t;
	    tail->next=head;
	  }
	else
	  myins(head);
      }
    do
      {
	if(p->next->empno==j)
	  {
	    cout<<"\n1.Before"
		<<"\n2.After";
	    cin>>i;
	    if(i==1)
	      myins(p);
	    else
	      myins(p->next);
	    p=p->next;
	    bulb=1;
	    break;
	  }
      }while(p->next!=head);
    if(bulb==0)
      cout<<"\nElement not found";
  }

/*void myadd()
   {
      node *t;
      t=new node;
      input(t);
      if(head==NULL)
	{
	  head=t;
	  t->next=t;
	  return;
	}
      else
	{
	  tail->next=t;
	  tail=t;
	  tail->next=head;
	}
   }
*/
void print(node *p)
   {
     cout<<"\nEmpno :"<<p->empno
	 <<"\nName :"<<p->name
	 <<"\nSalary :"<<p->sal;
   }

void mylist()
   {
     node *t,*m;
     int bulb=0,p;
     if(head==NULL)
       {
	 cout<<"\nList is empty";
	 return;
       }
     cout<<"\nEnter a no to find :";
     cin>>p;
     t=head;
     do
       {
	 if(t->empno==p)
	   {
	     bulb=1;
	     break;
	   }
	 t=t->next;
       }while(t!=head);
     if(bulb==0)
       {
	 cout<<"\nElement not found";
	 return;
       }
     m=t;
     do
       {
	 print(m);
	 m=m->next;
       }while(m!=t);
   }

void find()
  {
    int i,j,bulb=0;
    node *t,*p;
    if(head==NULL)
      {
	cout<<"\nList is empty";
	return;
      }
    cout<<"\nEnter a empno to find :";
    cin>>i;
    if(head->empno==i)
      {
	tail->next=head->next;
	delete head;
	head=t;
	return;
      }
    do
      {
	if(t->next->empno==i)
	  {
	    p=t->next->next;
	    delete t->next;
	    t->next=p;
	    if(p==head)
	      tail=t;
	    cout<<"\nOne record deleted ";
	    bulb=1;
	    break;
	  }
	t=t->next;
      }while(t->next!=head);
    if(bulb==0)
    cout<<"\nElement not found";
  }

void main()
   {
     node*x;
     int n;
     int ch;
     clrscr();
     while(1)
	{
	   cout<<"\n1.Add"
	       <<"\n2.List"
	       <<"\n3.Delete"
	       <<"\n4.Insert"
	       <<"\n5.Exit"
	       <<"\nEnter choice :";
	   cin>>ch;
	   switch(ch)
	      {
		 /*case 1:myadd();break;*/
		 case 2:mylist();break;
		 case 3:find();break;
		 case 4:insert();break;
		 case 5:exit(1);
	      }
	}
   }
