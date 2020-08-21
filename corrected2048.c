//#define row 橫 horizontal X axis = j, 
//#define column 直 vertical y axis = i
//先 loop i, then j
//fucking messing up with row and col

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
            brd[j][i]=0;
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

/*void rl(){                  //move from right to left y=0 only row
    int i;
    int save=0;
    int savearr[4]={0};
    /*for(i=0;i<=3;i++){
        printf("%d", savearr[i]);
    }
    for(i=0;i<=3;i++){
        if (checkbrd(i,0)){
            savearr[save]=brd[i][0];
            save++;
        }
    }
    for(i=0;i<=3;i++){
        printf("%d", savearr[i]);
    }

    for(i=0;i<=3;i++){
        brd[i][0]=savearr[i];
    }
}*/

void rightleft(){
    int i, j;
    int savearr[4][4] = {0};
    int save=0;
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

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            brd[j][i]=savearr[j][i];
        }
    }
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

int main(){
    int i, j;
    char userkey;
    intializebrd();
    pushbrd(1, 0, 0);
    pushbrd(3, 2, 0);
    pushbrd(5, 3, 0);
    printbrd();
    printf("\n\n");
    //rl();
    rightleft();
    printf("\n");
    printbrd();
    /*printf("\n please input wasd to move");
    scanf("%c", &userkey);*/
    return 0;
}