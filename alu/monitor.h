#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>

SC_MODULE(monitor) {

  sc_in<sc_uint<3>> OPCODE;
  sc_in<sc_uint<4>> OP1, OP2;
  sc_in<sc_uint<4>> RESULT;

  void monit();

  SC_CTOR(monitor) {
    SC_METHOD(monit);
    sensitive << OPCODE << RESULT;
    dont_initialize();
  }
};
#endif
