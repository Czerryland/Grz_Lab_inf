#ifndef SCI_DUMMYLIB_MATH_HPP
#define SCI_DUMMYLIB_MATH_HPP

#include <api.hpp>
#include <string>

namespace sci{
    namespace math{
        struct Object{
            std::string name;
            int counter;
        };

        __declspec(dllexport) bool isEven(int number);
        __declspec(dllexport)int addition(int, int);

        std::string version();
    }
}

#endif // SCI_DUMMYLIB_MATH_HPP