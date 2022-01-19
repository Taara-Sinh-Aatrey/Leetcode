class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int sr = 0 , er = n-1 , sc = 0 , ec = n-1;
        int x = 1;
        while(sr<=er && sc<=ec)
        {
            if(sr<=er && sc<=ec)
            {
                for(int col=sc ; col<=ec ; col++)
                    matrix[sr][col] = x++;
                sr++;
            }
            
            if(sr<=er && sc<=ec)
            {
                for(int row=sr ; row<=er ; row++)
                    matrix[row][ec] = x++;
                ec--;
            }
            
            if(sr<=er && sc<=ec)
            {
                for(int col = ec ; col>=sc ; col--)
                    matrix[er][col] = x++;
                er--;
            }
            
             if(sr<=er && sc<=ec)
            {
                for(int row = er; row>=sr; row--)
                    matrix[row][sc] = x++;
                sc++;
            }
        }
        return matrix;
    }
};