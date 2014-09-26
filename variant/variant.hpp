// "<Copyright 2014 Giacomo Dabisias>"

#pragma once
#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <string>

// defines the type in the arg list that has the biggest type
template <typename... List>
struct FindMaxSizeType;

template <typename First>
struct FindMaxSizeType<First> {
    typedef First type;
};

template <typename First, typename... List>
struct FindMaxSizeType<First, List...> {
    typedef typename FindMaxSizeType<List...>::type next;
    typedef typename std::conditional<sizeof(First) >= sizeof(next), First, next>::type type;
};

// defines the type in the arg list that has the biggest align
template <typename... List>
struct FindMaxAlignType;

template <typename First>
struct FindMaxAlignType<First> {
    typedef First type;
};

template <typename First, typename... List>
struct FindMaxAlignType<First, List...> {
    typedef typename FindMaxAlignType<List...>::type next;
    typedef typename std::conditional<alignof(First) >= alignof(next), First, next>::type type;
};

// defines value as the index of the searched type in the arg list
template <typename ToFind, size_t index, typename... List>
struct FindIndexByType{};

template <typename ToFind, size_t index, typename First>
struct FindIndexByType<ToFind, index, First> {
    enum {value = std::is_same<ToFind, First>::value ? index : -1};
};

template <typename ToFind, size_t index, typename First, typename... List>
struct FindIndexByType<ToFind, index, First, List...> {
    enum {value = std::is_same<ToFind, First>::value ? index : FindIndexByType<ToFind, index+1, List...>::value};
};

// defines type as the type at position index in the arg list
template <size_t toFind, size_t cur_index, typename... List>
struct FindTypeByIndex{};

template <size_t toFind, size_t cur_index, typename First>
struct FindTypeByIndex<toFind, cur_index, First> {
    typedef typename std::conditional<toFind == cur_index, First, void>::type type;
};

template <size_t toFind, size_t cur_index, typename First, typename... List>
struct FindTypeByIndex<toFind, cur_index, First, List...> {
    typedef typename std::conditional<toFind == cur_index, First, typename FindTypeByIndex<toFind, cur_index+1, List...>::type>::type type;
};

// checks if a type is present in the arg list
template <typename ToFind, typename... List>
struct IsPresent{};

template <typename ToFind,  typename First>
struct IsPresent<ToFind, First> {
    enum {value = std::is_same<ToFind, First>::value ? true : false};
};

template <typename ToFind, typename First, typename... List>
struct IsPresent<ToFind, First, List...> {
    enum {value = std::is_same<ToFind, First>::value ? true : IsPresent<ToFind, List...>::value};
}; 


template <typename... Args>
struct Variant {
public:
    Variant() {
        data = new char[sizeof(max_size_type)];
        current_type_index = -1;
    }

    void
    PrintInfo() {
        std::cout << "type " << typeid(max_size_type).name() << " size "
                  << sizeof(data) << " align " << alignof(max_align_type) << std::endl;
    }

    template<typename T>
    int
    FindIdxByType() {
        return static_cast<int>(FindIndexByType<T, 0, Args...>::value);
    }

    template<size_t i>
    std::string
    FindTpByIndex() {
        std::string tmp = typeid(typename FindTypeByIndex<i, 0, Args...>::type).name();
        if (tmp == "v")
            return "out of range";
        return tmp;
    }

    void
    Clear() {
        delete [] data;
        data = new char[sizeof(max_size_type)];
    }

    template<typename T>
    void
    operator=(T t){
        current_type_index = FindIdxByType<T>();
        data = (char*)(new T(t));
    }
    
    template<typename T>
    T GetDataByType() {
        if( FindIndexByType<T, 0, Args...>::value == current_type_index)
            return (T)*data;
        throw std::exception();
    }

private:
    typedef typename FindMaxAlignType<Args...>::type max_align_type;
    typedef typename FindMaxSizeType<Args...>::type max_size_type;
    char * data;
    size_t align;
    size_t current_type_index;
};
