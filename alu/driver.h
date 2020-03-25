#ifndef DRIVER_H
#define DRIVER_H

#include <systemc.h>


SC_MODULE(driver) {

  sc_out<sc_uint<3>> OPCODE;
  sc_out<sc_uint<4>> OP1,OP2;
  
  void drive();

  sc_uint<3> z;
  sc_uint<4> x, y;
  
  SC_CTOR(driver) {
    SC_THREAD(drive);
  }
};
#endif
