#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

std::vector<int> FrequencyOfMaxValue(std::vector<int> &price, std::vector<int> &query)
{
    /*
     This is the function calculating the frequency of maximum value.
     Input: price -> the price list; query -> the query list
     Output: the query result
    */

    int p_size = price.size(); // size of the price list
    int q_size = query.size(); // size of the query list

    std::vector<int> res; // initialize resolution

    for (auto idx_q : query)
    {
        int maximum = INT_MIN; // initialize maximum number
        int freq_max = 0; // initialize frequency of maximum number

        for (auto idx_p = idx_q - 1; idx_p < p_size; idx_p ++)
        {
            if (price[idx_p] > maximum)
            {   
                freq_max = 0; // reset frequency of maximum number
                maximum = std::max(price[idx_p], maximum); // reset maximum number
                freq_max ++; // increment maximum number
            }
            else if (price[idx_p] == maximum)
            {
                freq_max ++; // increment maximum number
            }
        }

        res.push_back(freq_max); //push back the result
    }

    return res;
}

int main() 
{
    /*
    This is the main function for running and testing the FrequencyOfMaxValue function
    */

    std::vector<int> price{5, 4, 5, 3, 2};
    std::vector<int> query{1, 2, 3, 4, 5};

    std::vector<int> res = FrequencyOfMaxValue(price, query);

    std::cout << "The output result is: " << std::endl;

    for (auto a : res)
    {
        std::cout << a << std::endl;
    }

    return 0;
}