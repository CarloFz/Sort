#include <vector>
#include "../Include/SortAlgorithm.h"
// using namespace std;
namespace Encore
{
    void SortAlgorithm::BubbleSort(std::vector<int>& array)
    {
        int size = array.size();
        for(int i = 0; i < size - 1; i++){ // 元素从数组一端交换到数组另一端最多需要交换 n-1 次
            for(int j = 0; j < size - i - 1; j++){ // 交换无序区相邻数组元素
                if(array[j] > array[j + 1]){
                    std::swap(array[j], array[j + 1]);
                }
            }
        }
    }

    void SortAlgorithm::SelectSort(std::vector<int>& array)
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
            std::swap(array[i], array[minIndex]);
        }
    }

    void SortAlgorithm::InsertionSort(std::vector<int>& array)
    {
        int size = array.size();
        for(int i = 1; i < size; i++){ // i是无序区的起始index 0～(i-1)为有序区 i~(size-1)为无序区
            int insertionValue = array[i];
            for(int j = i - 1; j >= 0; j--){
                if(array[j] > insertionValue){ // 将大于value的元素后移
                    array[j + 1] = array[j];
                }else{ // 将value插入到合适的位置
                    array[j] = insertionValue;
                    break;
                }
            }
        }
    }
}