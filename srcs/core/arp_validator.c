/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:51:53 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 12:03:41 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_validator.h"
#include "domain/ip_address.h"
#include "domain/mac_address.h"

char	*arp_packet_validation_strerror(t_arp_packet_status err)
{
	if (err == ARP_PACKET_VALID)
		return ("ARP packet is valid");
	else if (err == ARP_PACKET_UNSUPPORTED_OPERATION)
		return ("ARP packet is unsupported operation");
	else if (err == ARP_PACKET_INVALID_SRC_MAC)
		return ("ARP packet has invalid source MAC address");
	else if (err == ARP_PACKET_INVALID_TGT_MAC)
		return ("ARP packet has invalid target MAC address");
	else if (err == ARP_PACKET_INVALID_SRC_IP)
		return ("ARP packet has invalid source IP address");
	else if (err == ARP_PACKET_INVALID_TGT_IP)
		return ("ARP packet has invalid target IP address");
	return ("Unknown ARP packet validation error");
}

t_arp_packet_status	validate_arp_packet(const t_arp_packet *pkt,
		const t_config *config)
{
	const t_mac	broadcast_mac = {.bytes = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}};

	if (pkt->header.ar_op != ARPOP_REQUEST)
		return (ARP_PACKET_UNSUPPORTED_OPERATION);
	if (!mac_equal(&pkt->tgt_mac, &broadcast_mac))
		return (ARP_PACKET_INVALID_TGT_MAC);
	if (!mac_equal(&config->src_mac, &pkt->src_mac))
		return (ARP_PACKET_INVALID_SRC_MAC);
	if (!ip_equal(pkt->src_ip, config->tgt_ip.s_addr))
		return (ARP_PACKET_INVALID_SRC_IP);
	if (!ip_equal(pkt->tgt_ip, config->src_ip.s_addr))
		return (ARP_PACKET_INVALID_TGT_IP);
	return (ARP_PACKET_VALID);
}
