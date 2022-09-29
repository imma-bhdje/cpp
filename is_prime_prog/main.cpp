#include <iostream>
#include <valarray>
#include<math.h>

int main(int argc, char **argv) 
{
    unsigned int number;

    while (std::cin >> number) 
    {
        if (number <= 1) 
        {
            std::cout << number << " is a prime: False" << std::endl;
            continue;
        }

        bool is_prime = true;
        unsigned int root = sqrt(number);

        for (unsigned int i = 2; i <= root; ++i) 
        {
            if (number % i == 0) 
            {
                is_prime = false;
                break;
            }
        }
        std::cout << number << " is a prime: ";
        if (is_prime)
            std::cout << "True" << std::endl;
        else
            std::cout << "False" << std::endl;
    }

    return 0;
}
