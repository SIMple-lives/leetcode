//#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>

struct hashtable
{
    int key;
    int val;
    UT_hash_handle hh;
};

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    struct hashtable *hashtable=NULL;
    for(int i=0; i<nums1Size; ++i)
    {
        for(int j=0; j<nums2Size; ++j)
        {
            int ikey = nums1[i] + nums2[j];
            struct hashtable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if(tmp==NULL)
            {
                struct hashtable *tmp = malloc(sizeof(struct hashtable));
                tmp->key = ikey, tmp->val = 1;
                HASH_ADD_INT(hashtable, key, tmp);
            }
            else
            {
                tmp->val++;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<nums3Size; ++i)
    {
        for(int j=0; j<nums4Size; ++j)
        {
            int ikey = -nums3[i] - nums4[j];
            struct hashtable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if(tmp != NULL)
            {
                ans += tmp->val;
            }
        }
    }

    return ans;
}