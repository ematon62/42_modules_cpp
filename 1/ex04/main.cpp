/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/11 16:11:25 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	s1_to_s2(std::string content,
					std::string &s1, std::string &s2)
{
	size_t		last_pos;
	size_t		next_pos;
	std::string	new_cont;
	
	last_pos = 0;
	while ((next_pos = content.find(s1, last_pos)) != std::string::npos)
	{
		new_cont.append(content.substr(last_pos, next_pos - last_pos) + s2);
		last_pos = next_pos + s1.size();
	}
	new_cont.append(content.substr(last_pos, content.size()));
	return (new_cont);
}

std::string	get_replaced_text(std::ifstream &basefile,
							std::string &s1, std::string &s2)
{
	std::string	line;
	std::string	base_content;

	while (std::getline(basefile, line))
		base_content.append(line + "\n");

	return (s1_to_s2(base_content, s1, s2));
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "losers: [filename] [string1] [string2]\n";
		return (1);
	}
	else if (!argv[2][0])
	{
		std::cerr << "losers: Empty string exists in all substrings\n";
		return (1);
	}

	std::string		filename(argv[1]);
	std::string		new_filename = filename.append(".replace");
	std::ifstream	basefile(argv[1]);
	if (!basefile.good())
	{
		std::perror("open");
		return (1);
	}
	std::ofstream	newfile(new_filename.c_str());
	if (!newfile.good())
	{
		std::perror("open");
		return (1);
	}
	std::string 	s1(argv[2]);
	std::string 	s2(argv[3]);
	newfile << get_replaced_text(basefile, s1, s2);
	return (0);
}
