/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:05:23 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_signed4(t_data *mem, char *str, int res)
{
	if (mem->width)
	{
		if (mem->plus)
			ft_addspace(res - (int)ft_strlen(str) - 1);
		else
			ft_addspace(res - (int)ft_strlen(str));
		ft_add_flag(mem);
		ft_putstr_fd(str, 1);
	}
	else if (mem->space)
	{
		ft_addspace(res - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
	else if (mem->plus && !ft_strchr(str, '-'))
	{
		ft_add_flag(mem);
		ft_addspace(res - (int)ft_strlen(str) - 1);
		ft_putstr_fd(str, 1);
	}
	else
		ft_putstr_fd(str, 1);
}

static void	ft_print_signed3(t_data *mem, char *str, int res)
{
	if (mem->has_prec)
	{
		if (!mem->prec && !ft_strncmp(str, "0", 1))
			return ;
		else if (ft_strchr(str, '-'))
		{
			ft_putchar_fd('-', 1);
			ft_addzero(mem->prec - (int)ft_strlen(str) + 1);
			ft_putstr_fd(str + 1, 1);
		}
		else
		{
			ft_addzero(mem->prec - (int)ft_strlen(str));
			ft_putstr_fd(str, 1);
		}
	}
	else
		ft_print_signed4(mem, str, res);
}

static void	ft_print_signed2(t_data *mem, char *str, int res)
{
	if (mem->zero && !mem->prec && !ft_strncmp(str, "0", 1))
	{
		if (mem->width == 1 && !mem->has_prec)
			ft_putchar_fd('0', 1);
		else if (mem->width && !mem->has_prec && !ft_strncmp(str, "0", 1))
			ft_addzero(mem->width);
		else if (mem->width)
			ft_addspace(mem->width);
	}
	else if (mem->zero && !mem->dash && !mem->has_prec)
		ft_z_nd_np(mem, str, res);
	else if (mem->zero && mem->has_prec && mem->prec > mem->width)
		ft_z_hp_pgw(mem, str, res);
	else if (mem->zero && mem->has_prec && mem->prec < mem->width)
	{	
		if (ft_strchr(str, '-'))
			ft_neg_z_hp_plw(mem, str, res);
		else
			ft_pos_z_hp_plw(mem, str, res);
	}
	else
		ft_print_signed3(mem, str, res);
}

static void	ft_print_signed(t_data *mem, char *str, int res)
{
	if (mem->dash && mem->width && mem->has_prec && !mem->prec)
	{
		if (!ft_strncmp(str, "0", 1))
			ft_putchar_fd(' ', 1);
		else
			ft_putstr_fd(str, 1);
		ft_addspace(res - (int)ft_strlen(str));
	}
	else if (mem->dash && mem->has_prec && mem->prec)
		ft_d_hp_p(mem, str, res);
	else if (mem->dash)
	{
		if (mem->has_prec && !mem->prec)
			return ;
		ft_add_flag(mem);
		ft_putstr_fd(str, 1);
		if (mem->space || mem->plus)
			ft_addspace(res - (int)ft_strlen(str) - 1);
		else
			ft_addspace(res - (int)ft_strlen(str));
	}
	else
		ft_print_signed2(mem, str, res);
}

int	ft_signed(t_data *mem, va_list av)
{
	long	num;
	int		result;
	char	*str;

	num = va_arg(av, long);
	str = ft_itoa(num);
	if (!str)
		return (0);
	result = ft_strlen(str);
	if (mem->width >= result && mem->width > mem->prec)
		result = mem->width;
	else if (ft_strchr(str, '-') && mem->has_prec && mem->prec >= result)
		result = mem->prec + 1;
	else if (mem->has_prec && mem->prec > result)
		result = mem->prec;
	else if (mem->has_prec && !mem->prec && !ft_strncmp(str, "0", 1))
		result = 0;
	else if (!ft_strchr(str, '-') && (mem->space || mem->plus))
		result++;
	ft_print_signed(mem, str, result);
	free(str);
	return (result);
}
