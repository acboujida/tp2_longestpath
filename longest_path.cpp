/**
 * @file longest_path.cpp
 * @author Achraf Boujida
 * @brief Implementation of the algorithm
 * @date 2024-02-19
 *
 */

#include "longest_path.h"

void read_graph(std::string file_name, graph_t& graph)
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << file_name << std::endl;
        graph.nbr_nodes = 0;
        graph.nbr_edge = 0;
        return;
    }

    file >> graph.nbr_nodes >> graph.nbr_edge;
    graph.neighbours.resize(graph.nbr_nodes);

    for (int i = 0; i < graph.nbr_edge; i++)
    {
        int node1, node2;
        file >> node1 >> node2;
        graph.neighbours[node1].push_back(node2);
        graph.neighbours[node2].push_back(node1);
    }

    file.close();
}

int BFS(int source, const graph_t graph)
{
    std::vector<bool> visited(graph.nbr_nodes, false);
    std::vector<int> distance(graph.nbr_nodes, 0);

    std::queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph.neighbours[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    int farthest_node = source;
    for (int i = 0; i < graph.nbr_nodes; ++i)
    {
        if (distance[i] > distance[farthest_node])
        {
            farthest_node = i;
        }
    }

    return farthest_node;
}

void longest_path(const graph_t graph)
{
    int farthest_node_from_source = BFS(0, graph);

    int farthest_node_from_farthest = BFS(farthest_node_from_source, graph);

    std::cout << "Longest path is between nodes " << farthest_node_from_source << " and " << farthest_node_from_farthest << std::endl;
}