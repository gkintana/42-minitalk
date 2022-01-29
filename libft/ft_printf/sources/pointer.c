/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:05:21 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_pointer(t_data *mem, char *str, int res)
{
	if (mem->dash)
	{
		ft_putstr_fd(str, 1);
		ft_addspace(res - (int)ft_strlen(str));
	}
	else
	{
		ft_addspace(res - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
}

int	ft_pointer(t_data *mem, va_list av)
{
	size_t	num;
	int		result;
	char	*str;
	char	*ptr;

	num = va_arg(av, size_t);
	str = ft_ntoa(num, 16, LOWER_HEX);
	if (!str)
		return (0);
	result = ft_strlen(str) + 2;
	if (mem->width > result)
		result = mem->width;
	ptr = ft_strjoin("0x", str);
	free(str);
	ft_print_pointer(mem, ptr, result);
	free(ptr);
	return (result);
}
