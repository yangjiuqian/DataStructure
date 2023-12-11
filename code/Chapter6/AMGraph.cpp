#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;
    unordered_map<int, string> vertexTable;  // 顶点表，将顶点的标识映射到实际的顶点名称

public:
    // 构造函数，初始化图的顶点数、邻接矩阵和顶点表
    Graph(int vertices) : numVertices(vertices), adjacencyMatrix(vertices, vector<int>(vertices, 0)) {}

    // 添加顶点，将顶点标识映射到实际的顶点名称
    void addVertex(int id, const string& name) {
        vertexTable[id] = name;
    }

    // 添加边
    void addEdge(int src, int dest) {
        // 无向图，两个方向都要设置为1
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;
    }

    // 打印邻接矩阵
    void printMatrix() {
        // 打印顶点表
        cout << "Vertex Table:" << endl;
        for (const auto& entry : vertexTable) {
            cout << entry.first << ": " << entry.second << endl;
        }

        // 打印邻接矩阵
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 创建一个包含4个顶点的图
    Graph graph(4);

    // 添加顶点
    graph.addVertex(0, "A");
    graph.addVertex(1, "B");
    graph.addVertex(2, "C");
    graph.addVertex(3, "D");

    // 添加边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    // 打印顶点表和邻接矩阵
    graph.printMatrix();

    return 0;
}
