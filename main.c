#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ft_color.h>

void	ft_printf_main(void)
{
	int	fd;
	char str[1000];
	int	len;
	int i;
	int	*color;

	color = (int [36]){46, 47, 48, 49, 50, 51, 
		82, 83, 84, 85, 86, 87, 
		118, 119, 120, 121, 122, 123, 
		154, 155, 156, 157, 158, 159, 
		190, 191, 192, 193, 194, 195,  
		226, 227, 228, 229, 230, 231};

	if ((fd = open( "./banner/banner.txt", O_RDONLY)) == -1) {
        printf("FILE READ OPEN ERROR: \n");
    }
	len = read(fd, str, 1000);
	i = 0;
	while (i < 1000)
	{
		printf(FG"%dm%c",color[i % 100 % 36], str[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	ft_printf_main();
	return (1);

}