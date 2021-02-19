/*
    给定两个字符串str1和str2及以下操作，可以在str1上执行。 
    查找最小编辑数量（操作）将“ str1”转换为“ str2” /
    一种。 
    a. 插入
    b.消除
    C.代替
    以上所有操作cost均等
*/
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int min(int x, int y, int z){return  min(min(x, y), z);}

namespace recursive{
    // 递归
    int editDist(string str1, string str2, int m, int n){
        if (m == 0)
            return n;
        if(n == 0) 
            return m;
        if(str1[m-1] == str2[n-1])
            return editDist(str1, str2, m - 1, n - 1);
        return 1 + min(editDist(str1, str2, m, n - 1),
                           editDist(str1, str2, m - 1, n),
                           editDist(str1, str2, m - 1, n - 1));
    }
}

namespace dynamic_programming{
    int editDistDP(string str1, string str2, int m, int n){
        // 创建表
        int dp[m + 1][n + 1];

        // 填表
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }
}

int main(){
    string str1 = "sunday";
    string str2 = "saturday";
    clock_t startTime1, endTime1, startTime2, endTime2;
    startTime1 = clock();
    cout << "The minimum edit distance = " << recursive::editDist(str1, str2, str1.length(), str2.length()) << endl;
    endTime1 = clock();
    cout << "Recursive time cost = " << (double)(endTime1 - startTime1) / CLOCKS_PER_SEC << "s" << endl;

    startTime2 = clock();
    cout << "The minimum edit distance = " <<dynamic_programming::editDistDP(str1, str2, str1.length(), str2.length()) << endl;
    endTime2 = clock();
    cout << "DP time cost = " << (double)(endTime2 - startTime2) / CLOCKS_PER_SEC << "s" << endl;

    return 0;

}
