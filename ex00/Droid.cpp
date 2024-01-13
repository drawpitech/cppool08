/*
** EPITECH PROJECT, 2024
** ppool08
** File description:
** Droid
*/

#include "Droid.hpp"

std::ostream &operator<<(std::ostream &os, const Droid &droid) {
    os << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", "
       << droid.getEnergy();
    return os;
}
