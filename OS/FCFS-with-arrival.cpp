#include<bits/stdc++.h>
using namespace std;

struct info
{
    int arrival,burst,process;

};
bool comparator(struct info a,struct info b)
{
    return a.arrival<b.arrival;
}
void waitingtime(struct info arr[],int wt[],int n)
{
    wt[0]=0;
    for (int i = 1; i <n; i++)
    {
        wt[i]=arr[i-1].burst+wt[i-1];
    }
    
}
void turnAroundTime( struct info arr[],int n,int tat[],int wt[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = arr[i].burst + wt[i];
}

void findAverage(struct info arr[],int n)
{
    int wt[n],tat[n],totalWaitingTime=0,totalTurnAroundTime=0;
     waitingtime(arr,wt,n);
 
    turnAroundTime(arr,n,tat,wt);
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time"<<" Arrival time\n";

    for (int  i=0; i<n; i++)
    {
        totalWaitingTime = totalWaitingTime + wt[i];
        totalTurnAroundTime = totalTurnAroundTime + tat[i];
        cout << "   " <<"P"<< arr[i].process << "\t\t" << arr[i].burst <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<"\t\t  "<<arr[i].arrival<<endl;
    }
 
    cout << "Average waiting time = "
         << (float)totalWaitingTime / (float)n;
    cout << "\nAverage turn around time = "
         << (float)totalTurnAroundTime / (float)n;

}

int main()
{
    int n;
    cout<<"Enter the total number of process: ";
    cin>>n;
    struct info arr[n];
    cout<<"Enter the process the burst time and then arrival time: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].process;
        cin>>arr[i].burst;
        cin>>arr[i].arrival;
    }
    sort(arr,arr+n,comparator);
   

    findAverage(arr,n);
    return 0;
    

    
}