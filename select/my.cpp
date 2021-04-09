#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

void sig_func(int signo)
{
	printf("exit...\n");
	exit(1);
}

int main() {
	struct timeval tv;
	fd_set rfds;
	int ret;

	signal(SIGINT, sig_func);
	FD_ZERO(&rfds);
	FD_SET(STDIN_FILENO, &rfds);

	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;

	while (1)
	{
		FD_ZERO(&rfds);
		FD_SET(STDIN_FILENO, &rfds);
		ret = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);

		/*
		if (ret == -1)
		{
			perror("select error");
			return 1;
		}
		*/
		/*
		if (ret == 0)
		{
			printf("%d seconds elapsed. \n", TIMEOUT);
		}
		*/
		if (FD_ISSET(STDIN_FILENO, &rfds)) {
			char buf[BUF_LEN + 1];
			int len;

			len = read(STDIN_FILENO, buf, BUF_LEN);
			if (len == -1) return 1;
			if (len) {
				buf[len] = '\0';
				printf("readed data : %s\n", buf);
			}
		}
	}
}
