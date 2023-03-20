#include<stdio.h>

int main(){
    int repeat;

    char arr[51] = {};
    int top = 0;

    scanf("%d",&repeat);
    char in = getchar();
    while(in == '\n'){
        in = getchar();
    }

    for(int i=0 ; i<repeat ; i++){
        while(in!='\n'){
            if(top!=0){
                int cmp = arr[top-1];
                if(cmp=='('&&in==')'){
                    top--;
                    arr[top] = 0;           //이전 입력값이 (이고 현 입력값이 )일때 둘 다 지운다.
                }else{
                    arr[top] = in;
                    top++;
                }
            }else{
                arr[0] = in;
                top++;
            }
            in = getchar();
        }
        if(top == 0){
            printf("YES\n");
            while(in == '\n'){
                if(i == repeat-1){
                    return 0;
                }
                in = getchar();
            }
        }else{
            printf("NO\n");
            top = 0;
            while(in == '\n'){
                if(i == repeat-1){
                    return 0;
                }
                in = getchar();
            }
        }
    }
    
}
//입력되는 값이 )일 경우 이전값이 ( 이면 지운다.