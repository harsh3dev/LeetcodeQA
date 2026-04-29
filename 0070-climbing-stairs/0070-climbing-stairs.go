func solve(curr int, n int, m []int) int {
    if curr > n {
        return 0
    }
    if curr == n {
        return 1
    }

    if m[curr] != -1 {
        return m[curr]
    }

    var two int = solve(curr + 2, n, m)
    var one int = solve(curr + 1, n, m)
    m[curr] = two + one
    return m[curr]
}

func climbStairs(n int) int {
    var curr int = 0

    m := make([]int, 46)

    for i := range m {
        m[i] = -1
    }

    return solve(curr, n, m)
}