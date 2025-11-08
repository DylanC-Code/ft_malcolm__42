/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:51:53 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:59 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_validator.h"
#include "domain/ip_address.h"
#include "domain/mac_address.h"

char	*arp_frame_validation_strerror(t_arp_frame_status err)
{
	if (err == ARP_FRAME_VALID)
		return ("ARP packet is valid");
	else if (err == ARP_FRAME_UNSUPPORTED_OPERATION)
		return ("ARP packet is unsupported operation");
	else if (err == ARP_FRAME_INVALID_SRC_MAC)
		return ("ARP packet has invalid source MAC address");
	else if (err == ARP_FRAME_INVALID_TGT_MAC)
		return ("ARP packet has invalid target MAC address");
	else if (err == ARP_FRAME_INVALID_SRC_IP)
		return ("ARP packet has invalid source IP address");
	else if (err == ARP_FRAME_INVALID_TGT_IP)
		return ("ARP packet has invalid target IP address");
	return ("Unknown ARP packet validation error");
}

t_arp_frame_status	validate_arp_frame(const t_arp_frame *pkt,
		const t_config *config)
{
	const t_mac	broadcast_mac = {.bytes = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

	if (pkt->header_arp.ar_op != ARPOP_REQUEST)
		return (ARP_FRAME_UNSUPPORTED_OPERATION);
	if (!mac_equal(&pkt->tgt_mac, &broadcast_mac))
		return (ARP_FRAME_INVALID_TGT_MAC);
	if (!mac_equal(&pkt->src_mac, &config->tgt_mac))
		return (ARP_FRAME_INVALID_SRC_MAC);
	if (!ip_equal(pkt->src_ip, config->tgt_ip.s_addr))
		return (ARP_FRAME_INVALID_SRC_IP);
	if (!ip_equal(pkt->tgt_ip, config->src_ip.s_addr))
		return (ARP_FRAME_INVALID_TGT_IP);
	return (ARP_FRAME_VALID);
}
