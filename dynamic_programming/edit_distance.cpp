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
using namespace std;

int min_xyz(int x, int y, int z){return  min(min(x, y), z);};

namespace recursive{
    // 递归
    int editDist(string str1, string str2, int m, int n){
        if (m == 0)
            return n;
        if(n == 0) 
            return m;
        if(str1[m-1]==str2[n-1])
            return editDist(str1, str2, m - 1, n - 1);
        return 1 + min_xyz(editDist(str1, str2, m, n - 1),
                           editDist(str1, str2, m - 1, n),
                           editDist(str1, str2, m - 1, n - 1));
    }
}

namespace dynamic_programming{


}

int main(){
    string str1 = "sunday";
    string str2 = "saturday";

    cout << "The minimum edit distance = " << recursive::editDist(str1, str2, str1.length(), str2.length()) << endl;
}
