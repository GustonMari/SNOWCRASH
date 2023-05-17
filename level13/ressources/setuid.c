#include <unistd.h>

int main()
{
	setuid(0x1092);
	execl("/home/user/level13", "level13", NULL);
	return (0);
}
