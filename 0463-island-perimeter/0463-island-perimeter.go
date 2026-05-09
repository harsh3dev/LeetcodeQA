type Pair struct {
    x int
    y int
}


func bfs(i int, j int, n int, m int, grid [][]int) int {
    pr := 0

    q := []Pair{}

    q = append(q, Pair{i, j})

    dir := [4][2]int{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    }

    grid[i][j] = -1

    for len(q) > 0 {
        ix := q[0].x
        jx := q[0].y

        q = q[1:]

        for idx := range dir {
            ii := ix + dir[idx][0]
            jj := jx + dir[idx][1]

            if ii < 0 || jj < 0 || ii >= n || jj >= m || grid[ii][jj] == 0 {
                pr++
                continue
            }

            if grid[ii][jj] == -1 {
                continue
            }

            q = append(q, Pair{ii, jj})
            grid[ii][jj] = -1
        }
    }


    return pr
}



func islandPerimeter(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 1 {
                return bfs(i, j, n, m, grid);
            }
        }
    }

    return -1;
}