#include "triangle.h"

Triangle::Node::Node(int v) : value(v), left(NULL), right(NULL) {}

Triangle::Triangle() {
    nodes.push_back(Node(3));
    nodes.push_back(Node(7));
    nodes.push_back(Node(4));
    nodes.push_back(Node(2));
    nodes.push_back(Node(4));
    nodes.push_back(Node(6));
    nodes.push_back(Node(8));
    nodes.push_back(Node(5));
    nodes.push_back(Node(9));
    nodes.push_back(Node(3));

    nodes[0].set_left(&nodes[1]);
    nodes[0].set_right(&nodes[2]);

    nodes[1].set_left(&nodes[3]);
    nodes[1].set_right(&nodes[4]);
    nodes[2].set_left(&nodes[4]);
    nodes[2].set_right(&nodes[5]);
    
    nodes[3].set_left(&nodes[6]);
    nodes[3].set_right(&nodes[7]);
    nodes[4].set_left(&nodes[7]);
    nodes[4].set_right(&nodes[8]);
    nodes[5].set_left(&nodes[8]);
    nodes[5].set_right(&nodes[9]);
}

Triangle::Triangle(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
    // Push all inputs onto nodes
    for (std::vector<int>::iterator i = begin; i != end; ++i) {
        nodes.push_back(Node(*i));
    }

    // Sort nodes into rows of increasing width
    std::vector<std::vector<Node*> > rows;
    int row_num = 0;

    std::vector<Node>::iterator i = nodes.begin();
    while (i != nodes.end()) {
        std::vector<Node*> new_row;

        // Push row_num + 1 nodes into new_row
        int j = 0;
        while (j < row_num + 1 && i != nodes.end()) {
            new_row.push_back(&(*i));
            ++i;
            ++j;
        }

        rows.push_back(new_row);
        row_num++;

    }

    // For each row, set the left and right pointers to the appropriate spots in the next row
    for (std::vector<std::vector<Node*> >::iterator i = rows.begin(); i != rows.end() - 1; ++i) {
        for (std::vector<Node*>::iterator j = i->begin(); j != i->end(); ++j) {
            // Each node should point to the next row item with the same index and index + 1
            int index = j - i->begin();
            (**j).set_left((i + 1)->at(index));
            (**j).set_right((i + 1)->at(index + 1));
        }
    }
}

int Triangle::find_max_path() {
    return find_max_subpath(&nodes[0]);
}

int Triangle::find_max_subpath(Node* root) {
    if (root->get_left() == NULL && root->get_right() == NULL) {
        return root->get_value();
    }
    else {
        // Return the greater of the two child paths
        int left_max = find_max_subpath(root->get_left());
        int right_max = find_max_subpath(root->get_right());

        if (left_max > right_max) {
            return root->get_value() + left_max;
        }
        else {
            return root->get_value() + right_max;
        }
    }
}