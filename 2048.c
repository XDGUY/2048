#define enter printf("\n");
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//move up: rotateclockwise(3), mv_combine, clockwise(1)
//move down: rotateclockwise(1), mv_combine, clockwise(3)
//left to right rotateclockwise(2), mv_combine, clockwise(2)
//25-8-2020

int brd[4][4]={0};
int savearr[4][4]={0};
int save=0;
int input[4][4];
enum{right_left, down, left_right, up};

int pushbrd(int n, int x, int y){ //cor
    brd[x][y] = n;
}

int ifnear(int first, int next){  //cor //rl
    if(first==next && first!=0){
        return 1;
    }
    else{
        return 0;
    }
}

int checkbrd(int x, int y){  //cor
    if(brd[x][y]==0){
        return 0;
    }
    else{
        return 1;
    }
}

void inputbrd(){
    int i, j;
    int n;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            scanf("%d", &n);
            pushbrd(n, j, i);
        }
    }
}

void intialize(int arrr[4][4]){
    int i, j;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            arrr[j][i]=0;
        }
    }
}

void intializebrd(){  //cor
    srand(time(NULL));
    int i, j;
    int n, x, y;
    int count=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            brd[j][i]=0;
        }
    }
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

void printarr(int toprint[4][4]){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", toprint[j][i]);
        }
        printf("\n");
    }
}

void mv_rl(){   //seems correct
    int i, j;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(checkbrd(j, i)){
                savearr[save][i]=brd[j][i];
                save++;
            }
        }
        save=0;
    }

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            brd[j][i]=savearr[j][i];
        }
    }

    intialize(savearr);

}

void combine_rl(){
    int i, j;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){  
            if(ifnear(brd[j][i], brd[j+1][i])){
                brd[j][i]=brd[j+1][i]+brd[j][i];
                brd[j+1][i]=0;
            }
        }
    }
}

void rotate_clockwise(int n){   //i:x   j: y  n: no. of times to rotate
    int i, j, k;
    save = 0;
    for(k=0;k<n;k++){
        for(i=0;i<=3;i++){
            for(j=3;j>=0;j--){
                savearr[save][i]=brd[i][j];
                save++;
            }
            save=0;
        }
    
        for(i=0;i<=3;i++){
            for(j=0;j<=3;j++){
                brd[j][i]=savearr[j][i];
            }
        }
        intialize(savearr);
    }
}

void mv_combine_rl(){
    mv_rl();
    combine_rl();
    mv_rl();
}

void slide(int direction){
    rotate_clockwise(direction);
    mv_combine_rl();
    direction % 2 ? rotate_clockwise(direction+2) : rotate_clockwise(direction+4);
}

void test(){
    intialize(brd);
    inputbrd();
    enter
    slide(up);
    printarr(brd);
}

int main(){
    int i, j;
    char userkey;
    test();
    return 0;
}