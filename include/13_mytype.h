#pragma once
#include <iostream>
#include <fstream>
namespace homework {
    /**
    * @brief A type with some members that can be serialized
    */
    class MyType {
        int i;
        double d;
    public:
        MyType(int i, double d) : i(i), d(d) {
        }
        /**
        * @brief Equality operator
        */
        auto operator==(const MyType& other) const {
            return i == other.i && d == other.d;
        }

        /**
         * @brief Write the MyType object to an output stream
         * @param os The output stream to write to
         * @param mt The MyType object to write
         * @return The output stream
         * @note The input stream is a friend function because it needs to access the private members of MyType
         */
        friend std::ofstream& operator<<(std::ofstream& os, const MyType& mt) {
            os << mt.i << ' ' << mt.d; // Writing the mt members to the output stream
            return os;
        }

        /**
         * @brief Read the MyType object from an input stream
         * @param is The input stream to read from
         * @param mt The MyType object to read into
         * @return The input stream
         * @note The output stream is a friend function because it needs to access the private members of MyType
         */
        friend std::ifstream& operator>>(std::ifstream& is, MyType& mt) {
            is >> mt.i >> mt.d; // Reading the mt members from the input stream
            return is;
        }

    };
    /**
    * @brief Write the MyType object to a file
    * @param mt The MyType object to write
    * @param filename The name of the file to write to
    */
    void writeToFile(const MyType& mt, const std::string& filename);
    /**
    * @brief Read the MyType object from a file
    * @param filename The name of the file to read from
    * @return The MyType object read from the file
    */
    MyType readFromFile(const std::string& filename);
} // namespace homework