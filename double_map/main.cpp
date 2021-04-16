#include <iostream>
#include <map>

int main(void)
{
	std::map<std::string, std::map<std::string, std::string> > m;
	std::string context;

	m[context]["world"] = "good";

	std::cout << m["hello"]["world"] << std::endl;
}
