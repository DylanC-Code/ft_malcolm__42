/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:58:03 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 14:17:58 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/log/logger.h"
#include "infrastructure/net/mac_parser.h"
#include "libft.h"
#include "shared/hex_utils.h"

static bool	is_valid_char(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || c == '*');
}

static bool	is_sep_pos(size_t i)
{
	return ((i + 1) % 3 == 0);
}

static t_mac_parse_error	valid_str_mac_address(char *mac)
{
	size_t	i;

	i = -1;
	if (!mac)
		return (INVALID_MAC_FORMAT);
	while (mac[++i])
	{
		if (i >= 17)
			return (INVALID_MAC_LENGTH);
		if (!is_sep_pos(i) && !is_valid_char(mac[i]))
			return (INVALID_MAC_CHAR);
		if (is_sep_pos(i) && mac[i] != ':')
			return (INVALID_MAC_FORMAT);
	}
	if (i != 17)
		return (INVALID_MAC_LENGTH);
	return (MAC_PARSING_SUCCESS);
}

static char	*mac_parse_strerror(t_mac_parse_error err)
{
	if (err == MAC_PARSING_SUCCESS)
		return ("mac address ok");
	else if (err == INVALID_MAC_LENGTH)
		return ("mac address invalid length (must be 17)");
	else if (err == INVALID_MAC_FORMAT)
		return ("mac address invalid format (use xx:xx:xx:xx:xx:xx)");
	else if (err == INVALID_MAC_CHAR)
		return ("mac address invalid character");
	else
		return ("mac parsing unknown error");
}

bool	parse_str_mac_address(char *src, t_mac *dst)
{
	t_mac_parse_error	parse_res;
	int					i;

	parse_res = valid_str_mac_address(src);
	if (parse_res != MAC_PARSING_SUCCESS)
	{
		log_error(mac_parse_strerror(parse_res));
		return (false);
	}
	i = -1;
	while (++i < 6)
		dst->bytes[i] = hex_pair_to_u8(src + i + i * 2);
	return (true);
}
