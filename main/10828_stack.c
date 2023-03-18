#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct STACK{
    int top;
    int* array;
}S;

void push(struct STACK *stack, int val);
void pop(struct STACK *stack);
void size(struct STACK *stack);
void empty(struct STACK *stack);
void top(struct STACK *stack);


int main(void){
    int inputNum;
    scanf("%d",&inputNum);
    struct STACK stack = {0,(int*)(malloc(sizeof(int)*(inputNum+1)))};
    for(int i=0; i<inputNum; i++){
        char command[10];
        scanf("%s",&command);
        if(strcmp(command,"push")==0){
            int val;
            scanf("%d",&val);
            push(&stack,val);
        }else if((strcmp(command,"pop"))==0){
            pop(&stack);
        }else if((strcmp(command,"size"))==0){
            size(&stack);
        }else if((strcmp(command,"empty"))==0){
            empty(&stack);
        }else{
            top(&stack);
        }
    }

    free(stack.array);
}

void push(struct STACK *stack, int val){
    (*stack).array[(*stack).top]=val;
    (*stack).top++;
}

void pop(struct STACK *stack){
    if((*stack).top==0){
        printf("-1\n");
    }else{
        (*stack).top--;
        int a = (*stack).array[(*stack).top]; 
        (*stack).array[(*stack).top] = 0;
        printf("%d\n",a);
    }
}

void size(struct STACK *stack){
    if((*stack).top>=0){
        printf("%d\n",(*stack).top);
    }
    else{
        printf("0\n");
    }
}

void empty(struct STACK *stack){
    if((*stack).top<=0){
        printf("%d\n",1);
    }else{
        printf("%d\n",0);
    }
}

void top(struct STACK *stack){
    if((*stack).top==0){
        printf("-1\n");
    }else{
        int temp = (*stack).top;
        int a = (*stack).array[--temp]; 
        printf("%d\n",a);
    }
}

//스택을 구조체로 구현. top부, array부로 나눠서 관리. 배열의 최대크기 = 명령어의 개수 + 1로 두고 초기 설정.

//모든 과정은 스택을 포인터로 넘겨 원 자료를 수정. so 모든 사용자 정의 함수는 void로 처리.