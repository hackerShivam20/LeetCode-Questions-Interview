class Solution {
public:
    bool isPlaced(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int cntOfB = 0;

        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                cntOfB += cnt/k;
                cnt = 0;
            }
        }
        cntOfB += cnt/k;
        return cntOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if (val > n) return -1;
int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

        while(mini <= maxi){
            int mid = (mini+maxi)/2;
            if(isPlaced(bloomDay, mid, m, k)){
                maxi = mid-1;
            }
            else{
                mini = mid + 1;
            }
        }
        return mini;
    }
};