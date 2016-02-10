#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char findIndex(char arr[], char *operator) {
	int index;
	for (index = 0; index <= 4; ++index) {
		if (&arr[index] == operator) {
			return (char)index;
		}
	}
	return (char)-1;
}

int main() {
	int num_expressions;
	scanf("%d", &num_expressions);

	int i;
	char operator[5] = {'-', '+', '/', '*', '^'};

	for (i = 0; i < num_expressions; ++i) {
		int stack_top = -1, output_top = 0;
		char tokens[401];
		// Use fgets()
		fgets(tokens, 401, stdin);
		char stack[200];
		char output[200];
		int j = 0;
		char token;
		while (((token = tokens[j]) != '\0') || (token == '\n')) {
			char o1;
			if ((token >= 97) && (token <= 122)) {
				stack[++stack_top] = token;
			} else if (token == '(') {
				stack[++stack_top] = token;
			} else if ((o1 = findIndex(operator, &token)) >= '0') {
				char o2 = stack[stack_top];
				while ((o2 >= '0' && o2 <= '4') &&
					   (operator[(short)o1] <= operator[(short)o2])) {
					   	output[output_top++] = operator[(short)o2];
					   	--stack_top;
				}
				stack[++stack_top]  = o1;
			} else if (token == ')') {
				while ((stack_top > -1) && (stack[stack_top] != '(')) {
					if (stack[stack_top] >= '0' && stack[stack_top] <= '4') {
						output[output_top++] = operator[stack[stack_top--]];
					} else {
						output[output_top++] = stack[stack_top--];
					}
				}
				if (stack_top == -1) {
					printf("Improper parenthesis pair\n");
					exit(1);
				}
				--stack_top;
			} else {
				output[output_top++] = token;
			}
			printf("%c\n", token);
			++j;
		}
		int out;
		for (out = 0; out < output_top; ++out) {
			printf("%s", output[out]);
		}
		printf("\n");
	}
}