class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int words_sz=words.size();
        int alpha[26];
        
        for(int i=0;i<26;i++)
            alpha[order[i]-'a']=i;
        
        for(int i=0;i<words_sz-1;i++){
            int same=0;
            int len=min(words[i].length(),words[i+1].length());
            
            for(int j=0;j<len;j++){
                int a=alpha[words[i].at(j)-'a'];
                int b=alpha[words[i+1].at(j)-'a'];
                
                if(a==b)
                    same++;
                else if(a<b)
                    break;
                else
                    return false;
            }
            if(same==len && words[i].length()>words[i+1].length())
                return false;
        }
        return true;
    }
};
