#include <stdio.h>
#include <stdlib.h>

void dfs(char** grid, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(grid, i + 1, j, rows, cols);
    dfs(grid, i - 1, j, rows, cols);
    dfs(grid, i, j + 1, rows, cols);
    dfs(grid, i, j - 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return count;
}

int main() {
    int rows = 4;
    int cols = 5;
    
    char* gridData[] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };

    char** grid = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc((cols + 1) * sizeof(char));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = gridData[i][j];
        }
    }

    int* colSizes = malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) colSizes[i] = cols;

    int result = numIslands(grid, rows, colSizes);
    printf("Number of islands: %d\n", result);

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(colSizes);

    return 0;
}
