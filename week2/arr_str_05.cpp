class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<pair<string,int>>qu;
        unordered_map<int,string>number={{2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"},
            {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
        vector<string>ans;
        int sz=digits.length();
        
        for(int i=0;i<sz;i++){
            int num=digits.at(i)-'0';
            string str=number[num];
            if(i==0){
                for(int j=0;j<str.length();j++)
                    ans.push_back(str.substr(j,1));
            }
            else{
                int n=ans.size();
                for(int j=0;j<n;j++){
                    for(int k=0;k<str.length();k++)
                        ans.push_back(ans[j]+str[k]);
                }
                ans.erase(ans.begin(),ans.begin()+n);
            }
        }
        
        return ans;
    }
};
