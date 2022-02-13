#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id,priority,burst,arrival;
};
struct comparePrority {
    bool operator()(struct process p1,struct  process  p2)
    {
        
        return p1.priority > p2.priority;
    }
};
vector<process>schedule;
bool comparator(struct process a,struct process b)
{
    return a.arrival<b.arrival;
}

void completionTime(vector<process>arr,int cmt[],int n)
{
    cmt[0]=arr[0].arrival+arr[0].burst;
    for (int i = 1; i < n; i++)
    {
        cmt[i]=cmt[i-1]+arr[i].burst;
    }
    
}

void waitingtime(vector<process>arr, int wt[], int n,int tat[])
{
    wt[0] = tat[0]-arr[0].burst;
    for (int i = 1; i < n; i++)
    {
        wt[i] = tat[i]-arr[i-1].burst;
    }
}
void turnAroundTime(vector<process>arr, int n, int tat[], int cmt[])
{
    for (int i = 0; i < n; i++)
        tat[i] = cmt[i]-arr[i].arrival;
}


void printdata(vector<process>arr, int n)
{
    
    int wt[n],cmt[n], tat[n];double totalWaitingTime = 0, totalTurnAroundTime = 0;
    completionTime(arr,cmt,n);
    turnAroundTime(arr, n, tat, cmt);
    waitingtime(arr, wt, n,tat);
    cout << "Processes  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime = totalWaitingTime + wt[i];
        totalTurnAroundTime = totalTurnAroundTime + tat[i];
        cout << "   "
             << "P" << arr[i].id << "\t\t" << arr[i].burst << "\t    "
             << wt[i] << "\t\t  " << tat[i] << endl;
    }
    cout << "Average waiting time = "
         << totalWaitingTime / (double)n;
    cout << "\nAverage turn around time = "
         << totalTurnAroundTime / (double)n;
}
void priorityScheduling(vector<process>arr,int n)
{
    int idx = 0;

    priority_queue<process,vector<process>,comparePrority>pq;
    int t=arr[0].arrival;
     while (idx < n and arr[idx].arrival == t)
    {
        pq.push(arr[idx]);
        idx++;
    }
  
    while (!pq.empty() or idx<n)
    {
      struct process temp=pq.top();
      pq.pop();
      schedule.push_back(temp);
      t+=temp.burst;
      if (pq.empty() and idx < n)
        {
           t = max(t, arr[idx].arrival);
        }
        while (idx < n and t >= arr[idx].arrival)
        {
            pq.push(arr[idx]);
            idx++;
        }
      
        
    }
   
    printdata(schedule,schedule.size());
    
}
int main()
{
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;
    vector<process>arr;
    cout<<"First enter the Priority and then Burst time and then enter the arrival time: "<<endl;
    struct process temp;
  
    for (int i = 0; i < n; i++)
    {
        temp.id=i+1;
        cin>>temp.priority;
        cin>>temp.burst;
        cin>>temp.arrival;
        arr.push_back(temp);
    
    }
    sort(arr.begin(),arr.end(),comparator);
  
    

    priorityScheduling(arr,n);
    
    return 0;
    
}