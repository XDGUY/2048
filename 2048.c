//#define row 橫 horizontal X axis = j, 
//#define column 直 vertical y axis = i
//先 loop i, then j
//fucking messing up with row and col
#define enter printf("\n");
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int brd[4][4];
int savearr[4][4] = {0};
int save=0;

int pushbrd(int n, int x, int y){ //cor
    brd[x][y] = n;
}

int ifnear(int first, int next){  //cor
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

void intializesavearr(){  //cor
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            savearr[j][i]=0;
        }
    }
}

void intializetestbrd(){  //cor
    int i, j;
    int n, x, y;
    int count=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            brd[j][i]=0;
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

void printbrd(){  //cor
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", brd[j][i]);
        }
        printf("\n");
    }
}

void printsavearr(){  //cor
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", savearr[j][i]);
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

    intializesavearr();

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

void test(){
    pushbrd(2, 3, 0);
    pushbrd(2, 1, 0);
    pushbrd(2, 2, 0);
    pushbrd(2, 0, 0);
    printbrd();
    enter
    mv_rl();
    printbrd();
    enter
    combine_rl();
    mv_rl();
    printbrd();
    
}

int main(){
    int i, j;
    char userkey;
    test();
    return 0;
}