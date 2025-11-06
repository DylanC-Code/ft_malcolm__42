/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:42:05 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 21:38:29 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOM_H
#define FT_MALCOM_H

typedef enum e_exit_code
{
    SUCCESS_CODE,
    NOT_ROOT_ERR_CODE = 66,
    PARSING_CONFIG_ERR_CODE,
    INVALID_CONFIG_ERR_CODE,
    SPOOFING_ERR_CODE,

} t_exit_code;

// #include <stdlib.h>

#include "domain/mac.h"
#include "domain/config.h"

#include "infrastructure/shared.h"
#include "infrastructure/permissions.h"
#include "infrastructure/cli/cli_config_parser.h"
#include "infrastructure/net/mac_parser.h"

#include "core/arp_service.h"

#endif