#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverseWord(char* word);

int main(void){
    // char* input = (malloc(sizeof(char)*100000));
    // gets(input);
    char input[100000] = "<std>helloyou<friend>";
    
    char* restTemp;
    char* temp;

    if(input[0]=='<'){
        temp = strtok_r(input,"<",&restTemp);
        goto label;
    }else{
        temp = strtok_r(input,"<",&restTemp);
    }
    
    if(strcmp(temp,restTemp)==0){                   //<이 없을때(공백만 처리)
        temp = strtok_r(input," ",&restTemp);
        while(temp!= NULL){
            reverseWord(temp);
            printf("%s ",temp);
            temp = strtok_r(NULL, " ",&restTemp);
        }
    }
    while(temp!= NULL){
        if(strcmp(restTemp,"")==0){
            temp = strtok_r(temp," ",&restTemp);
            while(temp!= NULL){
                reverseWord(temp);
                printf("%s ",temp);
                temp = strtok_r(NULL, " ",&restTemp);
            }
        }else{
            if(strcmp(restTemp,"")!=0){
                reverseWord(temp);
                printf("%s",temp);
                temp=NULL;
            }
            label:
            printf("<");
            temp = strtok_r(temp, ">",&restTemp);
            printf("%s>",temp);                         //<>처리
            temp = strtok_r(NULL, "<",&restTemp);
        }
    }
    printf("\n");

    // char* restTemp;
    // char *temp = strtok_r(input," ",&restTemp);
    // while(temp!= NULL){
    //     reverseWord(temp);
    //     printf("%s ",temp);
    //     temp = strtok_r(NULL, " ",&restTemp);
    // }
    // free(input);
}

void reverseWord(char* word){
    int wordLen = strlen(word);
    char* stack = malloc(sizeof(char)*(wordLen+1));
    for(int i = 0; i<wordLen; i++){
        stack[i] = word[wordLen-(i+1)];
    }
    for(int i = 0; i<wordLen; i++){
        word[i] = stack[i];
    }
}