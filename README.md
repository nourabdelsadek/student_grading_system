Student grading System
This is a C++ console application that manages student records. It allows users to add, update, search, and delete student records, as well as perform statistical operations like calculating average grades, displaying students who need improvements, and more. The data is saved to a file for persistence.

Table of Contents
Project Overview
Features
Installation
Usage
File Format
License
Project Overview
This system is designed to manage and maintain student records. Each student has a unique ID, name, and grade. The system provides several functionalities such as searching by ID or name, updating student information, deleting records, and calculating statistical data.

The system persists data by saving all student records into a file when the program exits, ensuring that records can be reloaded when the application is reopened.

Features
Add Student: Add a student to the system by entering their name, ID, and grade.
Display All Students: View the list of all students along with their details.
Search Student by ID: Search for a student by their unique ID.
Search Student by Name: Search for a student by their name.
Update Student Information: Modify an existing student's name and grade.
Delete Student Record: Remove a student's record from the system by their ID.
Calculate Average Grade: Compute the average grade of all students.
Display Grade Statistics: Show the highest and lowest grades in the system.
Display Students Needing Enhancements: List students who have a grade less than 50%.
Load Students from File: Load student data from a text file (input.txt).
Save Data: Automatically save student records to a file (students.txt) when the program exits.
Installation
Clone the Repository:

bash
Copy code
git clone https://github.com/nourabdelsadek/student_grading_system.git
Compile the Program:
Compile the program using any C++ compiler. For example, using g++:

bash
Copy code
g++ student_grading_system.cpp -o student_system
Run the Program:
Run the compiled program:

bash
Copy code
./student_system
Usage
Upon running the program, you will be presented with a menu offering various options to manage student records.

Example Menu:
plaintext
Copy code
========== Student Record Management ==========
1. Add Student
2. Display All Students
3. Search for Student by ID
4. Search for Student by Name
5. Update Student Information
6. Delete Student Record
7. Calculate Average Grade
8. Display Grade Statistics
9. Display Students Needing Enhancements
10. Load Students from input.txt
11. Exit
===============================================
Choose an option: 
Adding a Student:
Choose option 1 to add a new student.
Enter the student's name, ID, and grade.
The system will automatically store the student and maintain the list in sorted order by ID.
Updating a Student:
Choose option 5 to update a student's information.
Provide the student ID and the new name and grade.
Exiting the Program:
Choosing option 11 will save all data to students.txt and exit the program.
File Format
Input File (input.txt)
The program can load student data from an input file called input.txt. The file should contain one student's record per line in the following format:

Copy code
ID Name Grade
Output File (students.txt)
When the program exits, it saves all student data to students.txt in the same format as the input file:

Copy code
ID Name Grade
Example:

Copy code
101 John 85.5
102 Alice 90.0
103 Bob 47.0
