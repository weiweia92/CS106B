#include "Gun.h"
#include "Solider.h"

void test() {
    Solider sanduo("xusanduo");
    sanduo.addGun(new Gun("AK47"));
    sanduo.addBulletToGun(20);
    sanduo.fire();
}

int main() {
    test();
    return 0;
}