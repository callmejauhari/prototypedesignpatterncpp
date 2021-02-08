#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Toys
{
protected:
    string _type;
    string _color;

public:
    Toys(string type, string color) : _type(type), _color(color) {}
    virtual Toys *clone() = 0;
    void GetDescription()
    {
        cout << "Toys Description:";
        cout << "Type: " << _type << endl;
        cout << "Color: " << _color << endl;
    }
};

class HumanToys : public Toys
{
public:
    HumanToys(string type, string color) : Toys(type, color) {}
    Toys *clone() override
    {
        return new HumanToys(*this);
    }
};

class AnimalToys : public Toys
{
public:
    AnimalToys(string type, string color) : Toys(type, color) {}
    Toys *clone() override
    {
        return new AnimalToys(*this);
    }
};

int main()
{
    HumanToys toys("police", "blue");
    Toys *cloneHuman = toys.clone();
    toys.GetDescription();
    cloneHuman->GetDescription();
}