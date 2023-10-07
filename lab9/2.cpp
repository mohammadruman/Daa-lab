#include <iostream>
#include <vector>

#define MAX_NODES 100

using namespace std;

// Function to perform Depth-First Search (DFS)
void dfs(int node, int numNodes, vector<vector<int>> &graph, vector<bool> &visited)
{
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < numNodes; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i, numNodes, graph, visited);
        }
    }
}

void findConnectedComponents(int numNodes, vector<vector<int>> &graph)
{
    vector<bool> visited(numNodes, false);

    cout << "Connected Components:\n";

    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, numNodes, graph, visited);
            cout << endl;
        }
    }
}

int main()
{
    int numNodes = 9;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0}};

    findConnectedComponents(numNodes, graph);

    return 0;
}
