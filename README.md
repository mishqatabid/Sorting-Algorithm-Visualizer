# Sorting Algorithm Visualizer

This project is a sorting algorithm visualizer that allows users to input an array and observe the sorting process visually. It consists of three main components:

## Files

### 1. Main GUI (main_gui.py)

- This file contains the main graphical user interface (GUI) of the sorting algorithm visualizer written in Python. Users input an array, and the GUI coordinates the interaction with the sorting algorithm implemented in C++ and the visualization component.

### 2. Sorting Algorithms (sorting_algorithms.cpp)

- The core sorting algorithms are implemented in C++ in a separate file. This file receives the input array, sorts it, and records the time taken for the sorting process. The sorted array is then returned to the GUI for display.

### 3. Visualization Module (visualization.py)

- A Python file responsible for visually representing the sorting process. It receives the input array and the steps taken during the sorting from the GUI, and it dynamically updates a bar chart to reflect the changes in the array over time.


## Integration Flow

1. User inputs an array in the GUI.
2. GUI sends the input array to both the C++ sorting algorithms and the visualization module.
3. Sorting algorithms in C++ sort the array and measure the time taken.
4. Sorted array and sorting time are returned to the GUI.
5. The visualization module visually represents the sorting process step by step.
