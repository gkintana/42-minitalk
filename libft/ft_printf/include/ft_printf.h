/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 16:54:18 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*------------------------------- DEFINITIONS -------------------------------*/
# define FLAGS			"-0# +"
# define PRECISION		"."
# define DECIMAL		"0123456789"
# define LOWER_HEX		"0123456789abcdef"
# define UPPER_HEX		"0123456789ABCDEF"

/*-------------------------------- LIBRARIES --------------------------------*/
# include "../../include/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*---------------------------- PROGRAM STRUCTURE ----------------------------*/
typedef struct s_data
{
	const char	*data;
	int			i;
	int			result;
	int			width;
	int			has_prec;
	int			prec;
	int			dash;
	int			zero;
	int			space;
	int			plus;
}				t_data;

/*--------------------------- FUNCTION PROTOTYPES ---------------------------*/
int		ft_printf(const char *format, ...);
int		ft_parse_format(va_list av, const char *format);
int		ft_formspec(t_data *mem, va_list av);

int		ft_character(t_data *mem, va_list av);
int		ft_string(t_data *mem, va_list av);
int		ft_signed(t_data *mem, va_list av);
int		ft_unsigned(t_data *mem, va_list av);
int		ft_hexadecimal(t_data *mem, va_list av);
int		ft_pointer(t_data *mem, va_list av);

t_data	*ft_init_data(const char *format);
void	ft_reset_data(t_data *mem);

void	ft_addspace(int len);
void	ft_addzero(int len);
void	ft_add_flag(t_data *mem);
char	*ft_ntoa(size_t n, int base, char *base_str);

void	ft_d_hp_p(t_data *mem, char *str, int res);
void	ft_z_nd_np(t_data *mem, char *str, int res);
void	ft_z_hp_pgw(t_data *mem, char *str, int res);
void	ft_neg_z_hp_plw(t_data *mem, char *str, int res);
void	ft_pos_z_hp_plw(t_data *mem, char *str, int res);

#endif
