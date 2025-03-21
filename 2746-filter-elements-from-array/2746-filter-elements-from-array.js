/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let fr = []
    for(let i = 0; i < arr.length; i++){
        if(fn(arr[i], i)){
            fr.push(arr[i])
        }
    }
    return fr
};