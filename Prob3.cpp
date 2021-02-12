#include <iostream>

bool IsCoprime (int a, int b)
{
    /*
    Given two integers, this function would use method of successive division to justify whether the two integers are coprime or not
    */

}

int TotalRotorConfiguration(int rotorCount, int minRotorValue, int maxRotorValue)
{
    /*
    Given number of variable, range of variable, the output is the total number of feasible solutions for Enigma
    */
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