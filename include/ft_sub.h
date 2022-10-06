

#ifndef FT_SRC_H
# define FT_SRC_H
# include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_malloc(void **ptr, size_t size);
char	*ft_strdup(const char* str);
#endif