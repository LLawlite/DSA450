#include <bits/stdc++.h>
using namespace std;
void survival(int s, int n, int m)
{

   if(m>n)
   {
       cout<<"NO"<<endl;
       return ;
   }
   int w=s*m;
   int i = 0;
   for (; i < s; i++)
   {
       if(i%6==0 and i!=0)
       {
           continue;
       }
       else
       {
           if(n<w)
           {
               w=w-n;

           }
           else
           {
               break;
           }
           
       }
       
   }
   cout<<i+1<<endl;
   
}

// Driver code
int main()
{
    int S = 10, N = 20, M = 30;
    survival(S, N, M);
    return 0;
}