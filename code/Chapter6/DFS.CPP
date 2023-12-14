#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // 顶点数
    vector<vector<int>> adjMatrix; // 邻接矩阵

public:
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // 添加边
    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1; // 如果是无向图，还需要将另一方向也设置为1
    }

    // 深度优先搜索
    void DFS(int startVertex, vector<bool>& visited) {
        cout << startVertex << " ";
        visited[startVertex] = true;

        // 遍历当前顶点的邻接顶点
        for (int neighbor = 0; neighbor < V; ++neighbor) {
            // 如果邻接顶点未被访问，并且存在边相连
            if (!visited[neighbor] && adjMatrix[startVertex][neighbor] == 1) {
                DFS(neighbor, visited);
            }
        }
    }

    // 对外提供的接口，用于启动DFS
    void startDFS(int startVertex) {
        vector<bool> visited(V, false);

        cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        DFS(startVertex, visited);

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

    // 从顶点0开始进行DFS
    g.startDFS(0);

    return 0;
}
