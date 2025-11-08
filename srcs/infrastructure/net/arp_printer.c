/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:09:14 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:42 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/ip_address.h"
#include "domain/mac_address.h"
#include "infrastructure/net/arp_printer.h"
#include <stdio.h>

void	print_arp_frame(t_arp_frame *pkt)
{
	if (!pkt)
		return ;
	printf("ARP Packet:\n");
	printf("  Hardware Type: %u\n", pkt->header_arp.ar_hrd);
	printf("  Protocol Type: %u\n", pkt->header_arp.ar_pro);
	printf("  Hardware Address Length: %u\n", pkt->header_arp.ar_hln);
	printf("  Protocol Address Length: %u\n", pkt->header_arp.ar_pln);
	printf("  Operation: %u\n", pkt->header_arp.ar_op);
	printf("  Source MAC: ");
	print_mac(&pkt->src_mac);
	printf("\n");
	printf("  Source IP: ");
	print_ip(pkt->src_ip);
	printf("\n");
	printf("  Target MAC: ");
	print_mac(&pkt->tgt_mac);
	printf("\n");
	printf("  Target IP: ");
	print_ip(pkt->tgt_ip);
	printf("\n");
}
