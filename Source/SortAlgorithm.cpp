#include <vector>
#include "../Include/SortAlgorithm.h"
using namespace std;
namespace Encore
{
    void SortAlgorithm::BubbleSort(vector<int>& array)
    {
        int size = array.size();
        for(int i = 0; i < size - 1; i++){ // 元素从数组一端交换到数组另一端最多需要交换 n-1 次
            for(int j = 0; j < size - i - 1; j++){ // 交换无序区相邻数组元素
                if(array[j] > array[j + 1]){
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }

    void SortAlgorithm::SelectSort(vector<int>& array)
    {
        int size = array.size();
        for(int i = 0; i < size; i++){ // i是无序区的起始index
            // 求无序区的最小值
            int minIndex = i;
            for(int j = i; j < size; j++){
                if (array[j] < array[minIndex]){
                    minIndex = j;
                }
            }
            swap(array[i], array[minIndex]);
        }
    }
}