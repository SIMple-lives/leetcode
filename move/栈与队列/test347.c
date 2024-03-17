#include <stdio.h>
#include <stdlib.h>

typedef struct Stack 
{
    int num;
    int frep;
} Stack;

void swap(Stack* a, Stack* b) //交换两个结点
{
    Stack tmp = *a;
    *a = *b;
    *b = tmp;
}

void minHeapify(Stack* S, int size, int i) //构造小顶堆的二叉树
{
    int smallest = i;//当前结点
    int left = 2 * i ;//左孩子
    int right = 2 * i +1;//右孩子
    if (left < size && S[left].frep < S[smallest].frep) 
    {
        smallest = left;
    }
    if (right < size && S[right].frep < S[smallest].frep) 
    {
        smallest = right;
    }
    if (smallest != i) 
    {
        swap(&S[i], &S[smallest]);//交换，再次构造
        minHeapify(S, size, smallest);
    }
}

void buildminHeap(Stack* arr, int size) //构造小顶堆
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--) 
    {
        minHeapify(arr, size, i);
    }
}

Stack extractMin(Stack* S, int* size) //拿到最小值
{
    Stack min = S[0];
    S[0] = S[*size - 1];//找到最小的值
    (*size)--;//数量减一
    minHeapify(S, *size, 0);//继续构造小顶堆
    return min;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) 
{
    int i;
    int hashSize = numsSize * 2;
    Stack* Hash = (Stack*)malloc(sizeof(Stack) * hashSize);
    int hashcount = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        int j;
        for (j = 0; j < hashcount; j++) 
        {
            if (Hash[j].num == nums[i]) 
            {
                Hash[j].frep++;
                break;
            }
        }
        if (j == hashcount) 
        {
            Hash[hashcount].num = nums[i];
            Hash[hashcount].frep = 1;
            hashcount++;
        }
    }

    Stack* heap = (Stack*)malloc(sizeof(Stack) * k);
    int heapSize = 0;

    for (i = 0; i < hashcount; i++) 
    {
        if (heapSize < k) 
        {
            heap[heapSize] = Hash[i];
            heapSize++;
            if (heapSize == k) 
            {
                buildminHeap(heap, k);
            }
        } 
        else if (Hash[i].frep > heap[0].frep) 
        {
            heap[0] = Hash[i];
            minHeapify(heap, k, 0);
        }
    }

    int* ret = (int*)malloc(sizeof(int) * k);
    for (i = k - 1; i >= 0; i--) 
    {
        Stack min = extractMin(heap, &heapSize);
        ret[i] = min.num;
    }

    *returnSize = k;
    free(heap);
    free(Hash);
    return ret;
}

int main()
{
    int numsSize=0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int k=0;
    scanf("%d",&k);
    int count=0;
    int *ret=topKFrequent(nums,numsSize,k,&count);
    for(int i=0;i<count;i++)
    {
        printf("%d ",ret[i]);
    }
    printf("\n");
    free(ret);
    return 0;
}