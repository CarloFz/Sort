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

    // 从index开始自上而下堆化
    void SortAlgorithm::Heapity(std::vector<int>& array, int heapSize, int index)
    {
        while(index < heapSize)
        {
            // get maxPos
            int maxPos = index;
            if(index * 2 < heapSize && array[index * 2] > array[index]){
                maxPos = index * 2;
            }
            if(index * 2 + 1 < heapSize && array[index * 2 + 1] > array[maxPos]){
                maxPos = index * 2 + 1;
            }
            if (maxPos == index){
                break;
            }

            std::swap(array[index], array[maxPos]);
            index = maxPos;
        }
    }

    void SortAlgorithm::HeapBuild(std::vector<int>& array)
    {
        int size = array.size();
        for(int i = size / 2; i >= 0; i--) // 从最后一个非叶子结点开始倒序自上而下堆化
        {
            Heapity(array, size, i);
        }
    }

    void SortAlgorithm::HeapSort(std::vector<int>& array)
    {
        int size = array.size();
        // 建堆
        HeapBuild(array);
        for(int i = size - 1; i >= 0; i--)
        {
            std::swap(array[i], array[0]);
            Heapity(array, i, 0);
        }
    }

    int SortAlgorithm::Min(int value1, int value2)
    {
        return value1 > value2 ? value2 : value1;
    }

    void SortAlgorithm::Swap(int* &value1, int* &value2)
    {
        int* temp = value1;
        value1 = value2;
        value2 = temp;
    }

    void SortAlgorithm::MergeSort(int array[], int len)
    {
        int* a = array;
        int* b = new int[len];
        for(int seg = 1; seg < len; seg += seg) // 段长度
        {
            for(int start = 0; start < len; start += seg + seg) // 遍历每两个段
            {
                //段：start...end-1
                int start1 = start, end1 = Min(start1 + seg, len);
                int start2 = end1, end2 = Min(start2 + seg, len);
                int bKey = start;
                while(start1 < end1 && start2 < end2) // 两段归并
                    b[bKey++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
                // 剩余的单段归并
                while(start1 < end1)
                    b[bKey++] = a[start1++];
                while(start2 < end2)
                    b[bKey++] = a[start2++];
            }
            // 交换ab数组
            Swap(a, b);
        }

        if (array != a)
        {
            for(int i = 0; i < len; i++)
            {
                array[i] = a[i];
            }
            b = a;
        }

        delete[] b;
    }
}