#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int *data;
    int length;
    int ca;

}Stack;
void init_stack(Stack*s,int ini_ca){
    s->data=(int*)malloc(sizeof(int)*ini_ca);
    s->length=0;
    s->ca=ini_ca;
    


}
void free_stack(Stack*s){
    free(s->data);
    s->data=NULL;
    s->length=0;
    s->ca=0;



}
void resize_s(Stack*s){
    int new_ca=s->ca<<1;
    s->data=(int*)realloc(s->data,sizeof(int)*new_ca);
    s->ca=new_ca;

}
void push(Stack*s,int element){
    if (s->length==s->ca)
    {
        resize_s(s);
    }
    s->data[s->length]=element;
    s->length++;
    

}
int pop(Stack* s){
    if (s->length<=0)
    {
        return -1;
    }
    int element=s->data[s->length-1];
    s->length--;
    return element;
    

}
void printf_s(Stack*s){
    for (int i = 0; i < s->length; i++)
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
    printf_s(&s);
    free_stack(&s);
    

    
    return 0;
}
