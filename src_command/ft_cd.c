#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ft_color.h>

void	ft_cd(const char *path)
{
	int ret;

	ret = chdir(path);
	if (ret != 0)
	{
		printf(FG_LRED"ERROR"NO_COLOR" : ");
		printf(FG_YELLOW"'"FG_NAME"%s"FG_YELLOW"' is ", path);
		printf(FG_YELLOW"%s\n"NO_COLOR,  strerror(errno));
	}
}