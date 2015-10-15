/**
Floyd-Washall

# mat[i][j] can be copied if, we don't want to change original matrix
# finally mat[i][j] will be having the shortest path length between i and j
# below code: indexing from 1 to n
**/
    /*********FW - Algo*********/
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n;j++)
            for (int k = 1; k<=n; k++)
                if (mat[j][k] > mat[j][i] + mat[i][k])
                    mat[j][k] = mat[j][i] + mat[i][k];
    /*******Checking is any -ve cycle**********/
    bool is_neg_cycle = false;
    for (int i = 1; i<=n; i++)
        if (mat[i][i] < 0)
            is_neg_cycle = true;
    /******get min path length b/w u and v*****/
    return mat[u][v];
