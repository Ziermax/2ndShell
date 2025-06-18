#include <stdlib.h>
#include "libft.h"

int	ft_arraylen(void *array)
{
	void	**aux;
	int		len;

	if (!array)
		return (0);
	aux = array;
	len = 0;
	while (aux[len])
		++len;
	return (len);
}

void	*add_dir(void *array, void *dir)
{
	void	**new_array;
	void	**old_array;
	int		len;
	int		i;

	if (!dir)
		return (array);
	old_array = array;
	len = ft_arraylen(old_array);
	new_array = malloc(sizeof(void *) * (len + 2));
	if (!new_array)
		return (free_array(array), NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = old_array[i];
		i++;
	}
	new_array[i] = dir;
	new_array[i + 1] = NULL;
	free(old_array);
	return (new_array);
}
