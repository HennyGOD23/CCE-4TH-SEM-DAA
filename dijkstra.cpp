#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int inf = 9999;
int sc = 0;
class Graph
{
private:
    int **adj;
    int n;

public:
    Graph(int numb)
    {
        n = numb + 1;
        sc++;
        adj = new int *[n];
        sc++;
        for (int i = 0; i < n; ++i)
        {
            sc++;
            adj[i] = new int[n];
        }
        for (int i = 0; i < n; ++i)
        {
            sc++;
            for (int j = 0; j < n; j++)
            {
                sc++;
                adj[i][j] = inf;
            }
            adj[i][i] = 0;
            sc++;
        }
    }
    void addVertex(int src, int dest, int cost)
    {
        adj[src][dest] = cost;
        sc++;
    }
    void dijkstra(int src)
    {
        int cost[n];
        int pre[n] = {0};
        sc++;
        bool visited[n] = {false};
        sc++;
        auto compare =
            [=](int lhs, int rhs)
        {
            sc++;
            return adj[src][lhs] > adj[src][rhs];
        };
        priority_queue<int, vector<int>, decltype(compare)> list(compare);
        for (int i = 1; i < n; i++)
        {
            sc++;
            cost[i] = adj[src][i];
            if (cost[i] != inf && cost[i] != 0)
            {
                sc++;
                pre[i] = src;
                sc++;
                list.push(i);
                sc++;
                visited[i] = true;
                sc++;
            }
        }
        while (!list.empty())
        {
            sc++;
            int i = list.top();
            sc++;
            list.pop();
            for (int j = 1; j < n; j++)
            {
                sc++;
                int temp = min(cost[j], cost[i] + adj[i][j]);
                if (temp != cost[j])
                {
                    sc++;
                    cost[j] = temp;
                    sc++;
                    pre[j] = i;
                    if (!visited[j])
                    {
                        sc++;
                        list.push(j);
                        sc++;
                        visited[j] = true;
                        sc++;
                    }
                }
            }
        }
        cout << " ";
        for (int i = 1; i < n; i++)
            cout << i << " ";
        cout << endl
             << "Cost: ";
        for (int i = 1; i < n; i++)
            cout << cost[i] << " ";
        cout << endl
             << "Predecessor: ";
        for (int i = 1; i < n; i++)
            cout << pre[i] << " ";
    }
};

int main()
{
    Graph G(5);
    G.addVertex(1, 4, 1);
    G.addVertex(2, 5, 2);
    G.addVertex(2, 3, 5);
    G.addVertex(3, 1, 2);
    G.addVertex(4, 3, 4);
    G.addVertex(5, 2, 1);
    G.dijkstra(2);
}
