#  Result Calculator in C

A simple console-based  Result Calculator developed using C language.

This project was created as my First Year Final Project for learning and implementing core concepts of C programming such as functions, structures, arrays, loops, conditions, and file handling.

The program helps in calculating:
- SPI (Semester Performance Index)
- Student percentage
- Subject grades
- Backlog detection
- Class topper details

It also stores student records in a text file.



# Features

- Calculate SPI using subject credits
- Automatic grade generation
- Backlog detection for failed subjects
- Percentage calculation
- Class topper identification
- Student record storage using file handling
- User-friendly console interaction



# Concepts Used

This project uses the following C programming concepts:

- Functions
- Structures
- Arrays
- Loops
- Conditional Statements
- File Handling
- String Handling



# Project Workflow

1. Enter total subjects
2. Enter maximum marks and passing marks
3. Enter subject names and credits
4. Enter student details and marks
5. Program calculates:
   - Grades
   - SPI
   - Percentage
   - Backlogs
6. Result gets stored in `record.txt`
7. Topper details are displayed at the end



# Technologies Used

- C Language
- GCC Compiler / MinGW
- VS Code



# Files

 File Name  Description

 record.txt  Stores student result records 



# How to Run

## Compile
 you can run this program using vs code follow folloeing stepd
 1.make an folder in vs code
 2.imoprt the code
 3.run it

 the record.txt file will created in where you made folder

# Sample Output

text
=====Result Calculator=====
                Please enter the required information
Enter total number of subjects: 2
Enter maximum marks for each subject: 100
Enter minimum passing marks: 23
wants to calculate SPI(yes=1;no=0):1
Enter name of 1 subject: math
Enter credit: 5
Enter name of 2 subject: physics
Enter credit: 4

≡ƒÄ» Enter all marks between 0 to 100 ≡ƒÄ»

≡ƒæºEnter number of students≡ƒæ¿: 2
Sr Number: 1
Enter last two digits of enrollment number: 1
Enter name of student: bhavesh aanand dandgavhal

Enter marks of math
:86
Grade: AB
Enter marks of physics
:79
Grade: BB

======Result======
Enrollment number: 250140107001 
Student name: bhavesh aanand dandgavhal

Total marks: 165/200.00
Percentage: 82.50 
Semester Performance Index: 8.556
 
≡ƒÑ│ Congratulations! You have passed all subjects ≡ƒÑ│ 
≡ƒÑê Grade is A2 ≡ƒÑê 

===================
Sr Number: 2
Enter last two digits of enrollment number: 2
Enter name of student: ronak patel

Enter marks of math
:79
Grade: BB
Enter marks of physics
:58
Grade: CC

======Result======
Enrollment number: 250140107002 
Student name: ronak patel

Total marks: 137/200.00
Percentage: 68.50 
Semester Performance Index: 7.111
 
≡ƒÑ│ Congratulations! You have passed all subjects ≡ƒÑ│ 
≡ƒÅå Grade is B2 ≡ƒÅå

===================

 ===Class Topper=== 
Name: bhavesh aanand dandgavhal
Enrollment number: 250140107001 
SPI: 8.555555

# Future Improvements

- Add CGPA calculation
- Create graphical interface
- Add database connectivity
- Export result in PDF format
- Add login system for students

---

# About Project

This project is made for educational purposes and beginner-level practice in C programming.

It helped me improve my logic-building and programming fundamentals.

---

# Author

Bhavesh Aanand Dandgavhal  
First Year B.Tech Computer Engineering Student
