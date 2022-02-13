#include <bits/stdc++.h>
using namespace std;
struct Person
{
    int id,arrival;
};
struct CompareHeight {
    bool operator()(Person const& p1, Person const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.id > p2.id;
    }
};

int main()
{
    Person info[3];
    info[0].id=1;
    info[0].arrival=2;
    info[1].id=13;
    info[1].arrival=2;
    info[2].id=8;
    info[2].arrival=2;
    priority_queue<Person,vector<Person>,CompareHeight>q;
    q.push(info[1]);
    q.push(info[0]);
    q.push(info[2]);
    while (!q.empty())
    {
        cout<<q.top().id<<" ";
        q.pop();
    }
    return 0;
}