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
   node *head,*tail;

void input(node *p)
   {
      cout<<"\nEnter empno name salary:";
      cin>>p->empno>>p->name>>p->sal;
      p->next=NULL;
   }

void myadd()
   {
      node *t;
      t=new node;
      input(t);
      if(head==NULL)
	 head=t;
      else
	 tail->next=t;
      tail=t;
   }

void print(node *p)
   {
     cout<<"\nEmpno :"<<p->empno
	 <<"\nName :"<<p->name
	 <<"\nSalary :"<<p->sal;
   }

void mylist()
   {
      node *t;
      if(head==NULL)
	 {
	    cout<<"\nQueue is empty";
	    return;
	 }
      for(t=head;t!=NULL;t=t->next)
	 print(t);
   }

void mydel()
   {
      if(head==NULL)
	 {
	   cout<<"\nStock is empty";
	   return;
	 }
      int i;
      int bulb=0;
      node *p,*t;
      cout<<"\nEnter a empno to find :";
      cin>>i;
      if(head->empno==i)
	 {
	   t=head->next;
	   delete head;
	   head=t;
	   return;
	 }
      for(t=head;t->next!=NULL;t=t->next)
	 {
	    if(t->next->empno==i)
	       {
		 p=t->next->next;
		 delete t->next;
		 t->next=p;
		 if(p==NULL)
		    tail=t;
		 cout<<"\nOne record deleted ";
		 bulb=1;
		 break;
	       }
	 }
      if(bulb==0)
	 cout<<"\nRecord not found";
   }

int main()
   {
     node*x;
     int n;
     int ch;
     while(1)
	{
	   cout<<"\n1.Add"
	       <<"\n2.List"
	       <<"\n3.Delete"
	       <<"\n4.Exit"
	       <<"\nEnter choice :";
	   cin>>ch;
	   switch(ch)
	      {
		 case 1:myadd();break;
		 case 2:mylist();break;
		 case 3:mydel();break;
		 case 4:exit(1);
	      }
	}
   }


