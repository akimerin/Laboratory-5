#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib> 

class Graph {
public:
    int vertices;

    // Конструктор
    Graph(int v) : vertices(v), adjacencyMatrix(v, std::vector<int>(v, 0)) {}

    // Добавление ребра между вершинами u и v
    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // для неориентированного графа
    }

    // Обход графа в глубину из вершины v
    void dfs(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int i = 0; i < vertices; ++i) {
            if (adjacencyMatrix[v][i] == 1 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }
    // Обход графа в ширину из вершины v
    void bfs(int v) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            std::cout << currentVertex << " ";

            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    std::vector<std::vector<int>> adjacencyMatrix; // Матрица смежности
};

int main() {
    std::system("chcp 1251");
    int numVertices;

    // Вводим количество вершин графа
    std::cout << "Enter the number of vertices of the graph: ";
    std::cin >> numVertices;

    // Создаем граф с введенным количеством вершин

    Graph graph(numVertices);

    // Вводим матрицу смежности
    std::cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cin >> graph.adjacencyMatrix[i][j];
        }
    }

    std::cout << "Traversing the graph in depth, starting from vertex 0: ";
    std::vector<bool> visitedDFS(graph.vertices, false);
    graph.dfs(0, visitedDFS);
    std::cout << std::endl;

    std::cout << "Traversing the graph in width, starting from vertex 0: ";
    graph.bfs(0);
    std::cout << std::endl;

    return 0;
}
