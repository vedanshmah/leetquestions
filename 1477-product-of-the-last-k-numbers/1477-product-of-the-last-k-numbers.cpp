class ProductOfNumbers {
public:
    vector<int> vec;
    int n;
    ProductOfNumbers() {
        vec.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            vec={};
            n=0;
        }
        else{
            if(!vec.empty()){
                vec.push_back(num*vec[n-1]);
            }
            else{
                vec.push_back(num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if(n==k){
            return vec[n-1];
        }
        else if(k>n){
            return 0;
        }
        return vec[n-1]/vec[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */