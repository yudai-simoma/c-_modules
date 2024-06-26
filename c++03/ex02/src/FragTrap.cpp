/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:20:27 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/26 21:18:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->setName("");
    this->setHitPoints(FragTrap::FRAGTRAP_DEFAULT_HIT_POINTS);
    this->setEnergyPoints(FragTrap::FRAGTRAP_DEFAULT_ENERGY_POINTS);
    this->setAttackDamage(FragTrap::FRAGTRAP_DEFAULT_ATTACK_DAMAGE);
    std::cout << RED_START << "FragTrap object created" << COLOR_END
              << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    this->setHitPoints(FragTrap::FRAGTRAP_DEFAULT_HIT_POINTS);
    this->setEnergyPoints(FragTrap::FRAGTRAP_DEFAULT_ENERGY_POINTS);
    this->setAttackDamage(FragTrap::FRAGTRAP_DEFAULT_ATTACK_DAMAGE);
    std::cout << RED_START << "FragTrap " << name << " is created" << COLOR_END
              << std::endl;
}

// 暗黙的にClapTrapへキャストされる
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << RED_START << "FragTrap " << this->getName()
              << " is Copy constructor created" << COLOR_END << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << RED_START << "FragTrap " << this->getName()
              << " is Copy assignment operator called" << COLOR_END
              << std::endl;
    return *this;
}

// 継承しているため、ClapTrapのデストラクターも自動で走る。
FragTrap::~FragTrap() {
    std::cout << RED_START << "FragTrap " << this->getName() << " is destroyed"
              << COLOR_END << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 0) {
        std::cout << "FragTrap " << this->getName() << " attacks " << target
                  << ", causing " << this->getAttackDamage()
                  << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        std::cout << "FragTrap " << this->getName()
                  << " is out of energy and cannot attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->getName()
              << " is requesting high fives! Up top!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const FragTrap& fragTrap) {
    os << static_cast<const ClapTrap&>(fragTrap);
    return os;
}
