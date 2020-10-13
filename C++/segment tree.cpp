#include<bits/stdc++.h>
using namespace std;
void buildTree (int *tree,int *a,int index,int s,int e)    // s->start , e ->end
{
	// base case
	if(s>e)
	{
		return;
	}
	// base case - leaf node
	if(s==e)
	{
		tree[index] = a[s];
		return;
	}
	
	// recursive case 
	int mid = (s+e)/2;
	//left subtree
	buildTree(tree,a,2*index,s,mid);
	//right subtree
	buildTree(tree,a,2*index+1,mid+1,e);
	
	
	int left = tree[2*index];
	int right = tree[2*index +1];
	
	
	tree[index]= min(left,right);
	
}

// return a min element from the tree lying in range qs and qe
int query(int *tree,int index,int s,int e,int qs,int qe)    // qs --> query start and qe --> query end
{
	// 3 cases
	 
	
	// 1. no overlap
		if(qs>e || qe<s)
		{
			return INT_MAX;
		}
	
	// 2. complete overlap
		if(s>=qs || qe<=e)
		{
			return tree[index];
		}
	// 3. partial overlap
		int mid =(s+e)/2;
		int leftAns = query(tree,2*index,s,mid,qs,qe);
		int rightAns = query(tree,2*index+1,mid+1,e,qs,qe);
		return min(leftAns,rightAns); 
	
}
// i -> update array which index 
// value -> is the new value to be placed
void updateNode(int *tree, int index, int s, int e,int i,int value)
{
 // no overlap
 if(i<s||i>e)
 return;
 
 // reached leaf node
 if(s==e)
 {
 	tree[index] = value;
 	return;
 }
	 
 // partial overlap - i is lying between s and e
 int mid = (s+e)/2;
 updateNode(tree,2*index,s,mid,i,value);
 updateNode(tree,2*index+1,mid+1,e,i,value);
 tree[index] = min(tree[2*index],tree[2*index+1]);
 return;
}


// range update
// you will be given a range rs and re
// and you increment every element in the range by a value v
void updateRange(int *tree,int index,int s,int e,int rs,int re,int incr)
{
	// no overlap
	if(re<s|| rs>e)
	{
		return;
	}
	// reached leaf node
	if(s==e)
	{
		tree[index] += incr;
		return;
	}
	
	// lying in range - call both sides
	int mid = (s+e)/2;
	updateRange(tree,2*index,s,mid,rs,re,incr);
	updateRange(tree,2*index+1,mid+1,e,rs,re,incr);
	
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}
int main()
{
	int a[] = {1,3,2,-2,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	
	//build the tree array
	int *tree = new int[4*n+1];
	int index=1;
	int s=0;
	int e=n-1;

	buildTree(tree,a,index,s,e); 
	
	int q;
	cin>>q;
	while(q--)
	{
		int qs,qe;
		cin>>qs>>qe;
		cout<<"min value b/w range is : ";
		cout<<query(tree,1,s,e,qs,qe)<<endl;
	}
}
