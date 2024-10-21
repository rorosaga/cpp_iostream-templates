#include "13_split.h"
#include <string>
#include <vector>
#include <sstream>

namespace homework{

    std::vector<std::string> split(const std::string& str){
        std::vector<std::string> result;

        std::istringstream ss(str); // ss is stream string

        for(std::string word; ss>>word;){
            result.push_back(word); 
        }

        return result;
    }
}