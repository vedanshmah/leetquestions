class Solution {
public:
    bool isset(int &x,int bit){
        if((x & (1<<bit)) != 0){
            return true;
        }
        return false;
    }

    void setbit(int &x,int bit){
        x = x | (1<<bit);
        return;
    }

    void unsetbit(int &x,int bit){
        x = x & (~(1<<bit));
        return;
    }
    int minimizeXor(int num1, int num2) {
        int x=num1;
        int req_setbits=0;
        int curr_setbits=0;
        int t1=num1,t2=num2;
        while(t2){
            if((t2&1)==1){
                req_setbits++;
            }
            t2=t2>>1;
        }
        while(t1){
            if((t1&1)==1){
                curr_setbits++;
            }
            t1=t1>>1;
        }
        int bit=0;
        if(req_setbits > curr_setbits){
            while(req_setbits > curr_setbits){
                if(!isset(x,bit)){
                    setbit(x,bit);
                    curr_setbits++;
                }
                bit++;
            }
        }
        else if(req_setbits < curr_setbits){
            while(req_setbits < curr_setbits){
                if(isset(x,bit)){
                    unsetbit(x,bit);
                    curr_setbits--;
                }
                bit++;
            }
        }
        return x;
    }
};