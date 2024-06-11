/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:48:12 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/11 15:32:31 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#include "StringUtils.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Invalid parameters." << std::endl;
        return 1;
    }

    try {
        std::string fileName = argv[1];
        std::ifstream readFile;
        std::string line;
        std::string contents = "";
        std::ofstream writeFali;

        // ファイルを開いて中身を取得
        readFile.open(fileName, std::ios::in);
        if (!readFile) {
            std::cout << "Failed to open file: " << fileName << std::endl;
            return 1;
        }
        while (std::getline(readFile, line)) {
            contents += line + '\n';
        }
        // ファイルの中のs1をs2に変換
        contents = StringUtils::replaceContents(contents, argv[2], argv[3]);
        // ファイルを開いて、書き込み
        writeFali.open(fileName + ".replace");
        if (!writeFali) {
            std::cout << "Failed to open file: " << fileName << ".replace"
                      << std::endl;
            return 1;
        }
        writeFali << contents;

        readFile.close();
        writeFali.close();
        return 0;
    } catch (...) {
        std::cout << "An error occurred." << std::endl;
        return 1;
    }
}
