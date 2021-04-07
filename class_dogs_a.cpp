#include <iostream>
#include <vector>
#include <string>
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

class House
{
private:
	Address address;
public:
	House(){}
	House(Address address)
	{
		this->address=address;
	}
};

class Dog
{
private:
	string name;
	string code;
public:
	Dog(){}
	Dog(string name, string code):name{name}, code{code}{}
	virtual ~Dog() {}

	bool operator==(Dog other)
	{
		if (other.code!=this->code) return false;
		return true;
	}
};

class Action
{
private:
	vector<Dog*>list_of_dogs;
public:
	Action(){}
	void addDog(Dog* dog)
	{
		list_of_dogs.push_back(dog);
	}

	void removeDog(Dog other)
	{
		for (int i=0; i<list_of_dogs.size(); i++)
		{
			if (*list_of_dogs[i]==other)
				list_of_dogs.erase(list_of_dogs.begin()+i);
		}
	}

	int getDogs()
	{
		return list_of_dogs.size();
	}
};

int main()
{
	Address a1("Sai Gon", 3004, "Cai Lay");
	Action ac;
	Dog d1("Vip","ABC");
	ac.addDog(&d1);
	Dog d2("Pro","XYZ");
	ac.addDog(&d2);
	Dog d3("VT","ABC");
	ac.addDog(&d3);
	cout << "The number of Dogs: " << ac.getDogs() << endl;
	ac.removeDog(d2);
	ac.removeDog(d1);
	ac.removeDog(d3);
	cout << "The number of Dogs left: " << ac.getDogs();
}