class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        //array[i]用来表示结尾index为i的连续数组最大值
        for(int i=1; i<array.size(); ++i){
            if(array[i-1] > 0)
                array[i] += array[i-1];
        }
        return *max_element(begin(array), end(array));
    }
};