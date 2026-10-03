#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    
    int* stack = (int*)malloc(sizeof(int) * (len + 1));
    int top = -1;
    
    stack[++top] = -1;
    int maxLen = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                maxLen = MAX(maxLen, i - stack[top]);
            }
        }
    }
    
    free(stack);
    return maxLen;
}
