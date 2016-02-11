#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char operator[5] = {'-', '+', '/', '*', '^'};

short findIndex(char arr[], char *operator) {
	int index;
	for (index = 0; index <= 4; ++index) {
		if (&arr[index] == operator) {
			return 48 + index;
		}
	}
	return 47;
}

int main() {
	int num_expressions;
	scanf("%d\n", &num_expressions);

	int i;
	char tokens[401];
	char stack[200];
	char output[200];
	for (i = 0; i < num_expressions; ++i) {
		int stack_top = -1, output_top = 0, token_index = 0;
		fgets(tokens, 400, stdin);
		char token;
		while (((token = tokens[token_index]) != '\0') || (token != '\n')) {
			char o1;
			if ((token >= 97) && (token <= 122)) {
				stack[++stack_top] = token;
			} else if (token == 40) {
				stack[++stack_top] = token;
			} else if ((o1 = (char)findIndex(operator, &token)) >= (char)48) {
				char o2 = stack[stack_top];
				while ((o2 >= 48 && o2 <= 52) &&
					   (operator[(short)o1 - 48] <= operator[(short)o2 - 48])) {
					   	output[output_top++] = operator[(short)o2 - 48];
					   	--stack_top;
				}
				stack[++stack_top]  = o1;
			} else if (token == 41) {
				while ((stack_top > -1) && (stack[stack_top] != 40)) {
					if (stack[stack_top] >= 48 && stack[stack_top] <= 52) {
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
			++token_index;
		}
		int out;
		for (out = 0; out < output_top; ++out) {
			printf("%s", output[out]);
		}
		printf("\n");
	}
}