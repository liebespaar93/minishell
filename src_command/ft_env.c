#include <stdlib.h>
#include <stdio.h>

#include <ft_env.h>
#include <ft_sub.h>
#include <ft_color.h>

void	ft_env(t_env *head)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		printf(FG_LYELLOW"%s",temp->name);
		printf(FG_DGREY"=");
		printf(FG_LGREEN"%s\n"NO_COLOR,temp->data);
		temp = temp->next;
	}
}
