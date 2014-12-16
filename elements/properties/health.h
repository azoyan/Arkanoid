#ifndef HEALTH_H
#define HEALTH_H


class Health
{
public:    
    Health(int health);
    Health();

    void hit();
    bool isNull();

private:
    int innerHP;
    enum { Dead = 0, Damage = 1 };
    enum Type { Mortal, Immortal };
    Type type;

};

#endif // HEALTH_H
