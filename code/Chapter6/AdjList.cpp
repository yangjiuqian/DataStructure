#include <iostream>
#include <list>
#include <vector>

using namespace std;
// 边的结构体，包含目标顶点和权重
struct Edge {
    int destination;
    int weight;
    
    Edge(int dest, int w) : destination(dest), weight(w) {}
};
// 图的邻接表表示
class Graph {
private:
    int numVertices; // 顶点数量
    vector<list<int>> adjList; // 邻接表

public:
    // 构造函数
    Graph(int numVertices) : numVertices(numVertices), adjList(numVertices) {}

    // 添加边
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // 无向图需要添加反向边
    }

    // 打印图的邻接表表示
    void printGraph() {
        for (int v = 0; v < numVertices; ++v) {
            cout << "顶点 " << v << " 的邻接表:";
            for (const auto& neighbor : adjList[v]) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

// 网的邻接表表示
class WeightedGraph {
private:
    int numVertices; // 顶点数量
    vector<list<Edge>> adjList; // 邻接表

public:
    // 构造函数
    WeightedGraph(int numVertices) : numVertices(numVertices), adjList(numVertices) {}

    // 添加带权重的边
    void addEdge(int src, int dest, int weight) {
        Edge edge(dest, weight);
        adjList[src].push_back(edge);
    }

    // 打印图的邻接表表示
    void printGraph() {
        for (int v = 0; v < numVertices; ++v) {
            cout << "顶点 " << v << " 的邻接表:";
            for (const auto& edge : adjList[v]) {
                cout << " -> (" << edge.destination << ", " << edge.weight << ")";
            }
            cout << endl;
        }
    }
};


int main() {
    // 创建一个包含5个顶点的图
    Graph graph(5);

    // 添加边
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // 打印图的邻接表表示
    graph.printGraph();

    return 0;
}
