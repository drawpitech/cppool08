/*
** EPITECH PROJECT, 2024
** ppool08
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _fingerprint(random()), _exp(0) {}

DroidMemory::DroidMemory(const DroidMemory &other)
    : _fingerprint(other._fingerprint), _exp(other._exp) {}

size_t DroidMemory::getFingerprint() const { return _fingerprint; }
void DroidMemory::setFingerprint(size_t fingerprint) {
    _fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const { return _exp; }
void DroidMemory::setExp(size_t exp) { _exp = exp; }

DroidMemory &DroidMemory::operator<<(const DroidMemory &other) {
    _exp += other._exp;
    _fingerprint ^= other._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other) const {
    other._exp += _exp;
    other._fingerprint ^= _fingerprint;
    return other;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &other) {
    return (*this) << other;
}

DroidMemory &DroidMemory::operator+=(size_t value) {
    _exp += value;
    _fingerprint ^= value;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const {
    return DroidMemory(*this) += other;
}

DroidMemory DroidMemory::operator+(size_t value) const {
    return DroidMemory(*this) += value;
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &mem) {
    os << "DroidMemory '" << mem.getFingerprint() << "', " << mem.getExp();
    return os;
}

DroidMemory &DroidMemory::operator=(const DroidMemory &other) {
    _fingerprint = other._fingerprint;
    _exp = other._exp;
    return *this;
}

bool DroidMemory::operator==(const DroidMemory &other) const {
    return (_fingerprint == other._fingerprint && _exp == other._exp);
}
bool DroidMemory::operator!=(const DroidMemory &other) const {
    return !(other == *this);
}

bool DroidMemory::operator<(size_t val) const { return _exp < val; }
bool DroidMemory::operator>(size_t val) const { return _exp > val; }
bool DroidMemory::operator<=(size_t val) const { return _exp <= val; }
bool DroidMemory::operator>=(size_t val) const { return _exp >= val; }

bool DroidMemory::operator<(const DroidMemory &other) const {
    return *this < other._exp;
}
bool DroidMemory::operator>(const DroidMemory &other) const {
    return *this > other._exp;
}
bool DroidMemory::operator<=(const DroidMemory &other) const {
    return *this <= other._exp;
}
bool DroidMemory::operator>=(const DroidMemory &other) const {
    return *this >= other._exp;
}
