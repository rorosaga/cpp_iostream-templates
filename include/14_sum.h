#pragma once
#include <vector>
#include <tuple>
namespace homework{
    /**
    * @brief Metafunction for summing the elements of a vector holding elements of any type
    * @param s The vector to sum
    * @param v The initial value of the sum
    * @tparam T The type of the elements in the vector
    * @return The sum of the elements in the vector, plus the initial value
    */
    template <typename T>
    auto sum_elements(std::vector<T>& s, T v){
        for(const auto& elem : s){
            v += elem;
        }
        return v;
    }

    // string specialization
    template <>
    auto sum_elements <std::string>(std::vector<std::string>& s, std::string v){
        for(const auto& elem : s){
            v += elem;
        }
        std::cout << v << std::endl;
        return v;
    }

    // for generic containers 
    template <typename Container>
    auto sum_elements(Container& s, typename Container::value_type v){
        for(const auto& elem : s){
            v += elem;
        }
        return v;
    }

    /**
     * @brief Function to create a tuple from a variadic number of arguments (using variadic templates)
     * @tparam Args The types of the arguments
     * @param args The arguments to put in the tuple
     * @return A tuple containing the arguments
     */
    template <typename... Args>
    auto make_tuple(Args... args){
        return std::make_tuple(args...);
    }

} // namespace homework