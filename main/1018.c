#include<stdio.h>
#include<stdlib.h>

int main(){
    int x=0;
    int y=0;
    scanf("%d %d",&x,&y);
    
    char in = getchar();
    while(in == '\n'){
        in = getchar();
    }

    int minScore = 0;

    for(int j=0; j<=y-8; j++){
        for(int i=0; i<=x-8; i++){
            int tempScoreW = 0;
            int tempScoreB = 0;
            int worB = 0;
            for(int iy=0; iy<8; iy++){              //8*8을 하나씩 확인. worB가 짝수일 경우 BWBWBWB순
                for(int ix=0; ix<8; ix++){
                    char value = arr[i+ix][j+iy];
                    if(worB%2==0){
                        if(value == 'W'){
                            tempScoreW++;
                        }
                    }else{
                        if(value == 'B'){
                            tempScoreB++;
                        }
                    }
                    worB++;                         //WB를 교차하기위한 변수.
                }
                worB++;                             //줄이 바뀌면 WB도 바뀌기에
            }
        }
    }

    return 0;
}