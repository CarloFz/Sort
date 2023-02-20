#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "../Include/SortAlgorithm.h"
using namespace Encore;

static void CreateData(int dataNum = 200)
{
    // 生成随机数种子
    srand((unsigned)time(NULL));

    std::ofstream ofs;
    ofs.open("../SortData.txt", std::ios::out);
    ofs << dataNum << std::endl;
    for(int i = 0; i < dataNum; i++)
    {
        ofs << rand() << std::endl;
    }
    ofs.close();
}

static int GetSortData(int* &array)
{
    std::ifstream ifs;
    ifs.open("../SortData.txt", std::ios::in);
    if(!ifs.good())
    {
        CreateData();
        ifs.open("../SortData.txt", std::ios::in);
    }

    int len;
    ifs >> len;
    array = new int[len];
    for(int i = 0; i < len; i++)
        ifs >> array[i];

    ifs.close();
    return len;
}

static bool ComfirmOrderdData(int array[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        if (array[i + 1] < array[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // CreateData();
    int* array;
    int len = GetSortData(array);

    // SortAlgorithm::BubbleSort(array);
    // SortAlgorithm::SelectSort(array);
    // SortAlgorithm::InsertionSort(array);
    // SortAlgorithm::HeapSort(array);
    SortAlgorithm::MergeSort(array, len);

    if (ComfirmOrderdData(array, len)){
        std::cout << "Finish" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
        for(int i = 0; i < len; i++)
        {
            std::cout << array[i] << std::endl;
        }
    }

    delete[] array;
}
