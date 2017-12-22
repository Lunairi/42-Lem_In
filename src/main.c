/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	parse_input(char *str)
{
	/*
	** parse shit here
	*/
}

/*
** Idea is to use GNL to take the input and store it into output
** However, if we parse the information while in GNL we may not need
** output, but for now we will leave until we decide if we should have
** a backup string of the input (aka output), or if we parse everything
** from input in GNL first and we don't need output
*/
int		main(void)
{
	char	*input;
	char	*output;

	output = ft_memalloc(sizeof(char));
	while (get_next_line(0, &input))
	{
		output = ft_strjoinfree(output, input);
		output = ft_strjoinfree(output, ft_strdup("\n"));
		parse_input(input);
	}
	printf("%s", output);
	return (0);
}