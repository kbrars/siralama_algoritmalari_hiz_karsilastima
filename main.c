#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ADRESLER ÜZERİNDEN DEĞER DEĞİŞTİRME
void swap (int *p1, int *p2)
{
    int temp;
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//DİZYİ TERS SIRALI HALE ÇEVİRME
void reverse_array(int arr[], int size)
{
    int counter;
    int counter2;
    
    counter = 0;
    while (counter < size -1)
    {
        counter2 = 0;
        while (counter2 < size - counter -1)
        {
           if (arr[counter2] < arr[counter2+1])
                swap(&arr[counter2], &arr[counter2 + 1]);
            counter2++;
        }
        counter++;
    }
}

void bubbleSort (int arr[], int size)
{
    int counter;
    int counter2;
    
    counter = 0;
    while (counter < size -1)
    {
        counter2 = 0;
        while (counter2 < size - counter -1)
        {
           if (arr[counter2] > arr[counter2+1])
                swap(&arr[counter2], &arr[counter2 + 1]);
            counter2++;
        }
        counter++;
    }
}

void selectionSort(int arr[], int size)
{
    int counter, counter2, temp, minIndex;
    
    counter = 0;
    while (counter < size -1)
    {
        minIndex = counter;
        temp = arr[counter];
        counter2 = 1 + counter;
        while (counter2 < size)
        {
            if (temp > arr[counter2])
                {
                    temp = arr [counter2];
                    minIndex = counter2;
                  
                }
            counter2++;
        }
        swap(&arr[counter], &arr[minIndex]);
        counter++;
    }
} 

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int beginIndex, int endIndex)
{
    if (beginIndex >= endIndex)
        return;
    
    int pivot = arr[endIndex];
    int j = beginIndex - 1;
    int i = beginIndex;
    while (i < endIndex)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
        i++;
    }
    j++;
    swap(&arr[endIndex], &arr[j]);
    quickSort(arr, beginIndex, j-1);
    quickSort(arr, j+1, endIndex);
}

void heapify(int arr[], int size, int i) 
 {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && arr[left] > arr[largest])
      largest = left;
  
    if (right < size && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, size, largest);
    }
  }
  
