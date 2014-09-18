//=================================
/* wireExtender.cpp - Extends the wire.h library to allow for
multipul virtual registers in a single i2c device.
By Brian Gratton and James Bliss 07/27/14*/
//=================================

#include <Arduino.h>
#include <Wire.h>
#include <wireextender.h>

WireExtender::WireExtender(){
    Wire.begin();
}

WireExtender::~WireExtender(){}

//=================================
//=================================

void WireExtender::set_register(int addr, int reg){
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.endTransmission();
}


uint8_t WireExtender::get_uint8(int addr, int reg){
    set_register(addr,reg);
    Wire.requestFrom(addr, sizeof(uint8_t));
    uint8_t c;

    while(Wire.available()){
        c = Wire.read();
    }
    return c;
}

//------------------------------------
typedef union {
    uint16_t v;
    uint8_t bytes[sizeof(uint16_t)];
} uint16_converter;
//-----------------------------------

uint16_t WireExtender::get_uint16(int addr, int reg){
    set_register(addr,reg);
    Wire.requestFrom(addr, sizeof(uint16_t));

    size_t p = 0;
    uint16_converter buffer;
    buffer.v = 0;
     
    while(Wire.available() && p < sizeof(uint16_t)){
        uint8_t c = Wire.read();
        buffer.bytes[p++] = c;
    }
    return buffer.v;
}

//-----------------------------------
typedef union {
    uint32_t v;
    uint8_t bytes[sizeof(uint32_t)];
} uint32_converter;
//-----------------------------------

uint32_t WireExtender::get_uint32(int addr, int reg){
    set_register(addr,reg);
    Wire.requestFrom(addr, sizeof(uint32_t));

    size_t p = 0;
    uint32_converter buffer;
    buffer.v = 0;

    while(Wire.available() && p < sizeof(uint32_t)){
        uint8_t c = Wire.read();
        buffer.bytes[p++] = c;
    }
    return buffer.v;
}


//-----------------------------------
typedef union {
    float v;
    uint8_t bytes[sizeof(float)];
} float_converter;
//-----------------------------------

float WireExtender::get_float(int addr, int reg){
    set_register(addr,reg);
    Wire.requestFrom(addr,sizeof(float));

    size_t p = 0;
    float_converter buffer;
    buffer.v = 0;

    while(Wire.available() && p < sizeof(float)){
        uint8_t c = Wire.read();
        buffer.bytes[p++] = c;
    }
    return buffer.v;
}

//-----------------------------------
/*
//=================================
//=================================
void WireExtender::select_register(int addr,int reg){
    Wire.beginTransmission(addr);
    Wire.write(data);
    Wire.endTransmission();
}

//=================================
//=================================
void WireExtender::store_sensor_addresses_to_eeprom(){
    //TODO 
    // Write the address_scan results to eeprom
}

//=================================
//=================================
void address_load(){
    // load existing i2c addresses and sensor info from eeprom
}

//=================================
//=================================
void address_clear(){
    // erases all i2c addresses from eeprom.
    // forces device to rescan for addresses in the event of a new sensor board being connected.
}

//=================================
//=================================
void address_scan(){
    // send out a request to the entire i2c address range
    // determine the address of attached modules by which ones respond back
    // request "Honest Sensor" data back and store in eeprom of Master

}
//=================================
//=================================
*/
