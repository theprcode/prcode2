'''
AIM:
Write a Python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble Sort and 
c) Display top five scores.

INPUT: Book Information
    1. Number of students in First Year
    2. First year percentage of students

OUTPUT:
    1. Display sorted list of students using Selection sort
    2. Display sorted list of students using Bubble sort
    3. Display top five scores

AUTHOR: Dr. Sunil D. Rathod
DATE: 01.08.2024
'''
# Implementation class
class FEStudent:
    def __init__(self):
        self.N = 0  # Number of students in FE
        self.studentList = []  # List of students in FE
        self.bSortList = []  # Sorted list for Bubble sort
        self.sSortList = []  # Sorted list for Selection sort

    def initialize(self):
        """Initialize the student lists."""
        self.N = 0
        self.studentList = []
        self.bSortList = []
        self.sSortList = []

    # 1. Read Student percentage
    def getStudentPercentage(self, nos):
        self.N = nos
        for i in range(self.N):
            percent = float(input(f"Enter percentage of student {i+1}: "))
            self.studentList.append(percent)
            self.bSortList.append(percent)
            self.sSortList.append(percent)

    # 2. Display Student percentage
    def displayStudentList(self, List):
        print("\nStudent percentages:")
        for percent in List:
            print(f"{percent:.2f}", end=" ")
        print()

    # 3. Sort list using Bubble Sort
    def bubbleSort(self):
        for i in range(self.N - 1):
            for j in range(self.N - i - 1):
                if self.bSortList[j] > self.bSortList[j + 1]:
                    self.bSortList[j], self.bSortList[j + 1] = self.bSortList[j + 1], self.bSortList[j]
            print(f"Pass {i + 1}: {self.bSortList}")

    # 4. Sort list using Selection Sort
    def selectionSort(self):
        for i in range(self.N - 1):
            min_idx = i
            for j in range(i + 1, self.N):
                if self.sSortList[j] < self.sSortList[min_idx]:
                    min_idx = j
            if min_idx != i:
                self.sSortList[i], self.sSortList[min_idx] = self.sSortList[min_idx], self.sSortList[i]
            print(f"Pass {i + 1}: {self.sSortList}")

    # 5. Display Top 5 Scores
    def topFive(self):
        self.sSortList.sort(reverse=True)  # Sorting in descending order for top scores
        top_scores = self.sSortList[:5]
        print("\nTop 5 Scores:")
        for score in top_scores:
            print(f"{score:.2f}", end=" ")
        print()


# Driver Code
std = FEStudent()
choice = 0

while choice != 6:
    print("\n************* SORTING ALGORITHMS ****************")
    print("1. Read Student Percentage Marks")
    print("2. Display Student Percentage Marks")
    print("3. Sort Students List using Bubble Sort")
    print("4. Sort Students List using Selection Sort")
    print("5. Display Top Five Scores")
    print("6. Exit Application")
    choice = int(input("Choose an operation: "))

    if choice == 1:
        std.initialize()
        n = int(input("Enter number of students in FE: "))
        std.getStudentPercentage(n)
    elif choice == 2:
        std.displayStudentList(std.studentList)
    elif choice == 3:
        std.bubbleSort()
        std.displayStudentList(std.bSortList)
    elif choice == 4:
        std.selectionSort()
        std.displayStudentList(std.sSortList)
    elif choice == 5:
        std.topFive()
    elif choice == 6:
        print("Goodbye!")
        break
    else:
        print("Invalid choice. Please try again.")
