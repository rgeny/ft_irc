/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_server_name.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/27 20:36:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"
# include <iostream>

void	print_server_name(void)
{
	std::cout		<<	BOLD MAGENTA
					<<	"__  __       _ _         ____					\n"               
					<<	"|  \\/  |     (_|_)       |  _ \\              \n"
					<<	"| \\  / | __ _ _ _ _ __   | |_) | ___   ___    \n"
					<<	"| |\\/| |/ _` | | | '_ \\  |  _ < / _ \\ / _ \\\n"  
					<<	"| |  | | (_| | | | | | | | |_) | (_) | (_) |   	(｡◝‿◜｡)\n"
					<<	"|_|  |_|\\__,_| |_|_| |_| |____/ \\___/ \\___/ \n" 
					<<	"            _/ |                               \n"
					<<	"            |__/                               \n"
					<< RESET
					<< std::endl;

	std::cout		<<	BOLD MAGENTA
					<< "                                   ⢀⡠⠒⠉⠉⢲⡄                          \n"
					<< "               ⠀⠀⠀⡠⠔⠒⠐⣦     ⠀⠀⠀⢠⠎⠀⠀⠀⡞⣹⡇                          \n"
					<< "               ⠀⠀⢾⠦⠠⢴⣋⢉⡇⠀⠀⠀⡠⠖⠊⠉⠀⠀⠀⠰⠓⢯⡀                          \n"
					<< "               ⠀⠀⢰     ⣶⢀⣠⣤⠊          ⠑⠐⠘⡄                         \n"
					<< "               ⠀⠀⢸⠒⠒⠂⢤⠿⡮⠃⠀⠀⠀⢀⡀⣔⡄⢀⡀     ⣾                         \n"
					<< "               ⠀⠀⠈⠆⠀⠀⠘⣄⡱⠃⠀⠛⠛⠛⠿⡉⠀⠈⢽⣶⣄⡀⠀⠛⡒⡄                       \n"
					<< "               ⠀⠀⠀⢎⠀⠀⠀⠙⢱     ⠀⠀⡏⠑⡸⠀⠉⠉⠉⠀⢀⢃⠇⢀⡀                     \n"
					<< "               ⠀⠀⢀⡨⢦⠀⢰⢸⡞⣦⡀     ⢡⡔⠁     ⠀⢈⡇⡞⠁⠈⠓⡄                  \n"
					<< "               ⡠⠔⠉⠀⡼⠯⠽⣛⡑⣝⠛⠦⣄⡀⠀⠈     ⠀⢀⣠⣾⢳⠁⠀⠀⠸⠏⢢⡀                \n"
					<< "          ⠀⣠⠔⠋     ⣿⣦⡈⠉⠁⢸⡏⢑⡾⢿⡟⢶⣶⣶⣶⣶⠟⢛⡯⣷⠋⠛⢶⠞⠂⠀⣀⡟                \n"
					<< "     ⠀⠀⠀⡠⠞⠁     ⠀⣠⢇⠈⠻⢷⣶⢷⣔⣁⣎⠝⠚⢟⠢⡈⢻⣩⢿⠫⠶⢻⣶⣀⠈⢶⡒⠋⠁⡚               \n"
					<< "     ⠀⡠⠊     ⠀⡠⠚⠉⢈⣪⡓⢤⡀⠀⠈⠁     ⠀⠑⢤⡀⣧⣣⣀⣀⣀⣈⣿⡗⠒⡖⢖⠊                 \n"
					<< "⠀⠀⠀⢠⠎     ⠀⠀⢸⠁⢠⠐⡱⠊⠙⠢⡈⠑⠢⣄     ⠀⠀⠀⠈⠃⠉⠙⠛⠋⠉⣻⡇⠀⠘⣎⠣⡀               \n"
					<< "⠀⠀⠀⡮⠴⠒⠓⠲⣄⠀⠀⢸⠀⠘⠀⠁⠀⠀⠀⡨⠦⡞⢁⢹⣖⠲⣂⠤⢤⠤⠤⠤⠤⠰⣖⣒⠭⢾⡉⢢⠀⠈⢆⠙⢄              \n"
					<< "          ⠘⢆⠀⠐⢆⢰⠀⠸⠀⠀⠰⢁⡔⠙⢿⣛⡹⠏⣯⣄⣠⣤⠤⠒⡍⢏     ⢳⠀⡇⠀⠈⢇⠀⢳              \n"
					<< "          ⠀⠈⠣⡀⠀⢙⣦⣇⠀⠀⠀⠈⠀⠀⠀⠈⠈⠉⠉⠀⢡⠈⡄⠀⢘⠈     ⣸⠀⡇⠀⠀⢹⠀⠈⡇            \n"
					<< "          ⠀⠀⠀⠈⡻⢻⡀⠈⢲⣄⡀⡇          ⠘     ⠀⠀⡼⠀⠀⣏⡰⠁⣀⠔⣺⠀⠠⡇            \n"
					<< "          ⠀⠀⠀⡠⢣⡀⠉⢉⡩⠇⠈⠡⣄⣀⠀⠀⠀⢮⡦⡀⠀⠀⢀⠀⠀⡠⢂⠇⣠⠞⠛⠒⠊⠁⢀⠏⣠⠞              \n"
					<< "          ⠀⠀⣜⣀⣀⣈⣠⠎     ⠀⠀⠉⠒⠒⠒⠛⠚⠒⠒⠓⢲⠚⠳⠭⢭⠇     ⠰⠟⠊⠁              \n"
					<< "          ⠀⠀⠈⠉⠁                    ⠀⠀⣎⠓⠒⠒⠊⠒⢄                        \n"
					<< "                                        ⠉⠉⠑⠒⠒⠚                       \n"
					<< RESET
					<< std::endl;
}


