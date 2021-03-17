#include <iostream>
#include <vector>
#include "common.cpp"

template <typename T>
void merge(std::vector<T>& arr, int low, int mid, int high){
    int i = low, j = mid+1;
    std::vector<T> aux(high - low + 1);
    for (int k = low; k <= high; k++){
        aux[k] = arr[k];
    }

    for (int k = low; k <= high; k++){
        if(i > mid)
            arr[k] = aux[j++];
        else if (j > high)
            arr[k] = aux[i++];
        else if(aux[j] < aux[i])
            arr[k] = aux[j++];
        else
            arr[k] = aux[i++];
    }
}

template <typename T>
void merge_sort(std::vector<T> &arr, int low, int high){
    if(high <= low)
        return;
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(int argc, char* argv[]){
    std::vector<float> arr;
    std::cout << argc << std::endl;
    for (int i = 1; i < argc; i++){
        arr.push_back(atof(argv[i]));
    }
    print(arr);
    merge_sort(arr, 0, arr.size()-1);
    print(arr);
}
