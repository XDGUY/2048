#include<stdio.h>
#include<time.h>
#include<stdlib.h>
char brd[3][3];

void input(int player){
    int inp,i ,j;
    if(player == 1){
        scanf("%d", &inp);
        i= 2-(inp-1)/3;
        j= (inp+2)%3;
        while(brd[i][j]=='o'||brd[i][j]=='X'){
            printf("Try again!");
            scanf("%d", &inp);
            i= 2-(inp-1)/3;
            j= (inp+2)%3;
        }
        brd[i][j] = 'o';
    }
    else{
        srand(time(NULL));
        inp = rand()%9+1;
        i= 2-(inp-1)/3;
        j= (inp+2)%3;
        while(brd[i][j]=='o'||brd[i][j]=='X'){
            inp = rand()%9+1;
            i= 2-(inp-1)/3;
            j= (inp+2)%3;
        }
        brd[i][j] = 'X';
    }
}

void initialize(){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            brd[i][j] ='0'+7-i*3+j ;
        }
    }
}
void printbd(){
    int i, j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%c|",brd[i][j]);
        }
        printf("%c\n-----\n",brd[i][j]);
    }
    for(j=0;j<2;j++){
        printf("%c|",brd[i][j]);
    }
    printf("%c\n",brd[i][j]);
}

int check_row_and_col(){
    int i,j;
    for(i=0;i<3;i++){
        if(brd[0][i]==brd[1][i]&&brd[2][i]==brd[1][i]){//Check col
            if(brd[0][i]=='0'){
                return 1;
            }
            else{
                return 2;
            }
        }
        if(brd[i][0]==brd[i][1]&&brd[i][2]==brd[i][1]){//Check row
            if(brd[0][i]=='0'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
    return 0;
}

int check_diag(){
    int same=0, same2=0, i;
    for(i=0;i<2;i++){
        if(brd[i][i]==brd[i+1][i+1]){
            same++;
        }
        if(brd[2-i][i]==brd[1-i][i+1]){
            same2++;
        }
    }
    if(same==2){
        if(brd[i][i]=='0')
            return 1;
        else
            return 2;
    }
    return 0;
}

int endgame(){
    if(!(check_row_and_col()&&check_diag())){
        return 0;
    }

}

int main(){
    int player=1, status;
    initialize();
    printbd();
    while(!(status=check_row_and_col())){
        input(player);
        printbd();
        player=player % 2 +1;
    }
    printf("Player %d wins!", status);
    return 0;
}
