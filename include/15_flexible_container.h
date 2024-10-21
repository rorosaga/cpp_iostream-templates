#pragma once
#include <vector>

namespace homework {

    /**
    * @brief A flexible container that can hold elements of any type.
    * @tparam T The type of the elements in the container.
    */
    template <typename T = int>
    class FlexibleContainer {
    private:
        std::vector<T> elements;

    public:

        FlexibleContainer() {};

        /**
         * @brief Constructor that takes a variadic number of elements
         * @tparam Args The types of the elements to add
         * @param args The elements to add
         */
        template <typename... Args>
        FlexibleContainer(Args... args) {
            (add(args), ...);
        }
        
        /**
         * @brief Add an element to the container
         * @param element The element to add
         */
        void add(const T& element);
        /**
         * @brief Get the number of elements in the container
         * @return The number of elements in the container
         */
        int size() const;

        /**
         * @brief Get an element from the container
         * @param index The index of the element to get
         * @return The element at the given index
         */
        T get(int index) const;

        /**
         * @brief Apply a function to each element in the container
         * @tparam Func The type of the function to apply
         * @param func The function to apply
         */
        template <typename Func>
        void map(Func func);

    };

    // Method definitions
    template <typename T>
    void FlexibleContainer<T>::add(const T& element) {
        elements.push_back(element);
    }

    template <typename T>
    int FlexibleContainer<T>::size() const{
        return elements.size();
    }

    template <typename T>
    T FlexibleContainer<T>::get(int index) const{
        return elements[index];
    }

    template <typename T>
    template <typename Func>
    void FlexibleContainer<T>::map(Func func){
        for(auto& element : elements){
            element = func(element);
        }
    }
    
}