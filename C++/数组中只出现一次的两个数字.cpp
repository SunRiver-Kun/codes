class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        int x_y = 0;
        for(auto& v : array) { x_y ^= v; }	//最后只剩下 x^y
        int flag = 1;	
        while((flag & x_y)==0) { flag <<= 1; }	//找到第一个判断点1，x，y的在&flag时就不同
        int x = 0;
        int y = 0;
        //把x，y分为两组，^到最后就剩下了
        for(auto& v : array){
            if(v & flag){
                x ^= v;
            }
            else{
                y ^= v;
            }
        }
        if(x <y ) { return {x, y}; }
        else { return {y, x}; }
    }
};