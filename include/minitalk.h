/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:08:22 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 17:17:21 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*------------------------------- TEXT COLOR -------------------------------*/
# define DEFAULT		"\033[0m"
# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define BLUE			"\033[0;34m"

/*--------------------------------- CLIENT ---------------------------------*/
# define MTC_BOOT_OK	"Minitalk Client Initialization Successful"
# define MTC_BOOT_KO1	"Minitalk Client Initialized with Missing Arguments"
# define MTC_BOOT_KO2	"Minitalk Client Initialized with Extra Arguments"
# define MTC_PID_OK		"Established Connection with Minitalk Server"
# define MTC_PID_KO		"Unable to Establish Connection with Minitalk Server"
# define MTC_ARGS_KO	"Expected ./client [Server Process ID] [String]"
# define MTC_ARGS_INC	"Incorrect Arguments Passed to Minitalk Client"
# define MTC_UPLOAD		"Uploading Data to Minitalk Server"
# define MTC_SENT		"Minitalk Client Sent: %d bytes"
# define MTC_RECEIVED	"Minitalk Server Received: %d bytes"
# define MTC_TERM		"Minitalk Client Terminated"
# define MIN_PID		100
# define MAX_PID		99999

/*--------------------------------- SERVER ---------------------------------*/
# define MTS_BOOT		"Minitalk Server Initialization Successful"
# define MTS_SPID		"Server Process ID: %d"
# define MTS_AMCI		"Awaiting Minitalk Client Instructions"

# include "../libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <signal.h>

#endif
