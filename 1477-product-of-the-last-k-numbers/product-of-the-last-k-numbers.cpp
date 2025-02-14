class ProductOfNumbers {
    vector<long long>stream;
public:
    ProductOfNumbers() {
        stream.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) stream = {1};
        else
        stream.push_back(stream.back()*num);
    }
    
    int getProduct(int k) {
        int n = stream.size();
        if(k>=n) return 0;
        return stream[n-1]/stream[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */