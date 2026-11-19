#include <stdio.h>
void swap(int *a,int*b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void swap2(int*x,int*y){
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;


}
void swap3(int *x,int*y){
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;

}
int main(int argc, char const *argv[])
{
    int a=10;
    int b=20;
    swap3(&a,&b);
    printf("a:%d,b:%d",a,b);
    return 0;
}
