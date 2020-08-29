//#define row 橫 horizontal X axis = j, 
//#define column 直 vertical y axis = i
//先 loop i, then j
//fucking messing up with row and col

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int brd[4][4];
int savearr[4][4] = {0};
int save=0;

int pushbrd(int n, int x, int y){
    brd[x][y] = n;
}

int ifnear(int first, int next){
    if(first==next && first!=0){
        return 1;
    }
    else{
        return 0;
    }
}

int checkbrd(int x, int y){
    if(brd[x][y]==0){
        return 0;
    }
    else{
        return 1;
    }
}

void intialize_all(int t){ //1 is inti brd, 2 is test brd, 3 is savearr
    
}

void intializetestbrd(){
    int i, j;
    int n, x, y;
    int count=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            brd[j][i]=0;
        }
    }
}

void intializebrd(){
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

void packrl(){
    int i, j;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            brd[j][i]=savearr[j][i];
        }
    }
}

void rightleft(){
    int i, j;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(checkbrd(j,i)){
                savearr[save][i]=brd[j][i];
                save ++;
            }
        }
        save = 0;
    }

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            printf("%d", savearr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    save=0;
    
    printf("\n");
    save =0;
    
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            brd[j][i]=savearr[j][i];
        }
    }
}

void combine_rl(){       //combine them in save array
    int i, j;
    for (i = 0; i <4; i++){
        for(j=0;j<3;j++){
            if(ifnear(brd[j][i], brd[j+1][i])){
                brd[j][i] = brd[j][i]+brd[j+1][i];
                brd[j+1][i]=0;  
            }
        }
    }

    /*for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            printf("%d", savearr[j][i]);
        }
        printf("\n");
    }*/
}

void printbrd(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", brd[j][i]);
        }
        printf("\n");
    }
}

void printsavearr(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", savearr[j][i]);
        }
        printf("\n");
    }
}

void test(){
    pushbrd(2,2,0);
    pushbrd(4,3,0);
    printbrd();
    rightleft();
    intializetestbrd();
    pushbrd(3, 2, 0);
    pushbrd(5, 3, 0);
    printf("\n");   
    printbrd();
    printf("\n");
    rightleft();
    printbrd();
}

int main(){
    int i, j;
    char userkey;
    test();
    return 0;
}