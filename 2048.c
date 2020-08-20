#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int brd[4][4];

int pushbrd(int n, int x, int y){
    brd[x][y] = n;
}

int checkbrd(int x, int y){
    if(brd[x][y]==0){
        return 0;
    }
    else{
        return 1;
    }
}

void intializebrd(){
    srand(time(NULL));
    int i, j;
    int n, x, y;
    int count=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            brd[i][j]=0;
        }
    }
    //printf("x and y is %d %d \n", x, y);
    while(count!=2){
        x=rand()%4;
        y=rand()%4;
        n=rand()%2;
        if(!checkbrd(x,y)){
            n ? pushbrd(2, x, y):pushbrd(4, x, y) ;
            count++;
        }
    }
}

void printbrd(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", brd[i][j]);
        }
        printf("\n");
    }
}

void lr(){                  //move from left to right y=0
    int i;
    
}

int main(){
    int i, j;
    char userkey;
    intializebrd();
    printbrd();
    /*printf("\n please input wasd to move");
    scanf("%c", &userkey);*/
    return 0;
}