class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        vector<int> ans;
        
        while(left<=right && top<=bottom){
            
            for(int i=left;i<=right && top<=bottom;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom && left<=right;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;i>=left && top<=bottom;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom;i>=top && left<=right;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
