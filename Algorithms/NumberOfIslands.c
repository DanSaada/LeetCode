/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.*/

void dfs(char** grid, int i, int j, int gridSize, int* gridColSize) {
    if (i < 0 || j < 0 || i >= gridSize || j >= *gridColSize || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i+1, j, gridSize, gridColSize);
    dfs(grid, i-1, j, gridSize, gridColSize);
    dfs(grid, i, j+1, gridSize, gridColSize);
    dfs(grid, i, j-1, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int counter = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1'){
                dfs(grid, i, j, gridSize, gridColSize);
                counter++;
            }
        }
    }
    return counter;
}