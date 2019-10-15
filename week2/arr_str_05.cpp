class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<pair<string,int>>qu;
        vector<vector<string>>v;
        vector<string>ans;
        v.resize(10);
        v[2]={"a","b","c"};
        v[3]={"d","e","f"};
        v[4]={"g","h","i"};
        v[5]={"j","k","l"};
        v[6]={"m","n","o"};
        v[7]={"p","q","r","s"};
        v[8]={"t","u","v"};
        v[9]={"w","x","y","z"};
        
        int sz=digits.length();
        qu.push(make_pair("",0));
        while(!qu.empty()){
            string str=qu.front().first;
            int index=qu.front().second;
            qu.pop();
            
            if(index==sz){
                if(index>0)
                    ans.push_back(str);
                continue;
            }
            int num=digits.at(index)-'0';
            for(auto i:v[num]){
                qu.push(make_pair(str+i,index+1));
            }
        }
        return ans;
    }
};
