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
        out.precision(4);   // 取数据的前四位有效数字
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

    template <typename T>
    std::ostream &operator<<(std::ostream &out, std::valarray<T> const &A){
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

    // 删除vector的是首个元素
    template <typename T>
    std::valarray<T> pop_front(const std::valarray<T> &A){
        std::valarray <T> B;
        B.resize(A.size() - 1);
        for (size_t i = 1; i < A.size(); i++){
            B[i - 1] = A[i];
        }
        return B;
    }

    // 移除vector的最后一个元素
    template <typename T>
    std::valarray<T> pop_back(const std::valarray<T> &A){
        std::valarray<T> B;
        B.resize(A.size() - 1);
        for (size_t i = 0; i < A.size() - 1; i++){
            B[i] = A[i];
        }
        return B;
    }

    // 打乱数据顺序 3D vector
    template <typename T>
    void  equal_shuffle(std::vector<std::vector<std::valarray<T>>> &A,
                        std::vector<std::vector<std::valarray<T>>> &B){
        // 确保A,B的size一致
        if(A.size() != B.size()){
            std::cerr << "ERROR (" << __func__ << ") : ";
            std::cerr << "Can not equally shuffle two vector with difference sizes: ";
            std::cerr << A.size() << " and " << B.size() << std::endl;
            std::exit(EXIT_FAILURE);
        }
        for (size_t i = 0; i < A.size(); i++){
            // 随机种子
            std::srand(std::chrono::system_clock::now().time_since_epoch().count());
            size_t random_index = std::rand() % A.size();
            // 交换具有相同的随机index的元素
            std::swap(A[i], A[random_index]);
            std::swap(B[i], B[random_index]);
        }
        return;
    }

    // 使用uniform random initialization 初始化2D vector
    template <typename T>
    void uniform_random_initialization(std::vector<std::valarray<T>> &A,
                                       const std::pair<size_t, size_t> &shape,
                                       const T &low, const T &high){
        // 确保A是空
        A.clear();
        // [low, high] 均匀分布
        std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<T> distibution(low, high);
        for (size_t i = 0; i < shape.first; i++){
            std::valarray<T> row; // 插入向量中的行
            row.resize(shape.second); // 每行的元素个数，即列数
            for(auto &r : row){
                r = distibution(generator);  // 随机数
            }
            A.push_back(row);
        }
        return;
    }

    // 将2D vector 初始化为单位矩阵
    template <typename T>
    void unit_matrix_initialization(std::vector<std::valarray<T>> &A,
                                    const std::pair<size_t, size_t> &shape){
        A.clear();
        for (size_t i = 0; i<shape.first; i++){
            std::valarray<T> row;
            row.resize(shape.second);
            row[i] = T(1);  // 其它元素默认为0
            A.push_back(row);
        }
        return;
    }

    // 将2D vector 初始化为0
    template <typename T>
    void zero_initialization(std::vector<std::valarray<T>> &A,
                                    const std::pair<size_t, size_t> &shape){
        A.clear();
        for (size_t i = 0; i<shape.first; i++){
            std::valarray<T> row;
            row.resize(shape.second);  // 默认元素是0
            A.push_back(row);
        }
        return;
    }

    // 计算2D vector中所有的元素之和
    template <typename T>
    T sum(const std::vector<std::valarray<T>> &A){
        T cur_sum = 0;
        for (const auto &a : A){
            cur_sum += a.sum(); //a.sum()每一列的和
        }
        return cur_sum;
    }

    void test01(){
        // print 1D vector
        std::vector<int> weekdays;
        weekdays.push_back(2);
        weekdays.push_back(3);
        weekdays.push_back(4);
        weekdays.push_back(5);
        std::cout << "print 1D vector: " << weekdays;

        // insert element
        // 创建一个大小为4、值全为3的valarray
        std::valarray<int> valarray_A(3, 4);
        int a = 5;
        std::valarray<int> B = insert_element(valarray_A, a);
        std::cout << "insert_element: " << B << std::endl;

        // print vector<std::valarray<int>>
        std::vector<std::valarray<int>> vec_va;
        vec_va.push_back(B);
        vec_va.push_back(B);
        std::cout << "print vector<std::valarray<int>>: " << vec_va << std::endl;

        // print pair
        std::pair<int, int> pair_A = {1, 2};
        std::cout << "print pair = "<< pair_A << std::endl;
    }
}

#endif

int main(){
    machine_learning::test01();
}
