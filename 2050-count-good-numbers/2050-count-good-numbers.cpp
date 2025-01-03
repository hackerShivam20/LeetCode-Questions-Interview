const int mod = 1e9 + 7;
class Solution {
public:
    int power(long long x, long long n){
        if(n==0) return 1;
        long long ans = power(x,n/2);
        ans *= ans;
        ans %= mod;
        if(n%2==1) ans *= x;
        ans %= mod;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = n/2;
        long long odd = n-even;
        long long pow4 = power(4, even);
        long long pow5 = power(5, odd);
        return (pow5 * pow4)%mod;
    }
};