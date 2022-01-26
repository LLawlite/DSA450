#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int S, int D){
      vector<int>v(D,0);
      v[0]=1;
      int n=D-1;
      int sum=1;
      
      while(sum!=S){
          
          if(sum==S){break;}
          
          if(v[0]==9){return "-1";}
          else{
              for(int i=D-1;i>=0;i--){
                  if(v[i]<9){v[i]=v[i]+1;sum=sum+1;break;}
              }
          }
      }
      
      string s1="";
      
      for(int i=0;i<D;i++){
          
          s1=s1+ to_string(v[i]);
      }


      return s1;
      
   }