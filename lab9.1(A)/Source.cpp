//–≤¬≈Õ‹ ¿
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

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
    int computer_science;

};

#pragma pack(pop)

void Create(Students* S, const int N);
double Avarage_grade(Students* S, const int i);
void Print(Students* S, const int N);
double Percentage(Students* S, const int N);
void Print_first(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Enter the number of students: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print_first(S, N);
    Print(S, N);
    cout << "Percentege of students , having 5 or 4 in physics: " << setprecision(2) << Percentage(S, N) << "%";

    return 0;
}
void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Student number: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Name: "; getline(cin, S[i].surname); cout << endl;
        cout << "Course: "; cin >> S[i].course; cout << endl;
        cout << "Speciality(0 - Informatuka, 1 - Radiotechnika, 2 - Cumputer ingenering,";
        cout << "\n3 - Cumputer ingenering, 4 - Programs defend): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "Assessment in physics: "; cin >> S[i].grade_physics; cout << endl;
        cout << "Assessment in mathematics: "; cin >> S[i].grade_math; cout << endl;
        cout << "Assessment in informating: "; cin >> S[i].computer_science; cout << endl;
        cout << endl;
    }

}
double Avarage_grade(Students* S, const int i)
{
    return (S[i].grade_math * 1. + S[i].grade_physics * 1. + S[i].computer_science * 1.) / 3.;
}
void Print_first(Students* S, const int N)
{
    cout << "==========================================================================" << endl;
    cout << "| No | Name | Course | Spieciality | Phisics | Mathematics | Informating |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(4);
        cout << "|" << setw(3) << S[i].course << setw(3);
        cout << "|" << setw(4) << speciality_str[S[i].speciality] << setw(4);
        cout << "|" << setw(5) << S[i].grade_physics << setw(5);
        cout << "|" << setw(5) << S[i].grade_math << setw(5);
        cout << "|" << setw(5) << S[i].computer_science << setw(5) << "|" << endl;
    }
    cout << "==========================================================================" << endl << endl;
}
void Print(Students* S, const int N)
{
    cout << fixed;
    cout << "=================================" << endl;
    cout << "|  No  |  Name  |      GPA      |" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(4);
        cout << "|" << setw(4) << S[i].surname << setw(4);
        cout << "|" << setw(8) << setprecision(2) << Avarage_grade(S, i) << setw(8) << "|";
        cout << endl;
    }
    cout << "=================================" << endl;
}
double Percentage(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics == 5 || S[i].grade_physics == 4)
            k++;
    return k / (N * 1.0) * 100;
}