#include <ft_export.h>
#include <ft_env_tool.h>
#include <ft_sub.h>
#include <stdlib.h>
#include <stdio.h>
#include <ft_color.h>

int ft_export(t_exp *exp)
{
	t_exp	*temp;

	temp = exp;

	while (temp)
	{
		printf(FG_RED"%s",temp->name);
		printf(FG_DGREY"=");
		printf(FG_LGREEN"\"%s\"\n"NO_COLOR,temp->data);
		temp = temp->next;
	}
	return (0);
}
