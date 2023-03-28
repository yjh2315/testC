#include<stdio.h>


int main() {
	char in;
	int count1 = 0;
	int count2 = 0;
	int check = 0;

	int repeat = 0;
	scanf("%d", &repeat);
    while(getchar()!='\n');
    in = getchar();
	for (int i = 0; i < repeat; i++) {
		while (in != '\n') {
			while (in == '(') {
				count1++;
				in = getchar();
			}
			while (in == ')') {
				count2++;
				in = getchar();
			}
			if (count1 != count2) {
				check = 1;
			}
			count1 = 0;
			count2 = 0;
		}
		if (check == 1) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
		check = 0;
		if(i != repeat-1) in = getchar();
	}

}
