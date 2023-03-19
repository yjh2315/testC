#include<stdio.h>
#include<stdlib.h>


int main(void){
    int textN;
    int textM;
    scanf("%d %d",&textN,&textM);

    int** stackArr = (int**)malloc(sizeof(int*)*(textM+1));                         //배열을 (m개)선언해 각 배열을 스택으로 관리한다.
    int* top = (int*)malloc(sizeof(int)*(textM+1));                                 //각 스택의 탑을 기억한다.
    int max;

    for(int i=0 ; i<textM ; i++){
        max = 1000000;
        int eachNum;
        scanf("%d",&eachNum);
        stackArr[i] = (int*)malloc(sizeof(int)*(eachNum+1));                        //stack에 해당하는 배열을 초기화한다
        for(int j=0; j<eachNum; j++){
            int in;
            scanf("%d",&in);
            if(max>in){
                stackArr[i][top[i]]=in;             //입력받은 값을 i번째 스택에 top부분에 쌓아준다.
                top[i]++;                           //값이 추가되었으니 top을 +1한다.
                max = in;
            }else{
                printf("No");
                return 0;
            }
            
        }
    }
    printf("Yes");

    free(stackArr);
    free(top);
}





// 단순하게 stack 활용만으로는 문제가 풀리지 않는다.
// 1. 한 더미의 값을 평균내서 그 값이 작은걸 위로 올리면 되지 않을까? - 정렬하는데 시간이 오래 걸릴수도 있음을 확인해야 한다.