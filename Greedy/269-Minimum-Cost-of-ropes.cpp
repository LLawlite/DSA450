#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>>q;
	long long ans=0;
	for (int i = 0; i < n; i++)
	{
		q.push(arr[i]);
	}
	long long a1,a2;
	long long sum;
	while (q.size()>1)
	{
		a1=q.top();
		q.pop();
		a2=q.top();
		q.pop();
		sum=a1+a2;
		q.push(sum);
		ans+=sum;

	}
	
	
	return ans;
    }