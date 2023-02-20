#include "../Include/SortAlgorithm.h"
namespace Encore
{
    void SortAlgorithm::BubbleSort(int array[], int len)
    {
        for(int i = 0; i < len - 1; i++){ // 元素从数组一端交换到数组另一端最多需要交换 n-1 次
            for(int j = 0; j < len - i - 1; j++){ // 交换无序区相邻数组元素
                if(array[j] > array[j + 1]){
                    Swap(array[j], array[j + 1]);
                }
            }
        }
    }

    void SortAlgorithm::SelectSort(int array[], int len)
    {
        for(int i = 0; i < len; i++){ // i是无序区的起始index
            // 求无序区的最小值
            int minIndex = i;
            for(int j = i; j < len; j++){
                if (array[j] < array[minIndex]){
                    minIndex = j;
                }
            }
            Swap(array[i], array[minIndex]);
        }
    }

    void SortAlgorithm::InsertionSort(int array[], int len)
    {
        for(int i = 1; i < len; i++){ // i是无序区的起始index 0～(i-1)为有序区 i~(size-1)为无序区
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

    void SortAlgorithm::HeapSort(int array[], int len)
    {
        // 建堆
        HeapBuild(array, len);
        for(int i = len - 1; i >= 0; i--)
        {
            Swap(array[i], array[0]);
            Heapity(array, i, 0);
        }
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

    void SortAlgorithm::MergeSort_Recursive(int* array, int len)
    {
        int tempArray[len];
        DoMergeSort_Recursive(array, tempArray, len);
    }

    void SortAlgorithm::DoMergeSort_Recursive(int* array, int* tempArray, int len)
    {
        if (len <= 1) return;
        int mid = len / 2;
        DoMergeSort_Recursive(array, tempArray, mid);
        DoMergeSort_Recursive(array + mid, tempArray, len - mid);
        int tempKey = 0;
        int start1 = 0, end1 = mid;
        int start2 = mid, end2 = len;
        while(start1 < end1 && start2 < end2)
            tempArray[tempKey++] = array[start1] < array[start2] ? array[start1++] : array[start2++];
        while(start1 < end1) tempArray[tempKey++] = array[start1++];
        while(start2 < end2) tempArray[tempKey++] = array[start2++];
        for(int i = 0; i < len; i++)
        {
            array[i] = tempArray[i];
        }
    }

    void SortAlgorithm::QuickSort(int array[], int len)
    {
        DoQuickSort(array, 0, len - 1);
    }

    void SortAlgorithm::DoQuickSort(int array[], int left, int right)
    {
        if (left >= right) return;
        int keyPos = PartSort(array, left, right);
        DoQuickSort(array, left, keyPos - 1);
        DoQuickSort(array, keyPos + 1, right);
    }

    int SortAlgorithm::PartSort(int array[], int left, int right)
    {
        // return PartSort_Hoare(array, left, right);
        // return PartSort_DigHole(array, left, right);
        return PartSort_FastSlowPointer(array, left, right);
    }

    int SortAlgorithm::PartSort_Hoare(int array[], int left, int right)
    {
        int midIndex = GetMidIndex(array, left, right);
        Swap(array[midIndex], array[left]);
        int key = left; // 取最左边的值为key
        while(left < right) // 当左右没有相遇
        {
            // 由于取了左侧值为key所以right先动 反之亦然
            while(left < right && array[right] >= array[key]) right--; // 找到比key小的值 退出循环
            while(left < right && array[left] <= array[key]) left++; // 找到比key大的值 退出循环
            Swap(array[left], array[right]); // 交换左右值
        }
        Swap(array[key], array[left]); // 交换key和相遇处的值
        return left;
    }

    int SortAlgorithm::PartSort_DigHole(int array[], int left, int right)
    {
        int midIndex = GetMidIndex(array, left, right);
        Swap(array[midIndex], array[left]);
        int key = array[left]; // 取左边值做key 保存key值做坑
        while(left < right)
        {
            while(left < right && array[right] >= key) right--;
            array[left] = array[right]; // 赋值前左边为坑 赋值后右边为坑
            while(left < right && array[left] <= key) left++;
            array[right] = array[left]; // 赋值前右边为坑 赋值后左边为坑
        }
        // 相遇处为坑
        array[left] = key;
        return left;
    }

    int SortAlgorithm::PartSort_FastSlowPointer(int array[], int left, int right)
    {
        int midIndex = GetMidIndex(array, left, right);
        Swap(array[midIndex], array[left]);
        int key = left; // 取左边值为key
        int fast = key + 1, slow = key + 1;
        while(fast <= right)
        {
            if (array[fast] < array[key])
            {
                Swap(array[slow++], array[fast]);
            }
            fast++;
        }
        Swap(array[key], array[slow - 1]); // slow指在期望位置的下一位 所以此处需要回退一位
        return slow - 1;
    }

    // 三数取中 从数组的前、中、后三个位置中取中间大小的值作为key 能够让快速排序不管在数组否有序的情况下都能达到最佳效率
    int SortAlgorithm::GetMidIndex(int array[], int left, int right)
    {
        int mid = (right + left) / 2;
        if ((array[left] > array[right] && array[right] > array[mid]) ||
            (array[mid] > array[right] && array[right] > array[left]))
        {
            return right;
        }
        else if((array[mid] > array[left] && array[left] > array[right]) ||
                (array[right] > array[left] && array[left] > array[mid]))
        {
            return left;
        }
        else
        {
            return mid;
        }
    }

    // 从index开始自上而下堆化
    void SortAlgorithm::Heapity(int array[], int heapSize, int index)
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

            Swap(array[index], array[maxPos]);
            index = maxPos;
        }
    }

    void SortAlgorithm::HeapBuild(int array[], int len)
    {
        for(int i = len / 2; i >= 0; i--) // 从最后一个非叶子结点开始倒序自上而下堆化
        {
            Heapity(array, len, i);
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

    void SortAlgorithm::Swap(int &value1, int &value2)
    {
        int temp = value1;
        value1 = value2;
        value2 = temp;
    }
}