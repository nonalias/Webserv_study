#include <iostream>
#include <vector>

class A {
	private:
		std::string *name;
	public:
		A() : name(new std::string("default")){}
		~A() {
			delete name;
		}
		A(std::string *name) : name(name){}
		std::string getName()
		{
			return *(this->name);
		}
};

int main(void)
{
	std::string *name = new std::string("taehkim");
	A *a = new A(name);
	
	std::vector<A *> vt;

	vt.push_back(a);
	//std::cout << a->getName() << std::endl;
	delete a;
	std::cout << vt[0]->getName() << std::endl;
}
