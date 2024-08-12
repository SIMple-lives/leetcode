#include <vector>
#include <string>

class MagicDictionary {
public:
    std::vector<std::string> dict;
    MagicDictionary() 
    {
        dict.clear();
    }
    
    void buildDict(std::vector<std::string> dictionary) 
    {
        dict = dictionary;
    }
    
    bool search(std::string searchWord) 
    {
        for(int i = 0; i < dict.size(); i++)
        {
            if(dict[i].size() != searchWord.size())
                continue;
            int diff = 0;
            for(int j = 0; j < searchWord.size(); j++)
            {
                if(searchWord[j] != dict[i][j])
                    diff++;
            }
            if(diff == 1)
                return true;
        }
        return false;
    }
};

