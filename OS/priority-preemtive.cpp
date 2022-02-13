#include <bits/stdc++.h>
using namespace std;
struct process
{
	int id,burst,arrival,priority;

};


void waitingTime(process pro[],int wt[],int n,int cmt[])
{

	int burst[n];
	for (int i = 0; i < n; i++)
	{
		burst[i]=pro[i].burst;
	
		cout<<i<<" -> "<<burst[i]<<" "<<endl;
	}
	
	int t=0,finishTime,complete=0;
	int shortest;
	bool check=false;
	int minprio=INT_MAX;
	while(complete!=n)
	{
		for (int i = 0; i < n; i++)
		{
			if(pro[i].arrival<=t and burst[i]>0 and pro[i].priority<minprio)
			{
				shortest=i;
				minprio=pro[i].priority;
				check =true;
			}
		}
		if(check==false)
		{
			t++;
			continue;
		}
		else
		{
			minprio=INT_MAX;
				check=false;
			burst[shortest]--;
			if(burst[shortest]==0)
			{
				
				complete++;
				finishTime=t+1;
				cmt[shortest]=finishTime;
				wt[shortest]=finishTime-pro[shortest].arrival-pro[shortest].burst;
				if(wt[shortest]<0)
				{
					wt[shortest]=0;
				}
			}
		}

		

		t++;
	}

	
	
}
void troundAroundTime(process pro[],int n, int wt[],int tat[])
{
	for (int i = 0; i < n; i++)
	{
		tat[i]=wt[i]+pro[i].burst;
	}
	
}
void findavgTime(process proc[], int n) {
   int wt[n], tat[n], cmt[n],total_wt = 0,
   total_tat = 0;
   // Function to find waiting time of all
   // processes
   waitingTime(proc,wt,n,cmt);
   // Function to find turn around time for
   // all processes
   troundAroundTime(proc,n,wt,tat);
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time"<<" Completeion time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].id << "\t\t" << proc[i].burst << "\t\t " << wt[i] << "\t\t " << tat[i] << "\t\t" <<cmt[i]<< endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
int main()
{
	cout<<"Enter the number of porcess: ";
	int n;
	cin>>n;
	 process pro[n];
	 cout<<"Enter burst time then arrival and then priority"<<endl;
	for (int i = 0; i < n; i++)
	{
		pro[i].id=i;
		cin>>pro[i].burst;
		cin>>pro[i].arrival;
		cin>>pro[i].priority;
	}
	findavgTime(pro,n);
	
}
// 4 0 2
// 3 1 3
// 1 2 4
// 5 3 5
// 2 4 5