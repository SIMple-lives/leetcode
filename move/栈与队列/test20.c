#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack
{
    char data;
    struct Stack *next;
} Stack;

Stack *initStack()
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->next = NULL;
    return S;
}

void push(Stack *S, char data)
{
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->data = data;
    node->next = S->next;
    S->next = node;
}

bool isEmpty(Stack *S)
{
    return S->next == NULL;
}

char pop(Stack *S)
{
    if (isEmpty(S))
    {
        return '#';
    }
    else
    {
        Stack *node = S->next;
        char data = node->data;
        S->next = node->next;
        free(node);
        return data;
    }
}

void freeStack(Stack *S)
{
    while (!isEmpty(S))
    {
        pop(S);
    }
    free(S);
}

void printStack(Stack *S)
{
    Stack *temp = S->next;
    while (temp)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool isValid(char *s)
{
    Stack *S = initStack();
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(S, s[i]);
        }
        else
        {
            char x = pop(S);
            if (x == '#')
            {
                freeStack(S);
                return false;
            }
            else
            {
                if (s[i] == ')' && x != '(')
                {
                    freeStack(S);
                    return false;
                }
                else if (s[i] == '}' && x != '{')
                {
                    freeStack(S);
                    return false;
                }
                else if (s[i] == ']' && x != '[')
                {
                    freeStack(S);
                    return false;
                }
            }
        }
    }
    bool result = isEmpty(S);
    freeStack(S);
    return result;
}

int main()
{
    char s[100] = {0};
    printf("\033[32mEnter a string: ");
    scanf("%99s", s);
    bool end = isValid(s);
    printf("\033[31m%d\n", end);
    return 0;
}
