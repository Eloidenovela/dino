#include "util.hpp"

namespace util 
{
    void swap(int &p1, int &p2) 
    {
        int aux = p1;
        p1 = p2;
        p2 = aux;
    }

namespace math 
{
    bool is_prime(int number)
    {
        if (number <= 1) return false;

        for (int i = 2; i <= (number/2); i++)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }
}
}