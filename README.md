Step 1: What is this program trying to do?
The program demonstrates various C concepts such as:
Variables
Functions
Loops (for, while)
Arrays
Pointers
Variable scope
Function calls
Printing values
It intentionally contains many errors for debugging practice.
Line
Error Type
Error
Correction
10
Syntax
Missing ; after int department = 1
int department = 1;
12
Semantic
int marks = "90"; (string assigned to int)
int marks = 90;
26
Logical
if(x = 10) uses assignment
if(x == 10)
31
Semantic
score undeclared
Declare int score; or use correct variable
47
Linker
add() not declared/defined
Declare and define add()
54
Scope
temp used outside its block
Declare temp outside the block
58
Runtime
arr[10] out of bounds
Use index 0–4
62
Semantic
%d used for float
Use %f
78
Scope
result used outside loop
Declare result before the loop
83
Logical
Both if and else print "Eligible"
Change else to "Not Eligible"
89
Semantic
displayData() called without argument
displayData(value);
117
Logical
while(z > 0); has an extra semicolon
Remove the semicolon
123
Semantic
char grade = "A";
char grade = 'A';
127
Semantic
%s used for integer
Use %d
131
Runtime
Dereferencing NULL pointer
Allocate memory or point to a valid variable
135
Linker
calculateAverage() not declared/defined
Declare and define calculateAverage()
Additional observations
Variable shadowing occurs with x, department, count, totalStudents, and y. This is legal but can be confusing.
totalStudents inside main() hides the global totalStudents.
The global updateCount() modifies the global variable, not the local one in main().
Debugging Checklist
✅ Syntax Errors
✅ Undeclared Variables
✅ Type Mismatches
✅ Function Call Errors
✅ Scope Errors
✅ Shadowing Issues
✅ Linker Errors
✅ Array Bounds Errors
✅ Pointer Errors
❌ File Handling Errors (none)
✅ Runtime Errors
✅ Logical Errors
✅ Wrong Conditions
❌ Wrong Formulas (none)
PROBLEM2.C
Following your debugging checklist, here is the analysis of 2.c.
Line
Error
Type
Correction
10
int marks = "90";
Semantic
int marks = 90;
16
Missing ; after printf("Program Started\n")
Syntax
Add ;
24
total declared extern but not defined
Linker
Define int total = 0; globally
36
add() called before declaration
Semantic/Linker
Add prototype int add(int,int); before main()
42
Printing address of register variable
Semantic
Remove & or don't use register
44
static int salary = "50000";
Semantic
static int salary = 50000;
52
department used outside scope
Scope
Move printf inside block or declare outside
60
temp used outside loop
Scope
Declare temp before loop
64
arr[10] out of bounds
Runtime
Use index 0–4
69
a/b where b=0
Runtime
Check b!=0 before division
73
if(value = 100)
Logical
if(value == 100)
81
Both branches print "Pass"
Logical
Change else message (e.g. "Fail")
91
char grade = "A";
Semantic
char grade = 'A';
111
Uninitialized variable data
Runtime
Initialize before printing
115
Dereferencing NULL pointer
Runtime
Allocate memory or point to valid variable
117
companyCode declared but not defined
Linker
Define int companyCode = ...;
121
calculateAverage() undeclared/undefined
Linker
Declare and define the function
125
int employeeId = "EMP101";
Semantic
char employeeId[] = "EMP101";
129
while(counter > 0); has extra ;
Logical
Remove the semicolon
Variables
marks, age, count, visits, x, result, number, salary, department, i, temp, arr, a, b, value, score, counter, grade, totalMarks, data, ptr, average, employeeId, y
Functions
main()
update()
display()
add()
calculateAverage() (missing)
Loops
for
while
Arrays
arr[5]
Structures
None
File Operations
None
Pointers
int *ptr = NULL; (incorrectly dereferenced)
What is the program trying to do?
The program is designed as a debugging exercise demonstrating different categories of C programming errors, including syntax, semantic, scope, linker, runtime, logical, array, and pointer errors.

PROBLEM3.C
Here are the errors in 3.c categorized by type.
Line
Error
Type
Correction
20
int choice missing ;
Syntax
int choice;
49
default missing :
Syntax
default:
73
if(index > 5) allows index 5 (out of bounds)
Logical
if(index >= 5) (or check before inserting)
85
for(i=0;i<=totalStudents;i++)
Logical/Array
for(i=0;i<totalStudents;i++)
107
return total / 0;
Runtime
return total / totalStudents; (check totalStudents > 0)
112
int highest = students[0].marks;
Semantic
float highest = students[0].marks;
114
int lowest = students[0].marks;
Semantic
float lowest = students[0].marks;
130
printf("Highest = %d", highest);
Semantic
Use %f or %.2f
132
printf("Lowest = %d", lowest);
Semantic
Use %f or %.2f
135
totalStudent undeclared
Semantic
totalStudents
137
printGrade(); not declared/defined
Linker
Define the function or remove the call
139
calculateRank(); not declared/defined
Linker
Define the function or remove the call
147
s.rollNo = "101";
Type mismatch
s.rollNo = 101;
151
s.marks = "90";
Type mismatch
s.marks = 90.0;
165
students[roll].marks = 100;
Logical
Validate roll before accessing the array
175
students[roll] = NULL;
Semantic
Cannot assign NULL to a structure. Shift elements or mark the record deleted.
185
if(name == students[0].name)
Logical
if(strcmp(name, students[0].name) == 0)
194
int avg;
Semantic
float avg;
198
printf("%d\n", avg);
Semantic
printf("%.2f\n", avg);
211
File opened with "r" then fprintf()
File handling
Open with "w" or "a"
213
fp not checked for NULL
Runtime
Check if(fp == NULL) before writing
222
Reading "missing.txt" without checking fp
Runtime
Check if(fp == NULL) before fscanf()
224
fscanf() may use NULL file pointer
Runtime
Read only if fp != NULL
Summary
Syntax errors: 2
Semantic/type errors: 9
Logical errors: 5
Linker errors: 2
Runtime/File handling errors: 4
Total errors identified: 22

