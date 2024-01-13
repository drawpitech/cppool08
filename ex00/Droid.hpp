/*
** EPITECH PROJECT, 2024
** ppool08
** File description:
** Droid
*/

#pragma once

#include <iostream>
#include <string>
#include <utility>

constexpr size_t DEFAULT_ENERGY = 50;
constexpr size_t DEFAULT_ATTACK = 25;
constexpr size_t DEFAULT_TOUGHNESS = 15;

class Droid {
   public:
    Droid(std::string serial = "")
        : _id(std::move(serial)),
          _energy(DEFAULT_ENERGY),
          _attack(DEFAULT_ATTACK),
          _toughness(DEFAULT_TOUGHNESS),
          _status(new std::string("Standing by")) {
        talk("Activated");
    }
    Droid(const Droid &other)
        : _id(other._id),
          _energy(other._energy),
          _attack(other._attack),
          _toughness(other._toughness),
          _status(new std::string(*other._status)) {
        talk("Activated, Memory Dumped");
    }
    ~Droid() {
        setStatus(nullptr);
        talk("Destroyed");
    }

    Droid &operator=(const Droid &other) {
        setId(other._id);
        setEnergy(other._energy);
        setStatus(
            (other._status != nullptr) ? new std::string(*other._status)
                                       : nullptr);
        return *this;
    }
    bool operator==(const Droid &other) const {
        return _id == other._id && _energy == other._energy &&
               _attack == other._attack && _toughness == other._toughness &&
               *_status == *other._status;
    }
    bool operator!=(const Droid &other) const { return !(*this == other); }
    size_t &operator<<(size_t &battery) {
        const size_t needed = std::min(100 - _energy, battery);
        setEnergy(getEnergy() + needed);
        battery -= needed;
        return battery;
    }

    void setId(const std::string &id) { _id = id; }
    void setEnergy(size_t energy) { _energy = energy; }
    void setStatus(std::string *status) {
        delete _status;
        _status = status;
    }
    [[nodiscard]] std::string getId() const { return _id; }
    [[nodiscard]] std::size_t getEnergy() const { return _energy; }
    [[nodiscard]] std::string getStatus() const {
        return _status != nullptr ? *_status : "(null)";
    }
    [[nodiscard]] size_t getAttack() const { return _attack; }
    [[nodiscard]] size_t getToughness() const { return _toughness; }

   private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;

    void talk(const std::string &message) const {
        std::cout << "Droid '" << _id << "' " << message << "\n";
    }
};

std::ostream &operator<<(std::ostream &os, const Droid &droid);
