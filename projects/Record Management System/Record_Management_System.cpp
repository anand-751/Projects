// CRUD APPLICATION.....

#include <iostream>
#include <vector>
#include<limits>
#include<fstream>
#include<algorithm>



using namespace std;
class Student {
    private:
    static int lastAssignedRollNumber;

    public:
    string name;
    int age;
    int rollNo ;  

};
    vector<Student> studentRecords;

void createRecord() {
 ofstream outputFile("data.txt", ios::app); // Open the file in write mode

    if (!outputFile) {
        cout << "Failed to open the file." << endl;
        return;
    }

    Student student;

    // Prompt the user to enter data
        cout << "Enter name: ";
        getline(cin >> ws, student.name);

    try {
        cout << "Enter age: ";
        if (!(cin >> student.age)) {
            throw runtime_error("Invalid input for age.");
        }

        cout << "Enter roll number: ";
        if (!(cin >> student.rollNo)) {
            throw runtime_error("Invalid input for roll number.");
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();               // Clear the error state
       
        return;
    }

    // Write the data to the file
    outputFile << student.name << endl;
    outputFile << student.age << endl;
    outputFile << student.rollNo << endl;

    // Close the file
    outputFile.close();

    cout << "Data has been saved to the file." << endl;


}

void readRecords() {
    ifstream inputFile("data.txt",ios::in); // Open the file in read mode

    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return;
    }
    Student student;
    string name;
    int age;
    int rollNumber;
    
    // Read and display data until the end of the file is reached
     //&& inputFile >> age >> rollNumber)

    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cout << "No records found." << endl;
        inputFile.close();
        return;
    }
       
      while (getline(inputFile >> ws, name)) {
        inputFile >> age >> rollNumber;
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
    
    
        cout << "-----------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll number: " << rollNumber << endl;
        cout << "-----------------------" << endl;   
        cout << endl;

    }
    inputFile.close();

    // Close the file
    

}

void updateRecord() {
    fstream file("data.txt"); // Open the file in read and write mode

    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    vector<Student> students;

    string name;
    int age;
    int currentRollNumber;
    int rollNumber;
    
    try{
    cout<<"Enter the roll number to be updated : "<<endl;
    if (!(cin>> rollNumber)){
        throw runtime_error("Invalid input for roll number.");
        } 
    } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
    cin.clear();               // Clear the error state
       
    return;
    
}

    

    bool recordFound = false;

    // Read data from the file and update the record if found
    while (getline(file >> ws, name)) {
        file >> age >> currentRollNumber;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (currentRollNumber == rollNumber) {
            recordFound = true;

            // Prompt the user to update the record
            cout << "Enter new name: ";
            getline(cin >> ws, name);
            cout << "Enter new age: ";
            cin >> age;
        }

        Student student;
        student.name = name;
        student.age = age;
        student.rollNo = currentRollNumber;
        students.push_back(student);
    }

    if (!recordFound) {
        cout << "Record with roll number " << rollNumber << " not found." << endl;
        return;
    }

    // Close the file
    file.close();

    // Open the file in write modeto update the data
    file.open("data.txt", ios::out | ios::trunc);

    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    // Write the updated data to the file
    for (const auto& student : students) {
        file << student.name << endl;
        file << student.age << endl;
        file << student.rollNo << endl;
    }

    // Close the file
    file.close();

    cout << "Record with roll number " << rollNumber << " has been updated." << endl;
}


