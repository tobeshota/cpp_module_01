/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:03:54 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 22:36:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#define FILE_OPEN_ERRMSG "ft_sed: " + Sed::m_filename + ": failed to open"
#define OUTFILE_NAME Sed::m_filename + ".replace"


void Sed::replace_str(std::string &line, const size_t start_pos)
{
	line.erase(start_pos, Sed::m_s1.length());
	line.insert(start_pos, Sed::m_s2);
}

// 文字列line内のs1をs2に置換する
void Sed::replace_str_per_line(std::string &line)
{
	size_t	start_pos;

	start_pos = 0;
	while (true)
	{
		start_pos = line.find(Sed::m_s1, start_pos);
		if (start_pos == std::string::npos)
			break ;
		Sed::replace_str(line, start_pos);
		start_pos += Sed::m_s2.length();
	}
}

Sed::Sed(std::string filename, std::string s1, std::string s2) : m_filename(filename), m_s1(s1), m_s2(s2)
{
	// 入力ファイルを開く
	std::ifstream infile(m_filename);
	if (infile.is_open() == false)
		IOUtils::exit_with_msg(FILE_OPEN_ERRMSG, IOUtils::ERROR);
	// 出力ファイルを開く
	std::ofstream outfile(OUTFILE_NAME);
	if (outfile.is_open() == false)
		IOUtils::exit_with_msg(FILE_OPEN_ERRMSG, IOUtils::ERROR);
	// 1行ずつ見ていく
	std::string line;
	while (std::getline(infile, line))
	{
		replace_str_per_line(line);
		outfile << line << std::endl;
	}
	// ファイルを閉じる
	infile.close();
	outfile.close();
}
