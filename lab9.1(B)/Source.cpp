#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

using namespace std;

#pragma pack(push, 1)

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "Informatuka ",
                            "Radiotechnika", "Computer science",
                            "Cumputer ingenering", "Programs defend" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_pedagogy;
    union
    {
        int grade_programming;
        int grade_numerical_methods;
    };
};

#pragma pack(pop)

void Create(Students* S, const int N);
void Print(Students* S, const int N);
void Print_second(Students* S, const int N);
double Percentage(Students* S, const int N);
double Avarage_grade(Students* S, const int i);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Enter the number of students:  "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);
    Print_second(S, N);
    cout << "Percentege of students , having 5 or 4 in physics " << setprecision(2) << Percentage(S, N) << "%";

    return 0;
}
void Create(Students* S, const int N)
{
    int speciality;
    for (int i = 0; i < N; i++)
    {
        cout << "Student number: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Name: "; getline(cin, S[i].surname); cout << endl;
        cout << "Course: "; cin >> S[i].course; cout << endl;
        cout << "Speciality(0 - Informatuka, 1 - Radiotechnika, 2 - Cumputer science,";
        cout << "\n3 - Cumputer ingenering, 4 - Programs defend): ";
        cin >> speciality;
        cout << "Assessment in physics: "; cin >> S[i].grade_physics;
        cout << "Assessment in mathematics "; cin >> S[i].grade_math;
        S[i].speciality = (Speciality)speciality;

        switch (S[i].speciality)
        {
        case KN:
            cout << "Assessment in programing: "; cin >> S[i].grade_programming;
            break;
        case ITIS:
            cout << "Assessment in numerical methods: "; cin >> S[i].grade_numerical_methods;
            break;
        default:
            cout << "Assessment in pedagogy: "; cin >> S[i].grade_pedagogy;
        }
        cout << endl;
    }
}
void Print(Students* S, const int N)
{
    cout << "================================================================================" << endl;
    cout << "|No|Name|Course|Speciality|Physics|Mathematics|Programing|";
    cout << "NM|Pedagogy|" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(3) << S[i].surname << setw(3);
        cout << "|" << setw(2) << S[i].course << setw(2);
        cout << "|" << setw(2) << speciality_str[S[i].speciality] << setw(2);
        cout << "|" << setw(2) << S[i].grade_physics << setw(2);
        cout << "|" << setw(2) << S[i].grade_math << setw(2);
        switch (S[i].speciality)
        {
        case KN:
            cout << "|" << setw(2) << S[i].grade_programming << setw(2);
            cout << "|" << setw(2) << "-" << setw(2);
            cout << "|" << setw(2) << "-" << setw(2) << "|";
            break;
        case ITIS:
            cout << "|" << setw(2) << "-" << setw(2);
            cout << "|" << setw(2) << S[i].grade_numerical_methods << setw(2);
            cout << "|" << setw(2) << "-" << setw(2) << "|";
            break;
        default:
            cout << "|" << setw(2) << "-" << setw(2);
            cout << "|" << setw(2) << "-" << setw(2);
            cout << "|" << setw(2) << S[i].grade_pedagogy << setw(2) << "|";
        }
        cout << endl;
    }
    cout << "================================================================================" << endl;
}
double Avarage_grade(Students* S, const int i)
{
    switch (S[i].speciality)
    {
    case KN:
        return (S[i].grade_math * 1. + S[i].grade_physics * 1. + S[i].grade_programming * 1.) / 3.;
    case ITIS:
        return (S[i].grade_math * 1. + S[i].grade_physics * 1. + S[i].grade_numerical_methods * 1.) / 3.;
    default:
        return (S[i].grade_math * 1. + S[i].grade_physics * 1. + S[i].grade_pedagogy * 1.) / 3.;
    }
}
void Print_second(Students* S, const int N)
{
    cout << fixed;
    cout << "=====================================" << endl;
    cout << "|  No  |  Name  |        GPA        |" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(5) << S[i].surname << setw(4);
        cout << "|" << setw(7) << setprecision(2) << Avarage_grade(S, i) << setw(8) << "|";
        cout << endl;
    }
    cout << "=====================================" << endl;
}
double Percentage(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics == 5 || S[i].grade_physics == 4)
            k++;
    return k / (N * 1.0) * 100;
}