void deleteRecord() {
    ifstream inputFile("data.txt"); // Open the file in read mode

    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return;
    }

    vector<Student> students;

    string name;
    int age;
    int currentRollNumber;
    int rollNumber;
    cout<<"Enter the roll number to be deleted : "<<endl;
    try{
    if (!(cin>>rollNumber))
        {
            throw runtime_error("Invalid input for roll number.");
        }
    }catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();               // Clear the error state
       
        return;
    }
    

    bool recordFound = false;

    // Read data from the file and search for the record to delete
    while (getline(inputFile >> ws, name)) {
        inputFile >> age >> currentRollNumber;
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

        if (currentRollNumber == rollNumber) {
            recordFound = true;
        } else {
            Student student;
            student.name = name;
            student.age = age;
            student.rollNo = currentRollNumber;
            students.push_back(student);
        }
    }

    // Close the file
    inputFile.close();

    if (!recordFound) {
        cout << "Record with roll number " << rollNumber << " not found." << endl;
        return;
    }

    // Open the file in write mode to update the data
    ofstream outputFile("data.txt", ios::out | ios::trunc);

    if (!outputFile) {
        cout << "Failed to open the file." << endl;
        return;
    }

    // Write the updated data to the file
    for (const auto& student : students) {
        outputFile << student.name << endl;
        outputFile << student.age << endl;
        outputFile << student.rollNo << endl;
    }

    // Close the file
    outputFile.close();

    cout << "Record with roll number " << rollNumber << " has been deleted." << endl;
}

void searchRecord() {
    ifstream inputFile("data.txt"); // Open the file in read mode

    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return;
    }

    string name;
    int age;
    int currentRollNumber;
    int rollNumber;
    cout<<"Enter the roll number to be searched : "<<endl;
    try{
         if (!(cin>>rollNumber))
        {
            throw runtime_error("Invalid input for roll number.");
        }
    }catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();               // Clear the error state
       
        return;
    }

    vector<Student> students;
    bool recordFound = false;

    // Read data from the file and populate the vector
    while (getline(inputFile >> ws, name)) {
        inputFile >> age >> currentRollNumber;
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

        Student student;
        student.name = name;
        student.age = age;
        student.rollNo = currentRollNumber;
        students.push_back(student);
    }

    // Close the file
    inputFile.close();

    // Sort the vector by roll number in ascending order
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.rollNo < s2.rollNo;
    });

    // Perform binary search
    int left = 0;
    int right = students.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (students[mid].rollNo == rollNumber) {
            recordFound = true;
            break;
        } else if (students[mid].rollNo < rollNumber) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Display the record if found
    if (recordFound) {
        cout << "Record found:" << endl;
        cout << "Name: " << students[mid].name << endl;
        cout << "Age: " << students[mid].age << endl;
        cout << "Roll number: " << students[mid].rollNo << endl;
    } else {
        cout << "Record with roll number " << rollNumber << " not found." << endl;
    }
}

int main() {
    cout << "Welcome to Guru Nanak Dev University Portal" << endl;
    system("pause");

    cout << "\033[2J\033[1;1H";
    cout << "Welcome to Guru Nanak Dev University Portal" << endl;
    // Display the constant message at the top
    



    
    cout << endl;

    cout<<"SECURITY SYSTEM!"<< endl;
    cout<<"-----------------"<<endl;
    string username = "admin";
    string password = "password";

    string inputUsername;
    string inputPassword;

    cout << "Enter username: ";
    cin >> inputUsername;

    cout << "Enter password: ";
    cin >> inputPassword;

    if (inputUsername == username && inputPassword == password) {
        cout << "Login successful!" << endl;
        // Continue with the rest of your application logic here
    } else {
        cout << "Invalid username or password. Login failed." << endl;
        exit(1);
    }

    system("pause"); 
    
    system("CLS");

    cout<<"WELCOME! TO GURU NANAK DEV UNIVERSITY PORTAL"<<endl;
    char choice;

    do {
        cout<< "*******************"<<endl;
        cout << "CRUD Application" << endl;
        cout << "1. Create record" << endl;
        cout << "2. Read records" << endl;
        cout << "3. Update record" << endl;
        cout << "4. Delete record" << endl;
        cout << "5. Search record" << endl;
        cout << "6. Exit" << endl;
        cout<< "*******************"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                createRecord();
                break;
            case '2':
                readRecords();
                break;
            case '3':
                updateRecord();
                break;
            case '4':
                deleteRecord();
                break;
            case '5':
                searchRecord();
                break;
            case '6':
                cout << "Exiting the application. Goodbye!" << endl;
                exit(1);
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;  
    }   while (choice != 5);

    return 0;
}
 