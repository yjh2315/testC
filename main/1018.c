#include<stdio.h>
#include<stdlib.h>

int main(){
    int x=0;
    int y=0;
    scanf("%d %d",&y,&x);
    
    char in = getchar();
    while(in == '\n'){
        in = getchar();
    }

    char **arr = (char**)malloc(sizeof(char*)*x+1);
    for(int i=0; i<x; i++){
        arr[i] = (char*)malloc(sizeof(char)*y+1);
    }

    for(int j=0; j<y; j++){
        for(int i=0; i<x; i++){
            while(in == '\n'){
                in = getchar();
            }
            arr[i][j] = in;

            in = getchar();
        }
    }

    int minScore = 10000000;

    for(int j=0; j<=y-8; j++){
        for(int i=0; i<=x-8; i++){
            int tempScoreW = 0;
            int tempScoreB = 0;
            int worB = 0;
            for(int iy=0; iy<8; iy++){              //8*8을 하나씩 확인. worB가 짝수일 경우 WBWBWB순
                for(int ix=0; ix<8; ix++){
                    char value = arr[i+ix][j+iy];
                    if(worB%2==0){
                        if(value != 'W'){
                            tempScoreW++;
                        }else{
                            tempScoreB++;
                        }
                    }else{
                        if(value != 'B'){
                            tempScoreW++;
                        }else{
                            tempScoreB++;
                        }
                    }

                    worB++;                         //WB를 교차하기위한 변수.
                }
                worB++;                             //줄이 바뀌면 WB도 바뀌기
            }

            if(minScore>tempScoreB||minScore>tempScoreW){
            minScore = tempScoreB<tempScoreW?tempScoreB:tempScoreW;
            }
        }
    }
    printf("%d\n",minScore);

    return 0;
}