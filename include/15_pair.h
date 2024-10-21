#pragma once

namespace homework{

    /**
    * @brief A class template that holds two values of any type.
    * @tparam T1 The type of the first value.
    * @tparam T2 The type of the second value.
    */
    template<typename T1, typename T2>
    class Pair {
    public:
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) : first(first), second(second) {}

    };
}