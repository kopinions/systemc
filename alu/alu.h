#ifndef ALU_H
#include <systemc.h>

#define ALU_H

SC_MODULE(ALU) {

  sc_in<sc_uint<3>> OPCODE;
  sc_in<sc_uint<4>> OP1,OP2;
  sc_out<bool> CARRY;
  sc_out<sc_uint<4>> RESULT;
  
  void operate();

  sc_uint<4> DATA1, DATA2;
  sc_uint<5> RES;
  
  SC_CTOR(ALU) {
    SC_METHOD(operate);
    sensitive << OPCODE << OP1 << OP2;
  }
};
#endif
