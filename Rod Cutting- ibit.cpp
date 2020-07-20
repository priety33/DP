vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.insert(B.begin(), 0);
    B.push_back(A);
    sort(B.begin(), B.end());
    int n=B.size();
    
    vector<vector<long>>dp(n, vector<long>(n, 0));
    vector<vector<int>>path(n, vector<int>(n, 0));
    
    for(int gap=2; gap<=n-1; gap++)
    {
        for(int i=0, j=i+gap; j<=n-1; i++, j++)
        {
            dp[i][j]=LONG_MAX;
            for(int k=i+1; k<j; k++)
            {
                long tmp=B[j]-B[i]+dp[i][k]+dp[k][j];
                if(dp[i][j]>tmp)
                {
                    dp[i][j]=tmp;
                    path[i][j]=k;
                }
            }
        }
    }
    //cout << path[2][4];
    stack<pair<int, int>> st;
    int flag=1;
    pair<int, int> pair1=make_pair(0, n-1);
    vector<int> res;
    while(flag || !st.empty())
    {
        if(flag)
        {
            if(pair1.first+1>=pair1.second)
            {
                flag=!flag;
                continue;
            }
            int tmmp=path[pair1.first][pair1.second];
            res.push_back(B[tmmp]);
            st.push(make_pair(tmmp, pair1.second));
            pair1=make_pair(pair1.first, tmmp);
        }
        else
        {
            pair1=st.top();
            st.pop();
            flag=!flag;
        }
        
    }
    return res;
    
}
