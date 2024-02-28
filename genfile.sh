# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    genfile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 04:18:27 by vtestut           #+#    #+#              #
#    Updated: 2024/02/28 19:43:40 by vtestut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MY_LOGIN="login42"

SOURCES_PATH="/sgoinfre/goinfre/Perso/$MY_LOGIN"

MAKEFILE_PATH="$SOURCES_PATH/cpp_FileGenerator"

make -C "$MAKEFILE_PATH" -f "$MAKEFILE_PATH/Makefile"
echo ""
cd "$MAKEFILE_PATH"

if [ -z "$2" ]; then
    ./a.out "$1"
else
    ./a.out "$1" "$2"
fi
	
mv "$SOURCES_PATH/cpp_FileGenerator/output"/* "$OLDPWD/"
if [ $? -eq 0 ]; then
	echo "\nFile(s) successfully added to your current directory"
else
	echo "\nif nothing work, check genfile.sh to verifiy paths to sources"
fi