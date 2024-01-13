#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    char *arr;
};

// isEmpty
int isEmpty(struct stack *sp){
    if (sp->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}

//isFull
int isFull(struct stack *sp){
    if (sp->top == sp->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}

//push
void push(struct stack *sp, int data){
    if (isFull(sp))
    {
        printf("stack overflow!!!\n");
    }else{
        sp->top++;
        sp->arr[sp->top];
    }
}

//pop
void pop(struct stack *sp){
    if (isEmpty(sp))
    {
        printf("stack underflow!!!\n");
    }else{
        sp->top--;
    }
}

//parenthesis macth function
int parenthesisMatch(char *exp){
    //creating a stack pointer 
    struct stack *sp;
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *) malloc(sp->size*sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }  
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }else{
        return 0;
    }   
}

int main()
{
    char exp[] = "8)*(9)"; //expression

    if (parenthesisMatch(exp))
    {
        printf("matched\n");
    }else{
        printf("not match\n");
    }
    
    return 0;
}
