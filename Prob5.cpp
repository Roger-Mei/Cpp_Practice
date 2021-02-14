 vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
{
    int trgetLevel; // locate the target 
    int level = 0; // initialize level
    queue<Node*> q; // initialize queue for BFS
    q.push(root); // push the root node into BFS
    unordered_map<int, vector<int>> Dict; // key-> level, value->numbers in the level
    vector<int> res; // initialize resolution
    
    
    //BFS
    while (!q.empty())
    {
        int q_size = q.size();
        
        while(q_size-->0)
        {
            Node* curr_node = q.front(); // retrieve the first element in the queue
            Dict[level].push_back(root->val); // push the value to the current level
            q.pop(); // pop the first element
            
            if (curr_node->val == target->val)
            {
                targetLevel = level; // locate the target node
            }
        }
        
        level++; // increment level
    }
    
    // procerss the relative distance
    if (Dict[targetLevel + K].size()) // examine and traverse the lower side
    {
        for (auto a : Dict[targetLevel+K])
        {
            res.push_back(a);
        }
    }
    
    if ( (targetLevel - K) >= 0 )//examine and traverse the upper side (don't need to traverse through the root node)
    {
        for (auto a : Dict[targetLevel+K])
        {
            res.push_back(a);
        }
    }
    
}