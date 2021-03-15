#include <iostream>
#include <vector>

#include "common.cpp"

template <typename T>
void selcection(std::vector<T> &arr){
    int N = arr.size();
    for (int i = 0; i < N-1; i++){
        int min = i;
        for (int j = i + 1; j < N; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
        print(arr);
    }
}

int main(int argc, char* argv[]){
    std::vector<int> arr;
    std::cout << argc << std::endl;
    for (int i = 1; i < argc; i++){
        arr.push_back(atoi(argv[i]));
    }
    print(arr);
    selcection(arr);
    print(arr);

}
