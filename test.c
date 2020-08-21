#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    /*int r=0;
    srand(time(NULL));
    r = rand()%2;
    printf("%d", r);*/

    int arr[4]={0};
    int nos[3]={0};
    arr[2]=1;
    nos[3]=2;
    arr[2]=nos[3];
    printf("arr[2]is %d, nos[3]is %d", arr[2], nos[3]);
    return 0;
}