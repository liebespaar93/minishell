int	ft_strlen(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
		temp++;
	return (temp - str);
}