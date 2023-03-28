#include<stdio.h>

int main(){
    int in = 0;
    scanf("%d",&in);
    
    int d1 = in;
    int d2 = in/2;
    int d3 = 0;

    int cnt = 2;

    int arr[100]={0,};
    arr[0] = d1;
    arr[1] = d2;
    int i = 2;
    while(1){
        d3 = d1-d2;
        if(d3<0) break;
        arr[i] = d3;
        d1 = d2;
        d2 = d3;
        cnt++;
        i++;
    }

    for(int j=0; j<cnt; j++){
        printf("%d ",arr[j]);
    }

    

    
}