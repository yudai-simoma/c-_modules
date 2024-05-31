/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:27 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/31 18:10:15 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : _max_id(0) {
    std::clog << "PhoneBookオブジェクト生成" << std::endl;
}

PhoneBook::~PhoneBook() {
    std::clog << "PhoneBookオブジェクト破壊" << std::endl;
}

/* 連絡先を追加する */
void PhoneBook::add() {
    std::string input;
    int id = _max_id % MAX_CONTACT_SIZE;

    _max_id++;
    _contacts[id].setId(_max_id);
    getValidatedInput(input, "FirstNameを入力してください\t: ");
    _contacts[id].setFirstName(input);
    getValidatedInput(input, "LastNameを入力してください\t: ");
    _contacts[id].setLastName(input);
    getValidatedInput(input, "Nicknameを入力してください\t: ");
    _contacts[id].setNickname(input);
    getValidatedInput(input, "PhoneNumberを入力してください\t: ");
    _contacts[id].setPhoneNumber(input);
    getValidatedInput(input, "DarkestSecretを入力してください\t: ");
    _contacts[id].setDarkestSecret(input);
}

/* 連絡先を表示し、検索させる */
void PhoneBook::search() {
    if (_max_id == 0) {
        std::cout << "登録されている連絡先は0件です。" << std::endl;
        return;
    }
    std::cout << std::setw(10) << std::right << "ID"
              << "|";
    std::cout << std::setw(10) << std::right << "FirstName"
              << "|";
    std::cout << std::setw(10) << std::right << "LastName"
              << "|";
    std::cout << std::setw(10) << std::right << "Nickname"
              << "|" << std::endl;
    for (int i = 0; i < MAX_CONTACT_SIZE; i++) {
        putContact(_contacts[i]);
    }
    int id = 0;
    while (true) {
        id = numberEntry();
        if (id > 0 && id <= _max_id) {
            putContactDetail(_contacts[id - 1]);
            break;
        } else {
            std::cout << "正しい値を入力してください。" << std::endl;
        }
    }
}

/* プログラムを終了する */
void PhoneBook::exit() {
    return;
}

/** 以下からprivate関数 */

void PhoneBook::putContact(Contact& contact) {
    std::cout << std::setw(10) << std::right << truncateString(std::to_string(contact.getId()))
              << "|";
    std::cout << std::setw(10) << std::right << truncateString(contact.getFirstName()) << "|";
    std::cout << std::setw(10) << std::right << truncateString(contact.getLastName()) << "|";
    std::cout << std::setw(10) << std::right << truncateString(contact.getNickname()) << "|"
              << std::endl;
}

int PhoneBook::numberEntry() {
    int id = 0;
    std::stringstream ss;
    std::string str;

    std::cout << "表示する連絡先の番号を入力してください: ";
    std::getline(std::cin, str);
    if (std::cin.eof()) {
        std::cout << "EOFが入力されたためプログラムを終了します。" << std::endl;
        std::exit(EXIT_SUCCESS);
    }
    ss << str;
    ss >> id;
    return id;
}

void PhoneBook::putContactDetail(Contact& contact) {
    std::cout << "ID\t\t: " << contact.getId() << std::endl;
    std::cout << "FirstName\t: " << contact.getFirstName() << std::endl;
    std::cout << "LastName\t: " << contact.getLastName() << std::endl;
    std::cout << "Nickname\t: " << contact.getNickname() << std::endl;
    std::cout << "PhoneNumber\t: " << contact.getPhoneNumber() << std::endl;
    std::cout << "DarkestSecret\t: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::getValidatedInput(std::string& input, const std::string& msg) {
    while (true) {
        input = "";
        std::cout << msg;
        std::getline(std::cin, input);
        if (!input.empty() && input.size() != 0) {
            return;
        } else {
            std::cout << "1文字以上入力してください。" << std::endl;
        }
    }
}

std::string PhoneBook::truncateString(const std::string& str) {
    size_t size = str.length();

    if (size < 10) {
        return str;
    } else {
        std::string ret = str.substr(0, 9);
        return ret + ".";
    }
}
