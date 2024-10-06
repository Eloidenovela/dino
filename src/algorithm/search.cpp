#include "search/search.hpp"

namespace search {
    
    bool binary(int arr[], int begin, int end, int value) {
        if (begin <= end) {
            int middle = (begin + end) / 2;

            if (arr[middle] == value) {
                return true;
            } else if (value < arr[middle]) {

                return binary(arr, begin, middle - 1, value);
            } else if (value > arr[middle]) {

                return binary(arr, middle + 1, end, value);
            }
        }

        return false;
    }

    bool linear(int arr[], int size, int value) {
        for (int i = 0; i < size; i++)
            if (arr[i] == value)
                return true;

        return false;
    }

}