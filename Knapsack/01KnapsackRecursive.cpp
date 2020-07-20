#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll findMaxProfit(ll itemsValue[],ll weights[],ll weight,ll itemIndex){
    if(!weight || !itemIndex)
    return 0;

    if(weights[itemIndex-1]<=weight)
    return max(itemsValue[itemIndex-1]+findMaxProfit(itemsValue,weights,weight-weights[itemIndex-1],itemIndex-1),
    findMaxProfit(itemsValue,weights,weight,itemIndex-1)
    );

    else
        return findMaxProfit(itemsValue,weights,weight,itemIndex-1);
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

    cout<<findMaxProfit(itemsValue,weights,knapsackSize,numberOfItems);
}