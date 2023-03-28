#include<stdio.h>

int main(){
    int in = 0;
    scanf("%d",&in);
    
    int d1 = in;
    int d2 = in/2;
    int d3 = 0;

    int cnt = 2;
    int tCnt = 2;

    int arr[100]={0,};
    int tmp[100]={0,};
    while(d2++<in){
        arr[0] = d1;
        arr[1] = d2;
        int i = 2;
        
        while(1){
            d3 = d1-d2;
            if(d3<0) break;
            tmp[i] = d3;
            d1 = d2;
            d2 = d3;
            tCnt++;
            i++;
        }

        if(cnt<tCnt){
            for(int i=0; i<tCnt; i++){
                arr[i] = tmp[i];
            }
            cnt = tCnt;
        }
    }

    for(int i=0; i<cnt; i++){
        printf("%d ",arr[i]);
    }
    

    

    
}