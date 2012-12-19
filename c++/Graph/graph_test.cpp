#include <iostream>
#include <map>
#include <vector>

#include "graph.cpp"

void main() {
    //Graph::Graph<int> graph;
    
    std::vector<int> vertices;
    vertices.push_back(3);
    vertices.push_back(7);
    vertices.push_back(4);
    
    std::multimap<int, int> edges;
    
    Graph::Graph<int> graph (vertices, edges);
    
    // Can't declare vertex pointers
    // graph.addVertex(3);
    //graph.addVertex(7);
    //graph.addVertex(4);
    
    //Graph::Graph<int>::iterator i = graph.begin();
    //std::cout << i* << " ";
    //++i;
    //std::cout << i* << " ";
    //++i;
    //std::cout << i* << std::endl;
}