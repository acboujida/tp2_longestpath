/**
 * @file longest_path_unit_test.cpp
 * @author Achraf Boujida
 * @brief File that contain some test
 * @date 2024-02-28
 * 
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "longest_path.h"

TEST_CASE("TEST read_graph function: Test reading a valid graph file")
{
    graph_t graph;
    read_graph("input_file.txt", graph);
    REQUIRE(graph.nbr_nodes == 5);
    REQUIRE(graph.nbr_edge == 6);
}

TEST_CASE("TEST read_graph function: Test reading a non existent graph file")
{
    graph_t graph;
    read_graph("nonexistent_file.txt", graph);
    REQUIRE(graph.nbr_nodes == 0);
    REQUIRE(graph.nbr_edge == 0);
}

TEST_CASE("TEST BFS function: on a graph with multiple nodes")
{
    graph_t graph;
    graph.nbr_nodes = 5;
    graph.nbr_edge = 6;
    graph.neighbours = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    };
    int farthest_node = BFS(0, graph);
    REQUIRE(farthest_node == 4);
}

TEST_CASE("TEST BFS function: on a graph with only two nodes")
{
    graph_t graph;
    graph.nbr_nodes = 2;
    graph.nbr_edge = 1;
    graph.neighbours = {
        {1},
        {0}
    };
    int farthest_node = BFS(0, graph);
    REQUIRE(farthest_node == 1);
}

TEST_CASE("TEST BFS function: on a disconnected graph")
{
    graph_t graph;
    graph.nbr_nodes = 5;
    graph.nbr_edge = 0;
    graph.neighbours =
    {
        {},
        {},
        {},
        {},
        {}
    };
    int farthest_node_disconnected = BFS(0, graph);
    REQUIRE(farthest_node_disconnected == 0);
}

TEST_CASE("Test longest_path function: on a graph with multiple nodes")
{
    graph_t graph;
    graph.nbr_nodes = 5;
    graph.nbr_edge = 6;
    graph.neighbours = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    };

    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    longest_path(graph);
    std::string result = output.str();
    std::cout.rdbuf(oldCout);

    REQUIRE((result.find("Longest path is between nodes 4 and 0") != std::string::npos || result.find("Longest path is between nodes 0 and 4") != std::string::npos));
}

TEST_CASE("Test longest_path function: on a graph with only two nodes")
{
    graph_t graph;
    graph.nbr_nodes = 2;
    graph.nbr_edge = 1;
    graph.neighbours = {
        {1},
        {0}
    };

    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    longest_path(graph);
    std::string result = output.str();
    std::cout.rdbuf(oldCout);

    REQUIRE((result.find("Longest path is between nodes 1 and 0") != std::string::npos || result.find("Longest path is between nodes 0 and 1") != std::string::npos));
}