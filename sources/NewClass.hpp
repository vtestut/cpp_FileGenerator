/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/28 19:52:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWCLASS_HPP
# define NEWCLASS_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <filesystem>
# include <iterator>

# define INCLUD "#include XXX"
# define IFNDEF "#ifndef XXX"
# define DEFINE "# define XXX"

enum Mod {
    ALL = 1,
    SRC = 2,
    MAKE = 3,
    MAIN = 4,
    HEADR = 5,
    ERR = 6
};

class NewClass {

public:

    void generateFiles(const std::string& className, int mod);

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