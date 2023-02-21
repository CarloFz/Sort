namespace Encore
{
    class SortAlgorithm
    {
    public:
        static void BubbleSort(int array[], int len);
        static void SelectSort(int array[], int len);
        static void InsertionSort(int array[], int len);
        static void HeapSort(int array[], int len);
        static void MergeSort(int array[], int len);
        static void MergeSort_Recursive(int* array, int len);
        static void QuickSort(int array[], int len);
        static void QuickSort_NonRecursive(int array[], int len);
        static void ShellSort(int array[], int len);
    private:
        static int Min(int value1, int value2);
        static void Swap(int* &value1, int* &value2);
        static void Swap(int &value1, int &value2);
        static void Heapity(int array[], int heapSize, int index);
        static void HeapBuild(int array[], int len);
        static void DoMergeSort_Recursive(int* array, int* tempArray, int len);
        static void DoQuickSort(int array[], int left, int right);
        static int PartSort(int array[], int left, int right);
        static int PartSort_Hoare(int array[], int left, int right);
        static int PartSort_DigHole(int array[], int left, int right);
        static int PartSort_FastSlowPointer(int array[], int left, int right);
        static int GetMidIndex(int array[], int left, int right);
    };
}
