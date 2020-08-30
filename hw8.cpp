/*
 Joanne Kwon
 March 13, 2017
 Description: create and build a phonebook by defining all the given member functions of the Person class and all the function prototypes that are given.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "phonebook.h"
using namespace std;

//default constructor
Person::Person(){
}

//constructor with parameters
Person::Person(string new_name, int new_phone){
    name = new_name;
    phone = new_phone;
}

string Person::get_name() const{
    return name;
}

int Person::get_phone() const{
    return phone;
}

bool Person::operator<(Person p) const{
    return name < p.name;
}

void Person::print() const{
    cout << name << " " << phone;
}

//adds a contact to the phonebook
void add_people(vector<Person> &phone_book){
    string name;
    int number;
    
    do
    {
        cout << "Please enter a name (Last, First) or press Q to quit. ";
        getline (cin, name); //user inputs name
        
        if (name == "Q") //quits adding new contacts to the phonebook when user outputs "Q"
        {
            return;
        }
        
        cout << "Enter a phone number: ";
        cin >> number; //user inputs phone number
        string clear;
        getline (cin, clear);
        phone_book.push_back(Person(name, number));
    }
    while (name != "Q"); //continues to ask for name and phone number until user outputs "Q"
}

//searches for a name in the phonebook
int find (const vector<Person> &phone_book, string name){
    for(int i = 0; i < phone_book.size(); ++i)
    {
        if (phone_book[i].get_name() == name)
        {
            return i;
        }
    }
    return -1;
}

//erases a contact from the phonebook
void erase(vector<Person> &phone_book, string name){
    int index = find(phone_book, name);
    
    //if name isn't in the phonebook
    if (index == -1)
    {
        return;
    }
    
    for (int i = index; i < phone_book.size()-1; i++){
        phone_book[i] = phone_book[i+1];
    }
    phone_book.pop_back();
}

//helper function for sort
bool compare (Person P1, Person P2){
    return P1 < P2;
}

//organizes the contacts in lexicographical order
void sort(vector<Person> &phone_book){
    sort(phone_book.begin(), phone_book.end(), compare);
}

//randomizes the order of contacts by swaping positions between contacts
void shuffle(vector<Person> &phone_book){
    vector <int> shuffled;
    
    for (int i=0; i < phone_book.size(); i++)
    {
        int place = rand() % (phone_book.size()-i) +i;
        swap (phone_book[i], phone_book [place]);
    }
}

//reverse the order of contacts in the phonebook
void reverse(vector<Person> &phone_book){
    vector <Person> r;
    
    for (int i = phone_book.size(); i>0; i--)
    {
        r.push_back(Person(phone_book[i-1].get_name(), phone_book[i-1].get_phone()));
    }
    phone_book = r;
}

//search for a person in the phonebook
int lookup(const vector<Person> &phone_book, string name){
    int index = find(phone_book, name);
    
    //if name isn't in the phonebook
    if (index == -1)
    {
        return -1;
    }
    
    int p = phone_book[index].get_phone();
    return p;
}

//output everyone in the phonebook
void print(vector<Person> &phone_book){
    for (int i= 0; i < phone_book.size();  i++)
    {
        cout << phone_book[i].get_name() << " " << phone_book[i].get_phone() << endl;
    }
}

