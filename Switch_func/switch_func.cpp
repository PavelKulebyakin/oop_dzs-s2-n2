#include "switch_func.h"

int random(int range)
{
    return (rand() % range) * pow(-1, rand() % 2);
}

void func_1(int* arr, unsigned arr_len) {

    for (unsigned i = 0; i < (arr_len / 2); i++)
        std::swap(arr[i], arr[arr_len - i - 1]);
}

void func_2(int* arr, unsigned arr_len)
{
    std::sort(arr, arr + arr_len);
}

void func_3(int* arr, unsigned arr_len)
{
    std::sort(arr, arr + arr_len);
    for (unsigned i = 0; i < (arr_len / 2); i++)
        std::swap(arr[i], arr[arr_len - i - 1]);
}

void(*switch_func(int* arr, unsigned arr_len))(int* arr, unsigned arr_len)
{
    int sum = 0;
    for (int i = 0; i < arr_len; i++) {
        sum += arr[i];
    }

    if (arr[0] == sum) {
        std::cout << "\n\nElement 1 = sum";
        return func_1;
    }
    else if (arr[0] < sum) {
        std::cout << "\n\nElement 1 > sum";
        return func_2;
    }
    else {
        std::cout << "\n\nElement 1 < sum";
        return func_3;
    }
}

