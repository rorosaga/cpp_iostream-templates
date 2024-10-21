#include <iostream>
namespace homework{

    /**
     * @brief A type trait that checks if a type is a raw pointer.
     * @tparam T The type to check.
     */
    template <typename T>
    struct IsRawPointer{
        static constexpr bool value = false;

    };

    template <typename T>
    struct IsRawPointer<T*>{
        static constexpr bool value = true;
    };

    template <typename T>
    constexpr bool IsRawPointer_v = IsRawPointer<T>::value;

}