void heapSort(int arr[], int size) 
 {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
  
    for (int i = size - 1; i >= 0; i--) 
    {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
 }
  
void shellSort(int array[], int n) 
{

  for (int interval = n / 2; interval > 0; interval /= 2) 
  {
    for (int i = interval; i < n; i += 1) 
    {
        int temp = array[i];
        int j;
        for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
                array[j] = array[j - interval];
        array[j] = temp;
    }
  }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int finish)
{
    if (start < finish)
    {
        int m = start + (finish - start)/2;
        mergeSort(arr, start, m);
        mergeSort(arr, m+1, finish);
        merge(arr, start, m, finish);
    }
}

//DİNAMİK OLARAK DİZİ OLUŞTURMA
int *array_create (int size)
{
    int *p;
    p = (int*)malloc(sizeof(int) * size);
    return p;
}

//RANDOM DİZİ ÜZERİNDEN ALGORİTMALARIN ÇALIŞMA SÜRELERİNİ BULMA
void random_function_timing(int *p,int size)
{
    clock_t start, end;
    double exe1;
    srand(time(NULL));
    
    //bubbleSort 
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    start = clock();
    bubbleSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Bubble Sort : %lf\n ", exe1);
    
    // selectionSort
     for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    start = clock();
    selectionSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Selection Sort: %lf\n",exe1);
    
    
    //İnsertionSort
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    start = clock();
    insertionSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Insertion Sort: %lf\n",exe1);   
    
    //quickSort
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    start = clock();
    quickSort(p, 0, size-1);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Quick Sort: %lf\n",exe1); 

    //heapSort
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    start = clock();
    heapSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Heap Sort: %lf\n",exe1);  
    
    //shellSort
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    start = clock();
    shellSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Shell Sort: %lf\n",exe1);  
    
    //mergeSort
     for (int i = 0; i < size; i++)
        p[i] = rand() ;
    start = clock();
    mergeSort(p, 0, size-1);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Merge Sort: %lf\n\n",exe1);

    free(p);
}

//SIRALANMIŞ DİZİ ÜZERİNDEN ALGORİTMALARIN ÇALIŞMA SÜRELERİNİ BULMA
void inline_function_timing(int *p,int size)
{
    clock_t start, end;
    double exe1;
    srand(time(NULL));
    
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    insertionSort(p, size);
    
    //bubbleSort 
    start = clock();
    bubbleSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Bubble Sort : %lf\n ", exe1);
    
    // selectionSort
    start = clock();
    selectionSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Selection Sort: %lf\n",exe1);
    
    //İnsertionSort
    start = clock();
    insertionSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Insertion Sort: %lf\n",exe1);   
    
    //quickSort
    start = clock();
    quickSort(p, 0, size-1);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Quick Sort: %lf\n",exe1); 

    //heapSort
    start = clock();
    heapSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Heap Sort: %lf\n",exe1);  
    
    //shellSort
    start = clock();
    shellSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Shell Sort: %lf\n",exe1);  
    
    //mergeSort
    start = clock();
    mergeSort(p, 0, size-1);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Merge Sort: %lf\n\n",exe1);

    free(p);
}
 
//TERS SIRALANMIŞ DİZİ ÜZERİNDEN ALGORİTMALARIN ÇALIŞMA SÜRELERİNİ BUL
 void reverse_function_timing(int *p,int size)
{
    clock_t start, end;
    double exe1;
    srand(time(NULL));
    
    for (int i = 0; i < size; i++)
        p[i] = rand() % size;
    
    //bubbleSort 
    reverse_array(p,size);
    start = clock();
    bubbleSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Bubble Sort : %lf\n ", exe1);
    
    // selectionSort
    reverse_array(p,size);
    start = clock();
    selectionSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Selection Sort: %lf\n",exe1);
    
    //İnsertionSort
    reverse_array(p,size);
    start = clock();
    insertionSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Insertion Sort: %lf\n",exe1);   
    
    //quickSort
    reverse_array(p,size);
    start = clock();
    quickSort(p, 0, size-1);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Quick Sort: %lf\n",exe1); 

    //heapSort
    reverse_array(p,size);
    start = clock();
    heapSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Heap Sort: %lf\n",exe1);  
    
    //shellSort
    reverse_array(p, size);
    start = clock();
    shellSort(p, size);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Shell Sort: %lf\n",exe1);  
    
    //mergeSort
    reverse_array(p, size);
    start = clock();
    mergeSort(p, 0, size-1);
    end = clock();
    exe1 = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Merge Sort: %lf\n\n",exe1);

    free(p);
}
 
int main()
{
    int *a;
    printf ("-----1000 elemanli random----- \n");
    a = array_create(1000);
    random_function_timing(a, 1000);
  
    printf ("-----10000 elemanli random----- \n");
    a = array_create(10000);
    random_function_timing(a, 10000);
   
    printf ("-----100000 elemanli random----- \n");
    a = array_create(100000);
    random_function_timing(a, 100000);

    printf ("-----1000000 elemanli random----- \n");
    a = array_create(1000000);
    random_function_timing(a, 1000000);
    
    printf ("-----50000 elemanli random----- \n");
    a = array_create(50000);
    random_function_timing(a, 50000);
  
    printf ("-----500000 elemanli random----- \n");
    a = array_create(500000);
    random_function_timing(a, 500000);
    
    
    //Sıralanmis dizi üzerinde islemler
    printf ("-----1000 elemanli siralı----- \n");
    a = array_create(1000);
    inline_function_timing(a, 1000);
    
    printf ("-----10000 elemanli siralı----- \n");
    a = array_create(10000);
    inline_function_timing(a, 10000);
   
    printf ("-----100000 elemanli siralı----- \n");
    a = array_create(100000);
    inline_function_timing(a, 100000);
    
    printf ("-----1000000 elemanli siralı----- \n");
    a = array_create(1000000);
    inline_function_timing(a, 1000000);
    
    printf ("-----50000 elemanli siralı----- \n");
    a = array_create(50000);
    inline_function_timing(a, 50000);
  
    printf ("-----500000 elemanli siralı----- \n");
    a = array_create(500000);
    inline_function_timing(a, 500000);
    
    //Ters Sıralanmis dizi üzerinde islemler
    printf ("-----1000 elemanli ters siralı----- \n");
    a = array_create(1000);
    reverse_function_timing(a, 1000);
    
    printf ("-----10000 elemanli ters siralı----- \n");
    a = array_create(10000);
    reverse_function_timing(a, 10000);
   
    printf ("-----100000 elemanli ters siralı----- \n");
    a = array_create(100000);
    reverse_function_timing(a, 100000);

    printf ("-----1000000 elemanli ters siralı----- \n");
    a = array_create(1000000);
    reverse_function_timing(a, 1000000);
    
    printf ("-----50000 elemanli ters siralı----- \n");
    a = array_create(50000);
    reverse_function_timing(a, 50000);
  
    printf ("-----500000 elemanli ters siralı----- \n");
    a = array_create(500000);
    reverse_function_timing(a, 500000);
    return 0;
}

  
