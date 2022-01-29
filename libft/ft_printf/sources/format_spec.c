/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:05:10 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_formspec(t_data *mem, va_list av)
{
	if (mem->data[mem->i] == 'c')
		return (ft_character(mem, av));
	if (mem->data[mem->i] == 's')
		return (ft_string(mem, av));
	if (mem->data[mem->i] == 'p')
		return (ft_pointer(mem, av));
	if (mem->data[mem->i] == 'd' || mem->data[mem->i] == 'i')
		return (ft_signed(mem, av));
	if (mem->data[mem->i] == 'u')
		return (ft_unsigned(mem, av));
	if (mem->data[mem->i] == 'x' || mem->data[mem->i] == 'X')
		return (ft_hexadecimal(mem, av));
	if (mem->data[mem->i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
