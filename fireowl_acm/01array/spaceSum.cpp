/*
question: spaceSum
author: fireowl
date: 2024-04-02
*/
#include <iostream>
#include <vector>

using namespace std;


int main(){
/************************输入数据************************/
 
    int n; 
    cin >> n; // 读取数组长度
    vector<int> arr(n,0);
    vector<int> arrSum(n,0);
    int sum = 0;
    
    for(int i = 0; i < n; ++i){
        cin >> arr[i]; //读取单个数组的数字
        sum += arr[i]; // 每一位上放入当前区间的和
        arrSum[i] = sum;
    }

    int left = 0,  right= 0;
    while(cin >> left >> right){ //读取区间值
        cout << arrSum[right] - arrSum[left-1] << endl; // 注意left为闭区间
    }

    return 0;
}