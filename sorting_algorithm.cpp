#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <thread>

using namespace std;
using namespace chrono;

double timing;

class BubbleSort{
	private:
		int *arr,size;
	public:
		BubbleSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
		int swap(int i){
			int temp;
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
		void sort(){
			for(int i=0; i<size; ++i){
				for(int j=0; j<size-1; ++j){
					if(arr[j]>arr[j+1]){
						swap(j);
					}
				}
			}
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~BubbleSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
};

class SelectionSort{
	private:
		int *arr,size;
	
	public:
		SelectionSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
		void selection(){
			for (int i=0; i<size-1; ++i){
				int min = i;
				for(int j=i+1; j<size; ++j){
					if(arr[j]< arr[min]){
						min=j;
					}
				}
				
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~SelectionSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        selection();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }	
};

class InsertionSort{
	private:
		int *arr,size;
	public:
		InsertionSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
		void insertion(){
			for(int i=0; i<size; ++i){
				int num = arr[i];
				int j;	
				for(j = i-1; j >= 0 && arr[j] > num;j--) {
	            	arr[j + 1] = arr[j];
	        	}
	        	arr[j + 1] = num;
			}
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~InsertionSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        insertion();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
};

class MergeSort {
	private:
		int *arr, size; 
	    void merge(int low, int middle, int high){
			int n1 = middle - low + 1;
		    int n2 = high - middle;
		
		    int L[n1], R[n2];
		
		    for (int i = 0; i < n1; i++)
		        L[i] = arr[low + i];
		    for (int i = 0; i < n2; i++)
		        R[i] = arr[middle + 1 + i];
		
		    int i = 0, j = 0, k = low;
		    while (i < n1 && j < n2) {
		        if (L[i] <= R[j]) {
		            arr[k] = L[i];
		            i++;
		        } else {
		            arr[k] = R[j];
		            j++;
		        }
		        k++;
		    }
		
		    while (i < n1) {
		        arr[k] = L[i];
		        i++;
		        k++;
		    }
		
		    while (j < n2) {
		        arr[k] = R[j];
		        j++;
		        k++;
		    }
		}
	public:
		MergeSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
	    void sort(int low, int high){
		    if (low < high){
		        int middle = low + (high - low) / 2;
		        sort(low, middle);
		        sort(middle + 1, high);
		        merge(low, middle, high);
		    }
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~MergeSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort(0, size - 1);
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
};

class QuickSort {
	private:
		int *arr, size;
		int partition(int low, int high){
		    int pivot = arr[high];
		    int i = (low - 1);
		
		    for (int j = low; j <= high - 1; j++) {
		        if (arr[j] < pivot) {
		            i++;
		            swap(arr[i], arr[j]);
		        }
		    }
		
		    swap(arr[i + 1], arr[high]);
		    return (i + 1);
		}
	public:
		QuickSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
	    void sort(int low, int high){
		    if (low < high) {
		        int pivot = partition(low, high);
		        sort(low, pivot - 1);
		        sort(pivot + 1, high);
		    }
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~QuickSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort(0, size - 1);
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
	
};

class HeapSort {
	private:
		int *arr, size;
	    void heapify(int size, int root){
		    int largest = root;
		    int left = 2 * root + 1;
		    int right = 2 * root + 2;
		
		    if (left < size && arr[left] > arr[largest]) {
		        largest = left;
		    }
		
		    if (right < size && arr[right] > arr[largest]) {
		        largest = right;
		    }
		
		    if (largest != root) {
		        swap(arr[root], arr[largest]);
		        heapify(size, largest);
		    }
		}
	public:
		HeapSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
		void sort(){
		    for (int i = size / 2 - 1; i >= 0; i--) {
		        heapify(size, i);
		    }
		
		    for (int i = size - 1; i > 0; i--) {
		        swap(arr[0], arr[i]);
		        heapify(i, 0);
		    }
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~HeapSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
};

class CountingSort {
	private:
		int *arr, size;
	public:
		CountingSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
	    void sort(){
		    int max = *max_element(arr, arr + size);
		    int min = *min_element(arr, arr + size);
		    int range = max - min + 1;
		
		    int* count = new int[range]();
		    int* output = new int[size];
		
		    for (int i = 0; i < size; i++) {
		        count[arr[i] - min]++;
		    }
		
		    for (int i = 1; i < range; i++) {
		        count[i] += count[i - 1];
		    }
		
		    for (int i = size - 1; i >= 0; i--) {
		        output[count[arr[i] - min] - 1] = arr[i];
		        count[arr[i] - min]--;
		    }
		
		    for (int i = 0; i < size; i++) {
		        arr[i] = output[i];
		    }
		
		    delete[] count;
		    delete[] output;
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~CountingSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
};

class RadixSort {
	private:
		int *arr, size;
	public:
		RadixSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
		void sort(){
		    int max = getMax();
		
		    for (int exp = 1; max / exp > 0; exp *= 10) {
		        countingSort(exp);
		    }
		}
	    int getMax(){
		    int max = arr[0];
		    for (int i = 1; i < size; i++) {
		        if (arr[i] > max) {
		            max = arr[i];
		        }
		    }
		    return max;
		}
	    void countingSort(int exp){
		    int output[size];
		    int count[10] = {0};
		
		    for (int i = 0; i < size; i++) {
		        count[(arr[i] / exp) % 10]++;
		    }
		
		    for (int i = 1; i < 10; i++) {
		        count[i] += count[i - 1];
		    }
		
		    for (int i = size - 1; i >= 0; i--) {
		        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		        count[(arr[i] / exp) % 10]--;
		    }
		
		    for (int i = 0; i < size; i++) {
		        arr[i] = output[i];
		    }
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~RadixSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }
};

class BucketSort {
	private:
		int *arr, size;
	public:
		BucketSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
	    void sort(){
		    const int maxVal = *max_element(arr, arr + size) + 1;
		    const int numBuckets = 10;
		    int buckets[numBuckets][size];
		
		    for (int i = 0; i < numBuckets; i++) {
		        for (int j = 0; j < size; j++) {
		            buckets[i][j] = -1;
		        }
		    }
		
		    for (int i = 0; i < size; i++) {
		        int index = arr[i] * numBuckets / maxVal;
		        for (int j = 0; j < size; j++) {
		            if (buckets[index][j] == -1) {
		                buckets[index][j] = arr[i];
		                break;
		            }
		        }
		    }
		
		    for (int i = 0; i < numBuckets; i++) {
		        // Sort each bucket (e.g., using insertion sort)
		        int currentSize = 0;
		        for (int j = 0; j < size; j++) {
		            if (buckets[i][j] != -1) {
		                currentSize++;
		            }
		        }
		
		        // Perform insertion sort on the current bucket
		        for (int j = 1; j < currentSize; j++) {
		            int key = buckets[i][j];
		            int k = j - 1;
		
		            while (k >= 0 && buckets[i][k] > key) {
		                buckets[i][k + 1] = buckets[i][k];
		                k--;
		            }
		
		            buckets[i][k + 1] = key;
		        }
		    }
		
		    int index = 0;
		    for (int i = 0; i < numBuckets; i++) {
		        for (int j = 0; j < size; j++) {
		            if (buckets[i][j] != -1) {
		                arr[index++] = buckets[i][j];
		            }
		        }
		    }
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~BucketSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
	    }

};
 
class ShellSort {
	private:
		int *arr, size;
	public:
		ShellSort(int *array, int arr_size){
			arr = new int[arr_size];
			size = arr_size;
			
			for (int i = 0; i < size; ++i) {
            arr[i] = array[i]; // Copy elements from the provided array
        	}
		}
	    void sort(){
		    for (int gap = size / 2; gap > 0; gap /= 2) {
		        for (int i = gap; i < size; i++) {
		            int temp = arr[i];
		            int j;
		            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
		                arr[j] = arr[j - gap];
		            }
		            arr[j] = temp;
		        }
		    }
		}
		void display(){
			for(int i=0; i<size; ++i){
			cout << arr[i] << "   ";
			}
		}
		~ShellSort(){
			delete[]arr;
		}
		double sortAndGetTime(){
	        auto start = steady_clock::now();
	        sort();
	        auto end = steady_clock::now();
	
	        duration<double> elapsed_seconds = end - start;
	        return elapsed_seconds.count();
    	}
};

void sortAlgo(int *array, int size, string algo){
	
	int arr_size = size;
    int *arr = new int[arr_size];
    
    for (int i = 0; i < arr_size; ++i) {
        arr[i] = array[i]; // Copy elements from the provided array
    }
    string algorithm = algo; 

	if(algorithm == "Bubble Sort"){
		// Bubble Sort
	    BubbleSort bubbleSort(arr, arr_size);
	    timing = bubbleSort.sortAndGetTime();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Selection Sort"){
	    // Selection Sort
	    SelectionSort selectionSort(arr, arr_size);
	    timing = selectionSort.sortAndGetTime();
	    selectionSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Insertion Sort"){
	    // Insertion Sort
		InsertionSort insertionSort(arr, arr_size);
	    timing = insertionSort.sortAndGetTime();
	    insertionSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Merge Sort"){
	    // Merge Sort
	    MergeSort mergeSort(arr, arr_size);
	    timing = mergeSort.sortAndGetTime();
	    mergeSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Quick Sort"){
	    // Quick Sort
		QuickSort quickSort(arr, arr_size);
	    timing = quickSort.sortAndGetTime();
	    quickSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Heap Sort"){
	    // Heap Sort
	    HeapSort heapSort(arr, arr_size);
	    timing = heapSort.sortAndGetTime();
	    heapSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Counting Sort"){
	    // Counting Sort
		CountingSort countingSort(arr, arr_size);
	    timing = countingSort.sortAndGetTime();
	    countingSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Radix Sort"){
	    // Radix Sort
		RadixSort radixSort(arr, arr_size);
	    timing = radixSort.sortAndGetTime();
	    radixSort.display();
	    cout << endl;;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Bucket Sort"){
		// Bucket Sort
	    BucketSort bucketSort(arr, arr_size);
	    timing = bucketSort.sortAndGetTime();
	    bucketSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else if(algorithm == "Shell Sort"){
	    // Shell Sort
	    ShellSort shellSort(arr, arr_size);
	    timing = shellSort.sortAndGetTime();
	    shellSort.display();
	    cout << endl;
	    cout << fixed << setprecision(8) << "\nTiming: " << timing <<endl;
	}
	else{
		cout << "INVALID SORTING ALGORITHM" <<endl;
	}
}
 
int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <element1> <element2> ... <sorting_algorithm>" << std::endl;
        return 1;
    }

    // Parse input data
    int array_size = argc - 2;
    int *arr = new int[array_size];
    for (int i = 0; i < array_size; ++i) {
        arr[i] = std::atoi(argv[i + 1]);
    }

    // Determine the sorting algorithm
    std::string sorting_algorithm = argv[array_size + 1];
    
    //cout << sorting_algorithm;
    sortAlgo(arr, array_size, sorting_algorithm);
    
    delete[] arr;
    return 0;
}

