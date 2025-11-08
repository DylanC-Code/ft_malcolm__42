/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:42:03 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 11:10:19 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_PARSER_H
# define ARP_PARSER_H

# include "domain/arp/arp_packet.h"
# include <stdbool.h>
# include <stdlib.h>

typedef enum e_arp_parser_status
{
	ARP_PARSING_SUCCESS,
	ARP_REQUEST_TOO_SHORT,
	ARP_INVALID_LENGTHS,
	ARP_INVALID_IP,
	ARP_INVALID_MAC,
}		t_arp_parser_status;

bool	parse_arp_request(unsigned char *buff, size_t buff_size,
			t_arp_packet *dst);

#endif
