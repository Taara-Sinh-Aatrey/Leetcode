class Solution {
public:
    
    unordered_map <string , int > mp ;

int Solve(string A , int i , int j , string B , int x , int y)
{
    if(j-i != y-x)
    {
        return 0 ;
    }

    if(i==j && x==y)
    {
        if(A[i] == B[x])
        {
            return 1 ;
        }
        else
        {
            return 0 ;
        }
    }

    if(A.substr(i,j+1) == B.substr(x,y+1))
    {
        return 1 ;
    }
    
    string key = to_string(i) ;
    key.append("_") ;
    key.append(to_string(j)) ;
    key.append("_") ;
    key.append(to_string(x)) ;
    key.append("_") ;
    key.append(to_string(y)) ;
    if(mp.find(key) != mp.end())
    {
        return mp[key] ;
    }

    int flag = 0 ;
    for(int k=i,z=x ; k<j && z<y ; k++,z++)
    {
        int c1 = Solve(A,i,k,B,x,z) && Solve(A,k+1,j,B,z+1,y) ;
        if(c1==1)
        {
            flag = 1 ;
            break ;
        }
        int c2 = Solve(A,i,k,B,x+y-z,y) && Solve(A,k+1,j,B,x,x+y-z-1) ;
        if(c2==1)
        {
            flag = 1 ;
            break ;
        }
    }

    return mp[key] = flag ;
}

bool isScramble(string A, string B) 
{
    if(A.length() != B.length())
    {
        return 0 ;
    }    
    return Solve(A,0,A.length()-1,B,0,B.length()-1) ;   
    //return Solve(A,B) ;
}
    
    
//     bool isScramble(string s, string t) {
//         int n = s.size();
//         vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n)));
        
//         for (int l = 1; l <= n; l++) {
//             for (int i = 0; i + l <= n; i++) {
//                 for (int j = 0; j + l <= n; j++) {
//                     if (l == 1) {
//                         dp[l][i][j] = s[i] == t[j];
//                     }
//                     else {
//                         for (int l2 = 1; l2 < l; l2++) {
//                             dp[l][i][j] = dp[l][i][j] | (dp[l2][i][j] && dp[l - l2][i + l2][j + l2]);
//                             dp[l][i][j] = dp[l][i][j] | (dp[l2][i][j + l - l2] && dp[l - l2][i + l2][j]);
//                         }
//                     }
//                 }
//             }
//         }
        
//         return dp[n][0][0];
//     }
};