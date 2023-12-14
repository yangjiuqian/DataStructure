#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V; // 顶点数
    vector<vector<int>> adjList; // 邻接表

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // 添加边
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    // 广度优先搜索
    void BFS(int startVertex) {
        // 记录已访问的顶点
        vector<bool> visited(V, false);

        // 使用队列来实现BFS
        queue<int> q;

        // 将起始顶点入队并标记为已访问
        q.push(startVertex);
        visited[startVertex] = true;

        cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            // 出队并访问当前顶点
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            // 遍历当前顶点的邻接顶点
            for (int neighbor : adjList[currentVertex]) {
                // 如果邻接顶点未被访问，则入队并标记为已访问
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // 创建一个图并添加边
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    // 从顶点0开始进行BFS
    g.BFS(0);

    return 0;
}
