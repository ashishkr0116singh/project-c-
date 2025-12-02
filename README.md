Daily Task Tracking System (C Programming Project)

This is my mini-project for the Programming in C course (1st semester, B.Tech CSE).
I made this project to practice all major concepts taught in class such as structures, functions, file handling, arrays, pointers, and modular programming.

The program is a Daily Task Tracking System where the user can create tasks, assign time limits, update progress, delete tasks, and view completed or pending tasks.
All records are saved using file handling so that tasks remain stored even after the program is closed.

📁 Project Structure
/
├── src/
│   ├── main.c
│   ├── task.c
│   ├── tracker.c
│   ├── utils.c
│
├── include/
│   ├── task.h
│   ├── tracker.h
│   ├── utils.h
│ 
│
├── assets/
│   └── ( flowcharts. )
│
├── docs/
│   └── ProjectReport.pdf
│
└── README.md


This structured format follows the standard guidelines required for modular C programming projects.

🎯 Features

Add new tasks

Display all tasks

Mark tasks as completed or pending

Delete existing tasks

Assign and update time required for each task

Sort tasks by name or status

Store tasks permanently using file handling

Small concept demos using:

Recursion

Pointers

Arrays and string handling

🧠 Concepts Used

This project covers almost all major topics of the C syllabus:

Structures

Functions and modular programming

One-dimensional arrays

Pointer operations

Dynamic memory (optional use cases)

File handling (fopen, fprintf, fscanf, etc.)

Recursion (demo functions)

String handling (strcpy, strcmp, etc.)

📂 Data Storage

All task records are saved in:

tasks.txt


This file is automatically created during the first run of the program.

🛠️ How to Compile & Run

Using GCC:

gcc src/*.c -I include -o tracker
./tracker


Or using a Makefile (if included):

make
./tracker

📝 Sample Output

Screenshots and terminal outputs are provided inside:

➡️ assets/ folder

These include:

Main menu

Adding a task

Viewing tasks

Marking completed tasks

📄 Project Report

The complete project report is available in:

➡️ docs/ProjectReport.pdf

This includes:

Problem definition

Flowcharts

Algorithms

Implementation details

Testing & output screenshots

Conclusion & future work

🙌 Acknowledgement

This project was created as part of the Programming in C course under the guidance of Mohsin F. Dar, UPES.
Developing this mini-project helped improve my understanding of C programming and strengthened my practical coding skills.
