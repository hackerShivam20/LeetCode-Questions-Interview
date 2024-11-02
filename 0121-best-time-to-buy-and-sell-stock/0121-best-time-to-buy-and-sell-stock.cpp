// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini = prices[0];
//         int index = -1;
//         int ans = 0;

//         for(int i=1;i<prices.size();i++){
//             if(prices[i] <  mini){
//                 mini = prices[i];
//                 index = i;
//             }
//         }

//         cout<<mini<<" "<<index<<endl;

//         for(int i = index+1;i<prices.size();i++){
//             int diff = prices[i] - mini;
//             if(diff > ans){
//                 ans = diff;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini = prices[0];
//         int maxprofit = 0;

//         for(int i=0;i<prices.size();i++){
//             int cost = prices[i] - mini;
//             maxprofit = max(maxprofit, cost);
//             mini = min(mini, prices[i]);
//         }
//         return maxprofit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
    }
};