#include<stdio.h>

struct STACK {
	int top;
	int arr[100000];
};

int pop( struct STACK* in );

int main(){
	int repeat;
	scanf("%d",&repeat);

	int inV = 0;
	int check = 1;

	struct STACK stack = {0,{}};
	int result[100000] = {};
	int nowResult = 0;

	struct STACK num = { 0, {}};

	for( int i = 0 ; i<repeat ; i++ ){
		num.arr[i] = repeat - i;
        num.top++;
	}

    for( int i = 0; i<repeat; i++ ){
        scanf("%d",&inV);
		if(stack.top!=0){
			//임시 보관 스택에 값이 들어있을 경우
			if(stack.arr[stack.top-1]>inV){	
				//임시스택에 들어간 바로 앞 수보다 낮은 수인지 확인(낮은 수라면 수열 구현 불가능)
				check = 0;
				break;
			}else if(num.top==0){
				//더 이상 push할 값이 없을 경우(pop만 수행)
				int temp = pop(&stack);
				int rep = 0;
				while(temp!=-1){
					rep++;
					if(temp == inV) break;
					//pop한 값이 입력된 값과 같을 경우 정지.
				}
				result[nowResult++] = rep*-1;
				//pop이기에 -로 반복횟수 표기

			}else if(num.arr[num.top-1]>inV){
				//inV(입력된 값)이 pop을 수행해야 하는 경우
				int temp = pop(&stack);
				int rep = 0;
				while(temp!=-1){
					rep++;
					if(temp == inV) break;
					//pop한 값이 입력된 값과 같을 경우 정지.
				}
				result[nowResult++] = rep*-1;
				//pop이기에 -로 반복횟수 표기
			}else{
				//inV(입력된 값)이 push를 새로 수행해야 하는 경우
				num.top--;
				int rep = 0;
				while(num.arr[num.top]!=inV){
				//1~n까지의 스택에서 입력된 값을 빼온다.
					stack.arr[stack.top] = num.arr[num.top];
					stack.top++;
					num.top--;
					rep++; //반복한 횟수 표시
				}
				//inV값이므로 마지막으로 저장
				stack.arr[stack.top] = num.arr[num.top];
				stack.top++;
				rep++;

				result[nowResult++] = rep;
				//결과 배열에 push한 횟수 작성.(push면 +로, pop이면 -로 표기예정)
				
				int temp = pop(&stack);
				//push한 결과값 출력을 위해 pop 실행
				//push의 끝에는 무조건 pop이 한번 있기에 추후 코드 진행시 꼭 한번은 pop 출력.	
			}
		}else{
			//스택에 값이 없을 경우
			//inV(입력된 값)이 push를 새로 수행해야 하는 경우와 동일

			num.top--;
			int rep = 0;
			while(num.arr[num.top]!=inV){
			//1~n까지의 스택에서 입력된 값을 빼온다.
				stack.arr[stack.top] = num.arr[num.top];
				stack.top++;
				num.top--;
				rep++; //반복한 횟수 표시
			}
			//inV값이므로 마지막으로 저장
			stack.arr[stack.top] = num.arr[num.top];
			stack.top++;
			rep++;

			result[nowResult++] = rep;
			//결과 배열에 push한 횟수 작성.(push면 +로, pop이면 -로 표기예정)
			
			int temp = pop(&stack);
			//push한 결과값 출력을 위해 pop 실행
			//push의 끝에는 무조건 pop이 한번 있기에 추후 코드 진행시 꼭 한번은 pop 출력.	
		}
    }

	if(check==1){
		int i = 0;
		while(result[i]!=0){
			if(result[i]>0){
				for(int j = 0; j<result[i]; j++){
					printf("+\n");
				}
				printf("-\n");
			}else{
				int k = (result[i]*-1);
				for(int j = 0; j<k; j++){
					printf("-\n");
				}
			}
			i++;
		}
	}else{
		printf("NO\n");
		//check가 0이 되었다면 불가능하다는 것이기에 출력
	}
}

int pop( struct STACK* in ){
    if((*in).top>=1){
        (*in).top--;
        int ret = in->arr[in->top];
		in->arr[in->top] = 0;
        return ret;
    }else{
        return -1;
    }
}