#include "Weapon.h"

Weapon::Weapon(float fireRate, int maxAmmo)
    : fireRate(fireRate), cooldownTimer(0), maxAmmo(maxAmmo), 
      currentAmmo(maxAmmo), reloading(false), reloadTimer(0), reloadTime(2.0f) {
}

void Weapon::update(float deltaTime) {
    if (cooldownTimer > 0) {
        cooldownTimer -= deltaTime;
        if (cooldownTimer < 0) cooldownTimer = 0;
    }
    
    if (reloading) {
        reloadTimer -= deltaTime;
        if (reloadTimer <= 0) {
            currentAmmo = maxAmmo;
            reloading = false;
            reloadTimer = 0;
        }
    }
}

bool Weapon::canFire() const {
    return !reloading && currentAmmo > 0 && cooldownTimer <= 0;
}

void Weapon::fire() {
    if (canFire()) {
        currentAmmo--;
        cooldownTimer = 1.0f / fireRate;
    }
}

void Weapon::reload() {
    if (!reloading && currentAmmo < maxAmmo) {
        reloading = true;
        reloadTimer = reloadTime;
    }
}

float Weapon::getReloadProgress() const {
    if (!reloading) return 0.0f;
    return 1.0f - (reloadTimer / reloadTime);
}

float Weapon::getCooldownProgress() const {
    if (cooldownTimer <= 0) return 1.0f;
    float cooldownTime = 1.0f / fireRate;
    return 1.0f - (cooldownTimer / cooldownTime);
}
