import sys
import subprocess
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QPushButton, QTextEdit, QComboBox
from PyQt5.QtCore import QProcess
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt
from Visualization import SortingAlgorithm, BubbleSort, SelectionSort, InsertionSort, MergeSort, QuickSort, HeapSort, CountingSort, RadixSort, BucketSort, ShellSort

class SortingApp(QWidget):
    def __init__(self):
        super().__init__()

        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Sorting Algorithms')
        self.setGeometry(100, 100, 600, 400)

        font = QFont()
        font.setFamily("Cascadia Code")
        self.setFont(font)

        # Add a QLabel for the title
        title_label = QLabel("Sorting Algorithm Visualizer", self)
        title_label.setStyleSheet("font-size: 120px; color: #007BFF;")
        title_label.setAlignment(Qt.AlignCenter)
        
        title_font = QFont()
        title_font.setFamily("Cascading Code")                
        title_font.setBold(True)            
        title_font.setItalic(True)        

        title_label.setFont(title_font)

        self.input_textedit = QTextEdit(self)
        self.input_textedit.setPlaceholderText("Enter space-separated integers")

        input_block_width = 1900
        input_block_height = 100
        self.input_textedit.setMinimumSize(input_block_width, input_block_height)
        self.input_textedit.setMaximumSize(input_block_width, input_block_height)

        self.sorting_combobox = SortingComboBox(self)
        self.sorting_combobox.setStyleSheet("background-color: #2E2E2E; color: #FFFFFF; padding-left: 20px")

        self.run_button = QPushButton("Run Sorting", self)
        self.run_button.setStyleSheet("background-color: #007BFF; color: #FFFFFF")

        self.output_label = QLabel(self)
        self.output_label.setStyleSheet("color: #FFFFFF;")

         # Set a larger font size for the QTextEdit widget
        font = self.input_textedit.font()
        font.setPointSize(14)  
        self.input_textedit.setFont(font)

        # Set a larger font size for the SortingComboBox
        font_combobox = self.sorting_combobox.font()
        font_combobox.setPointSize(14)
        self.sorting_combobox.setFont(font_combobox)
        self.sorting_combobox.setFixedHeight(60)

        # Set a larger font size for the QPushButton
        font_button = self.run_button.font()
        font_button.setPointSize(20) 
        self.run_button.setFont(font_button)
        self.run_button.setFixedHeight(80)

        # Set a larger font size for the QLabel
        font_label = self.output_label.font()
        font_label.setPointSize(14)
        self.output_label.setFont(font_label)

        layout = QVBoxLayout()
        layout.addWidget(title_label)
        layout.addWidget(self.input_textedit)
        layout.addSpacing(40)
        layout.addWidget(self.sorting_combobox)
        layout.addSpacing(40)
        layout.addWidget(self.output_label)
        layout.addSpacing(40)
        layout.addWidget(self.run_button)
        

        self.run_button.clicked.connect(self.run_sorting)

        self.setStyleSheet("background-color: #1C1C1C; color: #FFFFFF;")

        self.setLayout(layout)



    def run_sorting(self):
        input_data = self.input_textedit.toPlainText().strip()
        sorting_algorithm = self.sorting_combobox.currentText()

        if not input_data:
            self.output_label.setText("Please enter valid input data.")
            return

        try:
            input_array = list(map(int, input_data.split()))
        except ValueError:
            self.output_label.setText("Invalid input data. Please enter integers.")
            return

        command = ["./your_c++code_executable_file.exe"]
        command.extend([str(x) for x in input_array])
        command.append(sorting_algorithm)

        try:
            process = QProcess(self)
            process.setProgram(command[0])
            process.setArguments(command[1:])
            process.start()

            process.waitForFinished(-1)

            if process.exitCode() == 0:
                sorted_output = process.readAllStandardOutput().data().decode('utf-8').strip()
                self.output_label.setText(f"Sorted Output: {sorted_output}")
            else:
                error_message = process.readAllStandardError().data().decode('utf-8').strip()
                self.output_label.setText(f"Error: {error_message}")

        except Exception as e:
            self.output_label.setText(f"Error: {str(e)}")


        algorithm_class = globals()[sorting_algorithm.replace(' ', '')]

        sorting_algorithm_instance = algorithm_class(input_array)

        try:
            sorting_algorithm_instance.sort_and_visualize()

            sorted_output = sorting_algorithm_instance.arr
            self.output_label.setText(f"Sorted Output: {sorted_output}")

        except Exception as e:
            self.output_label.setText(f"Error: {str(e)}")


class SortingComboBox(QComboBox):
    def __init__(self, parent):
        super().__init__(parent)

        algorithms = ["Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort",
                      "Quick Sort", "Heap Sort", "Counting Sort", "Radix Sort",
                      "Bucket Sort", "Shell Sort"]

        self.addItems(algorithms)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    sorting_app = SortingApp()
    sorting_app.show()
    sys.exit(app.exec_())