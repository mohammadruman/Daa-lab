#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// Define a mapping between letters and their corresponding indices
map<char, int> nodeIndices = {
    {'A', 0},
    {'B', 1},
    {'C', 2},
    {'D', 3},
    {'E', 4},
    {'F', 5},
    {'G', 6},
    {'H', 7},
    {'I', 8}};

// Define the graph as an adjacency matrix
vector<vector<int>> graph = {
    {0, 1, 1, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0}};

// Breadth-First Search (BFS)
void bfs(int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (const auto &entry : nodeIndices)
        {
            if (entry.second == node)
            {
                cout << entry.first << " ";
                break;
            }
        }

        for (int neighbor = 0; neighbor < graph.size(); ++neighbor)
        {
            if (graph[node][neighbor] == 1 && !visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

// Depth-First Search (DFS)
void dfs(int node, vector<bool> &visited)
{
    if (!visited[node])
    {
        for (const auto &entry : nodeIndices)
        {
            if (entry.second == node)
            {
                cout << entry.first << " ";
                break;
            }
        }
        visited[node] = true;

        for (int neighbor = 0; neighbor < graph.size(); ++neighbor)
        {
            if (graph[node][neighbor] == 1 && !visited[neighbor])
            {
                dfs(neighbor, visited);
            }
        }
    }
}

int main()
{
    char startNode = 'A';

    cout << "DFS: ";
    vector<bool> visited(graph.size(), false);
    dfs(nodeIndices[startNode], visited);
    cout << endl;

    bfs(nodeIndices[startNode]);

    return 0;
}
