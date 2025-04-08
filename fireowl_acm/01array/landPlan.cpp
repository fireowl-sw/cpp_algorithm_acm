/*
question: 规划土地给两个公司
author: fireowl
date: 2025-04-03
detail:在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，
代表着其土地价值。目前，有两家开发公司，A 公司和 B 公司，希望购买这个城市区域的土地。
现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。
然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，而且每个子区域都
必须包含一个或多个区块。 为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司
各自的子区域内的土地总价值之差最小。
注意：区块不可再分。

请输出一个整数，代表两个子区域内土地总价值之间的最小差距。
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printMatrix1(vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

/************************自己的想法************************/
int landPlan(vector<vector<int>> &nums, int n, int m)
{
    vector<int> sumsR;
    vector<int> sumsC;
    int sum = 0;
    int i = 0;
    // 行循环的和与列循环的和
    for (auto &row : nums)
    {
        for (auto &num : row)
        {
            sum += num;
        }
        sumsR.push_back(sum); // 导入n行的和
        sum = 0;
    }

    for (int i = 0; i < nums[0].size(); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum += nums[j][i];
        }
        sumsC.push_back(sum); // 导入m列的和
        sum = 0;
    }

    // 比较分界线左边的数和右边的数的差记录 最小的result
    int result = INT_MAX; // INT_MAX来自 climits
    sum = 0;

    for(int i = 0; i < sumsC.size()-1; ++i){ // 总共有n-1个分界线
        // 左边的和
        // cout << sum << " ";
        for(int j = 0; j <= i; j++){
            sum += sumsC[j];
        }
        // cout << sum << " ";
        // 右边的和
        for(int j = i+1; j < sumsC.size(); ++j){
            sum = sum-sumsC[j]; //这里不可以每次做绝对值
        }
        result = min(result, abs(sum)); //在最后做绝对值
        // cout << sum << " " <<  result << endl;

        sum = 0;

    }

    for(int i = 0; i < sumsR.size()-1; ++i){ // 总共有n-1个分界线
        // 左边的和
        // cout << sum << " ";
        for(int j = 0; j <= i; j++){
            sum += sumsR[j];
        }
        // cout << sum << " ";
        // 右边的和
        for(int j = i+1; j < sumsR.size(); ++j){
            sum = sum-sumsR[j]; //这里不可以每次做绝对值
        }
        result = min(result, abs(sum)); //在最后做绝对值
        // cout << sum << " " <<  result << endl;

        sum = 0;

    }

    return result;
}

/************************区间和推导************************/
int spaceSum_landPlan(vector<vector<int>> &nums, int n, int m){
    vector<int> sumsR;
    vector<int> sumsC;
    int sum = 0;
    int result = INT_MAX;
    // 行循环的和与列循环的区间和
    for (auto &row : nums)
    {
        for (auto &num : row)
        {
            sum += num;
        }
        sumsR.push_back(sum); // 导入区间和
    }
    
    
    sum = 0;
    for (int i = 0; i < nums[0].size(); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum += nums[j][i];
        }
        sumsC.push_back(sum); // 导入m列的和
    }
    
    // 求行的最小差值
    for(int i = 0; i < sumsR.size()-1; ++i){ //总共 sumsR.size()-1条线
        result = min(result, abs(sumsR[sumsR.size()-1] - sumsR[i] - sumsR[i])); // 总和-左区间=右区间；右区间-左区间就是最小了
    }
    //求列的最小插值
    for(int i = 0; i < sumsC.size()-1; ++i){ //总共 sumsR.size()-1条线
        result = min(result, abs(sumsC[sumsC.size()-1] - sumsC[i] - sumsC[i])); // 总和-左区间=右区间；右区间-左区间就是最小了
    }

    return result;
}
int main()
{
    /************************输入数据************************/
    int n, m;
    int result;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (auto &row : arr)
    {
        for (auto &num : row)
        {
            cin >> num;
        }
    }

    /************************算法函数************************/
    // result = landPlan(arr, n, m);
    result = spaceSum_landPlan(arr, n, m);
    /************************打印输出************************/
    cout << result << endl;

    return 0;
}