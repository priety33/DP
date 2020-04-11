class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m = d.size(), n = d[0].size() ;
        d[m-1][n-1] = max( 1, 1 - d[m-1][n-1] ) ; //with what min height should we reach this block, so that after consuming power we can move forward.
        
        for( int i = n-2; i >= 0; i-- )
            d[m-1][i] = max( 1, d[m-1][i+1] - d[m-1][i] ) ; //height on reaching here should be suvh that after consuming power, we have the height                                                                   //required on arrival at below block
        
        for( int i = m-2; i >= 0; i-- )
            d[i][n-1] = max( 1, d[i+1][n-1] - d[i][n-1] ) ; //height on reaching here should be suvh that after consuming power, we have the height                                                                   //required on arrival at right block
        
        for( int i = m-2; i >= 0; i-- )
            for( int j = n-2; j >= 0; j-- )
                d[i][j] = max( 1, min( d[i+1][j], d[i][j+1] ) - d[i][j] ) ;
        
        return d[0][0] ;
    }
};
