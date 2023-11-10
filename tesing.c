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
	static char strTmp[100] = { 0, };
	for (int i = 0; i < strlen(strTmp); i++) {
		strTmp[i] = 0;
	}
	char* tarPt = strstr(text, target);
	if (tarPt != 0) {
		int tarIndex = tarPt - text;
		strncat(strTmp, text, tarIndex);

		int replaceNum = 0;
		if (strlen(replace) > strlen(target)) {
			replaceNum = maxStr;
			strncat(strTmp, replace, replaceNum);
			for (int i = 0; i < strlen(text); i++) {
				strTmp[tarIndex + i + replaceNum] = text[tarIndex + i + replaceNum];
			}
		}
		else {
			replaceNum = strlen(replace);
			strncat(strTmp, replace, replaceNum);
			for (int i = 0; i < strlen(text); i++) {
				strTmp[tarIndex + i + replaceNum] = text[tarIndex + i + strlen(target)];
			}
		}

		
	}
	return strTmp;
}

char* replaceText(char* text, char* target, char* replace, int maxStr) {
	if (strcmp(target,"")==0) return 0;
	static char tmpStr[100] = {0,};
	strcpy(tmpStr, text);
	while (strstr(tmpStr, target) != 0) {
		char* tmpPt = replaceTextOne(tmpStr, target, replace, maxStr);
		strcpy(tmpStr, tmpPt);
	}

	return tmpStr;
}


int main() {
	char* pt;
	pt = replaceText("n hello World hello now", "hello", "tes", 5);
	printf("%s\n",pt);
}