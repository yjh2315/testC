#include<stdio.h>
#include<stdlib.h>

int checkTop(int** stack, int* top, int val, int m);


int main(void){
    int textN;
    int textM;
    scanf("%d %d",&textN,&textM);

    int** stackArr = (int**)malloc(sizeof(int*)*(textM+1));                         //배열을 (m개)선언해 각 배열을 스택으로 관리한다.
    int* top = (int*)malloc(sizeof(int)*(textM+1));                                 //각 스택의 탑을 기억한다.

    for(int i=0;i<textM+1;i++){
        stackArr[i] = (int*)malloc(sizeof(int)*(textN+1));
    }

    for(int i=0 ; i<textM ; i++){
        int eachNum;
        scanf("%d",&eachNum);
        for(int j=0; j<eachNum; j++){
            int in;
            scanf("%d",&in);
            stackArr[i][top[i]]=in;             //입력받은 값을 i번째 스택에 top부분에 쌓아준다.
            top[i]++;                           //값이 추가되었으니 top을 +1한다.
        }
    }

    for(int i=1;i<textN+1;i++){
        int val = checkTop(stackArr,top,i,textM);
        if(val = 0){
            printf("No");
            free(stackArr);
            free(top);
            return 0;
        }
    }
    printf("Yes");
    free(stackArr);
    free(top);
}

int checkTop(int** stack, int* top, int val, int m){
    for(int i=0; i<m; i++){
        if(top[i]-1>=0){
            if(stack[i][top[i]-1]==val){
                stack[i][top[i]-1]=0;               //목표하는 값이 탑에 있다면 해당 값을 빼고
                top[i]--;                           //탑의 위치를 조정
                return 1;
            }
        }
    }
    return 0;
}