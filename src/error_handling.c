/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:34:27 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/18 09:39:07 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// The program must work with several numerical arguments
// ./push_swap 1 3 5 +9 20 -4 50 60 04 08

//The program also works if you receive a single character list as a parameter
//./push_swap "3 4 6 8 9 74 -56 +495"


// The program should NOT work if it encounters another character
// ./push_swap 1 3 dog 35 80 -3
// ./push_swap a
// ./push_swap 1 2 3 5 67b778 947
// .push_swap " 12 4 6 8 54fhd 4354"
// ./push_swap 1 --    45 32
// these examples should return "Error\n"


// The program should NOT work if it encounters a double number
// ./push_swap 1 3 58 9 3
// ./push_swap 3 03
// ./push_swap " 49 128     50 38   49"
// these examples should return "Error\n"
// ./push_swap "95 99 -9 10 9"
// this example should work because -9 & 9 are not equal

// The program should work with INT MAX & INT MIN
// ./push_swap 2147483647 2 4 7
// ./push_swap 99 -2147483648 23 545
// ./push_swap "2147483647 843 56544 24394"
// these examples should work and sort your list
// ./push_swap 54867543867438 3
// ./push_swap -2147483647765 4 5
// ./push_swap "214748364748385 28 47 29"
// these examples should return "Error\n"


