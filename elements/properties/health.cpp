#include "health.h"

Health::Health(int health) : innerHP(health)  {
    type = Mortal;
}

Health::Health()  {
    type = Immortal;
}

void Health::hit() {
    innerHP = innerHP - Damage;
}

bool Health::isNull() {
    return ( type != Immortal ) && ( innerHP == Dead );
}
