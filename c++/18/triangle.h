#include <vector>

class Triangle {
private:
    class Node {
    private:
        int value;
        Node* left;
        Node* right;
    public:
        Node(int);

        void set_left(Node* l) { left = l; }
        void set_right(Node* r) { right = r; }

        int get_value() { return value; }
        Node* get_left() { return left; }
        Node* get_right() { return right; }
    };

    std::vector<Node> nodes;

    int find_max_subpath(Node*);

public:
    Triangle();
    Triangle(const std::vector<int>::iterator&, const std::vector<int>::iterator&);

    int find_max_path();
};