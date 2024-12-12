class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> mh;

        for(int i=0;i<gifts.size();i++){
            mh.push(gifts[i]);
        }

        while(k>0){
            int top = mh.top();
            mh.pop();
            int newE = floor(sqrt(top));
            mh.push(newE);
            k--;
        }

        long long ans = 0;

        while(!mh.empty()){
            ans += mh.top();
            mh.pop();
        }
        return ans;
    }
};