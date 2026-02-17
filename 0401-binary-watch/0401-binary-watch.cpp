class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int hr=0;hr<=11;hr++){
            for(int mm=0;mm<=59;mm++){
                if(__builtin_popcount(hr) +__builtin_popcount(mm)==turnedOn){
                    string hour=to_string(hr);
                    string min="";
                    if(mm<10){
                        min="0" + to_string(mm);
                    }else{
                        min=to_string(mm);
                    }
                    res.push_back(hour + ":" + min);
                }
            }
        }
        return res;
    }
};