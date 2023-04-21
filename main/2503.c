#include<stdio.h>
#include<stdlib.h>

int checker(int in, int number, int strike, int ball);

int main(){
    int in = 0;
    scanf("%d",&in);
    int *arr = (int*)malloc(sizeof(int)*(in+1));
    int *strike = (int*)malloc(sizeof(int)*(in+1));
    int *ball = (int*)malloc(sizeof(int)*(in+1));
    for(int i=0; i<in; i++){
        scanf("%d %d %d",&arr[i],&strike[i],&ball[i]);
    }

    int check = 0;
    int cnt = 0;

    //숫자를 123~987까지 다 비교. 주어진 스트라이크, 볼에 위배되지 않는 수만 카운트

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            if(j==i) continue;              //자리수 숫자가 다르므로 이 경우는 스킵
            for(int k=1; k<10; k++){
                if(k==j||k==i) continue;    //자리수 숫자가 다르므로 이 경우는 스킵
                for(int l=0; l<in; l++){
                    int temp = i*100+j*10+k;
                    if(checker(temp,arr[l],strike[l],ball[l])!=1){
                        check++;
                        break;
                    }
                }
                if(check==0){
                    cnt++;
                }
                check = 0;
            }
        }
    }

    printf("%d\n",cnt);
}

//비교할 숫자, 입력된 숫자, 스트라이크, 볼을 입력받음
//만약 in과 입력된 숫자 스트라이크 볼 재판별후 이와 strike, ball값이 같으면 ok. - 1을 리턴함

//아닐경우 메인문에서 check변수값을 변화. check ==0이면 모든 조건을 만족하기에 카운트

int checker(int in, int number, int strike, int ball){
    int cStrike = 0;
    int cBall = 0;
    int arr[3] = {in/100,(in%100)/10,in%10};
    int arrC[3] = {number/100,(number%100)/10,number%10};

    for(int i=0; i<3; i++){
        if(arr[i] == arrC[i]){
            cStrike++;
        }
        else if(arr[i]==arrC[(i+1)%3]||arr[i]==arrC[(i+2)%3]){
            cBall++;
        }
    }

    if(cStrike == strike && cBall == ball){
        return 1;
    }else{
        return 0;
    }
}