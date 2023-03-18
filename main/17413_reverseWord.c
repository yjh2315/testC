#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverseWord(char* word);

int main(void){
    char* input = (malloc(sizeof(char)*100000));
    gets(input);
    
    char* restTemp;
    char *temp = strtok_r(input," ",&restTemp);
    while(temp!= NULL){
        reverseWord(temp);
        printf("%s ",temp);
        temp = strtok_r(NULL, " ",&restTemp);
    }
    free(input);
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