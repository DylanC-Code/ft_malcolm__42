/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:40:52 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:46:25 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_VALIDATOR_H
# define CONFIG_VALIDATOR_H

# include "domain/config.h"

typedef enum e_check_config_status
{
	CHECK_CONFIG_SUCCESS,
	CHECK_CONFIG_SAME_IP,
	CHECK_CONFIG_SAME_MAC,
	CHECK_CONFIG_LOCAL_SRC_IP,
	CHECK_CONFIG_LOCAL_TGT_IP,
	CHECK_CONFIG_LINK_LOCAL_SRC_IP,
	CHECK_CONFIG_LINK_LOCAL_TGT_IP,
	CHECK_CONFIG_BROADCAST_SRC_MAC,
	CHECK_CONFIG_BROADCAST_TGT_MAC,
	CHECK_CONFIG_MULTICAST_SRC_MAC,
	CHECK_CONFIG_MULTICAST_TGT_MAC,
}						t_check_config_status;

t_check_config_status	check_config(const t_config *conf) __attribute__((nonnull));
char					*config_validation_strerror(t_check_config_status err);

#endif
