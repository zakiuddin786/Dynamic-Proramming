#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN=10;

ll dp[maxN][maxN];

ll findMaxProfit(ll itemsValue[],ll weights[],ll weight,ll itemIndex){
    if(!weight || !itemIndex)
    return 0;

    if(~dp[itemIndex][weight])
    return dp[itemIndex][weight];

    if(weights[itemIndex-1]<=weight)
    {
        return dp[itemIndex][weight] = max(itemsValue[itemIndex-1]+findMaxProfit(itemsValue,weights,weight-weights[itemIndex-1],itemIndex-1),
    findMaxProfit(itemsValue,weights,weight,itemIndex-1)
    );
    }
    else
        return dp[itemIndex][weight] = findMaxProfit(itemsValue,weights,weight,itemIndex-1);
}
signed main(){
    ll numberOfItems;
    cin>>numberOfItems;
    ll itemsValue[numberOfItems],weights[numberOfItems];


    for(ll item=0;item<numberOfItems;item++)
    cin>>itemsValue[item];

    for(ll weight=0;weight<numberOfItems;weight++)
    cin>>weights[weight];

    ll knapsackSize;
    cin>>knapsackSize;
    cout<<sizeof(dp)<<" "<<8*(numberOfItems+2)*(knapsackSize+2)<<" ";
    memset(dp,-1,8*(numberOfItems+3)*(knapsackSize+2));

        for(int i=0;i<=numberOfItems;i++){
        for(int j=0;j<=knapsackSize;j++)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    cout<<findMaxProfit(itemsValue,weights,knapsackSize,numberOfItems);
}