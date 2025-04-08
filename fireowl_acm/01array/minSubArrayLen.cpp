/*
leetcode: 209 Minimum Size Subarray Sum
author: fireowl
date: 2025-04-02
*/
#include <iostream>
#include "vector"
#include "sstream"
#include "cctype"


using namespace std;

int minSubArrayLen(int target, vector<int>& nums){
    int result = INT32_MAX;
    int slibeg = 0, sliend = 0;
    int sum = nums[slibeg];

    if(nums.empty()) return 0; //避免空数组

    while(sliend<nums.size()){
        //如何解决第一个元素的判断问题
        if(sum < target){
            // 判断两种情况,一种是slibeg++后如果小于，那么加的应该是下一个元素
            sliend++;
            if(sliend < nums.size()){ //防止数组越界
                sum += nums[sliend];
            }else{
                break;
            }
        }else{
            result = min(result, sliend-slibeg+1);
            sum -= nums[slibeg];
            slibeg++;
        }
    }
    return result == INT32_MAX ? 0 : result;
}


void arrayPrint(vector<int>& nums){
    cout<<"[";
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i];
        if(i != nums.size()-1){
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}


int main(){
/************************读取空格形式数组输入************************/
    // int target;
    // vector<int> nums;
    // int num;
    // int output;

    // cin >> target;
    // while(cin >> num){
    //     nums.push_back(num);
    //     if(getchar() == '\n'){
    //         break;
    //     }
    // }
/************************读取字符串形式数组输入************************/
    string line;    
    int target;
    int output;
    getline(cin, line);
    target = stoi(line);

    vector<int> nums;
    getline(cin, line);
    for(char &c : line){
        if(c=='[' || c==']' || c==','){
            c = ' ';
        }
    }

    istringstream iss(line); //转换为数字流
    int num;
    while(iss >> num){ //从流中逐个读取数字
        nums.push_back(num);
    }

/************************算法函数************************/
    output = minSubArrayLen(target, nums);
/************************打印输出************************/
    // arrayPrint(nums);
    cout<<output<<endl;

    return 0;
}