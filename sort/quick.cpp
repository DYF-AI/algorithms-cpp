#include <iostream>
#include <vector>
#include "common.cpp"

template <typename T>
int partition(std::vector<T> &arr, int low, int high){
    // 将数组划分为a[low..i-1], a[i], a[i+1..high]
    int i = low, j = high + 1;
    T v = arr[low];   // 切分元素
    while(true){
        // 扫描左右，检测扫描是否结束并交换元素
        while (arr[++i] < v){ 
            if(i == high)
                break;
        }
        while(v < arr[--j]){
            if(j == low)
                break;
        }
        if(i >= j)
            break;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}

template <typename T>
void quick_sort(std::vector<T> &arr, int low, int high){
    if(high <= low)
        return;
    int j = partition(arr, low, high);
    quick_sort(arr, low, j - 1);
    quick_sort(arr, j + 1, high);
}

int main(int argc, char* argv[]){
    std::vector<float> arr;
    std::cout << argc << std::endl;
    for (int i = 1; i < argc; i++){
        arr.push_back(atof(argv[i]));
    }
    print(arr);
    quick_sort(arr, 0, arr.size()-1);
    print(arr);
}