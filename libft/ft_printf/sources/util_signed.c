/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:06:04 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_d_hp_p(t_data *mem, char *str, int res)
{
	if (ft_strchr(str, '-'))
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
	if (mem->prec < (int)ft_strlen(str) && mem->width > (int)ft_strlen(str))
		ft_addspace(mem->width - (int)ft_strlen(str));
	else if (mem->width > (int)ft_strlen(str) && ft_strchr(str, '-'))
		ft_addspace(res - mem->prec - 1);
	else if (mem->width > (int)ft_strlen(str))
		ft_addspace(res - mem->prec);
}

void	ft_z_nd_np(t_data *mem, char *str, int res)
{
	if (ft_strchr(str, '-'))
	{
		ft_putchar_fd('-', 1);
		ft_addzero(res - (int)ft_strlen(str));
		ft_putstr_fd(str + 1, 1);
	}
	else
	{
		ft_add_flag(mem);
		if (mem->plus)
			ft_addzero(res - (int)ft_strlen(str) - 1);
		else
			ft_addzero(res - (int)ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
}

void	ft_z_hp_pgw(t_data *mem, char *str, int res)
{
	if (ft_strchr(str, '-'))
	{
		ft_putchar_fd('-', 1);
		ft_addzero(res - (int)ft_strlen(str));
		ft_putstr_fd(str + 1, 1);
	}
	else
	{
		if (mem->prec >= res)
			ft_addzero(res - (int)ft_strlen(str));
		else
			ft_addzero(res - mem->width);
		ft_putstr_fd(str, 1);
	}
}

void	ft_neg_z_hp_plw(t_data *mem, char *str, int res)
{
	if (mem->prec < (int)ft_strlen(str))
	{
		ft_addspace(res - (int)ft_strlen(str));
		ft_putchar_fd('-', 1);
	}
	else if (mem->prec > (int)ft_strlen(str))
	{
		ft_addspace(res - mem->prec - 1);
		ft_putchar_fd('-', 1);
		ft_addzero(mem->prec - (int)ft_strlen(str) + 1);
	}
	ft_putstr_fd(str + 1, 1);
}

void	ft_pos_z_hp_plw(t_data *mem, char *str, int res)
{
	if (mem->prec < (int)ft_strlen(str))
	{
		if (mem->plus)
			ft_addspace(res - (int)ft_strlen(str) - 1);
		else
			ft_addspace(res - (int)ft_strlen(str));
		ft_add_flag(mem);
	}
	else if (mem->prec > (int)ft_strlen(str))
	{
		if (mem->plus)
			ft_addspace(res - mem->prec - 1);
		else
			ft_addspace(res - mem->prec);
		ft_add_flag(mem);
		ft_addzero(mem->prec - (int)ft_strlen(str));
	}
	ft_putstr_fd(str, 1);
}
