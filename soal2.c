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

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            large[i][j] = 0;
            // for (int k = i; k < R; k++) {
            //     for (int l = j; l < C; l++) {
            //         if (visited[k][l] != 1) {
            //             visited[k][l] = 1;
            //             if (matriks[k][l] == 1) {
            //                 large[i][j]++;
            //             } else break;
            //         }
            //     }
            // }
            int temp = 0;
            dfs(matriks, visited, i, j, &temp);
            large[i][j] = temp;
        }
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         large[i][j] = 0;
    //         for (int k = i; k < R; k++) {
    //             for (int l = j; l < C; l++) {
    //                 if (visited[k][l] != 1) {
    //                     visited[k][l] = 1;
    //                     if (matriks[k][l] == 1) {
    //                         large[i][j]++;
    //                     } else break;
    //                 }
    //             }
    //         }
    //     }
    // }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         if ((i == 0 || j == 0) && matriks[i][j] == 1 && visited[i][j] == 0) {
    //             dfs(matriks, visited, i, j);
    //         }
    //     }
    // }

    int total = 0;
    int resLarge = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (large[i][j] != 0) total++;
            if (large[i][j] > resLarge) resLarge = large[i][j];
        }
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < R; j++) {
    //         if (matriks[i][j] == 1 && !visited[i][j]) {
    //             total++;
    //             dfs(matriks, visited, i, j);
    //         }
    //     }
    // }

    printf("ISLANDS %d\nLARGEST %d", total, resLarge);
    
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         printf("%d ", matriks[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}