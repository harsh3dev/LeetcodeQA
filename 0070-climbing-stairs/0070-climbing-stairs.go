func climbStairs(n int) int {
    if n < 2 {
        return n
    }
    s := make([]int, n+1)

    s[1] = 1
    s[2] = 2

    for i := 3; i <= n; i++ {
        s[i] = s[i-1] + s[i-2]
    }

    return s[n]
}