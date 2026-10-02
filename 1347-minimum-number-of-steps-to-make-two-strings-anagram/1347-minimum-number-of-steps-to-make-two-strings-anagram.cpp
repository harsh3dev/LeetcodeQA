class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26,0);

        for(int i = 0; i < s.length(); i++){
            a[s[i] - 'a']++;
        }

        for(int i = 0; i < t.length(); i++){
            a[t[i] - 'a']--;
        }
        int ans = 0;
        for(auto x:a){
            if(x>0) ans+=x;
        }

        return ans;
    }
};

// leetcode
// practice

// a b c d e f g h i j k l m n o p q r s t u v w x y z
// 0 0 1 1 3 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 

// a b c d e f g h i j k l m n o p q r s t u v w x y z
// 1 0 2 0 1 0 0 0 1 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 

// a b c d e f g h i j k l m n o p q r s t u v w x y z
// 0 0 0 1 2 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 = 5

// a b c d e f g h i j k l m n o p q r s t u v w x y z
// 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 = 5


// praic
// leeod