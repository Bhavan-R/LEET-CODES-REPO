int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int n = 0;
    while (seq[n] != '\0') {
        n++;
    }
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            d++;
            ans[i] = d % 2;
        } else {
            ans[i] = d % 2;
            d--;
        }
    }
    return ans;
}
