class RideSharingSystem {
public:
    queue <int> riders;
    queue <int> drivers;
    vector<bool> check;
    RideSharingSystem() {
        check.assign(1001,false);
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        check[riderId]=true;
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty() && check[riders.front()]==false){
            riders.pop();
        }
        if(riders.empty() || drivers.empty()){
            return {-1,-1};
        }
        int rid=riders.front();
        riders.pop();
        check[rid]=false;
        int did=drivers.front();
        drivers.pop();
        return{did,rid};
        
        
    }
    
    void cancelRider(int riderId) {
        check[riderId]=false;
    }
};

