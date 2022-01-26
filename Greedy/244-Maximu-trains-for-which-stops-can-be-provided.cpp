#include<bits/stdc++.h>
using namespace std;

struct train
{
    int arrival;
    int dept;
    int plt;
    train()
    {}
    train(int _arr,int _dep,int _plt)
    {
        arrival=_arr;
        dept=_dep;
        plt=_plt;
    }

};
bool comparator(struct train a ,struct train b)
{
    return a.dept<b.dept;
}
int maxStops(struct train arr[],int n,int m)
{
    sort(arr,arr+m,comparator);
    cout<<" endl"<<endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout<<arr[i].arrival<<" "<<arr[i].dept<<" "<<arr[i].plt<<endl;
    // }
    
    vector<int>plat(n+1,-1);
    plat[arr[0].plt]=arr[0].dept;
    int counter=1;
    for (int i = 1; i < m; i++)
    {
        
        if (arr[i].plt==-1)
        {
            counter++;
            plat[arr[i].plt]=arr[i].dept;
        }
        else
        {
            if (plat[arr[i].plt]<arr[i].arrival)
            {
                counter++;
                plat[arr[i].plt]=arr[i].dept;

            }
            
        }
        
        
    }
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<"dept-->"<<i<<"  ->>"<<plat[i]<<" "<<endl;
    // }
    
    return counter;
}

int main()
{
    int n=3;
    int m=5;
   struct  train arr[m];
   for (int i = 0; i < m; i++)
   {
      int x,y,z;
      cin>>x>>y>>z;
      arr[i].arrival=x;
      arr[i].dept=y;
      arr[i].plt=z;
       
   }
   cout<<maxStops(arr,n,m);
   
   
}