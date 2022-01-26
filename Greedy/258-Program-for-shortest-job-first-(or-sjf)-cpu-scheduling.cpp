#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getOrder(vector<vector<int>>& rq) {
       for(int i=0 ;i<rq.size(); i++)
            rq[i].push_back(i);
        
        sort(rq.begin(),rq.end());
        
        priority_queue<p,vector<p> ,greater<p>> rnq;
        
        int idx=0;
        long long t=rq[0][0];
    
        while(idx<rq.size() and rq[idx][0]==t){
            rnq.push({rq[idx][1], rq[idx][2]});
            idx++;
        }
        
        vector<int> ans;
        while(!rnq.empty() or idx<rq.size()){
            p node=rnq.top();rnq.pop();
            t+=node.first;
            ans.push_back(node.second);
            if(rnq.empty() and idx<rq.size()){
                t=max(t,(long long)rq[idx][0]);
                
            }
            
            while(idx<rq.size() and t>=rq[idx][0]){
                rnq.push({rq[idx][1],rq[idx][2]});
                idx++;
            }
        }
        return ans;
    }
};