function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    var newArr = [];
    for(let i = 0; i<arr.length; i++){
        newArr[i] = fn(arr[i], i)
    }
    return newArr;
};