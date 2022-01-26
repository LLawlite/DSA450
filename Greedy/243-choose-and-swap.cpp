#include <bits/stdc++.h>
using namespace std;

string chooseandswap(string a)
{
   set<char>s;
   for (int i = 0; i < a.length(); i++)
   {
       s.insert(a[i]);
   }
   char ch2,ch;
   for (int i = 0; i < a.length(); i++)
   {
       s.erase(a[i]);
       if (s.empty())
       {
           break;
       }
       
        ch=*s.begin();
       if(ch<a[i])
       {
           ch2=a[i];
           for (int k = 0; k < a.length(); k++)
           {
               if (a[k]==ch)
               {
                   a[k]=ch2;
               }
               else if(a[k]==ch2)
               {
                   a[k]=ch;
               }
               
           }
           break;
           
       }
   }
   
   return a;
}