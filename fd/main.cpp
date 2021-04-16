#include <iostream>
#include "fd.hpp"

int main(void)
{
	fd_set fds;

	ft::FD_ZERO_M(&fds);
	ft::FD_SET_M(1, &fds);
	std::cout << ft::FD_ISSET_M(1, &fds) << std::endl;
	std::cout << ft::FD_ISSET_M(102, &fds) << std::endl;
	ft::FD_SET_M(102, &fds);
	std::cout << ft::FD_ISSET_M(102, &fds) << std::endl;
	std::cout << ft::FD_ISSET_M(127, &fds) << std::endl; // 왜 항상 값이 바뀌지? FD_ZERO를 하지 않으면 초기화가 안되어 쓰레기 값이 들어간다!
	ft::FD_SET_M(127, &fds);
	std::cout << ft::FD_ISSET_M(127, &fds) << std::endl; 
	std::cout << ft::FD_ISSET_M(10, &fds) << std::endl;
	ft::FD_SET_M(10, &fds);
	std::cout << ft::FD_ISSET_M(10, &fds) << std::endl;
	ft::FD_CLR_M(10, &fds);
	std::cout << ft::FD_ISSET_M(10, &fds) << std::endl;
}
