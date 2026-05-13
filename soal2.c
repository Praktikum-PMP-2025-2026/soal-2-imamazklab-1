#include <stdio.h>

int R = 0, C = 0;

void dfs(int matriks[R][C], int visited[R][C], int x, int y, int *large) {
    if (x < 0 || y < 0 || x >= R || y >= C || visited[x][y] == 1 || matriks[x][y] == 0) {
        return;
    }

    visited[x][y] = 1;
    *large = *large + 1;
    
    dfs(matriks, visited, x + 1, y, large);
    dfs(matriks, visited, x - 1, y, large);
    dfs(matriks, visited, x, y + 1, large);
    dfs(matriks, visited, x, y - 1, large);
}

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

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         large[i][j] = 0;
    //         // for (int k = 0; k < R; k++) {
    //         //     for (int 0 = j; l < C; l++) {
    //         //         if (visited[k][l] != 1) {
    //         //             visited[k][l] = 1;
    //         //             if (matriks[k][l] == 1) {
    //         //                 large[i][j]++;
    //         //             } else break;
    //         //         }
    //         //     }
    //         // }
    //         dfs(matriks, visited, i, j, &large[i][j]);
    //     }
    // }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            large[i][j] = 0;
            for (int k = 0; k < R; k++) {
                for (int l = 0; l < C; l++) {
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