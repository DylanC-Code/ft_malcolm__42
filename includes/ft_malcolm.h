/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:42:05 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:33:15 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include "core/arp_service.h"
# include "core/config_manager.h"
# include "core/config_validator.h"
# include "domain/config.h"
# include "domain/mac_address.h"
# include "infrastructure/cli/cli_config_parser.h"
# include "infrastructure/cli/cli_usage.h"
# include "infrastructure/net/mac_parser.h"
# include "infrastructure/permissions.h"
# include "infrastructure/shared.h"
# include "infrastructure/signal/signal_handler.h"

typedef enum e_exit_code
{
	SUCCESS_EXIT_CODE,
	NOT_ROOT_EXIT_CODE = 66,
	INVALID_ARGS_EXIT_CODE,
	SPOOFING_EXIT_CODE,
}	t_exit_code;

#endif
