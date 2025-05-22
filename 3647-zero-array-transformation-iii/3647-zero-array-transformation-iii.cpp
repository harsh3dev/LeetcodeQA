class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> cache;
        int j = 0;
        int usedCount = 0;

        sort(queries.begin(), queries.end());

        for(int i = 0; i < n; i++){
            while(j < m && queries[j][0] == i){
                maxHeap.push(queries[j][1]);
                j++;
            }

            nums[i] -= cache.size();

            while(nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i){
                nums[i]--;
                usedCount++;
                int x = maxHeap.top();
                maxHeap.pop();
                cache.push(x);
            }

            if(nums[i] > 0){
                return -1;
            }

            while(!cache.empty() && cache.top() == i){
                cache.pop();
            }
        }

        return queries.size() - usedCount;
    }
};


/*
 * ALGORITHM
 * first initalize a maxHeap --> range
 * then initialize a cache --> minHeap
 * then initialize j (to traverse the queries array)
 * then initialize usedCount (our ans)
 * sort the queries array
 * now iterate on loop in nums
 * insert queries[1] into maxHeap until the curr index matches queries[0]
 * decrement nums[i] with cache.size()
 * decrement nums[i] with maxHeap elements and increase the usedCount and update cache
 * if nums[i] still > 0 then return -1;
 * now remove/clean the used cache as we progress
 * return the final queries.size() - usedCount
*/




// we have to find the min no of elements/queries which can be used to make it a zero array
// we have to use those queries which cover the max range
// for that we need to start small and go till last (as far as we can)
// so we iterate on the array nums
// and we'll check if the curr index and the index from queries match
// then we decrement the index
// also we store the end-point for future index
// so if the curr index is 2 and the j is 1,2
// but it doesn't match, so we'll check the past index, which is 2 so we can decrement
// but we have to also check if its not already zero (the element)
// then if the past index isnt available we'll fetch from the max heap
// -----------------------------------------------------------------------
// we'll push the end of the query to max heap as far as the  
// first of the query matches the curr index, to track how far we can go
// then as we use the end from the maxHeap, we put it in the past
// and dec the element by 1
// we will dec till the elem is not 0
// if the el is not 0 we return -1
// now we move to the next element
// now first we check from the cached past used index, as it may affect the curr range
// then we dec the element
// now if the elem is still not 0 then we dec from the max heap
// we also remove the expired cache
// --------------------------------------------------------------------------
