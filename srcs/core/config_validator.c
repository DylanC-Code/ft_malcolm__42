/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:40:40 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 11:57:02 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/config_validator.h"
#include "domain/ip_address.h"
#include "domain/mac_address.h"

char	*config_validation_strerror(t_check_config_status err)
{
	if (err == CHECK_CONFIG_SUCCESS)
		return ("Configuration is valid.");
	else if (err == CHECK_CONFIG_SAME_IP)
		return ("Source and target IP cannot be the same.");
	else if (err == CHECK_CONFIG_SAME_MAC)
		return ("Source and target MAC cannot be the same.");
	else if (err == CHECK_CONFIG_LOCAL_SRC_IP)
		return ("Source IP cannot be a local IP. (loopback, 127.*.*.*)");
	else if (err == CHECK_CONFIG_LOCAL_TGT_IP)
		return ("Target IP cannot be a local IP. (loopback, 127.*.*.*)");
	else if (err == CHECK_CONFIG_LINK_LOCAL_SRC_IP)
		return ("Source IP cannot be a link-local IP. (169.254.*.*)");
	else if (err == CHECK_CONFIG_LINK_LOCAL_TGT_IP)
		return ("Target IP cannot be a link-local IP. (169.254.*.*)");
	else if (err == CHECK_CONFIG_BROADCAST_SRC_MAC)
		return ("Source MAC cannot be a broadcast MAC. (ff:ff:ff:ff:ff:ff)");
	else if (err == CHECK_CONFIG_BROADCAST_TGT_MAC)
		return ("Target MAC cannot be a broadcast MAC. (ff:ff:ff:ff:ff:ff)");
	else if (err == CHECK_CONFIG_MULTICAST_SRC_MAC)
		return ("Source MAC cannot be a multicast MAC. (first byte LSB is 1)");
	else if (err == CHECK_CONFIG_MULTICAST_TGT_MAC)
		return ("Target MAC cannot be a multicast MAC. (first byte LSB is 1)");
	return ("Unknown configuration validation error!");
}

t_check_config_status	check_config(const t_config *conf)
{
	if (is_loopback_ip(conf->src_ip.addr.s_addr))
		return (CHECK_CONFIG_LOCAL_SRC_IP);
	if (is_link_local_ip(conf->src_ip.addr.s_addr))
		return (CHECK_CONFIG_LINK_LOCAL_SRC_IP);
	if (is_loopback_ip(conf->tgt_ip.addr.s_addr))
		return (CHECK_CONFIG_LOCAL_TGT_IP);
	if (is_link_local_ip(conf->tgt_ip.addr.s_addr))
		return (CHECK_CONFIG_LINK_LOCAL_TGT_IP);
	if (is_broadcast_mac(&conf->src_mac))
		return (CHECK_CONFIG_BROADCAST_SRC_MAC);
	if (is_broadcast_mac(&conf->tgt_mac))
		return (CHECK_CONFIG_BROADCAST_TGT_MAC);
	if (is_multicast_mac(&conf->src_mac))
		return (CHECK_CONFIG_MULTICAST_SRC_MAC);
	if (is_multicast_mac(&conf->tgt_mac))
		return (CHECK_CONFIG_MULTICAST_TGT_MAC);
	if (ip_equal(conf->src_ip.addr.s_addr, conf->tgt_ip.addr.s_addr))
		return (CHECK_CONFIG_SAME_IP);
	if (mac_equal(&conf->src_mac, &conf->tgt_mac))
		return (CHECK_CONFIG_SAME_MAC);
	return (CHECK_CONFIG_SUCCESS);
}
