#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

struct Node
{
    int name; // name of the node is represented by integer
    int cost; // cost from origin point to current point
    bool XFlag = false; // initialize XFlag to be false. This means we haven't arrive x yet.
    bool YFlag = false; // initialize YFlag to be false. This means we haven't arrive y yet.
    std::unordered_map<Node*, int> neighbors; // neighbors of the current node, key->node pointer, value->edge weight

    
    // constructor
    Node (int _name)
        : name(_name) {}
    
    // destructor
    ~Node() {}
};

struct TwoJunctions
{
    // constructor
    TwoJunctions(int s, int e, int n, int _x, int _y, 
                std::vector<int>& from, std::vector<int>& to, std::vector<int>& weight)
    {   
        // initialize variables
        start = s;
        end = e;
        g_nodes = n;
        x = _x;
        y = _y;
        g_from = from;
        g_to = to;
        g_weight = weight;

        // build up the map
        BuildMap();
    }

    // destructor
    ~TwoJunctions() {}

    int MinShortestPath()
    {
        /*
        This functrion calculate the shortest path from origin point to the goal point with constraints satisfied. 
        Dijkstra's algorithm is adopted. If no suitable path, return -1
        */

        auto comp = [](const Node* a, const Node* b)
        {
            return a->cost < b->cost;
        };

        std::priority_queue<int, std::vector<int>, decltype(comp)> res(comp); // initialize resolution
        
        std::priority_queue<Node*, std::vector<Node*>, decltype(comp)> frontier(comp); // initialize frontier

        for (auto neighbor : map[start - 1]->neighbors)
        {
            if ((neighbor.first->name == y) && (!neighbor.first->XFlag))
            {
                continue; // if we arrive y before arriving x, this path is invalid
            }
            if (neighbor.first->name == x)
            {
                neighbor.first->XFlag = true; // update XFlag
            }

            neighbor.first->cost += neighbor.second;// update the cost
            frontier.push(neighbor.first);
        }

        while(!frontier.empty())
        {
            auto curr = frontier.top();

            frontier.pop();

            for (auto neighbor : curr->neighbors)
            {
                // falg updating
                neighbor.first->XFlag = curr->XFlag; // update XFlag
                if ((neighbor.first->name == y) && (!neighbor.first->XFlag))
                {
                    continue; // if we arrive y before arriving x, this path is invalid
                }
                if (neighbor.first->name == y)
                {
                    neighbor.first->YFlag = true; // update YFlag
                }
                
                // update path cost
                neighbor.first->cost = std::min(curr->cost + neighbor.second, neighbor.first->cost);

                // judge whether arrives goal with constraints satisfied
                if ((neighbor.first->name == end) && (neighbor.first->XFlag) && (neighbor.first->YFlag))
                {

                }
            }

        }



        
    }

private:
    void BuildMap()
    {
        /*
        This function will read the given input information and build up the map
        */

        // corner case check
        if ((g_from.size() != g_to.size()) || (g_from.size() != g_weight.size()))
        {
            std::cout << "Error! Please check your input!" << std::endl;
            exit(-1);
        }
       
        // Initialize the nodes and map
        for (int name = 1; name  < g_nodes; name++)
        {   
            Node temp_node(name);
            map.push_back(&temp_node);
        }

        // construct edges
        for (int idx = 0; idx < g_from.size(); idx++)
        {
            int from = g_from[idx];
            int to = g_to[idx];
            int weight = g_weight[idx];

            map[from - 1]->neighbors[map[to - 1]] = weight; // -1 because node number start from 1
            map[to - 1]->neighbors[map[from - 1]] = weight;
        }
    }

private:
    int start;
    int end;
    int g_nodes; // number of total 
    int x; // first restrict point
    int y; // second restrict point
    std::vector<int> g_from; // initial points
    std::vector<int> g_to; // end points
    std::vector<int> g_weight; // edge weights

    std::vector<Node*> map; // graphic map
}; 

int main()
{
    // initialize input
    int start = 1;
    int end = 5;
    int g_node = 5;
    int x = 2;
    int y = 3;
    std::vector<int> g_from{1, 2, 3, 4, 5, 3};
    std::vector<int> g_to{2, 3, 4, 5, 1, 5};
    std::vector<int> g_weight{9, 11, 6, 1, 4, 10};

    TwoJunctions Solver(start, end, g_node, x, y, g_from, g_to, g_weight);

    int res = Solver.MinShortestPath();

    std::cout << "The minimum cost is: " << res << std::endl;

    return 0;
}