#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> path;
    void dfs(std::vector<std::vector<int>> &graph,int index)
    {
        if(index==graph.size()-1)
        {
            ret.push_back(path);
            return;
        }
        for(int i=0;i<graph[index].size();i++)
        {
            path.push_back(graph[index][i]);
            dfs(graph,graph[index][i]);
            path.pop_back();
        }
    }
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) { 
        path.push_back(0);
        dfs(graph,0);
        return ret;
    }
};

int main()
{
    std::vector<std::vector<int>> graph;
    std::vector<int> v1={4,3,1};
    std::vector<int> v2={3,2,4};
    std::vector<int> v3={3};
    std::vector<int> v4={4};
    std::vector<int> v5;
    graph.push_back(v1);
    graph.push_back(v2);
    graph.push_back(v3);
    graph.push_back(v4);
    graph.push_back(v5);
    Solution s;
    std::vector<std::vector<int>> a=s.allPathsSourceTarget(graph);
    for(auto i:a)
    {
        for(auto j:i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}