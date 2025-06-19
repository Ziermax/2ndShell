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

void	*add_array(void *array, void *to_add)
{
	void	**new_array;
	void	**old_array;
	int		len1;
	int		len2;
	int		i;

	if (!array || !to_add)
		return (free_array(array), NULL);
	len1 = ft_arraylen(array);
	len2 = ft_arraylen(to_add);
	new_array = malloc(sizeof(void *) * (len1 + len2 + 1));
	if (!new_array)
		return (free_array(array), NULL);
	old_array = array;
	i = -1;
	while (old_array[++i])
		new_array[i] = old_array[i];
	old_array = to_add;
	i = -1;
	while (old_array[++i])
		new_array[len1 + i] = old_array[i];
	new_array[len1 + len2] = NULL;
	return (free(array), free(to_add), new_array);
}

void	*add_array_to_array(void *array, void *to_add, void *position)
{
	void	**new_array;
	int		len[2];
	int		idx[3];

	if (!to_add)
		return (array);
	len[0] = ft_arraylen(array);
	len[1] = ft_arraylen(to_add);
	new_array = malloc(sizeof(void *) * (len[0] + len[1] + 1));
	if (!new_array)
		return (free_array(array), NULL);
	ft_bzero(idx, sizeof(int) * 3);
	while (J[idx] < len[0])
	{
		new_array[I[idx]++] = ((void **)array)[J[idx]];
		if (((void **)array)[J[idx]++] == position)
			break ;
	}
	while (K[idx] < len[1])
		new_array[I[idx]++] = ((void **)to_add)[K[idx]++];
	while (J[idx] < len[0])
		new_array[I[idx]++] = ((void **)array)[J[idx]++];
	new_array[I[idx]] = NULL;
	return (free(array), new_array);
}
