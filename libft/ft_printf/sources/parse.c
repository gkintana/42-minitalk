/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:05:18 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_flags(t_data *mem)
{
	if (mem->data[mem->i] == '-')
		mem->dash = 1;
	if (mem->data[mem->i] == '0')
		mem->zero = 1;
	if (mem->data[mem->i] == ' ')
		mem->space = 1;
	if (mem->data[mem->i] == '+')
		mem->plus = 1;
	mem->i++;
}

static void	ft_width(t_data *mem)
{
	while (ft_isdigit(mem->data[mem->i]))
	{
		mem->width *= 10;
		mem->width += mem->data[mem->i] - 48;
		mem->i++;
	}
}

static void	ft_prec(t_data *mem)
{
	mem->has_prec = 1;
	mem->i++;
	while (ft_isdigit(mem->data[mem->i]))
	{
		mem->prec *= 10;
		mem->prec += mem->data[mem->i] - 48;
		mem->i++;
	}
}

static void	ft_after_percent(t_data *mem)
{
	ft_reset_data(mem);
	mem->i++;
	while (ft_strchr(FLAGS, mem->data[mem->i]))
		ft_flags(mem);
	if (ft_strchr(DECIMAL, mem->data[mem->i]))
		ft_width(mem);
	if (ft_strchr(PRECISION, mem->data[mem->i]))
		ft_prec(mem);
}

int	ft_parse_format(va_list av, const char *format)
{
	int		result;
	t_data	*mem;

	mem = ft_init_data(format);
	if (!mem)
		return (0);
	while (format[mem->i] != '\0')
	{
		if (format[mem->i] == '%')
		{
			ft_after_percent(mem);
			mem->result += ft_formspec(mem, av);
		}
		else
			mem->result += write(1, &format[mem->i], 1);
		mem->i++;
	}
	result = mem->result;
	free(mem);
	return (result);
}
