/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 17:44:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NEWCLASS_HPP
# define _NEWCLASS_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <filesystem>
# include <iterator>

# define INCLUD "#include XXX"
# define IFNDEF "#ifndef  _XXX"
# define DEFINE "# define _XXX"

enum Mod {
    ALL = 1,
    CPP = 2,
    MAKE = 3,
    MAIN = 4,
    HPP = 5,
};

class NewClass {

public:

    void generateFiles(const std::string& className, int option);

private:

    void _generateHeader(const std::string& path, const std::string& filename);
    void _generateSource(const std::string& path, const std::string& filename);
    void _generateMain(const std::string& path, const std::string& filename) ;
    void _generateMakefile(const std::string& path, const std::string& filename);
    void _replaceAllOccurences(std::string& str, const std::string& from, const std::string& to);
    void _capitalizeFirstLetter(std::string& str);
    void _toUpperCase(std::string& str);
};

#endif