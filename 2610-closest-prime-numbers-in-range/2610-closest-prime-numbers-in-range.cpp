class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        int n = isPrime.size();

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = 2; i * j <= n; j++) {
                    isPrime[i * j] = false;
                }
            }
        }

        vector<int> prime;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
            }
        }

        unordered_map<int, pair<int, int>> mp;
        if (prime.size() < 2)
            return {-1, -1};
        for (int i = 0; i < prime.size() - 1; i++) {
            int diff = prime[i + 1] - prime[i];
            mp.insert({diff, {prime[i], prime[i + 1]}});
        }

        vector<int> ans(2, -1);
        int min_diff = INT_MAX;

        for (auto& element : mp) {
            int diff = element.first;
            pair<int, int> nums = element.second;
            if (diff < min_diff) {
                min_diff = diff;
                ans[0] = nums.first;
                ans[1] = nums.second;
            }
        }

        return ans;
    }
};

// find out all the prime numbers in the given range
// iterate through the prime array and check for two consecutive numbers with
// least diff which is occuring first 11 13 17 19
//   2  4  2
// iterate through the diff array and then take the first smallest pair
// 2 -> {11, 13}
// 4 -> {13, 17}
// 2 -> {17, 19}

// 2 1 3 1
// use seive of eratosthenes for better optimisation