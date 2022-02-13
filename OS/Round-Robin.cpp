#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, burst, arrival;
};

void waitingTime(process pro[], int n, int wt[], int quantum,int cmt[])
{
    int burst[n];
    for (int i = 0; i < n; i++)
    {
        burst[i] = pro[i].burst;
    }
    int t = 0;
    while (true)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if(pro[i].arrival<=t)
            {

            
                if (burst[i] != 0)
                {
                    done = false;

                    if (burst[i] > quantum)
                    {
                        t += quantum;
                        burst[i] = burst[i] - quantum;
                    }
                    else
                    {
                        t = t + burst[i];
                        burst[i] = 0;
                        cmt[i]=t;
                        wt[i] = t - pro[i].arrival - pro[i].burst;
                        if (wt[i] < 0)
                        {
                            wt[i] = 0;
                        }
                    }
                }
            }
            
            
            
        }
        if (done)
        {
            break;
        }
    }
}
void findTurnAroundTime(process pro[], int n,
                        int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = pro[i].burst + wt[i];
}
void findavgTime(process pro[], int n, int quantum)
{
    int wt[n], tat[n],cmt[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    waitingTime(pro, n, wt, quantum,cmt);

    // Function to find turn around time for all processes
    findTurnAroundTime(pro, n, wt, tat);

    // Display processes along with all details
    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time"
         <<" Completion Time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t\t" << pro[i].burst << "\t "
             << wt[i] << "\t\t " << tat[i] <<"\t\t "<<cmt[i]<< endl;
    }
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
int main()
{
    // process id's
    int n;
    cout << "Enter the number of process" << endl;
    cin >> n;

    // Time quantum
    int quantum = 2;
    process pro[n];
    cout << "Enter the  arrical time and the burst time" << endl;
    for (int i = 0; i < n; i++)
    {
        pro[i].id = i;
        cin >> pro[i].arrival;
        cin >> pro[i].burst;
    }

    findavgTime(pro, n, quantum);
    return 0;
}
//5 0 4 1 2 2 3 1