#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void scroll(char* str1, int n) {
	char str[100] = {0,};
	strncpy(str, str1, strlen(str1));
	char temp = 0;
	int strlen1 = strlen(str1);
	printf("%s\n", str1);
	for (int i = 0; i < strlen1 * n; i++) {
		temp = str[strlen1 - 1];
		for (int j = strlen1-1; j >= 1; j--) {
			str[j] = str[j - 1];
		}
		str[0] = temp;
		printf("%s\n", str);
	}
}

char* replaceTextOne(char* text, char* target, char* replace, int maxStr) {
	printf("text:%s\n", text);
	static char strTmp[100] = { 0, };
	for (int i = 0; i < strlen(strTmp); i++) {
		strTmp[i] = 0;
	}
	char* tarPt = strstr(text, target);
	if (tarPt != 0) {
		int tarIndex = tarPt - text;
		printf("index는 %d\n", tarIndex);
		printf("1차 복사이전:%s\n", strTmp);
		printf("1차 복사이전text:%s\n", text);

		strncpy(strTmp, text, tarIndex);
		printf("1차 복사:%s\n", strTmp);

		int replaceNum = 0;
		if (strlen(replace) > strlen(target)) {
			replaceNum = maxStr;
			strncat(strTmp, replace, replaceNum);
			printf("strTmp:%s\n", strTmp);
			for (int i = 0; i < strlen(text); i++) {
				strTmp[tarIndex + i + replaceNum] = text[tarIndex + i + replaceNum];
			}
		}
		else {
			replaceNum = strlen(replace);
			strncat(strTmp, replace, replaceNum);
			printf("strTmp:%s\n", strTmp);
			for (int i = 0; i < strlen(text); i++) {
				strTmp[tarIndex + i + replaceNum] = text[tarIndex + i + strlen(target)];
			}
		}

		
	}
	printf("%s\n", strTmp);
	return strTmp;
}

char* replaceText(char* text, char* target, char* replace, int maxStr) {
	if (strcmp(target,"")==0) return 0;
	char tmpStr[100] = {0,};
	strcpy(tmpStr, text);
	while (strstr(tmpStr, target) != 0) {
		char* tmpPt = replaceTextOne(tmpStr, target, replace, maxStr);
		strcpy(tmpStr, tmpPt);
	}
}


int main() {
	replaceText("n hello World hello now", "hello", "tes", 5);
}