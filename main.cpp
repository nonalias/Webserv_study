#include <iostream>

unsigned short my_htons(int tmp)
{
	unsigned short inp = (unsigned short)tmp;
	unsigned short a = 0;
	if (BYTE_ORDER == BIG_ENDIAN)
		return (inp);
	for (int i = 0; i < 2; i++)
	{
		a += (inp % 16) << ((i + 2) * 4);
		inp /= 16;
	}
	for (int i = 0; i < 2; i++)
	{
		a += (inp % 16) << (i * 4);
		inp /= 16;
	}
	return (a);
}

void test()
{
	unsigned short a = 0x5000;

	for (int i = 0; i < 4; i++)
	{
		std::cout << a % 16 << " ";
		a /= 16;
	}
	std::cout << std::endl;

}

void htons_test()
{
	//unsigned short port = 0x1234;// 0x04d2; htons expected result : 0xd204

	//unsigned short port = 99999; 
	//test();
	//printf("%x\n", port);
	printf("%x\n", htons(-8080));
	//printf("%x\n", port);
	printf("%x\n", my_htons(-8080));
	/*
	*/
	//std::cout << htons(port) << std::endl;

}

/*
unsigned int my_htonl(unsigned int inp)
{

}
*/

void htonl_test()
{
	//std::string str = "192.168.0.1";
	//unsigned int ip = atoi(str.c_str());
	unsigned int ip = 0x12345678;

	printf("%x\n", ip);
	printf("%x\n", htonl(ip));
}

int main(void)
{
	htons_test();
	//htonl_test();
	return (0);
}
