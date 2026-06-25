#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(float fireRate, int maxAmmo);
    
    void update(float deltaTime);
    bool canFire() const;
    void fire();
    void reload();
    
    int getAmmo() const { return currentAmmo; }
    int getMaxAmmo() const { return maxAmmo; }
    bool isReloading() const { return reloading; }
    float getReloadProgress() const;
    float getCooldownProgress() const;
    
private:
    float fireRate;
    float cooldownTimer;
    int maxAmmo;
    int currentAmmo;
    bool reloading;
    float reloadTimer;
    float reloadTime;
};

#endif // WEAPON_H
