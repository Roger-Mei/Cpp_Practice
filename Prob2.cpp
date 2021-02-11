#include <iostream>
#include <unordered_map>
#include <vector>

struct Node
{
    int name; // name of the node is represented by integer
    std::unordered_map<Node*, int> neighbors; // neighbors of the current node, key->node pointer, value->edge weight
    
    // constructor
    Node (int _name)
        : name(_name) {};
    
    // destructor
    ~Node() {};
};

struct TwoJunctions
{
    int MinShortestPath()
    {
        /*
        This functrion calculate the shortest path from origin point to the goal point with constraints satisfied. 
        If no suitable path, return -1
        */

    }

    // constructor
    TwoJunctions(int n, int _x, int _y, 
                std::vector<int>& from, std::vector<int>& to, std::vector<int>& weight)
    {   
        // initialize variables
        g_nodes = n;
        x = _x;
        y = _y;
        g_from = from;
        g_to = to;
        g_weight = weight;

        // build up the map
        BuildMap();
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

}