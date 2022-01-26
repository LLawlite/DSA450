#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>>list;
    for (int i = 0; i < n; i++)
    {
        list.push_back({end[i],start[i]});

    }
    sort(list.begin(),list.end());
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<list[i].second<<" "<<list[i].first<<endl;
    }
    
    pair<int,int>curr=list[0];
    int count=0;
   for (int i = 1; i < n; i++)
   {
       if(list[i].second>=curr.first)
       {
           count++;
           curr=list[i];
       }
   }
   
    return count;
    
}
int main()
{
       int s[] = { 1, 3, 0, 5, 8, 5 };

    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
    maxMeetings(s,f,6);
}