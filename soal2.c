/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 05 – Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Imam Azkaziyan Ahmad (13224058)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk mencari pulau dan pulau terbesar
 * 
 */

#include <stdio.h>

int R = 0, C = 0;

// fungsi dfs
void dfs(int matriks[R][C], int visited[R][C], int row, int col, int *large) {
    if (row < 0 || col < 0 || row >= R || col >= C || visited[row][col] == 1 || matriks[row][col] == 0) {
        return;
    }

    visited[row][col] = 1;
    *large = *large + 1;
    
    dfs(matriks, visited, row + 1, col, large);
    dfs(matriks, visited, row - 1, col, large);
    dfs(matriks, visited, row, col + 1, large);
    dfs(matriks, visited, row, col - 1, large);
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
            // for (int k = 0; k < R; k++) {
            //     for (int 0 = j; l < C; l++) {
            //         if (visited[k][l] != 1) {
            //             visited[k][l] = 1;
            //             if (matriks[k][l] == 1) {
            //                 large[i][j]++;
            //             } else break;
            //         }
            //     }
            // }
            dfs(matriks, visited, i, j, &large[i][j]);
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