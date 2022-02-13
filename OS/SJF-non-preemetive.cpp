#include <bits/stdc++.h>
using namespace std;
struct info
{
    int burst, process, arrival;
};
vector<int> arrivalarr;
vector<int> completion;

void getcompletion(struct info arr[], int n)
{
    completion.resize(n);
    completion[0] = arr[0].burst;
    for (int i = 1; i < n; i++)
    {
        completion[i] = completion[i - 1] + arr[i].burst;
    }
}

void waitingtime(struct info arr[], int wt[], int n)
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = completion[i] - arr[i].burst - arrivalarr[arr[i].process];
    }
}
void turnAroundTime(struct info arr[], int n, int tat[], int wt[])
{
    for (int i = 0; i < n; i++)
        tat[i] = arr[i].burst + wt[i];
}
void printdata(struct info newburst[], int n)
{
    getcompletion(newburst, n);
    int wt[n], tat[n], totalWaitingTime = 0, totalTurnAroundTime = 0;
    waitingtime(newburst, wt, n);
    turnAroundTime(newburst, n, tat, wt);
    cout << "Processes  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime = totalWaitingTime + wt[i];
        totalTurnAroundTime = totalTurnAroundTime + tat[i];
        cout << "   "
             << "P" << newburst[i].process << "\t\t" << newburst[i].burst << "\t    "
             << wt[i] << "\t\t  " << tat[i] << endl;
    }
    cout << "Average waiting time = "
         << (float)totalWaitingTime / (float)n;
    cout << "\nAverage turn around time = "
         << (float)totalTurnAroundTime / (float)n;
}
void solve(vector<vector<int>> &arr, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int idx = 0;
    int currTime = arr[0][0];
    while (idx < n and arr[idx][0] == currTime)
    {
        q.push({arr[idx][1], arr[idx][2]});
        idx++;
    }
    struct info newburst[n];
    int i = 0;
    while (!q.empty() or idx < n)
    {
        pair<int, int> node = q.top();
        q.pop();
        currTime += node.first;
        newburst[i].burst = node.first;
        newburst[i].process = node.second;
        i++;

        if (q.empty() and idx < n)
        {
            currTime = max(currTime, arr[idx][0]);
        }
        while (idx < n and currTime >= arr[idx][0])
        {
            q.push({arr[idx][1], arr[idx][2]});
            idx++;
        }
    }

    printdata(newburst, n);
}

int main()
{
    cout << "Enter the total number of process: " ;
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    arrivalarr.resize(n);
    cout << "Enter arrival time and then burst time" << endl;
    for (int i = 0; i < n; i++)
    {
        int arrival, burst;

        cin >> arrival >> burst;
        arrivalarr[i] = arrival;
        arr[i].push_back(arrival);
        arr[i].push_back(burst);
        arr[i].push_back(i);
    }
    sort(arr.begin(), arr.end());
    solve(arr, n);

    return 0;
}