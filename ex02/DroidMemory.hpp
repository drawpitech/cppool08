/*
** EPITECH PROJECT, 2024
** ppool08
** File description:
** DroidMemory
*/

#pragma once

#include <cstddef>
#include <ostream>

class DroidMemory {
   public:
    DroidMemory();
    DroidMemory(DroidMemory const &other);

    [[nodiscard]] size_t getFingerprint() const;
    void setFingerprint(size_t fingerprint);
    [[nodiscard]] size_t getExp() const;
    void setExp(size_t exp);

    DroidMemory &operator<<(const DroidMemory &other);
    DroidMemory &operator>>(DroidMemory &other) const;
    DroidMemory &operator+=(const DroidMemory &other);
    DroidMemory &operator+=(size_t value);
    DroidMemory operator+(const DroidMemory &other) const;
    DroidMemory operator+(size_t value) const;
    DroidMemory &operator=(const DroidMemory &other);
    bool operator==(const DroidMemory &other) const;
    bool operator!=(const DroidMemory &other) const;
    bool operator<(size_t val) const;
    bool operator>(size_t val) const;
    bool operator<=(size_t val) const;
    bool operator>=(size_t val) const;
    bool operator<(const DroidMemory &other) const;
    bool operator>(const DroidMemory &other) const;
    bool operator<=(const DroidMemory &other) const;
    bool operator>=(const DroidMemory &other) const;

   private:
    size_t _fingerprint;
    size_t _exp;
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &mem);
