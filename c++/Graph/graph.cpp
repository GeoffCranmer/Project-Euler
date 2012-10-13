#include "graph.h"

// Vertex functions
template <typename value_type>
Graph::Graph<value_type>::Vertex::Vertex(value_type value) : value(value) {}

template <typename value_type>
void Graph::Graph<value_type>::Vertex::addEdge(int tail) {
    edges.push_back(tail);
}

// Graph modifiers
template <typename value_type>
void Graph::Graph<value_type>::addVertex(value_type value) {
    adjacency_list.append(Vertex(value));
}

template <typename value_type>
void Graph::Graph<value_type>::addEdge(int head, int tail) {
    adjacency_list[head].addEdge(tail);
}

// Iterators
//template <typename value_type>
//void Graph::Graph<value_type>::iterator::operator++() {

//}
