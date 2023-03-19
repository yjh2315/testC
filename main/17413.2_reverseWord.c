#include<stdio.h>

int check(char in);
void stackIn(char* arr, int* top, char in);
void stackOut(char* arr, int* top);

int main(){
    char arr[100000];
    int top=0;

    char in;
    while(in!='\n'){
        in = getchar();
        switch(check(in)){
            case 1:
                while(check(in)!=2){
                    if(in=='\n') break;
                    printf("%c",in);
                    in = getchar();
                }
                break;
            case 0:
                while(check(in)!=3){
                    if(in=='\n') break;
                    stackIn(arr,&top,in);
                    in = getchar();
                }
                stackOut(arr,&top);
                break;
        }
    }
}

int check(char in){
    if(in=="<"){
        return 1;
    }else if(in==">"){
        return 2;
    }else if(in==" "||in=='\n'){
        return 3;
    }else{
        return 0;
    }
}

void stackIn(char* arr, int* top, char in){
    arr[*top] = in;
    (*top)++;
}
void stackOut(char* arr, int* top){
    while(*top!=0){
        (*top)--;
        printf("%c",arr[*top]);
    }
}