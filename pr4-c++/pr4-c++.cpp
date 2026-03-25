#include <iostream>
#include <windows.h>
using namespace std;

struct Student {
	int number; // номер з.п
	string lastName; // прізвище
	string firstName; // ім'я
	int birthYear; // рік народження
	string Faculty; // факультет (МБФ, ІКФ, ЕФ, ЗФ)
	string formOfEducation; // форма навчання (очна, заочна, вечірня)
};

class StudentsParent {

protected:

	Student* students;
	int size;

public:

	StudentsParent(int n) { // конструктор класу, який приймає кількість студентів
		size = n;
		students = new Student[size];
	}

	StudentsParent(const StudentsParent& other) { // конструктор копіювання
		size = other.size;
		students = new Student[size];
		for (int i = 0; i < size; i++) {
			students[i] = other.students[i];
		}
	}

	void input() { // метод для введення даних про студентів
		for (int i = 0; i < size; i++) {
			cout << "Введіть дані про студента " << i + 1 << ":\n";
			cout << "Номер за списком: ";
			cin >> students[i].number;
			cout << "Прізвище: ";
			cin >> students[i].lastName;
			cout << "Ім'я: ";
			cin >> students[i].firstName;
			cout << "Рік народження: ";
			cin >> students[i].birthYear;
			cout << "Факультет (МБФ, ІКФ, ЕФ, ЗФ): ";
			cin >> students[i].Faculty;
			cout << "Форма навчання (очна, заочна, вечірня): ";
			cin >> students[i].formOfEducation;
			cout << endl;
		}
	}

	void display() { // метод для виведення даних про студентів
		for (int i = 0; i < size; i++) {
			cout << "Студент " << i + 1 << ":\n";
			cout << "Номер за списком: " << students[i].number << endl;
			cout << "Прізвище: " << students[i].lastName << endl;
			cout << "Ім'я: " << students[i].firstName << endl;
			cout << "Рік народження: " << students[i].birthYear << endl;
			cout << "Факультет: " << students[i].Faculty << endl;
			cout << "Форма навчання: " << students[i].formOfEducation << endl;
			cout << endl;
		}
	}

};

class StudentsChild : public StudentsParent {

public:

	StudentsChild(int size) : StudentsParent(size) {}

	StudentsChild(const StudentsChild& other) : StudentsParent(other) {}

	void sort(string option) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((option == "Прізвище" || option == "прізвище") && students[j].lastName > students[j + 1].lastName) {
					swap(students[j], students[j + 1]);
				}
				else if ((option == "Імя" || option == "імя") && students[j].firstName > students[j + 1].firstName) {
					swap(students[j], students[j + 1]);
				}
			}
		}
	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (students[j].number > students[j + 1].number) {
					swap(students[j], students[j + 1]);
				}
			}
		}
	}
};


int main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "program check";

	return 0;
}