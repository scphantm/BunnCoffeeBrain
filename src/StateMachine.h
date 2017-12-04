
#include <inttypes.h>

class StateMachine {
    public StateMachine();

     void setHalfPotButton(int half);
     void setEnterButton(int enter);
     void setUpButton(int up);
     void setDownButton(int down);
     void setBrewButton(int brew);

    protected:
    uint8_t half;
    uint8_t enter;
    uint8_t up;
    uint8_t down;
    uint8_t brew;
}