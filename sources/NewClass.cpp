/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:49:54 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/28 22:00:36 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

/* ************************************************************************** */
/*									PUBLIC									  */
/* ************************************************************************** */

void NewClass::generateFiles(const std::string& className, int mod) {
	std::string headerPath = "./templates/header.txt";
	std::string sourcePath = "./templates/source.txt";
	std::string makefilePath = "./templates/makefile.txt";
	std::string mainPath = "./templates/main.txt";
	std::string classCopie = className;
	
	if (!std::filesystem::exists("output")) {
		if (!std::filesystem::create_directory("output")) {
			std::cerr << "Error: Unable to create directory 'output'\n";
			return;
		}
	} if (!std::filesystem::exists(headerPath)) {
		std::cerr << "Error: Header directory '" << headerPath << "' does not exist\n";
		return;
	} if (!std::filesystem::exists(sourcePath)) {
		std::cerr << "Error: Source directory '" << sourcePath << "' does not exist\n";
		return;
	}  if (!std::filesystem::exists(sourcePath)) {
		std::cerr << "Error: Source directory '" << sourcePath << "' does not exist\n";
		return;
	} 
	
	_capitalizeFirstLetter(classCopie);
	
	const std::string& classConst = classCopie;

	if (mod == ALL) {
		_generateHeader(headerPath, classConst);
		_generateSource(sourcePath, classConst);
		_generateMain(mainPath, classConst);
		_generateMakefile(makefilePath, classConst);
	} else if (mod == SRC) {
		_generateSource(sourcePath, classConst);
	} else if (mod == MAKE) {
		_generateMakefile(makefilePath, classConst);
	} else if (mod == MAIN) {
		_generateMain(mainPath, classConst);
	} else if (mod == HEADR) {
		_generateHeader(headerPath, classConst);
		_generateSource(sourcePath, classConst);
	}
}


/* ************************************************************************** */
/*									PRIVATE									  */
/* ************************************************************************** */


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
		std::cerr << "Error: Unable to open file '" << path << "' for reading\n";
		return;
	}

	std::string ifndef = filename;
	this->_toUpperCase(ifndef);
	ifndef = "#ifndef _" + ifndef;

	std::string define = filename;
	this->_toUpperCase(define);
	define = "# define _" + define;

	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
	_replaceAllOccurences(content, IFNDEF, ifndef);
	_replaceAllOccurences(content, DEFINE, define);
	_replaceAllOccurences(content, "XXX", filename);

	std::ofstream outputFile("output/" + filename + ".hpp");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/" << filename << ".hpp' for writing\n";
		return;
	}

	outputFile << content;
	std::cout << "Header file generated: " << filename << ".hpp" << std::endl;
}


//!		Génère un fichier <filename>.cpp
void NewClass::_generateSource(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file '" << path << "' for reading\n";
		return;
	}

	std::string include = filename;
	include = "#include \"" + include + ".hpp\"";

	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
	_replaceAllOccurences(content, INCLUD, include);
	_replaceAllOccurences(content, "XXX", filename);
	
	std::ofstream outputFile("output/" + filename + ".cpp");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/" << filename << ".cpp' for writing\n";
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
		std::cerr << "Error: Unable to open file '" << path << "' for reading\n";
		return;
	}
	
	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));

	std::ofstream outputFile("output/Makefile");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/Makefile' for writing\n";
		return;
	}

	outputFile << content;
	std::cout << "File generated: Makefile" << std::endl;
}


//!  Génère un main.cpp qui va #inlcude "<filename>.hpp"
void NewClass::_generateMain(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Unable to open file '" << path << "' for reading\n";
		return;
	}

	std::string include = filename;
	include = "#include \"" + include + ".hpp\"";

	std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
	_replaceAllOccurences(content, INCLUD, include);
	_replaceAllOccurences(content, "XXX", filename);
	
	std::ofstream outputFile("output/main.cpp");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to create file 'output/main.cpp' for writing\n";
		return;
	}

	outputFile << content;
	std::cout << "File generated: main.cpp" << std::endl;
}
