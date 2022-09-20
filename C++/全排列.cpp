//没有重复数字的全排列
class Solution {
  public:
    void recursion(vector<vector<int>>& res, vector<int>& num, int index) {
        if (index + 1 == num.size()) {
            res.push_back(num);
        } else {
            for (int i = index; i < num.size(); ++i) {
                swap(num[i], num[index]);
                recursion(res, num, index + 1);
                swap(num[i], num[index]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& num) {
        sort(begin(num), end(num));
        vector<vector<int>> res;
        recursion(res, num, 0);
        return res;
    }
};

//有重复数字的全排列
class Solution {
  public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        sort(begin(num), end(num));
        vector<vector<int>> res;
        vector<int> choosed;
        fn(num, res, choosed);
        return res;
    }

    void fn(const vector<int>& num, vector<vector<int>>& res,
            vector<int>& choosed) {
        if (choosed.size() == num.size()) {
            vector<int> data;
            for (auto& index : choosed) {
                data.push_back(num[index]);
            }
            res.push_back(data);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            int ok = true;
            for (auto& index : choosed) {
                if (index == i || (num[index] == num[i] && index > i)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                choosed.push_back(i);
                fn(num, res, choosed);
                choosed.pop_back();
            }
        }
    }

};