#include <stdio.h>

int R = 0, C = 0;

int main() {
    scanf("%d %d", &R, &C);

    int matriks[R][C];
    char temp[C];
    for (int i = 0; i < R; i++) {
        scanf("%s", temp);
        for (int j = 0; j < C; j++) {
            matriks[i][j] = (int)temp[j] - '0';
        }
    }

    int large[R][C];
    int visited[R][C];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            large[i][j] = 0;
            for (int k = i; k < R; k++) {
                for (int l = j; l < C; l++) {
                    if (visited[k][l] != 1) {
                        visited[k][l] = 1;
                        if (matriks[k][l] == 1) {
                            large[i][j]++;
                        } else break;
                    }
                }
            }
        }
    }

    int total = 0;
    int resLarge = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (large[i][j] != 0) total++;
            if (large[i][j] > resLarge) resLarge = large[i][j];
        }
    }

    printf("ISLANDS %d\nLARGEST %d", total, resLarge);
    
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         printf("%d ", matriks[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}