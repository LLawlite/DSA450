// Time Complexity O(n^2)

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool comparison(Job a,Job b)
{
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr,arr+n,comparison);
    int profit=0,jobs=0;
    vector<bool>slot(n,false);
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n,arr[i].dead); j >=0; j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                jobs++;
                profit+=arr[i].profit;
                break;
            }
        }
        
    }
    vector<int>ans;
    ans.push_back(jobs);
    ans.push_back(profit);
    return ans;
    


}