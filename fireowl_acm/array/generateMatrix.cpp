/*
question: leetcode 59 Spiral Matrix II
author: fireowl
date: 2025-04-02
*/
#include <iostream>
#include <vector>

using namespace std;

void printMatrix1(vector<vector<int>> & nums){
    for(auto &row : nums){
        for(int num : row){
            cout<<num<<" ";
        }
        cout << endl;
    }
}
void printMatrix2(vector<vector<int>> & nums){
    
    cout << "[";
    for(size_t i = 0; i<nums.size(); ++i){
        cout << "[";
        for(size_t j = 0; j<nums[i].size(); ++j){
            cout<<nums[i][j];
            if(j != nums[i].size()-1){
                cout<<",";
            }
        }
        cout<<"]";
        if(i != nums.size()-1){
            cout<<",";
        }
    }
    cout<<"]";
}

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> output(n, vector<int>(n, 1));
    int startx = 0, starty= 0; //创建起始点坐标 右边x下边y
    int loop = n/2; // 创建循环次数
    int offset = 0; // 偏移量来根据循环次数减少移动位数
    int count = 1; // 递增的填充数字

    while(loop--){
        //建立循环变量
        int i = starty;
        int j = startx;
        //顺着走 取最大值-偏移量
        // [左, 右) 移动j, starty不变
        for(j = startx; j < n-1-offset; ++j){ 
            output[i][j] = count++;
        }
        
        // [上, 下) 移动i, 左闭右开 j为n-1-offset
        for(i = starty; i < n-1-offset; ++i){
            output[i][j] = count++;
        }

        // 逆着走取起始点位置
        // [右, 左) 移动j 
        for(; j > startx; --j){
            output[i][j] = count++;
        }

        // [下, 上) 移动i
        for(; i > starty; --i){
            output[i][j] = count++;
        } 
        
        // 一次循环后起始点需要+1
        startx++;
        starty++;

        // 一次循环后偏移量也需要增加
        offset++;
    }

    // 考虑n为奇数，最后一位需要手动填充
    if(n%2){
        output[n/2][n/2] = n*n; 
    }

    return output;
}
vector<vector<int>> generateMatrix2(int n){
    vector<vector<int>> output(n, vector<int>(n));
    // 模拟写法
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int k = 1;

    while(k <= n*n){
        // [左, 右] 完全填充 直接由固定边界right
        for(int i = left; i <= right; ++i, ++k){
            output[top][i] = k;
        }
        ++top;

        // [上, 下] 固定边界bottion
        for(int i = top; i<=bottom; ++i, ++k){
            output[i][right] = k;
        }
        --right;

        // [右,左] 固定边界left
        for(int i = right; i >= left; --i, ++k){
            output[bottom][i] = k;
        }
        --bottom;

        // [下, 上] 固定边界top
        for(int i = bottom; i >= top; --i, ++k){
            output[i][left] = k;
        }
        ++left;
    }

    return output;
}

int main(){
/************************输入数据************************/
    int n;
    cin >> n;
    vector<vector<int>> output;
/************************算法函数************************/
    output = generateMatrix2(n);

/************************打印输出************************/
    printMatrix2(output);
    
    return 0;
}