#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

namespace fs = std::filesystem;

std::string filename = "users.txt";

class User
{
public:
	std::string _name;
	std::string _login;
	std::string _pass;

	User(): _name("default"), _login("default"), _pass("default") { }

	User(const char* n, const char*  l, const char* p) : _name(n), _login(l), _pass(p) {}

};

class Message
{
	std::string _text;
	std::string _sender;
	std::string _receiver;
};

void saveToF(User& u)
{
	
	std::fstream file(filename, std::ios::in| std::ios::out |std::ios::app);
	if (file.is_open())
	{
		file << u._login << ' ' << u._name << ' ' << u._pass << '\n';
		file.close();
	}

	fs::permissions(filename, fs::perms::group_all | fs::perms::owner_all);
	
}

void readFromF(User& nU, int strNum)
{
	std::string n;
	std::string l;
	std::string p;

	std::fstream file("users.txt", std::ios::in | std::ios::out | std::ios::app);
	
	if (file.is_open())
	{
		file >> l >> n >> p;

		file.close();
	}

	nU._login= l;
	nU._name = n;
	nU._pass = p;

}

int main()
{
	User us1((const char*)"semen", (const char*)"smok", (const char*)"pass");
	User us2((const char*)"snen", (const char*)"smodfk", (const char*)"passss");
	User us3;
	saveToF(us1);
	saveToF(us2);

}