PROBLEM 4.C
Using your debugging checklist, here are the errors in 4.c.
Line
Error Type
Error
Correction
83
Logical
totalAccounts++ is done before checking limit.
Check if(totalAccounts >= 10) before inserting a new account.
85
Logical
if(totalAccounts > 10) allows writing to accounts[10].
Use if(totalAccounts >= 10) before storing data.
95
Logical/Runtime
for(i=0; i<=totalAccounts; i++) accesses one extra element.
for(i=0; i<totalAccounts; i++)
122
Logical
Uses account number as array index (accounts[acc]).
Search the account by accNo first, then update its balance.
143
Logical
Condition is reversed.
if(accounts[index].balance < amount) → Insufficient balance.
149
Logical
Same indexing problem in withdrawal.
Find the correct account index first.
189
Runtime
total / totalAccounts may divide by zero if no accounts exist.
Check if(totalAccounts>0) first.
198
Semantic
totalAccount is undeclared.
Replace with totalAccounts.
201
Linker
calculateInterest() is undefined.
Use interestCalculator() or define calculateInterest().
203
Linker
saveAccounts() called before declaration.
Add function prototype void saveAccounts();.
211
Semantic
a.accNo = "1001"; assigns a string to an int.
a.accNo = 1001;
215
Semantic
a.balance = "50000"; assigns a string to a float.
a.balance = 50000;
242
Semantic
accounts[accNo] = NULL; is invalid because accounts[accNo] is a structure.
Shift elements or mark the record as deleted.
252
Semantic
if(name == accounts[0].name) compares addresses.
if(strcmp(name, accounts[0].name)==0)
263
Linker
generateAverage() is undefined.
Define it or remove the call.
274
File Handling
File opened in "r" mode but written using fprintf().
Open with "w" or "a".
276
Runtime
No check if fp == NULL.
Check before using the file pointer.
286
Runtime
Opens "missing.txt" without checking if file exists.
Check if(fp==NULL) before fscanf().
323
Runtime
arr[10] is out of bounds for arr[5].
Use indices 0 to 4.
327
Runtime
Dereferencing NULL pointer (*ptr=100).
Allocate memory or point to a valid variable.
332
Runtime
Division by zero (a/b).
Ensure b != 0 before division.
Summary
Syntax Errors: None
Semantic Errors: 6
Scope Errors: None (scopeDemo() only demonstrates variable shadowing)
Linker Errors: 3 (calculateInterest, generateAverage, missing prototype for saveAccounts)
Runtime Errors: 6
Logical Errors: 5
File Handling Errors: 2
Array Errors: 2
Pointer Errors: 1

PROBLEM 5.C
Below is an error analysis of 5.c following your debugging checklist.
Line
Error
Type
Correction
23
int choice missing ;
Syntax
int choice;
57
default missing :
Syntax
default:
82
Library full check after increment
Logical
Check before inserting or use if(totalBooks >= 20)
94
i <= totalBooks
Logical/Array
i < totalBooks
116
Uses books[id] where id is Book ID
Logical
Search the array by bookId before updating
126
Missing prompt before input
Logical
Add printf("Enter Book ID : ");
129
Again uses Book ID as array index
Logical
Search by bookId
139
Accesses books[0] without checking if library is empty
Runtime
Check if(totalBooks==0) first
165
totalBook undeclared
Semantic
Replace with totalBooks
168
saveLibrary() called before declaration
Semantic
Add function prototype
170
calculateFine() undefined
Linker
Define it or remove the call
177
b.bookId = "101";
Type mismatch
b.bookId = 101;
183
b.price = "500";
Type mismatch
b.price = 500; or 500.0f
195
title == books[0].title
Logical
strcmp(title, books[0].title) == 0
207
books[id] = NULL;
Semantic
Cannot assign NULL to a structure. Shift records or mark as deleted.
224
calculateAveragePrice() undefined
Linker
Define the function or remove the call
233
File opened in "r" then written
Runtime/File
Open with "w" or "a"
235
fprintf() without checking fp
Runtime
Check if(fp != NULL)
245
Opens "missing.txt" without checking existence
Runtime
Check fp != NULL
248
fscanf() may use NULL pointer
Runtime
Verify file opened successfully
273
Dereferencing NULL pointer
Runtime/Pointer
Allocate memory before use
277
arr[10] out of bounds
Runtime
Use indices 0–4
282
Division by zero
Runtime
Ensure denominator is not zero
290
Buffer overflow in strcpy()
Runtime
Increase array size or use strncpy()
299
malloc(5) allocates only 5 bytes
Runtime
malloc(5 * sizeof(int))
301
Writes 20 integers into space for 5
Runtime
Allocate enough memory or loop only 5 times
307
Accessing memory after free()
Runtime
Do not use pointer after free()
309
Double free()
Runtime
Remove second free() or set ptr = NULL
Summary
Syntax errors: 2
Semantic/type errors: 4
Logical errors: 5
Linker errors: 2
Runtime/pointer/array/file errors: 12
Total errors identified: 25.
