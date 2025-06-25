class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        if(i==j){
            return true;
        }
        if(i>j){
            return true;
        }
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    /*
    int palindromePartitioning(string &s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(s,i,j)){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int ans=INT_MAX;
        

        for(int k=i;k<j;k++){
            int left=0;
            int right=0;
            if(t[i][k]!=-1){
                left = t[i][k];
            } else {
                left = palindromePartitioning(s,i,k);
            }
            if(t[k+1][j]!=-1){
                right = t[k+1][j];
            } else {
                right = palindromePartitioning(s,k+1,j);
            }

            int temp= 1 + left + right;
            ans=min(ans,temp);
        }
        return ans;
    } 
    */

    void solve(string &s, int index, vector<vector<string>> &ans ,vector<string> &result){
        if(index==s.size()){
            ans.push_back(result);
            return;
        }

        for(int i=index ; i<s.size() ; i++){
            if(isPalindrome(s,index,i)){
                result.push_back(s.substr(index,i-index+1));
                solve(s,i+1,ans,result);
                result.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> result;
        solve(s,0,ans,result);

        return ans;
    }
};