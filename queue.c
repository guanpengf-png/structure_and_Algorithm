#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct{
    int *data;
    size_t capacity;
    size_t length;
    size_t front;
    size_t rear;

}Queue;
void init_queue(Queue*q,size_t ini_capacity){
    q->data=(int*)malloc(sizeof(int)*ini_capacity);
    q->capacity=ini_capacity;
    q->front=0;
    q->rear=0;
    q->length=0;
}
void destroy(Queue*q){
    free(q->data);
    q->data=NULL;
    q->front=0;
    q->rear=0;
    q->length=0;

}
size_t get_lenght(Queue*q){
    return q->length;


}
void enqueue(Queue*q,int element){
    if (q->rear==q->capacity)
    {
        return;
    }
    q->data[q->rear]=element;
    q->rear=(q->rear+1)%q->capacity;
    q->length++;
    


}
bool dequeue(Queue*q,int *del_number){
    if (q->length==0)
    {
        return false;
    }
    *del_number=q->data[q->front];
    q->front=(q->front+1)%q->capacity;
    q->length--;

    
}
void print_queue(Queue*q){
    if (q->length==0)
    {
       return ;
    }
    for (int i = 0; i < q->length; i++)
    {
        size_t index =(q->front+i)%q->capacity;
        printf("%d",q->data[index]);

    }
    printf("\n");
    

}
int main(int argc, char const *argv[])
{
    Queue q;
    init_queue(&q,3);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    print_queue(&q);
    destroy(&q);
    return 0;
}
