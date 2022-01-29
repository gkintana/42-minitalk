/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:07:17 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_data	*ft_init_data(const char *format)
{
	t_data	*mem;

	mem = malloc(sizeof(t_data));
	if (!mem)
		return (NULL);
	mem->data = format;
	mem->i = 0;
	mem->result = 0;
	mem->width = 0;
	mem->has_prec = 0;
	mem->prec = 0;
	mem->dash = 0;
	mem->zero = 0;
	mem->space = 0;
	mem->plus = 0;
	return (mem);
}

void	ft_reset_data(t_data *mem)
{
	mem->dash = 0;
	mem->zero = 0;
	mem->space = 0;
	mem->plus = 0;
	mem->width = 0;
	mem->has_prec = 0;
	mem->prec = 0;
}
