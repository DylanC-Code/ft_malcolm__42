/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:42:03 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 17:11:33 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_PARSER_H
# define ARP_PARSER_H

# include "domain/arp/arp_packet.h"
# include <stdlib.h>

typedef enum e_arp_parser_status
{
	ARP_PARSING_SUCCESS,
}					t_arp_parser_status;

t_arp_parser_status	parse_arp_request(unsigned char *buff, size_t buff_size,
						t_arp_packet *dst);

#endif
