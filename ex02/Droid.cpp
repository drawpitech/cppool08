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
      _status(new std::string("Standing by")),
      _battle_data(new DroidMemory())
{
    talk("Activated");
}

Droid::Droid(const Droid &other)
    : _id(other._id),
      _energy(DEFAULT_ENERGY),
      _attack(DEFAULT_ATTACK),
      _toughness(DEFAULT_TOUGHNESS),
      _status(new std::string(*other._status)),
      _battle_data(new DroidMemory(*other._battle_data))
{
    talk("Activated, Memory Dumped");
}

Droid::~Droid()
{
    delete _battle_data;
    delete _status;
    talk("Destroyed");
}

Droid &Droid::operator=(const Droid &other)
{
    setId(other._id);
    setStatus(
        (other._status != nullptr) ? new std::string(*other._status) : nullptr);
    setBattleData(
        (other._battle_data != nullptr) ? new DroidMemory(*other._battle_data)
                                        : nullptr);
    return *this;
}

bool Droid::operator==(const Droid &other) const
{
    return *_status == *other._status;
}

bool Droid::operator!=(const Droid &other) const { return !(*this == other); }

size_t &Droid::operator<<(size_t &battery)
{
    const size_t needed = std::min(100 - _energy, battery);
    setEnergy(getEnergy() + needed);
    battery -= needed;
    return battery;
}

void Droid::talk(const std::string &message) const
{
    std::cout << "Droid '" << _id << "' " << message << "\n";
}

std::string Droid::getId() const { return _id; }
void Droid::setId(const std::string &id) { _id = id; }

std::size_t Droid::getEnergy() const { return _energy; }
void Droid::setEnergy(size_t energy) { _energy = energy; }

std::string Droid::getStatus() const
{
    return _status != nullptr ? *_status : "(null)";
}
void Droid::setStatus(std::string *status)
{
    delete _status;
    _status = status;
}

DroidMemory *Droid::getBattleData() const { return _battle_data; }
void Droid::setBattleData(DroidMemory *battle_data)
{
    delete _battle_data;
    _battle_data = battle_data;
}

size_t Droid::getAttack() const { return _attack; }

size_t Droid::getToughness() const { return _toughness; }

std::ostream &operator<<(std::ostream &os, const Droid &droid)
{
    os << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", "
       << droid.getEnergy();
    return os;
}

bool Droid::operator()(std::string *data, size_t expNeeded)
{
    if (_energy <= TASK_ENERGY) {
        _energy = 0;
        delete data;
        setStatus(new std::string("Battery Low"));
        return false;
    }

    const size_t exp = _battle_data->getExp();
    _energy -= TASK_ENERGY;

    if (exp < expNeeded) {
        *data += " - Failed!";
        setStatus(data);
        _battle_data->setExp(exp + expNeeded);
        return false;
    }

    *data += " - Completed!";
    setStatus(data);
    _battle_data->setExp(exp + expNeeded / 2);
    return true;
}
