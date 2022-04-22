 vector<vector<int> > permuteUnique(vector<int> &nums) {
        if(nums.empty()) { return {}; }
        if(nums.size()==1) { return {{nums.front()}}; }
        sort(begin(nums),end(nums));
        return fn(begin(nums), end(nums));
    }
    
    using _It = vector<int>::iterator;
    vector<vector<int> > fn(_It first, _It last){
        if(distance(first, last)==1) { return {{*first}};}
        else{
            vector<vector<int> > out;
            vector<int> data( distance(first, last) );    
            for(auto it=first; it!=last;){
                auto datait = data.begin();
                *datait++ = *it;
                for(auto it2=first; it2!=last; ++it2){
                    if(it2 != it)
                        *datait++ = *it2;
                }
                auto&& subs = fn(++begin(data), end(data));
                for(auto& sub : subs){
                    copy(begin(sub), end(sub), ++begin(data));
                    out.push_back(data);
                }
                while((it!=last) && (*it++) == *it);   //避免重复数值
            }
            return out;
        }
    }