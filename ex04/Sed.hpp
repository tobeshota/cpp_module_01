/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:59:54 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 22:36:01 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOUtils.hpp"
#include <fstream>	//	std::ifstream, std::ofstream

/* ファイルfilenameに含まれる文字列s1を文字列s2に置換したファイルfilename.replaceを生成する */
class Sed
{
private:
	std::string m_filename;
	std::string m_s1;	// 被置換文字列
	std::string m_s2;	// 置換文字列
	void replace_str_per_line(std::string &line);
	void replace_str(std::string &line, const size_t start_pos);
public:
	Sed(std::string filename, std::string s1, std::string s2);
};
