#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pet
{
public:
	Pet(){}
	virtual ~Pet(){}
};

class Dog : public Pet
{
private:
	string name;
public:
	Dog(string name) : name{name}{}
};

class Cat : public Pet
{
private:
	string name;
public:
	Cat(string name) : name{name}{}
};

class Action
{
private:
	vector<Pet*> list_of_pet;
public:
	void addPet(Pet* pet) 
	{
		list_of_pet.push_back(pet);
	}

	int getPet()
	{
		return list_of_pet.size();
	}
};

int main()
{
	Action a;
	Dog d1{"Peter"};
	a.addPet(&d1);
	Cat c1{"Lilly"};
	a.addPet(&c1);
	cout << a.getPet();
}