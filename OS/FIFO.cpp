#include<iostream>
using namespace std;

void waitingTime(int processes[], int n,
                          int bt[], int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
 

void turnAroundTime( int processes[], int n,
                  int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 

void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
   
    waitingTime(processes, n, bt, wt);
 
    turnAroundTime(processes, n, bt, wt, tat);
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
 

int main()
{
 
    int n;
    cin>>n;
    int processes[n];
    cout<<"Enter the process"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>processes[i];
    }
    cout<<"Enter the burst time"<<endl;
    int  burst_time[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>burst_time[i];
    }
    
    findavgTime(processes, n,  burst_time);
    return 0;
}