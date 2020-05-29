#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>

std::vector<std::vector<int>> inputData(std::string fileName) {
    std::ifstream inputFile(fileName);

    std::vector<std::vector<int>> adjacencyMatrix;

    if (inputFile.is_open()) {
        std::string fileLine;
        int counter = 0;

        while (std::getline(inputFile, fileLine)) {
            adjacencyMatrix.push_back(std::vector<int>());

            std::stringstream ss(fileLine);
            std::string temp;

            while (ss >> temp) {
                adjacencyMatrix[counter].push_back(stoi(temp));
            }

            counter++;
        }
    }

    inputFile.close();

    return adjacencyMatrix;
}

bool bfs(std::vector<std::vector<int>> graph, bool checkPrint = false) {
    std::cout << "BFS is used to control if the graph is connected." << '\n'
              << '\n';

    std::vector<bool> visitedNodes(graph.size(), false);
    std::queue<int> queue;
    int currentNode;
    int fullyConnectedGraph = 0;

    // Push the start node to the queue and mark it as visited
    queue.push(0);
    visitedNodes[0] = true;

    while (!queue.empty()) {
        currentNode = queue.front();
        if (checkPrint) std::cout << "Current: " << currentNode << '\n';
        std::cout << "Pop: " << currentNode << '\n';
        queue.pop();

        for (int j = 0; j < graph.size(); j++) {
            if (visitedNodes[j] == false && graph[currentNode][j] > -1) {
                if (checkPrint) std::cout << "Push: " << j << '\n';

                queue.push(j);
                visitedNodes[j] = true;
            }
        }
    }

    // Control if all nodes visited
    for (size_t i = 0; i < visitedNodes.size(); i++) {
        if (visitedNodes[i] == false) {
            fullyConnectedGraph++;
        }
    }

    if (fullyConnectedGraph == 0) {
        if (checkPrint) std::cout << "\nTrue - Connected!" << '\n';

        return true;
    }
    if (checkPrint) std::cout << "\nFalse - Not connected!" << '\n';

    return false;
}

bool dfs(std::vector<std::vector<int>> graph, bool checkPrint = false) {
    std::cout << "DFS is used to control if the graph is connected." << '\n'
              << '\n';

    std::vector<bool> visitedNodes(graph.size(), false);
    std::stack<int> stack;

    int currentNode;
    int fullyConnectedGraph = 0;

    // Push the start node to the stack and mark it as visited
    stack.push(0);
    visitedNodes[0] = true;
    int visitedNodesCounter = 1;

    // Fill's up the stack
    while (!stack.empty()) {
        currentNode = stack.top();
        visitedNodesCounter = 0;

        if (checkPrint) std::cout << "Current: " << currentNode << '\n';

        for (size_t i = 0; i < graph.size(); i++) {
            if (visitedNodes[i] == false && graph[currentNode][i] > -1) {
                if (checkPrint) std::cout << "Push: " << i << '\n';

                stack.push(i);
                visitedNodes[i] = true;
                break;
            } else {
                visitedNodesCounter++;
            }
        }

        // When all nodes is visited
        if (visitedNodesCounter == graph.size()) {
            stack.pop();

            if (checkPrint) std::cout << "Pop:" << currentNode << '\n';
        }
    }

    // Control if all nodes visited
    for (size_t i = 0; i < visitedNodes.size(); i++) {
        if (visitedNodes[i] == false) {
            fullyConnectedGraph++;
        }
    }

    if (fullyConnectedGraph == 0) {
        if (checkPrint) std::cout << "\nTrue - Connected!" << '\n';

        return true;
    }

    if (checkPrint) std::cout << "\nFalse - Not connected!" << '\n';

    return false;
}

void dijkstras(int startNode, int endNode, std::vector<std::vector<int>> graph,
               std::string searchMethod) {
    bool graphConnectionControl;

    if (searchMethod == "bfs") {
        graphConnectionControl = bfs(graph);
    } else if (searchMethod == "dfs") {
        graphConnectionControl = dfs(graph);
    }

    // If the graph is connected
    if (graphConnectionControl && graph.size() > 0) {
        struct nodeData {
            int node, weight;
        };

        struct compare {
            bool operator()(nodeData lhs, nodeData rhs) {
                return lhs.weight < rhs.weight;
            }
        };

        struct resultData {
            int node, from;
            unsigned int weight;
        };

        unsigned int inf;

        std::stack<int> resultPath;
        bool pushToResultPath = true;

        std::priority_queue<nodeData, std::vector<nodeData>, compare> priorityQueue;
        std::vector<resultData> result(graph.size(), resultData{0, 0, inf});

        // Init. step of result vector and priority queue
        result[startNode].weight = 0;
        priorityQueue.push(nodeData{startNode, 0});

        std::cout << "Graph is connected!" << '\n'
                  << "Running Dijkstra's algortihm between node "
                  << (char)('A' + startNode) << " as start and node "
                  << (char)('A' + endNode) << " as end" << '\n'
                  << '\n';

        std::cout << "Algortihm operation's: " << '\n';

        while (!priorityQueue.empty()) {
            nodeData currentNode =
                nodeData{priorityQueue.top().node, priorityQueue.top().weight};
            priorityQueue.pop();

            for (int i = 0; i < graph.size(); i++) {
                std::vector<int> neigbourWeights = graph[currentNode.node];
                int neigbourWeight = neigbourWeights[i];
                int currentWeight = currentNode.weight + neigbourWeight;

                if (neigbourWeight != -1 && result[i].weight > currentWeight) {
                    priorityQueue.push(nodeData{i, currentWeight});
                    result[i].weight = graph[currentNode.node][i];
                    result[i].node = i;
                    result[i].from = currentNode.node;

                    std::cout << "Current node "
                              << (char)('A' + currentNode.node)
                              << " with weight " << currentNode.weight
                              << " visiting node " << (char)('A' + i)
                              << " with weight " << graph[currentNode.node][i]
                              << '\n';
                }
            }
        }

        std::cout << '\n' << "Adjacency list of graph:" << '\n';

        for (size_t i = 0; i < result.size(); i++) {
            std::cout << (char)('A' + result[i].from) << " -> "
                      << (char)('A' + result[i].node) << ": weight "
                      << result[i].weight << '\n';
        }

        std::cout << '\n'
                  << "Shortest path between node " << (char)('A' + startNode)
                  << " and " << (char)('A' + endNode) << ":" << '\n';

        resultPath.push(result[endNode].node);

        int nextConnected = result[endNode].node;

        // Push result nodes to result path stack
        while (pushToResultPath) {
            nextConnected = result[nextConnected].from;
            resultPath.push(nextConnected);

            if (nextConnected == startNode) {
                pushToResultPath = false;
            }
        }

        // Print and pop the result stack
        while (!resultPath.empty()) {
            std::cout << (char)('A' + resultPath.top());

            if (resultPath.size() > 1) {
                std::cout << " -> ";
            }

            resultPath.pop();
        }

        std::cout << '\n';
    } else {
        std::cout << "The graph is not connected!" << '\n'
                  << "The algorithm will not run" << '\n';
    }
}

int main(int argc, char const *argv[]) {
    std::string file = "matrix1.txt";
    // std::string file = "matrix2.txt";
    // std::string file = "matrix3.txt";
    // std::string file = "matrix4.txt";
    // std::string file = "heavyMatrix.txt";
    // std::string file = "heavyMatrix2.txt";

    // dfs(inputData(file), true);
    // bfs(inputData(file));
    dijkstras(0, 4, inputData(file), "bfs");
    return 0;
}
