#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"hello", "this", "is", "test", NULL};
	int		i;

	for (i = 0; strs[i]; i++)
		printf("[%2d]%s\n", i, strs[i]);
	ft_strssort(strs, ft_strcmp);
	printf("After strssort\n");
	for (i = 0; strs[i]; i++)
		printf("[%2d]%s\n", i, strs[i]);
	return (0);
}
