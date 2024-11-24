#include <iostream>
#include <string>

using namespace std;

class Person
{
    char* PIB;
    int age;
public:
    Person()
    {
        PIB = new char[80];
        cout << "Enter ur PIB: ";
        cin.ignore();
        cin.getline(PIB, 80);
        cout << "Enter ur age: ";
        cin >> age;
    }
    ~Person()
    {
        delete[] PIB;
    }
    void ShowInfo() const
    {
        cout << "Name: " << PIB << "\n";
        cout << "Age: " << age << "\n";
    }
};

class Flat
{
    Person* habitants;
    int size;
    float area;
    int flat_number;
    int floor;
public:
    Flat()
    {
        cout << "Enter how many people lives in flat: ";
        cin >> size;
        habitants = new Person[size]();
        cout << "Enter area of flat: ";
        cin >> area;
        cout << "Enter flat number: ";
        cin >> flat_number;
        cout << "Enter floor: ";
        cin >> floor;
    }
    ~Flat()
    {
        delete[] habitants;
    }
    void Show() const
    {
        cout << "Area: " << area << "\n";
        cout << "Flat number: " << flat_number << "\n";
        cout << "Floor: " << floor << "\n";
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << " Habitant info:\n";
            habitants[i].ShowInfo();
        }
    }
};

class House
{
    Flat* flats;
    int size;
    int floors;
    char* color;
public:
    House()
    {
        cout << "Enter count of flats in ur house: ";
        cin >> size;
        flats = new Flat[size];
        color = new char[100];
        cout << "Enter count of floors in ur house: ";
        cin >> floors;
        cout << "Enter color of ur house: ";
        cin.ignore();
        cin.getline(color, 80);
    }
    ~House()
    {
        delete[] flats;
        delete[] color;
    }
    void Show() const
    {
        cout << "House info\n";
        cout << "Floors: " << floors << "\n";
        cout << "Color: " << color << "\n";
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << " flat info:\n";
            flats[i].Show();
        }
    }
};

int main()
{
    House home;
    home.Show();
}