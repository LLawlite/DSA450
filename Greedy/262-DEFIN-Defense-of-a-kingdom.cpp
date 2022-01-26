#include <bits/stdc++.h>
using namespace std;
struct item
{
    int x,y;
};
bool comparator1(struct item a,struct item b)
{
    return a.x<b.x;
}
bool comparator2(struct item a,struct item b)
{
    return a.y<b.y;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int w,h,n;
        cin>>w>>h>>n;
        vector<int>xarr;
        vector<int>yarr;
        xarr.push_back(0);
        yarr.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int x,y;
            cin>>x>>y;
            xarr.push_back(x);
            yarr.push_back(y);
        }
        xarr.push_back(w+1);
        yarr.push_back(h+1);
        sort(xarr.begin(),xarr.end());
        sort(yarr.begin(),yarr.end());

        int my=0,mx=0;

        for (int i = 0; i < xarr.size()-1; i++)
        {
            mx=max(xarr[i+1]-xarr[i]-1,mx);
            my=max(yarr[i+1]-yarr[i]-1,my);
        }
        cout<<mx*my<<endl;
        

        
    }
    return 0;
}