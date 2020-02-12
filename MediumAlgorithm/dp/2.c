int uniquePaths(int m, int n){
    if(m == 1 || n == 1) return 1;
    int route[m][n];
    memset(route, 0, m*n*sizeof(int));
    for(int i = 1; i < m; ++i)
        route[i][0] = 1;
    for(int i = 1; i < n; ++i)
        route[0][i] = 1;
    for(int i = 1; i < m; ++i)
        for(int j = 1; j < n; ++j)
            route[i][j] = route[i][j-1] + route[i-1][j];
    return route[m-1][n-1];
}

