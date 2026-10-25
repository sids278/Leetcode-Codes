func dfs(i, j int, vis [][]bool, grid [][]int) bool {
    if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) {
        return false 
    }
    if grid[i][j] == 1 || vis[i][j] {
        return true 
    }
    vis[i][j] = true

    up := dfs(i-1, j, vis, grid)
    down := dfs(i+1, j, vis, grid)
    left := dfs(i, j-1, vis, grid)
    right := dfs(i, j+1, vis, grid)
    return up && down && left && right
}

func closedIsland(grid [][]int) int {
    n, m := len(grid), len(grid[0])

    visited := make([][]bool, n)
    for i := range visited {
        visited[i] = make([]bool, m)
    }

    cnt := 0
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 0 && !visited[i][j] && dfs(i, j, visited, grid) {
                cnt++
            }
        }
    }
    return cnt
}