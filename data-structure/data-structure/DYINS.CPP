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


void myins(node *t)
   {
      node *p;
      p=new node;
      input(p);
      p->next=t->next;
      t->next=p;
      if(p->next==NULL)
	 tail=p;
   }

void insert()
   {
      if(head==NULL)
	 {
	    cout<<"\nList is empty";
	    return;
	 }
      int i,n;
      int bulb=0;
      node *p,*j;
      cout<<"\nEnter no to find :";
      cin>>n;
      if(head->empno==n)
	 {
	    cout<<"\n1.After:"
		<<"\n2.Before:";
	    cin>>i;
	    if(i==1)
	       myins(head);
	    else
	       {
		  p=new node;
		  input(p);
		  p->next=head;
		  head=p;
	       }
	 }
      for(j=head;j->next!=NULL;j=j->next)
	 {
	    if(j->next->empno==n)
	       {
		  cout<<"\n1.After"
		      <<"\n2.Before";
		  cin>>i;
		  if(i==1)
		    myins(j->next);
		  else
		    myins(j);
		  bulb=1;
		  break;
	       }
	 }
      if(bulb==0)
	cout<<"\nElement not found";
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
	       <<"\n4.Insert"
	       <<"\n4.Exit"
	       <<"\nEnter choice :";
	   cin>>ch;
	   switch(ch)
	      {
		 case 1:myadd();break;
		 case 2:mylist();break;
		 case 3:mydel();break;
		 case 4:insert();break;
		 case 5:exit(1);
	      }
	}
   }


