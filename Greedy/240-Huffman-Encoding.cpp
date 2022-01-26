#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    char c;
    int freq;
    int sum;
    node *left,*right;
    
    node(char a,int f)
    {
        c=a;
        freq=f;
        left=NULL;
        right=NULL;
     
      
    }
    // int getFreq() const
    // {
    //     return freq;
    // }
};
class myComparator
{
public:
    int operator() (const node& p1, const node& p2)
    {
        // return p1.getFreq() > p2.getFreq();
        return p1.freq>p2.freq;
    }
};
vector<string> huffmanCodes(string S, vector<int> f, int n)
{
    priority_queue<node,vector<node>,myComparator>q;
    for (int i = 0; i < n; i++)
    {
        q.push(node(S[i],f[i]));
    }
    while (q.size()!=1)
    {
        node first=q.top();
        q.pop();
        node second=q.top();
        q.pop();
        int sum=first.freq+second.freq;
        node newnode=node('.',sum);
        newnode.left=first;
        newnode.right=second;
        q.push(newnode);


    }
    
    
}