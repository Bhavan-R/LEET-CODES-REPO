#include <stdlib.h>

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int count[100] = {0};
    int pairs = 0;

    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        
        int key = (a < b) ? (a * 10 + b) : (b * 10 + a);
        
        pairs += count[key];
        count[key]++;
    }

    return pairs;
}
