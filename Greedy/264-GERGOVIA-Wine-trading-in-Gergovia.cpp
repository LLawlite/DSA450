#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
    cin>>n;
   int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<pair<int, int> >buyer;
    vector<pair< int, int> >seller;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>0)
        {
            buyer.push_back({arr[i],i});
        }
        else
        {
            seller.push_back({arr[i],i});
        }
        
    }
     int i=0,j=0;
   int ans=0;
    while (i<buyer.size() and j<seller.size())
    {
        int noOfBottels=min(buyer[i].first,-seller[j].first);
        buyer[i].first-=noOfBottels;
        seller[j].first+=noOfBottels;
        int diff=abs(buyer[i].second-seller[j].second);
        ans+=noOfBottels*diff;
        if(buyer[i].first==0) i++;
        if(seller[i].first==0) j++;
    }
    
    cout<<ans<<endl;
    return 0;
    
}