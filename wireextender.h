#ifndef WireExtender_h
#define WireExtender_h
#include "Arduino.h"
#include <Wire.h>

class WireExtender{
    public:
        WireExtender();
        ~WireExtender();
        void set_register(int addr, int reg);
        uint8_t get_uint8(int addr, int reg);
        uint16_t get_uint16(int addr, int reg);
        uint32_t get_uint32(int addr, int reg);
        float get_float(int addr, int reg);
         


};
#endif
