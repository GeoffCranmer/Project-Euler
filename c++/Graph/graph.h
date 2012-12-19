#include <iterator>
#include <list>
#include <map>
#include <vector>

// Fundamental question:
// Should graphs be manipulated based on pointers or based on arbitrary indices?
// See: Graph::Vertex::edges, Graph::Vertex::addEdge, and Graph::addEdge
// Graphs should be manipulated based on pointers.
// The vertex class will need to either be made public or mode out of the Graph
// class altogether.
// Create a constructor that takes a vector of vertices and a map of the edges.

namespace Graph {

template <typename value_type> class Graph {
  private:

    class Vertex {
      private:
        value_type value;
        std::list<Vertex*> edges;

      public:
        Vertex(value_type);
        void addEdge(Vertex*);
    };

    std::vector<Vertex> adjacency_list;

  public:

    Graph(std::vector<value_type>, std::multimap<int, int>);
    Graph();
  
    void addVertex(value_type);
    void addEdge(Vertex*, Vertex*);

    class iterator : public std::iterator<std::forward_iterator_tag, Vertex> {
      private:
        Vertex* ptr;
      public:
        iterator(Vertex*);
        iterator(const iterator&);
        iterator operator=(const iterator&);
        iterator& operator++();
        bool operator==(const iterator&);
        bool operator!=(const iterator&);
        Vertex& operator*();
    };

};

}

