/* 
 * File:   util.hpp
 * Author: jun
 *
 * Created on September 1, 2018, 11:19 AM
 */

#ifndef LIB_UTIL_HPP
#define LIB_UTIL_HPP

#include <iostream>


template<typename _Container>
inline std::ostream& print_list(_Container& container, std::ostream& out) {
    out << '[';
    if (container.empty()) {
        out << ']';
        return out;
    }
    for (auto p = std::begin(container);;) {
        out << *p;
        if (++p == std::end(container)) {
            out << ']';
            return out;
        }
        out << ", ";
    }
    return out;
}

template<typename _Container>
inline std::ostream& print_list(const _Container& container, std::ostream& out) {
    out << '[';
    if (container.empty()) {
        out << ']';
        return out;
    }
    for (auto p = std::begin(container);;) {
        out << *p;
        if (++p == std::end(container)) {
            out << ']';
            return out;
        }
        out << ", ";
    }
    return out;
}

template<typename _Container>
inline std::ostream& print_list(_Container& container) {
    return print_list(container, std::cout);
}

template<typename _Container>
inline std::ostream& print_list(const _Container& container) {
    return print_list(container, std::cout);
}


#endif /* UTIL_HPP */

