/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:07:06 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_unsigned3(t_data *mem, char *str, int res)
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

static void	ft_print_unsigned2(t_data *mem, char *str, int res)
{
	if (mem->dash)
	{
		ft_putstr_fd(str, 1);
		ft_addspace(res - (int)ft_strlen(str));
		if (mem->prec < (int)ft_strlen(str) && mem->width > (int)ft_strlen(str))
			ft_addspace(mem->prec);
		else if (mem->width > (int)ft_strlen(str))
			ft_addspace(res - mem->prec);
	}
	else if (mem->width && mem->has_prec && !mem->prec && !ft_strncmp(str, "0", 1))
		ft_addspace(res - mem->prec);
	else
		ft_print_unsigned3(mem, str, res);	
}

static void	ft_print_unsigned(t_data *mem, char *str, int res)
{
	if (mem->has_prec && !mem->prec && !ft_strncmp(str, "0", 1))
	{	
		if (mem->dash || mem->width)
			ft_addspace(mem->width);
		else
			return ;
	}
	else if (mem->dash && mem->has_prec && mem->prec)
	{
		ft_addzero(mem->prec - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
		if (mem->prec < (int)ft_strlen(str) && mem->width > (int)ft_strlen(str))
			ft_addspace(mem->width - (int)ft_strlen(str));
		else if (mem->width > (int)ft_strlen(str))
			ft_addspace(res - mem->prec);
	}
	else
		ft_print_unsigned2(mem, str, res);	
}

int	ft_unsigned(t_data *mem, va_list av)
{
	unsigned int	num;
	int				result;
	char			*str;

	num = va_arg(av, unsigned int);
	str = ft_ntoa(num, 10, DECIMAL);
	if (!str)
		return (0);
	result = ft_strlen(str);
	if (mem->width >= result && mem->width > mem->prec)
		result = mem->width;
	else if (mem->has_prec && !ft_strncmp(str, "0", 1))
		result = 0;
	if (mem->has_prec && mem->prec >= result)
		result = mem->prec;
	ft_print_unsigned(mem, str, result);
	free(str);
	return (result);
}
