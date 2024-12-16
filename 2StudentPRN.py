'''
AIM:
Write a Python program 
1. To store students PRNs with date and month (year) of birth. 
List_A and List_B be the two list for two SE Computer divisions. 
2. Lists are sorted on date and month.
3. Merge these two lists into third list “List_SE_Comp_DOB”
resulting in sorted information about Date of Birth of SE Computer students

INPUT: 
    1. Student PRN, Day & Month (year) for SE-A & SE-B

OUTPUT:
   2. Sorted List of SE_Comp

AUTHOR: Dr. Sunil D. Rathod
DATE: 23.07.2024
'''
import datetime

# ADT of Student
class Student:
    def __init__(self):
        self.PRN = None
        self.dob = None  # Initialize date of birth as None


# Implementation Class
class SEComputer:
    def __init__(self):
        self.n1 = 0  # No. of students in SE-A
        self.n2 = 0  # No. of students in SE-B
        self.n3 = 0  # No. of students in SE Computer
        self.SEAList = []  # SE-A division list
        self.SEBList = []  # SE-B division list
        self.SECOMPList = []  # Merged SE-A & SE-B division list

    # Read Student Information for SE-A
    def readStudentdataSEA(self):
        self.n1 = int(input("Enter the no. of students for SE-A: "))
        for i in range(self.n1):
            s = Student()
            print(f"Enter information for student {i+1}:")
            s.PRN = input("Enter your PRN: ")
            day = int(input("Enter day of birth: "))
            month = int(input("Enter month of birth: "))
            year = int(input("Enter year of birth (4 digits): "))
            s.dob = datetime.date(year, month, day)
            self.SEAList.append(s)

    # Read Student Information for SE-B
    def readStudentdataSEB(self):
        self.n2 = int(input("Enter the no. of students for SE-B: "))
        for i in range(self.n2):
            s = Student()
            print(f"Enter information for student {i+1}:")
            s.PRN = input("Enter your PRN: ")
            day = int(input("Enter day of birth: "))
            month = int(input("Enter month of birth: "))
            year = int(input("Enter year of birth (4 digits): "))
            s.dob = datetime.date(year, month, day)
            self.SEBList.append(s)

    # Display Student List for SE-A
    def displayStudentListSEA(self):
        print("\nSE-A Student List:")
        for student in self.SEAList:
            print(f"\t{student.PRN} - {student.dob}")

    # Display Student List for SE-B
    def displayStudentListSEB(self):
        print("\nSE-B Student List:")
        for student in self.SEBList:
            print(f"\t{student.PRN} - {student.dob}")

    # Display Merged Student List for SE Computer
    def displayStudentListSECOMP(self):
        print("\nSE-Computer Merged Student List:")
        for student in self.SECOMPList:
            print(f"\t{student.PRN} - {student.dob}")

    # Sort Student List using Bubble Sort
    def sortStudentList(self, nos, List):
        for i in range(nos - 1):
            for j in range(nos - i - 1):
                if List[j].dob > List[j + 1].dob:
                    List[j], List[j + 1] = List[j + 1], List[j]

    # Merge SE-A and SE-B Lists into SE Computer List
    def mergeList(self):
        self.SECOMPList = []
        # Merge SE-A and SE-B
        self.SECOMPList.extend(self.SEAList)
        self.SECOMPList.extend(self.SEBList)
        self.n3 = len(self.SECOMPList)
        # Sort the merged list
        self.sortStudentList(self.n3, self.SECOMPList)


# Driver Code
obj = SEComputer()
choice = 0

while choice != 5:
    print("\n*************** SE COMPUTER STUDENT *******************")
    print("1. Read SE-A/SE-B Student Lists")
    print("2. Display SE-A/SE-B Student Lists")
    print("3. Sort SE-A/SE-B Student Lists")
    print("4. Merge SE-A/SE-B Student Lists")
    print("5. Exit Application")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("Enter SE-A student information:")
        obj.readStudentdataSEA()
        print("Enter SE-B student information:")
        obj.readStudentdataSEB()

    elif choice == 2:
        print("SE-A Student Information:")
        obj.displayStudentListSEA()
        print("SE-B Student Information:")
        obj.displayStudentListSEB()

    elif choice == 3:
        print("\n1. Sort SE-A\n2. Sort SE-B")
        sub_choice = int(input("Enter your choice: "))
        if sub_choice == 1:
            obj.sortStudentList(obj.n1, obj.SEAList)
            print("SE-A List Sorted Successfully.")
        elif sub_choice == 2:
            obj.sortStudentList(obj.n2, obj.SEBList)
            print("SE-B List Sorted Successfully.")
        else:
            print("Invalid choice!")

    elif choice == 4:
        obj.mergeList()
        print("Merged SE-Computer List:")
        obj.displayStudentListSECOMP()

    elif choice == 5:
        print("Goodbye!")
        break

    else:
        print("Invalid choice! Please try again.")
