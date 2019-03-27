/*
插入排序O(n²)
 */
void InsertSort(vector<int> &arr){
    for(int i = 1;i < arr.size();++i){
        for(int j = i;j > 0;--j){
            if(arr[j] < arr[j - 1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }
}   
 
/*
冒泡排序O(n²)
 */
void BubbleSort1(vector<int> &arr){
    for (int i = 0; i < arr.size() - 1; i++) {
        bool flag=true;
        for (int j = 0; j < arr.size() - i - 1; j++) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=false;
            }
        }
        if(flag) return;
    }

 
/*
快速排序
 */
void quicksort(vector<int> &arr, int left, int right)
{
    if(left >= right) return ;
    int i = left;
    int j = right;
    int key = arr[left]; 
    while(i < j)                            
    {
        while(i < j && key <= a[j])
        {
            j--;
        }
        arr[i] = arr[j];     
        while(i < j && key >= a[i])
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = key;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);              
}
 
 
/*
归并排序
 */
 
void Merge(int& arr[], int reg[], int start, int end) {
    if (start >= end) return;
    int mid = (end + start) >> 1;
    //分成两部分
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    //然后合并
    Merge(arr, reg, start1, end1);
    Merge(arr, reg, start2, end2);
 
    int k = start;

    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

    while (start1 <= end1)
        reg[k++] = arr[start1++];

    while (start2 <= end2)
        reg[k++] = arr[start2++];

    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
 
void MergeSort(int& arr[], const int len) {

    int reg[len];
    Merge(arr, reg, 0, len - 1);
}
 
 
//折半插入排序  O(nlog2(n)) 稳定
int low,high,middle;
void BinaryInsertSort(int a[], int len){
   for(int i=0;i<len;i++){
      int temp=a[i];
      low=0;high=i-1;
      while(low<=high){
         middle=(low+high)/2;
         if(temp<a[middle]){
            high=middle-1;
         }
         else{
            low=middle+1;
         }
      }
      for(int k=i;k>low;k--){
         a[k]=a[k-1];
      }
      a[low]=temp;
   }
}
 
  
//希尔排序  速度很难定量 但是效率挺高的 不稳定的算法
void Shellsort(int a[], int len){
   int gap=len-1;  
   bool flag=0;
   while(gap>=1){
      if(gap==1) flag=1;
      for(int i=0;i<len;i++){
         if(i+gap<len){
            if(a[i]>a[i+gap]){
               int temp=a[i];
               a[i]=a[i+gap];
               a[i+gap]=temp;
            }          
         }
         else break;
      }
      gap=gap/3+1; 
      if(flag) break;
   }
}
 
 
//堆排序
void HeapSort(int arr[],int len){
    int i;
    for(i = len/2 - 1; i >= 0; --i){
        Heapify(arr,i,len);
    }
    for(i = len - 1;i > 0;--i){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        Heapify(arr,0,i);
    }
}

 
void Heapify(int arr[], int first, int end){
    int father = first;
    int son = father * 2 + 1;
    while(son < end){
        if(son + 1 < end && arr[son] < arr[son+1]) ++son;
        if(arr[father] > arr[son]) break;
        else {

            int temp = arr[father];
            arr[father] = arr[son];
            arr[son] = temp;
            father = son;
            son = 2 * father + 1;
        }
    }
}