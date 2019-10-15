struct paren{
    string s;
    int left;
    int right;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<paren>qu;
        vector<string> ans;
        
        qu.push({"(",1,1});
        
        while(!qu.empty()){
            string str=qu.front().s;
            int left=qu.front().left;
            int right=qu.front().right;
            qu.pop();
            
            if(str.length()==2*n)
                ans.push_back(str);
            
            if(left<n)
                qu.push({str+"(",left+1,right+1});
            if(right>0)
                qu.push({str+")",left,right-1});
        }
        return ans;
    }
};
