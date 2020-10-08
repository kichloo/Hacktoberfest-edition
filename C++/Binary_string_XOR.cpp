#include<bits/stdc++.h> 
using namespace std; 

string xors(string a, string b, int n){ 
  string ans = ""; 
	for (int i = 0; i < n; i++) 
	 {
		 if (a[i] == b[i]) 
			  ans += "0"; 
		  else
		  	ans += "1"; 
  	} 
return ans; 
} 

int main() 
{
	string a,b;
	cin>>a>>b; 
	int n =a.length(); 
	string str = xors(a, b, n); 
	cout<<str; 
} 
