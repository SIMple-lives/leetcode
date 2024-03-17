#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
//     char s[6]="5678";
//     int num=atoi(s);
//     printf("%d\n",num);
//     return 0;
// }

typedef struct Stack
{
    int data;
    struct Stack* next;
} Stack;

Stack* init()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->next = NULL;
    return S;
}

void push(Stack* S, int data)
{
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->data = data;
    node->next = S->next;
    S->next = node;
}

int isEmpty(Stack* S)
{
    if (S->next == NULL)
    {
        return 1;
    }
    return 0;
}

int pop(Stack* S)
{
    if (isEmpty(S))
    {
        return -1;
    }
    else
    {
        Stack* node = S->next;
        S->next = node->next;
        int data = node->data;
        free(node);
        return data;
    }
}

int detail(int a, int b, char c)
{
    if (c == '+')
    {
        return a + b;
    }
    else if (c == '-')
    {
        return a - b;
    }
    else if (c == '*')
    {
        return a * b;
    }
    else
    {
        return a / b;
    }
}

int evalRPN(char** tokens, int tokensSize)
{
    Stack* S = init();
    for (int i = 0; i < tokensSize; i++)
    {
        char* mod = tokens[i];
        if (strlen(mod) == 1 && (mod[0] == '-' || mod[0] == '+' || mod[0] == '*' || mod[0] == '/'))//如果是大于9的数字
        {
            int num1 = pop(S);
            int num2 = pop(S);
            int new = detail(num2, num1, mod[0]);
            push(S, new);
        }
        else//将会将该字符解析并入栈.
        {
            push(S, atoi(mod));//aoti将字符串解析为对应的数字.
        }
    }
    int result = pop(S);
    free(S);
    return result;
}

int main()
{
    char *s[5]={"4","13","5","/","+"};
    int len=5;
    int num=evalRPN(s,len);
    printf("%d\n",num);
    return 0;
}