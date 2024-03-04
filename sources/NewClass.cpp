/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:51:48 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 17:43:54 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

void NewClass::generateFiles(const std::string& className, int option) {
	std::string headerPath = "./templates/header.txt";
	std::string sourcePath = "./templates/source.txt";
	std::string makefilePath = "./templates/makefile.txt";
	std::string mainPath = "./templates/main.txt";
	std::string nameCopie = className;
	
	if (!std::filesystem::exists("output")) {
		if (!std::filesystem::create_directory("output")) {
			std::cerr << "Error: Unable to create directory 'output'" << std::endl;
			return;
		}
	} if (!std::filesystem::exists(headerPath)) {
		std::cerr << "Error: '" << headerPath << "' does not exist" << std::endl;
		return;
	} if (!std::filesystem::exists(sourcePath)) {
		std::cerr << "Error: '" << sourcePath << "' does not exist" << std::endl;
		return;
	} if (!std::filesystem::exists(makefilePath)) {
		std::cerr << "Error: '" << makefilePath << "' does not exist" << std::endl;
		return;
	} if (!std::filesystem::exists(mainPath)) {
		std::cerr << "Error: '" << mainPath << "' does not exist" << std::endl;
		return;
	} 
	
	_capitalizeFirstLetter(nameCopie);
	
	const std::string& nameConst = nameCopie;

	switch(option) {
    case ALL:
        _generateHeader(headerPath, nameConst);
        _generateSource(sourcePath, nameConst);
        _generateMain(mainPath, nameConst);
        _generateMakefile(makefilePath, nameConst);
        break;
    case CPP:
        _generateSource(sourcePath, nameConst);
        break;
    case MAKE:
        _generateMakefile(makefilePath, nameConst);
        break;
    case MAIN:
        _generateMain(mainPath, nameConst);
        break;
    case HPP:
        _generateHeader(headerPath, nameConst);
        _generateSource(sourcePath, nameConst);
        break;
	}
}

/******************************************************************************/
/*									PRIVATE									  */
/******************************************************************************/


//!		Remplace toutes les occurrences de XXX par <filename>
void NewClass::_replaceAllOccurences(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}


//!		Passe toute la string en majuscule
void NewClass::_toUpperCase(std::string& str) {
	for (char& c : str) {
		c = std::toupper(static_cast<unsigned char>(c));
	}
}


//!		Passe la première lettre en majuscule
void NewClass::_capitalizeFirstLetter(std::string& str) {
	if (!str.empty() && !std::isupper(str[0])) {
		str[0] = std::toupper(str[0]);
	}
}


//!		Génère un fichier <filename>.hpp
void NewClass::_generateHeader(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file '" << path << "' for reading" << std::endl;
		return;
	}

	std::string ifndef = filename;
	this->_toUpperCase(ifndef);
	ifndef = "#ifndef  _" + ifndef;
	
	std::cout << ifndef << std::endl;
	
	std::string define = filename;
	this->_toUpperCase(define);
	define = "# define _" + define;

	std::cout << define << std::endl;

	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
	_replaceAllOccurences(content, IFNDEF, ifndef);
	_replaceAllOccurences(content, DEFINE, define);
	_replaceAllOccurences(content, "XXX", filename);

	std::ofstream outputFile("output/" + filename + ".hpp");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/" << filename << ".hpp' for writing" << std::endl;
		return;
	}

	outputFile << content;
	std::cout << "File generated: " << filename << ".hpp" << std::endl;
}


//!		Génère un fichier <filename>.cpp
void NewClass::_generateSource(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file '" << path << "' for reading" << std::endl;
		return;
	}

	std::string include = filename;
	include = "#include \"" + include + ".hpp\"";

	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
	_replaceAllOccurences(content, INCLUD, include);
	_replaceAllOccurences(content, "XXX", filename);
	
	std::ofstream outputFile("output/" + filename + ".cpp");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/" << filename << ".cpp' for writing" << std::endl;
		return;
	}

	outputFile << content;
	std::cout << "File generated: " << filename << ".cpp" << std::endl;
}


//!		Génère un Makefile
void NewClass::_generateMakefile(const std::string& path, const std::string& filename) {
	(void)filename;
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file '" << path << "' for reading" << std::endl;
		return;
	}
	
	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));

	std::ofstream outputFile("output/Makefile");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/Makefile' for writing" << std::endl;
		return;
	}

	outputFile << content;
	std::cout << "File generated: Makefile" << std::endl;
}


//!  Génère un main.cpp qui va #inlcude "<filename>.hpp"
void NewClass::_generateMain(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file '" << path << "' for reading" << std::endl;
		return;
	}

	std::string include = filename;
	include = "#include \"" + include + ".hpp\"";

	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
	_replaceAllOccurences(content, INCLUD, include);
	_replaceAllOccurences(content, "XXX", filename);
	
	std::ofstream outputFile("output/main.cpp");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/main.cpp' for writing" << std::endl;
		return;
	}

	outputFile << content;
	std::cout << "File generated: main.cpp" << std::endl;
}
