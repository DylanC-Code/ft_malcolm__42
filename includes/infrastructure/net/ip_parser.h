/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:43:23 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 10:51:19 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IP_PARSER_H
# define IP_PARSER_H

# include "domain/ip_address.h"
# include <stdbool.h>

bool	parse_str_ip_address(char *src, t_ip *dst);

#endif