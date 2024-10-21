#include "13_mytype.h"
#include <iostream>
#include <fstream>

namespace homework {

    void writeToFile(const MyType& mt, const std::string& filename) {
        // Write the MyType object to a file with the given filename
        std::ofstream ofile(filename);
        ofile << mt << std::endl;
    }

    MyType readFromFile(const std::string& filename) {
        // Read the MyType object from a file with the given filename and return it
        std::ifstream ifile(filename);
        MyType mt(0, 0.0); // temporary object to store file object

        ifile >> mt;

        return mt;
    }
}