#include <bits/stdc++.h>

using namespace std;

void DFS(vector<list<int>>& adjList, vector<int>& Num, vector<int>& Low, int currV, int prev, int& currT, int& bridges, int& APcnt)
{
    Num[currV] = Low[currV] = currT;

    bool isAP = false;

    int children = 0;
    for (int i : adjList[currV])
    {
        if (i == prev) continue;

        if (Num[i] != -1) Low[currV] = min(Low[currV], Num[i]);
        else
        {
            children++;
            DFS(adjList, Num, Low, i, currV, ++currT, bridges, APcnt);

            Low[currV] = min(Low[currV], Low[i]);

            if (Low[i] > Num[currV]) bridges++;
            if (prev != -1 && Low[i] >= Num[currV]) isAP = true;
        }
    }


    if (prev == -1 && children > 1) isAP = true;

    if (isAP) APcnt++;
}


int main()
{
    int v, e;
    cin >> v >> e;

    vector<list<int>> adjList(v);

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adjList[v1 - 1].push_back(v2 - 1);
        adjList[v2 - 1].push_back(v1 - 1);
    }

    vector<int> Num(v, -1);
    vector<int> Low(v);

    int bridges = 0, APcnt = 0, currT = 1;
    for(int i = 0; i < v; i++) if (Num[i] == -1) DFS(adjList, Num, Low, i, -1, currT, bridges, APcnt);

    cout << APcnt << ' ' << bridges << '\n';

    return 0;
}