#include "struct.h"

void ft_free_commandlist(t_cmd **cmd)
{
    t_cmd *temp;
	t_file *file;
    
    while (*cmd)
    {
		temp = (*cmd)-> next;
        t_cmd *next = temp->next;
        
        if (temp->argv)
        {
            for (int i = 0; temp->argv[i]; i++)
                ft_memfree(temp->argv[i]);
            ft_memfree(temp->argv);
        }
        file = temp->files;
        while (file)
        {
            t_file *next_file = file->next;
            ft_memfree(file->file_name);
            ft_memfree(file);
            file = next_file;
        }
        
        ft_memfree(temp->path);
        ft_memfree(temp);
        temp = next;
    }
    *cmd = NULL;
}

void	ft_free_tokenlist(t_token **token)
{
	t_token	*tmp;

	while (*token)
	{
		tmp = (*token)->next;
		ft_memfree((*token)->data);
		ft_memfree(*token);
		*token = tmp;
	}
	*token = NULL;
}
