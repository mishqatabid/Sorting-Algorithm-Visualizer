# Import necessary libraries
import matplotlib.pyplot as plt
import numpy as np

# Base class for sorting algorithms
class SortingAlgorithm:
    def __init__(self, arr):
        self.arr = arr.copy()

    def sort(self):
        raise NotImplementedError("Subclasses must implement the 'sort' method")

    def display(self):
        raise NotImplementedError("Subclasses must implement the 'display' method")

    def sort_and_visualize(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(1)

        self.sort()

        # Final visualization
        self.display()
        plt.show()

#BubbleSort
class BubbleSort(SortingAlgorithm):
    def sort(self):
        for i in range(len(self.arr)):
            for j in range(len(self.arr)-1):
                if self.arr[j] > self.arr[j+1]:
                    self.arr[j], self.arr[j+1] = self.arr[j+1], self.arr[j]
                    self.display()

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# SelectionSort
class SelectionSort(SortingAlgorithm):
    def sort(self):
        for i in range(len(self.arr)-1):
            min_index = i
            for j in range(i+1, len(self.arr)):
                if self.arr[j] < self.arr[min_index]:
                    min_index = j

            self.arr[i], self.arr[min_index] = self.arr[min_index], self.arr[i]
            self.display()

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# InsertionSort
class InsertionSort(SortingAlgorithm):
    def sort(self):
        for i in range(1, len(self.arr)):
            key = self.arr[i]
            j = i - 1
            while j >= 0 and key < self.arr[j]:
                self.arr[j + 1] = self.arr[j]
                j -= 1
            self.arr[j + 1] = key
            self.display()

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# MergeSort
class MergeSort(SortingAlgorithm):
    def sort(self):
        self._merge_sort(0, len(self.arr)-1)

    def _merge_sort(self, low, high):
        if low < high:
            middle = (low + high) // 2
            self._merge_sort(low, middle)
            self._merge_sort(middle+1, high)
            self._merge(low, middle, high)

    def _merge(self, low, middle, high):
        left = self.arr[low:middle+1]
        right = self.arr[middle+1:high+1]

        i = j = 0
        k = low

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                self.arr[k] = left[i]
                i += 1
            else:
                self.arr[k] = right[j]
                j += 1
            k += 1
            self.display()

        while i < len(left):
            self.arr[k] = left[i]
            i += 1
            k += 1
            self.display()

        while j < len(right):
            self.arr[k] = right[j]
            j += 1
            k += 1
            self.display()

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# QuickSort
class QuickSort(SortingAlgorithm):
    def sort(self):
        self._quick_sort(0, len(self.arr)-1)

    def _quick_sort(self, low, high):
        if low < high:
            pivot_index = self._partition(low, high)
            self._quick_sort(low, pivot_index - 1)
            self._quick_sort(pivot_index + 1, high)

    def _partition(self, low, high):
        pivot = self.arr[high]
        i = low - 1

        for j in range(low, high):
            if self.arr[j] <= pivot:
                i += 1
                self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
                self.display()

        self.arr[i + 1], self.arr[high] = self.arr[high], self.arr[i + 1]
        self.display()

        return i + 1

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# HeapSort
class HeapSort(SortingAlgorithm):
    def sort(self):
        for i in range(len(self.arr) // 2 - 1, -1, -1):
            self._heapify(len(self.arr), i)

        for i in range(len(self.arr) - 1, 0, -1):
            self.arr[i], self.arr[0] = self.arr[0], self.arr[i]
            self.display()
            self._heapify(i, 0)

    def _heapify(self, size, root):
        largest = root
        left = 2 * root + 1
        right = 2 * root + 2

        if left < size and self.arr[left] > self.arr[largest]:
            largest = left

        if right < size and self.arr[right] > self.arr[largest]:
            largest = right

        if largest != root:
            self.arr[root], self.arr[largest] = self.arr[largest], self.arr[root]
            self.display()
            self._heapify(size, largest)

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# CountingSort
class CountingSort(SortingAlgorithm):
    def sort(self):
        max_val = max(self.arr)
        min_val = min(self.arr)
        range_val = max_val - min_val + 1

        count = [0] * range_val
        output = [0] * len(self.arr)

        for num in self.arr:
            count[num - min_val] += 1

        for i in range(1, range_val):
            count[i] += count[i - 1]

        i = len(self.arr) - 1
        while i >= 0:
            output[count[self.arr[i] - min_val] - 1] = self.arr[i]
            count[self.arr[i] - min_val] -= 1
            i -= 1
            self.display()

        for i in range(len(self.arr)):
            self.arr[i] = output[i]

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# RadixSort
class RadixSort(SortingAlgorithm):
    def sort(self):
        max_val = max(self.arr)
        exp = 1
        while max_val // exp > 0:
            self._counting_sort(exp)
            exp *= 10

    def _counting_sort(self, exp):
        n = len(self.arr)
        output = [0] * n
        count = [0] * 10

        for i in range(n):
            index = self.arr[i] // exp
            count[index % 10] += 1

        for i in range(1, 10):
            count[i] += count[i - 1]

        i = n - 1
        while i >= 0:
            index = self.arr[i] // exp
            output[count[index % 10] - 1] = self.arr[i]
            count[index % 10] -= 1
            i -= 1
            self.display()

        for i in range(n):
            self.arr[i] = output[i]

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# BucketSort
class BucketSort(SortingAlgorithm):
    def sort(self):
        max_val = max(self.arr)
        num_buckets = 10
        buckets = [[] for _ in range(num_buckets)]

        for num in self.arr:
            index = int(num * num_buckets / (max_val + 1))
            buckets[index].append(num)

        for bucket in buckets:
            bucket.sort()
            self.display()

        self.arr = [num for bucket in buckets for num in bucket]

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# ShellSort
class ShellSort(SortingAlgorithm):
    def sort(self):
        n = len(self.arr)
        gap = n // 2

        while gap > 0:
            for i in range(gap, n):
                temp = self.arr[i]
                j = i
                while j >= gap and self.arr[j - gap] > temp:
                    self.arr[j] = self.arr[j - gap]
                    j -= gap
                self.arr[j] = temp
                self.display()
            gap //= 2

    def display(self):
        plt.bar(range(len(self.arr)), self.arr, color='purple')
        plt.title(type(self).__name__)
        plt.pause(0.1)
        plt.clf()

# Example usage
def main():
    # Example array
    arr = [42, 17, 29, 38, 11, 23, 8, 31, 19, 5, 14, 26, 35, 2, 47]

    # Create instances of sorting algorithms
    sorting_algorithms = [
        BubbleSort(arr),
        SelectionSort(arr),
        InsertionSort(arr),
        MergeSort(arr),
        QuickSort(arr),
        HeapSort(arr),
        CountingSort(arr),
        RadixSort(arr),
        BucketSort(arr),
        ShellSort(arr)
    ]

    # Visualize each sorting algorithm
    for algorithm in sorting_algorithms:
        algorithm.sort_and_visualize()

if __name__ == "__main__":
    main()
