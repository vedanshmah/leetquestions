class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int fullwater = numBottles; //16
        int emptybottle = numBottles; //16
        int drink = fullwater; //16
        while(emptybottle >= numExchange){ // 4=>4
            int newbottle = emptybottle / numExchange; //1
            drink = drink + newbottle; //16 +4 + 1
            int left = emptybottle % numExchange; //1
            emptybottle = newbottle + left ;//2
        }
        return drink;
    }
};