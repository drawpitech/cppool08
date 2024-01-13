/*
** EPITECH PROJECT, 2024
** ppool08
** File description:
** Droid
*/

#pragma once

#include <iostream>
#include <string>

constexpr size_t DEFAULT_ENERGY = 50;
constexpr size_t DEFAULT_ATTACK = 25;
constexpr size_t DEFAULT_TOUGHNESS = 15;

class Droid {
   public:
    Droid(std::string serial = "");
    Droid(const Droid &other);
    ~Droid();

    Droid &operator=(const Droid &other);
    bool operator==(const Droid &other) const;
    bool operator!=(const Droid &other) const;
    size_t &operator<<(size_t &battery);

    void setId(const std::string &id);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
    std::string getId() const;
    std::size_t getEnergy() const;
    std::string getStatus() const;
    size_t getAttack() const;
    size_t getToughness() const;

   private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;

    void talk(const std::string &message) const;
};

std::ostream &operator<<(std::ostream &os, const Droid &droid);
