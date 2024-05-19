/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:19:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/19 23:11:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""),_phoneNumber(""), _darkestSecret("") {
	std::cout << "Contactオブジェクト生成" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contactオブジェクト破壊" << std::endl;
}

void Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

std::string Contact::getFirstName() {
	return _firstName;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

std::string Contact::getLastName() {
	return _lastName;
}

void Contact::setNickname(std::string nickname) {
	_nickname = nickname;
}

std::string Contact::getNickname() {
	return _nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber() {
	return _phoneNumber;
}

void Contact::setDarkestSecret(std::string drakestSecret) {
	_darkestSecret = drakestSecret;
}

std::string Contact::getDarkestSecret() {
	return _darkestSecret;
}