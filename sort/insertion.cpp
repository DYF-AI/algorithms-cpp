#include <iostream>
#include <vector>

#include "common.cpp"

template <typename T>
void insertion(std::vector<T> &arr){
    for (int i = 1; i < arr.size(); i++){
        // 将arr[i] 插入到 arr[i-1] arr[i-2] arr[i-3]中
        for (int j = i; j > 0 && (arr[j] < arr[j - 1]); j--){
            std::swap(arr[j], arr[j - 1]);
        }
        print(arr);
    }
}

int main(int argc, char* argv[]){
    std::vector<float> arr;
    std::cout << argc << std::endl;
    for (int i = 1; i < argc; i++){
        arr.push_back(atof(argv[i]));
    }
    print(arr);
    insertion(arr);
    print(arr);
}
