#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int r=0;
    srand(time(NULL));
    r = rand()%2;
    printf("%d", r);
    return 0;
}