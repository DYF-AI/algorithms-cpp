#ifndef VECTOR_OPS_FOR_NN
#define VECTOR_OPS_FOR_NN

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <valarray>
#include <vector>

namespace machine_learning{
    // 重载<< 打印二维数组
    template <typename T>
    std::ostream &operator<<(std::ostream &out, std::vector<std::valarray<T>> const &A){
        out.precision(4);
        for(const auto &a : A){
            for(const auto &x : a){
                std::cout << x << ' ';
            }
            std::cout << std::endl;
        }
        return out;
    }


    // 重载 << 打印pair
    template <typename T>
    std::ostream &operator <<(std::ostream &out, const std::pair<T,T> &A){
        out.precision(4);
        // printing pair in the form (p, q)
        std::cout << "(" << A.first << ", " << A.second << ")";
        return out;
    }

    // 重载<< 打印一维数组
    template <typename T>
    std::ostream &operator<<(std::ostream &out, std::vector<T> const &A){
        out.precision(4);
        for(const auto &a : A){
            std::cout << a << ' ';
        }
        std::cout << std::endl;
        return out;
    }


    // 将element插入1D vector
    template <typename T>
    std::valarray<T> insert_element(const std::valarray<T> &A, const T &ele){
        std::valarray<T> B;     // 存储新的1D
        B.resize(A.size() + 1); // 调整大小
        for (size_t i = 0; i < A.size(); i++){
            B[i] = A[i];
        }
        B[B.size() - 1] = ele;  // 最后位置插入新元素
        return B;
    }


    void test01(){

        // 验证 重载<< 打印一维数组
        std::vector<int> weekdays;
        weekdays.push_back(2);
        weekdays.push_back(3);
        weekdays.push_back(4);
        std::cout << "print 1D: " << weekdays;

    }
}

#endif


int main(){
    machine_learning::test01();
}
