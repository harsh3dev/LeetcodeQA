function createCounter(n: number): () => number {
    var count = 0;
    return function() {
        return n + count++;
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */