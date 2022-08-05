//如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对
//归并
class Solution {
  public:
    int count = 0;

    int InversePairs(vector<int> data) {
        count = 0;
        if (data.size() < 2) {
            return 0;
        }
        mergesort(data, 0, data.size() - 1);
        return count;
    }

    void mergesort(vector<int>& data, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = (left + right) / 2;
        mergesort(data, left, mid);
        mergesort(data, mid + 1, right);
        merge(data, left, mid, right);
    }

    void merge(vector<int>& data,const int left, const int mid, const int right) {
        auto arr = make_unique<int[]>(right - left + 1);
        int index = 0;
        
        int leftit = left;
        int rightit = mid+1;
        while(leftit <= mid && rightit<=right){
            if(data[leftit] <= data[rightit]){
                arr[index++] = data[leftit];
                ++leftit;
            }
            else{
                arr[index++] = data[rightit];
                count += mid - leftit + 1;
                count %= 1000000007;
                ++rightit;
            }
        }
        
        while(leftit <= mid) { arr[index++] = data[leftit++]; }
        while(rightit <= right) { arr[index++] = data[rightit++]; }
        
        int out = left;
        for(int i=0; i<index; ++i, ++out) { data[out] = arr[i]; } 
    }
};