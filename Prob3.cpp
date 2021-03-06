#include <iostream>
#include <math.h>

int GCD (int a, int b)
{
    /*
    This function will return the greatest common divisor of two integers 
    */

   if (b == 0)
   {
       return a;
   }
   else
   {
       return GCD(b, a%b);
   }
}

bool IsCoprime (int a, int b)
{
    /*
    Given two integers (a > b by default), this function would justify whether the two integers are coprime or not.
    */

    if (a < b)
    {
        std::swap(a, b); // swap a and b to make a > b
    }

    if (GCD(a,b) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int TotalRotorConfiguration(int rotorCount, int minRotorValue, int maxRotorValue)
{
    /*
    Given number of variable, range of variable, the output is the total number of feasible solutions for Enigma
    */
    int res = 0; // initialize resolution

    for (int begin = minRotorValue; begin <= maxRotorValue; begin++)
    {
        int num_coprime = 0; // initialize number of coprimes to the first number 

        for (int idx = minRotorValue; idx <= maxRotorValue; idx++)
        {
            if (IsCoprime(begin, idx))
            {
                num_coprime++;
            }
        }
        res += pow(num_coprime, rotorCount - 1);
    }

    return res;
}

int main()
{
    int rotorCount = 3;
    int minRotorValue = 2;
    int maxRotorValue = 4;

    // run the TotalROtorConfiguration function
    int res = TotalRotorConfiguration(rotorCount, minRotorValue, maxRotorValue);

    // output result 
    std::cout << "The number of feasible solutions is: " << res << std::endl;

    return 0;
}