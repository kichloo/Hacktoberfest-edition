#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int *p,*q,*r;
	int max,t,n;
	cout<<"Enter Size"<<endl;
	cin>>n;
	p=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		cout<<"Enter at "<<i+1<<endl;
		cin>>p[i];
	}
	system("cls");
	cout<<"********************Previous Elements***************************"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<"  ";
	}
	max=p[0];
	for(int i=1;i<n;i++)
	{
		if(max<p[i])
		max=p[i];
	}
	q=(int *)malloc((max+1)*sizeof(int));
	for(int i=0;i<=max;i++)
	{
		q[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		q[p[i]]++;
	}
	for(int i=1;i<=max;i++)
	{
		q[i]+=q[i-1];
	}
	r=(int *)malloc(n*sizeof(int));
	for(int i=n-1;i>=0;i--)
	{
		q[p[i]]--;
		t=q[p[i]];
		r[t]=p[i];
	}
	cout<<endl;
	cout<<"********************SORTED ELEMENTS*****************************"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<r[i]<<"  ";
	}
	delete(p);
	delete(r);
	delete(q);
	return 0;
}
