/**************************
*   C++ Project Template by Ryan Molecke, Ph.D.
*   Tuesday, October 28th, 2014
*
*   includes simple CMake build system
*   includes clang scripts
*
*    to build test: from top folder
*       mkdir build
*       cmake ..
*       make
*
***************************/

// memory include to test C++11 build
#include <memory>
#include <iostream>
#include <vector>
#include <gPoint.hpp>

using namespace std;

int main(int argc, char **argv){

    std::cout
            << "¸.·´¯`·.¸¸.·´ NURBSurfer - Build Test Passed `·.¸¸.·´¯`·.¸\n";

    int64_t index = 0; // right now points just have a single global int64_t index

    // objects to test the OpenNURBS lib include
    vector<double> coords0 = {0.0, 0.0, 0.0};
    auto point0 = make_shared<gPoint<double>>(coords0, index++);

    
}
