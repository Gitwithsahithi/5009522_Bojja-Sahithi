#include <stdio.h>

int R, C;
long long N;
char grid[210][210];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void fill_bombs(char out[210][210]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            out[i][j] = 'O';
        }
        out[i][C] = '\0';
 }
}

void explode(char in[210][210], char out[210][210]) {
    fill_bombs(out);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (in[i][j] == 'O') {
                out[i][j] = '.';
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C)
                        out[ni][nj] = '.';
 }
     }
     }
}
}

void print(char g[210][210]) {
    for (int i = 0; i < R; i++)
        printf("%s\n", g[i]);
}

int main() {
    scanf("%d %d %lld", &R, &C, &N);
    for (int i = 0; i < R; i++)
        scanf("%s", grid[i]);

    if (N == 1) {
        print(grid);
        return 0;
    }

    if (N % 2 == 0) {
        char all[210][210];
        fill_bombs(all);
        print(all);
        return 0;
    }

    char after3[210][210];
    char after5[210][210];

    explode(grid, after3);
    explode(after3, after5);

    if (N % 4 == 3)
        print(after3);
    else
        print(after5);

    return 0;
}
