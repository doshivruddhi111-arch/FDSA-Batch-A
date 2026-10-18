#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void DFS(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cout << node << " ";

        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] && !visited[i])
                s.push(i);
        }
    }
    cout << endl;
}

void BFS(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int n, edges;

    cout << "Enter number of buildings: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter connected buildings:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    DFS(graph, start);
    BFS(graph, start);

    return 0;
}