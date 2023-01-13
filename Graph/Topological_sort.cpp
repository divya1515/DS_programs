#include <bits/stdc++.h>
using namespace std;
vector<int> Indegree_Outdegree(vector<int> AdjList[], int v)
{
    vector<int> indeg(v);
    vector<int> outdeg(v);
    for (int i = 0; i < v; i++)
    {
        outdeg.push_back(AdjList[i].size());
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            indeg[AdjList[i][j]]++;
        }
    }
    return indeg;
}
void Topological_sort(vector<int> Adjlist[], int v)
{
    vector<int> Indeg = Indegree_Outdegree(Adjlist, v);
    queue<int> q;
    for (int i = 0; i < Indeg.size(); i++)
    {
        if (Indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto j : Adjlist[x])
        {
            Indeg[j]--;
            if (Indeg[j] == 0)
                q.push(j);
        }
        cout << x << " ";
    }
}
int main()
{
    int v, e;

    cin >> v;

    cin >> e;
    vector<int> AdjcntList[v];
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        AdjcntList[a].push_back(b);
    }
    Topological_sort(AdjcntList, v);
}
