#include <bits/stdc++.h>
using namespace std;
struct process
{
    int id,burst,arrival;
};
void waiting(process pro[],int n,int wt[])
{
    int burst[n];
    for (int i = 0; i < n; i++)
    {
        burst[i]=pro[i].burst;
    }
    int t=0,complete=0,minBurst=INT_MAX;
    bool check=false;
    int shortest=0,finisTime;

    while (complete!=n)
    {
        for (int i = 0; i < n; i++)
        {
            if(pro[i].arrival<=t && burst[i]<minBurst && burst[i]>0)
            {
                shortest=i;
                minBurst=burst[i];
                check=true;
            }
        }
        if(check==false)
        {
            t++;
            continue;
        }
        burst[shortest]--;
        minBurst=burst[shortest];
        if(minBurst==0)
        {

            minBurst=INT_MAX;
            if(burst[shortest]==0)
            {
                complete++;
                check=false;
                finisTime=t+1;
                wt[shortest]=finisTime-pro[shortest].arrival-pro[shortest].burst;
                if(wt[shortest]<0)
                {
                    wt[shortest]=0;
                }
            }
        }

        t++;
        
    }
    
    
}
void turnAroundTime(process pro[],int n,int wt[],int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i]=wt[i]+pro[i].burst;
    }
    
}

void findavgTime(process proc[], int n) {
   int wt[n], tat[n], total_wt = 0,
   total_tat = 0;
   // Function to find waiting time of all
   // processes
   waiting(proc, n, wt);
   // Function to find turn around time for
   // all processes
   turnAroundTime(proc, n, wt, tat);
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].id << "\t\t" << proc[i].burst << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
// main function
int main() {
   int n;
   cout<<"Enter the number of process"<<endl;
   cin>>n;
   process proc[n];
   cout<<"Enter first burst time and then arrival time"<<endl;
    for (int i = 0; i < n; i++)
    {
        proc[i].id=i;

        cin>>proc[i].burst;
        cin>>proc[i].arrival;
    }
    

   
   findavgTime(proc, n);
   return 0;
}