#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Address
{
private:
	string street;
	int house_number;
	string city;
public:
	Address(){}
	Address(string street, int house_number, string city)
	:street{street}, house_number{house_number}, city{city}{}
};


class Campus
{
private:
	string campus_name;
	Address address;
	float distance;
public:
	Campus(string campus_name, Address address, float distance)
	:campus_name{campus_name}, address{address}, distance{distance}{}
};

class Club
{
private:
	string club_name;
	string building;
	int phone;
public:
	Club(){}
	Club(string club_name, string building, int phone)
	:club_name{club_name}, building{building}, phone{phone}{}
};

class Lecturer
{
protected:
	string name;
	string title;
	string office;
	string id;
public:
	Lecturer(){}
	Lecturer(string name, string title, string office, string id)
	{
		this->name = name;
		this->title = title;
		this->office = office;
		this->id = id;
	}

	string getId()
	{
		return this->id;
	}

	string getName()
	{
		return this->name;
	}
};

class System : public Lecturer
{
private:
	string id;
	vector<Lecturer*>list_of_Lecturer;
public:
	System(){}
	void addLecturer(Lecturer* lecturer)
    {
        list_of_Lecturer.push_back(lecturer);
    }

	bool operator == (Lecturer other)
	{
		if (other.getId()!=getId()) return false;
		return true;
	}
};

int main()
{
	System s1;
	Address a1("Cao thang", 16209, "Sai Gon");
	Campus c1("Chemistry", a1, 5.60);
	Club clb1("Drugs","A1",99);
	Lecturer l1("Peter","Dr","A308","ABX089");
	s1.addLecturer(&l1);
	Lecturer l2("Vip","Prof","A374","ABX089");
	s1.addLecturer(&l2);
	return 0;	
}