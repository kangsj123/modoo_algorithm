class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s,s.length()-1,0);
        return ans;
    }
    
    void dfs(string& s, int cur_indx, int point){
        int num=0;
        if(point==3){
            for(int i=0;i<=cur_indx;i++){
                num+=(s[i]-'0');
                if(i==cur_indx)break;
                num*=10;
            }
            if(s[0]=='0' && cur_indx!=0)return;
            if(num>=0 && num<256)
                ans.push_back(s);
            return;
        }
        int ten=1;
        for(int i=cur_indx;i>cur_indx-3 && i>=0;i--){
            string tmp=s;
            num+=(s[i]-'0')*ten;
            ten*=10;
            
            if(s[i]=='0' && i<cur_indx)continue;
            if(num>=0 && num<256 && i<=(3-point)*3 && i>=(3-point) )
                dfs(tmp.insert(i,"."),i-1,point+1);  
        }
    }
};
