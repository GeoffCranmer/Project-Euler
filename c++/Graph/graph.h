#include <iterator>
#include <list>
#include <vector>

// Fundamental question:
// Should graphs be manipulated based on pointers or based on arbitrary indices?
// See: Graph::Vertex::edges, Graph::Vertex::addEdge, and Graph::addEdge

namespace Graph {

template <typename value_type> class Graph {
  private:

    class Vertex {
      private:
        value_type value;
        std::list<int> edges;

      public:
        Vertex(value_type);
        void addEdge(int);
    };

    std::vector<Vertex> adjacency_list;

  public:

    void addVertex(value_type);
    void addEdge(int, int);

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

