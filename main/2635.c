#include<stdio.h>

int main(){
    int in = 0;
    scanf("%d",&in);
    
    int d1 = in;
    int d2 = 1;
    int d3 = 0;

    int added = 0;
    int cnt = 2;
    int tCnt = 2;

    int arr[30000]={0,};
    int tmp[30000]={0,};
    while(d2<=in){
        tmp[0] = d1;
        tmp[1] = d2;
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
            for(int j=0; j<tCnt; j++){
                arr[j] = tmp[j];
            }
            cnt = tCnt;
        }

        added++;
        d1 = in;
        d2 = 0 + added;
        tCnt = 2;
    }

    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++){
        printf("%d ",arr[i]);
    }
}