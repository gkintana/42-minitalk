/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 15:06:51 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_addspace(int len)
{
	int i;

	i = 0;
	while (i++ < len)
		ft_putchar_fd(' ', 1);
}

void	ft_addzero(int len)
{
	int i;

	i = 0;
	while (i++ < len)
		ft_putchar_fd('0', 1);
}

void	ft_add_flag(t_data *mem)
{
	if (mem->plus)
		ft_putchar_fd('+', 1);
	else if (mem->space)
		ft_putchar_fd(' ', 1);
	else
		return ;
}

static int	baselen(size_t n, int base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_ntoa(size_t n, int base, char *base_str)
{
	char	*str;
	int		i;

	if (!n)
		return (ft_strdup("0"));
	i = baselen(n, base);
	str = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	while (i--)
	{
		str[i] = base_str[n % base];
		n /= base;
	}
	return (str);
}
