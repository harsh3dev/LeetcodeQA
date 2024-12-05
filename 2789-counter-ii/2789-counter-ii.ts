type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(n: number): Counter {
    var count = n;
    return {
        increment: function(){
            return ++count;
        },
        decrement: function(){
            return --count;
        },
        reset: function(){
            count = n;
            return n;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */