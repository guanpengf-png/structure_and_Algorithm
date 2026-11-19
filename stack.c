#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
typedef struct 
{
    int *data;
    size_t capacity;
    size_t len;

    /* data */
}Stack;
void init_stack(Stack*s,size_t c){
    s->data=(int*)malloc(sizeof(int)*c);
    s->len=0;
    s->capacity=c;


}
void resize_stack(Stack*s,size_t c){
    s->data=(int*)realloc(s->data,sizeof(int)*c);
    s->capacity=c;


}
void destroy(Stack*s){
    free(s->data);
    s->data=NULL;
    s->capacity=0;
    s->len=0;


}
size_t get_len(Stack*s){
    return s->len;

}
void push(Stack*s,int element){
    if (s->capacity==s->len)
    {
        resize_stack(s,s->capacity*3);
    }
    
    s->data[s->len]=element;
    printf("%d",s->data[s->len]);
    s->len++;
}
bool pop(Stack*s,int*element){
    if (s->len==0)
    {
        return false;

    }
    *element=s->data[s->len-1];
    s->len--;
    return true;

    
    

}
void printf_stack(Stack*s){
    if (s->len==0)
    {
        return;
    }
    for (size_t i = 0; i < s->len; i++)
    {
        printf("%d",s->data[i]);
    }
    printf("\n");
    
    

}
int main(int argc, char const *argv[])
{
    Stack s;
    init_stack(&s,3);
    
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf_stack(&s);

    
    return 0;
}
