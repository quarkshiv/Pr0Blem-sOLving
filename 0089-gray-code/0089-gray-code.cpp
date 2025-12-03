class Solution {
public:
    vector<int> grayCode(int n) {
    int size = pow(2,n);
    vector<int>res(size);
    for(int i=0;i<size;i++){
        res[i] = i ^ (i>>1);

    }
    return res;
    }
};