class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    map<char, int> oplevel{
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'%', 2},
        {'^', 3}
    };

    int solve(string s) {
        //去掉所以空格
        for (size_t pos = s.find(' '); pos != string::npos; pos = s.find(' ', pos)) {
            s.replace(pos, 1, "");
        }
        stack<int> nums;
        stack<char> ops;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if ( ch == '(') {
                ops.push(ch);
            } else if ( ch == ')') {
                //计算直到遇到左括号
                while (ops.size()) {
                    if (ops.top() == '(') {
                        ops.pop();
                        break;
                    }
                    cal(nums, ops);
                }
            } else {
                if ( isdigit(ch) ) {
                    int n = 0;
                    int j = i;
                    while (j < s.size() && isdigit(s[j])) {
                        n = n * 10 + (s[j++] - '0');
                    }
                    nums.push(n);
                    i = j - 1;
                } else {
                    if ( (ch == '+' || ch == '-') && (i == 0 || s[i - 1] == '(')) {
                        nums.push(0);    //避免第一个+-号和括号后的+-号
                    }
                    //当栈内运算符高于/等于当前运算符时，先计算完栈内的再入栈
                    while (ops.size() && ops.top() != '(' &&
                            oplevel[ops.top()] >= oplevel[ch] ) {
                        cal(nums, ops);
                    }
                    ops.push(ch);
                }
            }
        }
    
        //计算剩余的
        while (ops.size()) {
            cal(nums, ops);
        }
        return nums.top();
    }




    void cal(stack<int>& nums, stack<char>& ops) {
        if(nums.size() < 2 || ops.empty()) { return; }
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        
        int res = 0;
        if(op =='+') { res = a+b; }
        else if(op =='-') { res = a-b; }
        else if(op =='*') { res = a*b; }
        else if(op =='/') { res = a/b; }
        else if(op =='%') { res = a%b; }
        else if(op =='^') { res = pow(a, b); }
        else{
            throw invalid_argument("op: " + to_string(op) + " is not defined!");
        }
        nums.push(res);
    }
};