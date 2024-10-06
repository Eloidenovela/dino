#include "sort/sort.hpp"
#include "../util/util.hpp"

namespace algo::sort {
    
    void selection(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int min_value = arr[i];
            int index = i;

            for (int j = i+1; j < size; j++) {
                if (min_value > arr[j]) {
                    min_value = arr[j];
                    index = j; 
                }
            }  

            util::swap(arr[i], arr[index]);
        }
    }

    void insertion(int arr[], int size) {
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] < arr[j]) {
                    using namespace util;
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    void bubble(int arr[], int size) {
        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size-1; j++) {

                if (arr[j] > arr[j+1]) {
                    using namespace util;
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    void quick(int arr[], int size) {
        
    }    

}