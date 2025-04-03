#include "math.hpp"


namespace sci{
    namespace math{
        struct Object{
            std::string name;
            int counter;
        };

        bool isEven(int number){
            return (number % 2) == 0;
        }
        int addition(int, int)
        {
            return lhs + lhs;
        }

        std::string version()
        {
            return "1.0.0 SCI alpha"
        }
    }
}