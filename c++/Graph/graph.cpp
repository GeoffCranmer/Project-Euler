#include "graph.h"

namespace Graph {

// Vertex functions
template <typename value_type>
Graph<value_type>::Vertex::Vertex(value_type value) : value(value) {}

template <typename value_type>
void Graph<value_type>::Vertex::addEdge(Vertex* tail) {
    edges.push_back(tail);
}

// Graph constructors
template <typename value_type>
Graph<value_type>::Graph(std::vector<value_type> vertices, std::multimap<int, int> edges) {
    // Copy vertices
    for (std::vector<value_type>::iterator i = vertices.begin();
         i != vertices.end(); ++i) {
        adjacency_list.push_back(Graph<value_type>::Vertex(*i));
    }
    // Copy edges
    for (std::multimap<int, int>::iterator i = edges.begin();
         i != edges.end(); ++i) {
        adjacency_list[i->first].addEdge(&adjacency_list[i->second]);
    }
}

template<typename value_type>
Graph<value_type>::Graph() {}

// Graph modifiers
template <typename value_type>
void Graph<value_type>::addVertex(value_type value) {
    adjacency_list.append(Vertex(value));
}

template <typename value_type>
void Graph<value_type>::addEdge(Vertex* head, Vertex* tail) {
    adjacency_list[head].addEdge(tail);
}

// Iterators
template <typename value_type>
Graph<value_type>::iterator::iterator(Vertex* x) : ptr(x) {}

template <typename value_type>
Graph<value_type>::iterator::iterator(const iterator& x) : ptr(x.ptr) {}

template <typename value_type>
typename Graph<value_type>::iterator Graph<value_type>::iterator::operator=(const iterator& x) {
	ptr = x.ptr;
}

// To accomplish this in a breadth-first manner, the iterator must maintain a visited list
template <typename value_type>
typename Graph<value_type>::iterator& Graph<value_type>::iterator::operator++() {

}

template <typename value_type>
bool Graph<value_type>::iterator::operator==(const iterator& x) {
	return ptr == x.ptr;
}

template <typename value_type>
bool Graph<value_type>::iterator::operator!=(const iterator& x) {
	return ptr != x.ptr;
}

template <typename value_type>
typename Graph<value_type>::Vertex& Graph<value_type>::iterator::operator*() {
	return ptr*;
}

}