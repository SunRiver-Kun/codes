
class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    inline bool IsLegal(contst string& str){
        int level = 0;  //正数表示(的数量， )用来抵消（的数量，左边没(时就非法了。(()()) -> (()) -> 合法
        for(auto& v : str){
            if(v=='(') { ++level; }
            else if(v==')') { --level; }

            if(level < 0) { return false; }    
        }
        return level == 0;
    }


    int size;
    int level;
    vector<string> generateParenthesis(int n) {
        // write code here
        this->size = 2*n;
        this->level = 0;
        string s;
        vector<string> out;
        fn(s, out);
        return out;
    }
    
    void fn(string& str, vector<string>& out){
        if(level < 0 || level>size/2) { return; }
        if(str.size() == size) { 
            if( level==0 ) { out.push_back(str); }
            return;
        }
        
        str += '(';
        ++level;
        fn(str, out);
        str.pop_back();
        --level;
        
        str += ')';
        --level;
        fn(str, out);
        str.pop_back();
        ++level;
    }
};