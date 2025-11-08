/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:09:14 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 11:31:28 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/mac_address.h"
#include "infrastructure/net/arp_printer.h"
#include <stdio.h>

void	print_arp_packet(t_arp_packet *pkt)
{
	if (!pkt)
		return ;
	printf("ARP Packet:\n");
	printf("  Hardware Type: %u\n", pkt->header.ar_hrd);
	printf("  Protocol Type: %u\n", pkt->header.ar_pro);
	printf("  Hardware Address Length: %u\n", pkt->header.ar_hln);
	printf("  Protocol Address Length: %u\n", pkt->header.ar_pln);
	printf("  Operation: %u\n", pkt->header.ar_op);
	printf("  Source MAC: ");
	print_mac(&pkt->src_mac);
	printf("\n");
	printf("  Source IP: %u.%u.%u.%u\n", (pkt->src_ip >> 24) & 0xFF,
		(pkt->src_ip >> 16) & 0xFF, (pkt->src_ip >> 8) & 0xFF,
		pkt->src_ip & 0xFF);
	printf("  Target MAC: ");
	print_mac(&pkt->tgt_mac);
	printf("\n");
	printf("  Target IP: %u.%u.%u.%u\n", (pkt->tgt_ip >> 24) & 0xFF,
		(pkt->tgt_ip >> 16) & 0xFF, (pkt->tgt_ip >> 8) & 0xFF,
		pkt->tgt_ip & 0xFF);
}
