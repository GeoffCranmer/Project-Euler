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
template <typename value_type>
Graph::Graph<value_type>::iterator::iterator(Vertex* x) : ptr(x) {}

template <typename value_type>
Graph::Graph<value_type>::iterator::iterator(const iterator& x) : ptr(x.ptr) {}

template <typename value_type>
typename Graph::Graph<value_type>::iterator Graph::Graph<value_type>::iterator::operator=(const iterator& x) {
	ptr = x.ptr;
}

// To accomplish this in a breadth-first manner, the iterator must maintain a visited list
template <typename value_type>
typename Graph::Graph<value_type>::iterator& Graph::Graph<value_type>::iterator::operator++() {

}

template <typename value_type>
bool Graph::Graph<value_type>::iterator::operator==(const iterator& x) {
	return ptr == x.ptr;
}

template <typename value_type>
bool Graph::Graph<value_type>::iterator::operator!=(const iterator& x) {
	return ptr != x.ptr;
}

template <typename value_type>
typename Graph::Graph<value_type>::Vertex& Graph::Graph<value_type>::iterator::operator*() {
	return ptr*;
}
