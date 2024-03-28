# Customer Record Manager

This Python project is a customer record management system implemented in C++ that reads customer records from a text file and displays them.

## Installation

To run the code locally:

1. Download the code.
2. Open a terminal and navigate to the directory containing the script.
3. Ensure that the following files are in the same directory:
   - `CustomerRecordManager.cpp`
   - `customer.txt`

## Usage

1. To execute the C++ code, open the terminal on the command prompt and navigate to the directory containing the files.

2. On the terminal, run the following command:
    ```
    g++ CustomerRecordManager.cpp -o CustomerRecordManager
    ```
    
3. Compile the C++:
    ```
    CustomerRecordManager
    ```

3. The system will prompt the user to enter a file: 
    ```
    customer.txt
    ```
    
**Text File Format:**

The text file containing customer records should have the following format:
```
name,occupation,Adr-is_condominium,Adr-street,Adr-postal,Adr-flr-lvl,Adr-unit-no
Steve Tan,Engineer,FALSE,35 Triselikon Ave,512456,38,#38-13
Tony Wong,Teacher,TRUE,60 Malibu Mansion,520123
Harry Evans,Student,FALSE,8 Central Castle,608833,5,#05-08
```

**Output:**
```
Enter the filename: customer.txt

Customer #1
Name           : Steve Tan
Occupation     : Engineer
Address        :
        Floor  : 38, Unit : #38-13
        Street : 35 Triselikon Ave, Postal : 512456

Customer #2
Name           : Tony Wong
Occupation     : Teacher
Address        :
        Street : 60 Malibu Mansion, Postal : 520123

Customer #3
Name           : Harry Evans
Occupation     : Student
Address        :
        Floor  : 5, Unit : #05-08
        Street : 8 Central Castle, Postal : 608833
```
