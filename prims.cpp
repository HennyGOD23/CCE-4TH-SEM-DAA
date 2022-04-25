#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int inf = 9999;
class UGraph
{
private:
    int **adj;
    int n;

public:
    UGraph(int num)
    {
        n = num + 1;
        adj = new int *[n];
        for (int i = 0; i < n; ++i)
            adj[i] = new int[n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                adj[i][j] = inf;
        }
    }
    void addVertex(int s, int d, int cost)
    {
        adj[s][d] = cost;
        adj[d][s] = cost;
    }
    pair<int, int> minimum(bool selected[])
    {
        int min = inf;
        int p1 = 0;
        int p2 = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (selected[i] && !selected[j] && adj[i][j] < min && i != j)
                {
                    min = adj[i][j];
                    p1 = i;
                    p2 = j;
                }
            }
        }
        return make_pair(p1, p2);
    }
    void Prim()
    {
        bool selected[n] = {false};
        selected[1] = true;
        int edges = 0;
        queue<pair<int, int>> output;
        while (edges != n - 2)
        {
            pair<int, int> small = minimum(selected);
            if (small.first == 0)
                break;
            edges++;
            selected[small.second] = true;
            output.push(small);
        }
        if (edges != n - 2)
            cout << "Spanning Tree Not Possible!\n";
        else
        {
            while (!output.empty())
            {
                int a = output.front().first;
                int b = output.front().second;
                output.pop();
                cout << "(" << a << ", " << b << ") -> " << adj[a][b] << "\n";
            }
        }
    }
};
int main()
{
    UGraph G(5);
    G.addVertex(1, 4, 1);
    G.addVertex(2, 5, 2);
    G.addVertex(2, 3, 5);
    G.addVertex(3, 1, 2);
    G.addVertex(4, 3, 4);
    G.addVertex(5, 2, 1);
    G.Prim();
}