#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Heap {
    int* heap;
    int heapSize;
    int realSize;
    bool (*cmp)(int, int);
};

void init(struct Heap* obj, int n, bool (*cmp)(int, int)) {
    obj->heap = malloc(sizeof(int) * (n + 1));
    obj->heapSize = 0;
    obj->cmp = cmp;
}

bool cmp1(int a, int b) {
    return a < b;
}

bool cmp2(int a, int b) {
    return a > b;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b, *b = tmp;
}

void push(struct Heap* obj, int x) {
    int p = ++(obj->heapSize), q = p >> 1;
    obj->heap[p] = x;
    while (q) {
        if (!obj->cmp(obj->heap[q], obj->heap[p])) {
            break;
        }
        swap(&(obj->heap[q]), &(obj->heap[p]));
        p = q, q = p >> 1;
    }
}

void pop(struct Heap* obj) {
    swap(&(obj->heap[1]), &(obj->heap[(obj->heapSize)--]));
    int p = 1, q = p << 1;
    while (q <= obj->heapSize) {
        if (q + 1 <= obj->heapSize) {
            if (obj->cmp(obj->heap[q], obj->heap[q + 1])) {
                q++;
            }
        }
        if (!obj->cmp(obj->heap[p], obj->heap[q])) {
            break;
        }
        swap(&(obj->heap[q]), &(obj->heap[p]));
        p = q, q = p << 1;
    }
}

int top(struct Heap* obj) {
    return obj->heap[1];
}

bool empty(struct Heap* obj) {
    return obj->heapSize == 0;
}

struct HashTable {
    int key;
    int val;
    UT_hash_handle hh;
} * hashtable;

void prune(struct Heap* obj) {
    while (!empty(obj)) {
        int num = top(obj);
        struct HashTable* tmp;
        HASH_FIND_INT(hashtable, &num, tmp);
        if (tmp == NULL) {
            break;
        }
        tmp->val--;
        if (!(tmp->val)) {
            HASH_DEL(hashtable, tmp);
            free(tmp);
        }
        pop(obj);
    }
}

void makeBalance(struct Heap* small, struct Heap* large) {
    if (small->realSize > large->realSize + 1) {
        push(large, top(small));
        pop(small);
        --(small->realSize);
        ++(large->realSize);
        prune(small);
    } else if (small->realSize < large->realSize) {
        push(small, top(large));
        pop(large);
        ++(small->realSize);
        --(large->realSize);
        prune(large);
    }
}

void insert(struct Heap* small, struct Heap* large, int num) {
    if (empty(small) || num <= top(small)) {
        push(small, num);
        ++(small->realSize);
    } else {
        push(large, num);
        ++(large->realSize);
    }
    makeBalance(small, large);
}

void erase(struct Heap* small, struct Heap* large, int num) {
    struct HashTable* tmp;
    HASH_FIND_INT(hashtable, &num, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = num;
        tmp->val = 1;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        tmp->val++;
    }
    if (num <= top(small)) {
        --(small->realSize);
        if (num == top(small)) {
            prune(small);
        }
    } else {
        --(large->realSize);
        if (num == top(large)) {
            prune(large);
        }
    }
    makeBalance(small, large);
}

double getMedian(struct Heap* small, struct Heap* large, int k) {
    return (k & 1) ? top(small) : (((double)top(small) + top(large)) / 2);
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    hashtable = NULL;
    struct Heap* small = malloc(sizeof(struct Heap));
    init(small, numsSize, cmp1);
    struct Heap* large = malloc(sizeof(struct Heap));
    init(large, numsSize, cmp2);
    for (int i = 0; i < k; ++i) {
        insert(small, large, nums[i]);
    }
    double* ans = malloc(sizeof(double) * (numsSize - k + 1));
    *returnSize = 0;
    ans[(*returnSize)++] = getMedian(small, large, k);
    for (int i = k; i < numsSize; ++i) {
        insert(small, large, nums[i]);
        erase(small, large, nums[i - k]);
        ans[(*returnSize)++] = getMedian(small, large, k);
    }
    return ans;
}

int main()
{
    int numsSize =0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int k = 0;
    scanf("%d",&k);
    int count = 0;
    double * mid=medianSlidingWindow(nums,nums,k,&count);
    for(int i=0;i<count;i++)
    {
        printf("%lf",mid[i]);
    }
    return 0;
}

/* static int compare(const void *a, const void *b)//排序函数//超出时间限制
{
    if ((long)(*(int *) a > (long)*(int *) b)) 
    {
        return 1;
    } 
    else if ((long)(*(int *) a > (long)*(int *) b)) 
    {
        return 0;
    } 
    else 
    {
        return -1;
    }
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = numsSize-k+1;
    double *result=(double *)malloc((*returnSize)*sizeof(double));
    int * temp=(int *)malloc(k*sizeof(int));//该数组用来存储当前窗口处的元素，并用来进行排序.
    for(int i=0; i<k; i++)
    {
        temp[i]=nums[i];
    }
    qsort(temp,k,sizeof(int),compare);
    int flag=k%2;//用来判断中位数是否需要除以2
    if(flag==0)//如果为偶数，则中位数为中间两位的平均数
    {
        result[0] = (double) ((long) temp[(int) (k / 2 - 1)] + (long) temp[(int) (k / 2)]) / 2;//
    }
    else
    {
        result[0]= (double) ((long)temp[(int)((k-1)/2)]);//直接为中间的元素.
    }
    int add_value, remove_value;//分别为窗口一次滑动需要添加的右边元素，与左端减少的元素
    int remove_index = -1;
    for (int i = 1; i < *returnSize; i++) 
    {
        add_value = nums[i + k - 1];//添加
        remove_value = nums[i - 1];//减少
        int is_add = 0;
        if (add_value != remove_value) //对temp中的数进行赋值。减去的元素与增加的元素不同
        {
            for (int j = 0; j < k; j++) 
            {
                if (temp[j] == remove_value) 
                {
                    remove_index = j;
                    break;
                }
            }
            if (add_value > remove_value) 
            {
                for (int j = remove_index + 1; j < k; j++) 
                {
                    if (add_value > temp[j]) 
                    {
                        temp[j - 1] = temp[j];
                    } 
                    else 
                    {
                        temp[j - 1] = add_value;
                        is_add = 1;
                        break;
                    }
                }
                if (is_add == 0) 
                {
                    temp[k - 1] = add_value;
                }
            } 
            else //减去的元素与增加的元素相同
            {
                for (int j = remove_index - 1; j > -1; j--) {
                    if (add_value < temp[j]) 
                    {
                        temp[j + 1] = temp[j];
                    } 
                    else 
                    {
                        temp[j + 1] = add_value;
                        is_add = 1;
                        break;
                    }
                }
                if (is_add == 0) 
                {
                    temp[0] = add_value;
                }
            }
        }
        if (flag == 0) //该处操作为对返回数组进行赋值.
        {
            result[i] = (double) ((long) temp[(int) (k / 2 - 1)] + (long) temp[(int) (k / 2)]) / 2;
        } 
        else 
        {
            result[i] = (double) (temp[(int) ((k - 1) / 2)]);
        }
    }
    return result;
} */