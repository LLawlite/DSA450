#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin>>t;
	while (t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		int mx=0;
		unordered_map<int,int>m;
		for (int i = 0; i < n; i++)
		{
			m[s[i]]++;
			if (m[s[i]]>mx)
			{
				mx=m[s[i]];
			}
			
		}
		if (mx<=n-mx+1)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
		
		
		
	}
	
	
	return 0;
}