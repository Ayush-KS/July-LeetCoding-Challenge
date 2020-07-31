// Best Time to Buy and Sell Stock with Cooldown

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int maxProfit(int* prices, int n){
    if(n == 0 || n == 1)
        return 0;
    
    int sell2 = 0;
    
    int buy1 = max(-prices[0], -prices[1]);
    int sell1 = max(prices[1] - prices[0], 0);
    
    for(int i = 2; i < n; i++) {
        int currBuy = max(buy1, sell2 - prices[i]);
        int currSell = max(sell1, buy1 + prices[i]);
        
        sell2 = sell1;
        
        sell1 = currSell;
        buy1 = currBuy;
    }
    
    return sell1;
}