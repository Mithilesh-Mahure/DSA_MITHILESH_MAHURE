class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int r=m;
        int top=0;
        int bottom=n;
        
        vector<int> ans;if(ans.size()==m*n) return ans;
        while(l<r && top<bottom){
            for(int i=l;i<r;i++){
                ans.push_back(matrix[top][i]);
                if(ans.size()==m*n) return ans;
            }
            top++;
            for(int i=top;i<bottom;i++){
                ans.push_back(matrix[i][r-1]);
                if(ans.size()==m*n) return ans;
            }
            r--;
            if (!(l < r && top < bottom)) break;
            for(int i=r-1;i>=l;i--){
                ans.push_back(matrix[bottom-1][i]);if(ans.size()==m*n) return ans;
            }
            bottom--;
            for(int i=bottom-1;i>=top;i--){
                ans.push_back(matrix[i][l]);
                if(ans.size()==m*n) return ans;
            }
            l++;
            
        }
        return ans;
    }
};