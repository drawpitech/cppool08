/*
** EPITECH PROJECT, 2024
** ppool08
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial)
    : _id(std::move(serial)),
      _energy(DEFAULT_ENERGY),
      _attack(DEFAULT_ATTACK),
      _toughness(DEFAULT_TOUGHNESS),
      _status(new std::string("Standing by")) {
    talk("Activated");
}

Droid::Droid(const Droid &other)
    : _id(other._id),
      _energy(other._energy),
      _attack(other._attack),
      _toughness(other._toughness),
      _status(new std::string(*other._status)) {
    talk("Activated, Memory Dumped");
}

Droid::~Droid() {
    setStatus(nullptr);
    talk("Destroyed");
}

Droid &Droid::operator=(const Droid &other) {
    setId(other._id);
    setEnergy(other._energy);
    setStatus(
        (other._status != nullptr) ? new std::string(*other._status) : nullptr);
    return *this;
}

bool Droid::operator==(const Droid &other) const {
    return _id == other._id && _energy == other._energy &&
           _attack == other._attack && _toughness == other._toughness &&
           *_status == *other._status;
}

bool Droid::operator!=(const Droid &other) const { return !(*this == other); }

size_t &Droid::operator<<(size_t &battery) {
    const size_t needed = std::min(100 - _energy, battery);
    setEnergy(getEnergy() + needed);
    battery -= needed;
    return battery;
}

void Droid::talk(const std::string &message) const {
    std::cout << "Droid '" << _id << "' " << message << "\n";
}

std::string Droid::getId() const { return _id; }

std::size_t Droid::getEnergy() const { return _energy; }

std::string Droid::getStatus() const {
    return _status != nullptr ? *_status : "(null)";
}

size_t Droid::getAttack() const { return _attack; }

size_t Droid::getToughness() const { return _toughness; }

void Droid::setId(const std::string &id) { _id = id; }

void Droid::setEnergy(size_t energy) { _energy = energy; }

void Droid::setStatus(std::string *status) {
    delete _status;
    _status = status;
}

std::ostream &operator<<(std::ostream &os, const Droid &droid) {
    os << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", "
       << droid.getEnergy();
    return os;
}
