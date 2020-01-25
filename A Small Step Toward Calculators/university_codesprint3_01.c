#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int solve(char* opr) {
    // Complete this function
	if (opr[1] == '+')
		return (atoi(&opr[0]) + atoi(&opr[2])); 
	if (opr[1] == '-')
		return (atoi(&opr[0]) - atoi(&opr[2]));
	return (0);	
}

int main() {
    char* opr = (char *)malloc(512000 * sizeof(char));
    scanf("%s", opr);
    int result = solve(opr);
    printf("%d\n", result);
    return 0;
}

