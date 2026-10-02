#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int n, int open, int close, char* current, int length, char** result, int* returnSize) {
    if (length == 2 * n) {
        current[length] = '\0';
        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[length] = '(';
        backtrack(n, open + 1, close, current, length + 1, result, returnSize);
    }

    if (close < open) {
        current[length] = ')';
        backtrack(n, open, close + 1, current, length + 1, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int maxCombinations = 1430;
    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;

    backtrack(n, 0, 0, current, 0, result, returnSize);

    free(current);
    return result;
}
