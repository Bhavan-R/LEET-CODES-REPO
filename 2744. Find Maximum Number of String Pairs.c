int maximumNumberOfStringPairs(char** words, int wordsSize) {
    int seen[26][26] = {0};
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        int u = words[i][0] - 'a';
        int v = words[i][1] - 'a';

        if (seen[v][u]) {
            count++;
            seen[v][u]--;
        } else {
            seen[u][v]++;
        }
    }

    return count;
}
