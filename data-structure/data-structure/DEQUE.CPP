#include <iostream>
using namespace std;



void fadd()
    {
	for(int j = i ;j > 0 ; j--)
		a[j+1]=a[j];
	i++;
	cout<<"\nEnter data :";
	cin>>a[0];
    }

void badd()
    {
	cout<<"\nEnter data :";
	cin>>a[++i];
    }

void myadd()
    {
	if(i==n-1)
	    {
		cout << "\nStock is full";
		int t;
		cin>>t;
		a=(int*)realloc(a,n+t);
		n+=t;
	    }
	int p;
	cout<<"\n1.Front add"
	    <<"\n2.Back add";
	cin>>p;
	if(i==-1)
	   p=1;
	if(p==1)
	   fadd();
	else
	   badd();
    }

void flist()
    {
	cout<<"\nData in front list :";
	for(int j=0;j<=i;j++)
	   cout<<" "<<a[j]<<" ";
    }

void blist()
    {
	cout<<"\nData in back list :";
	for(int j=i;j>=0;j--)
	   cout<<" "<<a[j]<<" ";
    }

void mylist()
    {
	if(i==-1)
	    {
		cout << "\nStock is empty"  ;
		return;
	    }
	int t;
	cout<<"\n1.Front list"
	    <<"\n2.Back list";
	cin>>t;
	if(t==1)
	   flist();
	else
	   blist();
    }

void bdel()
    {
	i--;
	cout<<"\nElement deleted :";
    }

void fdel()
    {
	for(int p=0;p<i;p++)
	   a[p]=a[p+1];
	i--;
	cout<<"\nElement deleted";
    }

void mydel()
    {
	if(i==-1)
	    {
		cout << "\nStock is empty" ;
		return;
	    }
	int t;
	cout<<"\n1.Front delete"
	    <<"\n2.Back delete";
	cin>>t;
	if(t==1)
	   fdel();
	else
	   bdel();
    }
int main()
{
   int ch,n;
   cout<<"\nHow many elements :";
   cin>>n;
   a=(int *)malloc(n*sizeof(int));
   while(1)
	{
	    cout<<"\n1.Add"
		<<"\n2.List"
		<<"\n3.Del"
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
