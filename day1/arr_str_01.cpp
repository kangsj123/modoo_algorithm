class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,int>>letter;
        vector<int>digit;
        vector<string>ans;
        
        for(int i=0;i<logs.size();i++){
            string str=logs[i];
            
            int ind=str.find(" ");
            if(str.at(ind+1)>='0' && str.at(ind+1)<='9' ){
                digit.push_back(i);
            }
            else{
                letter.push_back({str.substr(ind+1,string::npos),i});
            }
        }
        
        sort(letter.begin(),letter.end(),[logs](pair<string,int> a,pair<string,int>b){
            return a.first==b.first? logs[a.second]<logs[b.second]:a.first<b.first;
        });
        
        for(int i=0;i<letter.size();i++){
            int index=letter[i].second;
            ans.push_back(logs[index]);
        }
        for(int i=0;i<digit.size();i++){
            int index=digit[i];
            ans.push_back(logs[index]);
        }
        return ans;
    }
};
