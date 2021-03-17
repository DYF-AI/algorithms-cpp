#include <iostream>
#include <vector>

#include "common.cpp"

template <typename T>
void shell(std::vector<T> &arr){
    int h = 1;
    int N = arr.size();
    while (h < N/3){
        h = 3 * h + 1;
    }
    while (h >= 1){
        // 将数组变为h有序
        for (int i = h; i < N; i++){
            // 将a[i]插入到a[i-h], a[i-2*h], a[i-3*h]之中
            for (int j = i; j >= h && (arr[j] < arr[j - h]); j-=h){
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
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
    shell(arr);
    print(arr);
}
