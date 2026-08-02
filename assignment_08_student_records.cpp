#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store student information
struct Student
{
    string name;
    int id;
    vector<double> scores;
};

// Function to calculate average score
double calculateAverage(Student student)
{
    double sum = 0;

    for (int i = 0; i < student.scores.size(); i++)
    {
        sum += student.scores[i];
    }

    return sum / student.scores.size();
}

// Function to add a student
void addStudent(vector<Student>& students)
{
    Student student;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    int n;

    cout << "How many scores? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student added successfully." << endl;
}

// Function to display all students
void displayStudents(vector<Student> students)
{
    if (students.size() == 0)
    {
        cout << "No students found." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\nName: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;

        cout << "Scores: ";

        for (int j = 0; j < students[i].scores.size(); j++)
        {
            cout << students[i].scores[j] << " ";
        }

        cout << endl;

        cout << fixed << setprecision(2);
        cout << "Average: " << calculateAverage(students[i]) << endl;
    }
}

// Function to find a student's average
void findAverage(vector<Student> students)
{
    int id;

    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score is "
                 << calculateAverage(students[i]) << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

int main()
{
    vector<Student> students;
    int choice;

    do
    {
        cout << "\n===== STUDENT RECORD SYSTEM =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Calculate Average" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;

        case 2:
            displayStudents(students);
            break;

        case 3:
            findAverage(students);
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        } 

    } while(choice !=4);

    return 0;
}
