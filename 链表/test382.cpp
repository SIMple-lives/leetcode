#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
        std::vector<int> nums;
public:
    Solution(ListNode* head) 
    {
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() 
    {
        return nums[rand() % nums.size()];
    }
};

int main()
{
    std::vector<int> nums = {1,2,3};
    ListNode* head = new ListNode(nums[0]);
    for(int i = 1; i < nums.size(); i++)
    {
        ListNode* temp = new ListNode(nums[i]);
        head->next = temp;
        head = temp;
    }
    Solution* obj = new Solution(head);
    std::cout << obj->getRandom() << std::endl;
    return 0 ;  
}