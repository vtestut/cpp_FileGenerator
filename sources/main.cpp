/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:54:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/28 19:50:38 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

int printUsage(void) {
        std::cerr << "[ ERROR ]" << std::endl
        << "\nUsage:\tgenfile <fileName> +\n" << std::endl
        << "c\tpour créer un .cpp" << std::endl
        << "h\tpour créer un .hpp ET un .cpp" << std::endl
        << "m\tpour créer un main.cpp qui va #include \"<fileName>.hpp\"" << std::endl
        << "make\tpour créer un makefille (genfile make, sans <fileName>, 1 seul argument)" << std::endl
        << "all\tpour créer les 4 fichiers\n" << std::endl;
        return (1);
}

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
        return (printUsage());
    NewClass generator;
    if ((argc == 2) && std::string(argv[1]) != "make")
        return (printUsage());
    if ((argc == 2 || argc == 3) && std::string(argv[1]) == "make")
        generator.generateFiles(argv[1], MAKE);
    else if (argc == 3 && std::string(argv[2]) == "c")
        generator.generateFiles(argv[1], SRC);
    else if (argc == 3 && std::string(argv[2]) == "h")
        generator.generateFiles(argv[1], HEADR);
    else if (argc == 3 && std::string(argv[2]) == "m")
        generator.generateFiles(argv[1], MAIN);
    else if (argc == 3 && std::string(argv[2]) == "all")
        generator.generateFiles(argv[1], ALL);
    else
        return (printUsage());
        
    return (0);
}

