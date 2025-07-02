class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=0;i<numRows;i++){
            vector<int>row;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)row.push_back(1);
                else{
                    int no=0;
                    no=res[i-1][j-1]+res[i-1][j];
                    row.push_back(no);
                }
            }
            res.push_back(row);
        }
        return res;
        
    }
};