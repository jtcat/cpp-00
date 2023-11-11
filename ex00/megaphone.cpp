/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:10:14 by joaoteix          #+#    #+#             */
/*   Updated: 2023/11/11 14:24:02 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i=1; i < argc; i++)
			for (int j=0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
		std::cout << std::endl;
	}
}
