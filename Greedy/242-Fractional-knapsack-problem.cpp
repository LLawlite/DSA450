#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
bool comparison(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{

    sort(arr, arr + n, comparison);

    int currWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight <= W)
        {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - currWeight;
            finalValue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }
    }

    return finalValue;
}
// int main()
// {
//     int W = 50; //    Weight of knapsack
//     Item arr[] = { { 30, 10 }, { 100, 20 }, { 120, 30 } };

//     int n = sizeof(arr) / sizeof(arr[0]);

//     // Function call
//     cout << "Maximum value we can obtain = "
//          << fractionalKnapsack(W, arr, n);
//     return 0;
// }