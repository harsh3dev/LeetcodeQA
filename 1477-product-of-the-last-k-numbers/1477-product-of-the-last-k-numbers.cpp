class ProductOfNumbers {
public:
    vector<int> arr;
    int pr = 1; 
    int zeroCount = 0; 
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            arr.clear();
            pr = 1;
            zeroCount = 0;
        } else {
            if (!arr.empty())
                pr = arr.back() * num;
            else
                pr = num;

            arr.push_back(pr);
        }
    }

    int getProduct(int k) {
        if (k > arr.size()) 
            return 0;
        if (k == arr.size()) 
            return arr.back();
        int denominator = arr[arr.size() - k - 1];
        if (denominator == 0) 
            return arr.back();
        
        return arr.back() / denominator;
    }
};
