#ifndef WireExtender_h
#define WireExtender_h
#include "Arduino.h"
#include <Wire.h>

class WireExtender{
    public:
        WireExtender();
        ~WireExtender();
        
        #define REGISTER(n,name,type) inline type get_##name(int addr){\
           return get_##type(addr,n);\
        }
        #include "test.reg"
        #undef REGISTER

    private:
        void set(int addr,int len, const void* data);
        uint8_t get_uint8_t(int addr, int reg);
        uint16_t get_uint16_t(int addr, int reg);
        uint32_t get_uint32_t(int addr, int reg);
        double get_double(int addr, int reg);
         


};
#endif
