/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:17:34 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/12 00:59:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::DEBUG = "DEBUG";
const std::string Harl::INFO = "INFO";
const std::string Harl::WARNING = "WARNING";
const std::string Harl::ERROR = "ERROR";

Harl::Harl() {
    this->_funcArray[DEBUG_NUM] = &Harl::debug;
    this->_funcArray[INFO_NUM] = &Harl::info;
    this->_funcArray[WARNING_NUM] = &Harl::warning;
    this->_funcArray[ERROR_NUM] = &Harl::error;
    std::cout << "\033[1;31m --- Harl object created --- \033[0m" << std::endl;
}

Harl::~Harl() {
    std::cout << "\033[1;31m --- Harl object destroyed --- \033[0m"
              << std::endl;
}

void Harl::complain(std::string level) {
    std::string str[] = {Harl::DEBUG, Harl::INFO, Harl::WARNING, Harl::ERROR};
    size_t i;
    for (i = 0; i < LEVEL_NUM; i++) {
        if (str[i] == level) {
            break;
        }
    }
    if (i != LEVEL_NUM) {
        void (Harl::*funcPtr)() = _funcArray[i];
        (this->*funcPtr)();
    } else {
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
    }
}

void Harl::debug() {
    std::cout
        << "[" << Harl::DEBUG << "]\n"
        << "I love having extra bacon for my "
           "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
}

void Harl::info() {
    std::cout << "[" << Harl::INFO << "]\n"
              << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning() {
    std::cout << "[" << Harl::WARNING << "]\n"
              << "I think I deserve to have some extra bacon for free. I’ve "
                 "been coming for\n"
              << "years whereas you started working here since last month."
              << std::endl;
}

void Harl::error() {
    std::cout << "[" << Harl::ERROR << "]\n"
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
