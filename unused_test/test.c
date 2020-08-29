#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*
  2 0 4 0   
  8 2 0 4 
  4 2 2 2
  8 4 2 2
  */

int arr[4]={2,2,2,2};
int savearr[4]={0,0,0,0};
int save=0;

int ifnear(int first, int next){
    if(first==next && first!=0){
        return 1;
    }
    else{
        return 0;
    }
}

int checknozero(int x){
    if(arr[x]==0){
        return 0;
    }
    else
    {
        return 1;
    }
    
}

void combine(){
    int i;
    for(i=0;i<3;i++){
        if(ifnear(arr[i], arr[i+1])){
            arr[i]=arr[i]+arr[i+1];
            arr[i+1]=0;
        }
    }
}

void moveit(){
    int i;
    for(i=0;i<=3;i++){
        if(checknozero(i)){
            arr[save]=arr[i];
            save ++;    
        }
    }
}

void print(){
    int i;
    for(i=0;i<4;i++){
        printf("%d", arr[i]);
    }
}

void test(){
    printf("%d", 1/2);
}

int main(){
    int i, j;
    test();
    return 0;
}