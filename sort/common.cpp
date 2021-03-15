#include <iostream>
#include <vector>

template <typename T>
void print(std::vector<T> &arr){
    int N = arr.size();
    for (int i = 0; i < N; i++){
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;
}
