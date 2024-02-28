/**
 * @file longest_path.h
 * @author Achraf Boujida
 * @brief declarations of functions
 * @date 2024-02-19
 *
 */

#ifndef LONGEST__H
#define LONGEST__H

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

/**
 * @brief Structure representing a graph.
 */
typedef struct graph {
    int nbr_edge; /**< Number of edges in the graph. */
    int nbr_nodes; /**< Number of nodes in the graph. */
    std::vector<std::vector<int>> neighbours; /**< Adjacency list representing the graph. */
} graph_t;

/**
 * @brief Reads graph data from a file and populates the provided graph structure.
 * 
 * @param file_name The name of the file containing graph data.
 * @param graph Reference to the graph structure to be populated.
 */
void read_graph(std::string file_name, graph_t& graph);

/**
 * @brief Performs a breadth-first search (BFS) starting from the given source node
 *        and returns the farthest node reached.
 * 
 * @param source The source node for the BFS.
 * @param graph Reference to the graph structure.
 * @return The farthest node reached from the source node.
 */
int BFS(int source, const graph_t graph);

/**
 * @brief Finds the longest path in the graph.
 * 
 * @param graph The graph structure.
 */
void longest_path(const graph_t graph);

#endif