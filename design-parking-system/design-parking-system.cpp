class ParkingSystem {
public:
    int v[3];
    ParkingSystem(int big, int medium, int small) {
        v[0]=big;
        v[1]=medium;
        v[2]=small;
    }
    bool addCar(int carType) {
        if(v[carType-1]!=0){
            v[carType-1]=v[carType-1]-1;
            return true;
        }
        return false;
    }
    
    
    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */