#include <iostream>
#include "fd.hpp"

namespace ft {
	int FD_ISSET_M(int _n, fd_set *_p)
	{

	return (_p->fds_bits[(unsigned long)_n/__DARWIN_NFDBITS] & ((__int32_t)(1<<((unsigned long)_n % __DARWIN_NFDBITS))));
	}

	void FD_ZERO_M(fd_set *_p)
	{
		__builtin_bzero(_p, sizeof(*_p));
	}

	void FD_SET_M(int _n, fd_set *_p)
	{
		int __fd = _n;
		(_p->fds_bits[(unsigned long)__fd/__DARWIN_NFDBITS] |= ((__int32_t)(1<<(unsigned long)__fd % __DARWIN_NFDBITS)));
	}
	
	void FD_CLR_M(int _n, fd_set *_p)
	{
		int __fd = _n;
		_p->fds_bits[(unsigned long)__fd/__DARWIN_NFDBITS] &= ~((__int32_t)(1<<(unsigned long)__fd%__DARWIN_NFDBITS));
	}
}


