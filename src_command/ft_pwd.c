#include <unistd.h>
#include <stdio.h>
#include <ft_pwd.h>
#include <ft_color.h>
#include <errno.h>
#include <string.h>

void ft_pwd(void)
{
	char buf[PWD_SIZE];
	int	size;

	if (getcwd(buf, PWD_SIZE) == NULL)
	{
		printf(FG_LRED"ERROR"NO_COLOR" : ");
		printf(FG_YELLOW"PWD ");
		printf(FG_YELLOW"%s\n"NO_COLOR,  strerror(errno));
	}
	else
		printf(FG_NAME"%s\n"NO_COLOR, buf);
}