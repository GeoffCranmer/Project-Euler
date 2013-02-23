#include <fstream>
#include <iostream>

#include "triangle.h"

int main(int argv, char** argc) {
    
    std::string filename = "18.txt";

    // Read input file
    std::ifstream ifs (filename, std::ifstream::in);

    std::vector<int> v;
    while (ifs.good()) {
        int i;
        ifs >> i;
        v.push_back(i);
    }

    ifs.close();

    Triangle triangle (v.begin(), v.end());

    int max_path = triangle.find_max_path();
    std::cout << max_path << std::endl;

    return 0;
}