/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:05:16 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_hex2(t_data *mem, char *str, int res)
{
	if (mem->width && mem->has_prec && mem->prec < mem->width)
	{
		if (mem->prec > (int)ft_strlen(str))
			ft_addspace(res - mem->prec);
		else
			ft_addspace(res - (int)ft_strlen(str));
		ft_addzero(mem->prec - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
	else
	{
		if (mem->zero || mem->has_prec)
			ft_addzero(res - (int)ft_strlen(str));
		else
			ft_addspace(res - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
}

static void	ft_print_hex(t_data *mem, char *str, int res)
{
	if (mem->has_prec && !mem->prec && !ft_strncmp(str, "0", 1))
	{	
		if (mem->width)
			ft_addspace(mem->width);
		else
			return ;
	}
	else if (mem->dash && mem->has_prec && mem->prec)
	{
		ft_addzero(mem->prec - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
		if (mem->prec < (int)ft_strlen(str) && mem->width > (int)ft_strlen(str))
			ft_addspace(res - (int)ft_strlen(str));
		else if (mem->width > (int)ft_strlen(str))
			ft_addspace(res - mem->prec);
	}
	else if (mem->dash)
	{
		ft_putstr_fd(str, 1);
		ft_addspace(res - (int)ft_strlen(str));
	}
	else
		ft_print_hex2(mem, str, res);
}

static int	ft_print_hashhex(t_data *mem, char *str)
{
	int		result;
	char	*hash;

	if (mem->data[mem->i] == 'x')
		hash = ft_strjoin("0x", str);
	else
		hash = ft_strjoin("0X", str);
	if (ft_strlen(hash) <= 3
		&& (!ft_strncmp(hash, "0x0", 3) || !ft_strncmp(hash, "0X0", 3)))
	{
		free(hash);
		free(str);
		ft_putchar_fd('0', 1);
		return (1);
	}
	free(str);
	result = ft_strlen(hash);
	if (mem->width > result)
		result = mem->width;
	ft_print_hex(mem, hash, result);
	free(hash);
	return (result);
}

int	ft_hexadecimal(t_data *mem, va_list av)
{
	unsigned int	num;
	int				result;
	char			*str;

	num = va_arg(av, unsigned int);
	if (mem->data[mem->i] == 'x')
		str = ft_ntoa(num, 16, LOWER_HEX);
	else
		str = ft_ntoa(num, 16, UPPER_HEX);
	if (!str)
		return (0);
	if (mem->data[mem->i - 1] == '#')
		return (ft_print_hashhex(mem, str));
	result = ft_strlen(str);
	if (mem->width >= result && mem->width > mem->prec)
		result = mem->width;
	else if (mem->has_prec && mem->prec >= result)
		result = mem->prec;
	else if (mem->has_prec && !ft_strncmp(str, "0", 1))
		result = 0;
	ft_print_hex(mem, str, result);
	free(str);
	return (result);
}
