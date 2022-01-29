/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:06:01 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_char(t_data *mem, int result, int chr)
{
	if (mem->dash)
	{
		ft_putchar_fd(chr, 1);
		ft_addspace(result - 1);
	}
	else
	{
		ft_addspace(result - 1);
		ft_putchar_fd(chr, 1);
	}
}

int	ft_character(t_data *mem, va_list av)
{
	int	chr;
	int	result;

	chr = va_arg(av, int);
	result = 1;
	if (mem->width > result)
		result = mem->width;
	ft_print_char(mem, result, chr);
	return (result);
}
