class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int trans = q.front().second;
            q.pop();
            
            if(word == endWord)return trans;
            
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                for(char j='a';j<='z';j++){
                    word[i] = j;
                    if(st.find(word)!=st.end()){
                        q.push({word,trans+1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        
        return 0;
    }
};