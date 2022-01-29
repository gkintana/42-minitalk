/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:05:25 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_str2(t_data *mem, char *str, int len)
{
	int i;

	i = 0;
	if (mem->width)
	{
		if (mem->dash)
			ft_putstr_fd(str, 1);
		ft_addspace(mem->width - len);
		if (!mem ->dash)
			ft_putstr_fd(str, 1);
	}
	else if (mem->has_prec && len > mem->prec)
	{
		if (!mem->prec)
			return ;
		else if (len > mem->prec)
		{
			while (i < mem->prec)
				ft_putchar_fd(str[i++], 1);
		}
	}
	else
		ft_putstr_fd(str, 1);
}

static void	ft_print_str(t_data *mem, char *str, int len)
{
	int i;

	i = 0;
	if (mem->width && mem->has_prec)
	{
		if (mem->width > mem->prec)
		{
			if (!mem->dash && mem->width - mem->prec > len)
				ft_addspace(mem->width - mem->prec);
			while (i < mem->prec && i < len)
				ft_putchar_fd(str[i++], 1);
			if (mem->width - mem->prec <= len)
				ft_addspace(mem->width - mem->prec);
		}
		else
		{
			while (i < mem->prec && i < len)
				ft_putchar_fd(str[i++], 1);
			ft_addspace(mem->prec - mem->width + 1);
		}
	}
	else
		ft_print_str2(mem, str, len);
}

static char	*ft_check_str(va_list av, t_data *mem)
{
	char	*str;

	str = va_arg(av, char *);
	if (!str)
	{
		free(str);
		if ((!mem->width && !mem->has_prec && !mem->prec)
		|| (mem->width && !mem->has_prec && !mem->prec)
		|| (!mem->width && mem->has_prec && mem->prec >= 6))
			return ("(null)");
		else
			return (NULL);
	}
	else
		return (str);
}

int	ft_string(t_data *mem, va_list av)
{
	char	*str;
	int		result;

	str = ft_check_str(av, mem);
	if (!str)
		return (0);
	result = ft_strlen(str);
	if (mem->width > result)
		result = mem->width;
	else if (mem->width && mem->has_prec && mem->prec > result)
		result = mem->prec;
	else if (mem->has_prec && !mem->prec && result)
		result = 0;
	else if (mem->has_prec && mem->prec < result)
		result = mem->prec;
	ft_print_str(mem, str, ft_strlen(str));
	return (result);
}
