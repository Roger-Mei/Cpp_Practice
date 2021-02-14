#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int minKnightMoves(int x, int y) {
        // Corner case check
        if ((x == 0) && (y == 0))
        {
            return 0;
        }
        
        vector<vector<int>> dirs{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}}; // specify directions
        queue<vector<int>> q; // initialize queue for BFS
        q.push({0,0}); // push the initiali state in queue for BFS
        unordered_set<string> visited{"0,0"}; // initialize visited set
        int res = 0; // initialize resolution
        
        // BFS
        while (!q.empty())
        {
            int q_size = q.size();
            while (q_size-- > 0)
            {
                vector<int> curr = q.front();
                q.pop(); // pop the front element of the queue
                visited.insert(to_string(curr[0])+","+to_string(curr[1])); //update the visited list
                
                for (auto dir : dirs)
                {
                    int new_x = curr[0] + dir[0]; // inecrement x
                    int new_y = curr[1] + dir[1]; // increment y
                    if (visited.count(to_string(new_x)+","+to_string(new_y)))
                    {
                        continue; // This point has been veisited
                    }
                    else
                    {
                        if ((new_x == x) && (new_y == y))
                        {
                            return ++res; // terminate condition
                        }
                        else
                        {
                            q.push({new_x, new_y}); // push the element in q
                        }
                    }
                    
                }
            }
            res++; // increment step size
        }
    }

    int main() 
    {
        int x = 5;
        int y = 5;

        // output result 
        int res = minKnightMoves(x,y);

        cout  << "The final result is: " << res << endl;

        return 0;
    }