 /*
 Given a string, you need to output the least number of characters you need to change, s.t. any character
 is different from their neibors
 */

#include <iostream>

int Solver(std::string s)
{
    /*
    * This is the primary solver function 
    */ 

    int res = 0; // initialize resolution

    // we need to find out number of pairs
    for (int idx = 0; idx < s.length(); idx++)
    {
        if (s[idx] == s[idx+1])
        {   
            res++; 
            res += Solver(s.substr(idx+2));
            return res;
        }
    }

    return res;
    
}

int main() 
{
    std::string s = "aaaabsbs";

    int res = Solver(s);

    std::cout << "You need to modify " << res << " numbers" << std::endl;

    return 0;
}