#ifndef FD_HPP
# define FD_HPP

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

namespace ft{
	int FD_ISSET_M(int fd, fd_set *fdset);
	void FD_ZERO_M(fd_set *_p);
	void FD_SET_M(int _n, fd_set *_p);
	void FD_CLR_M(int _n, fd_set *_p);
}

#endif
