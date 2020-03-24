#ifndef ALU_H
#include <systemc.h>

#define ALU_H

SC_MODULE(ALU) {

  sc_in<sc_uint<3>> opcode;
  sc_in<sc_uint<4>> op1,op2;
  sc_out<bool> carry;
  sc_out<sc_uint<4>> result;
  
  void operate();

  sc_uint<4> data1, data2;
  sc_uint<5> res;
  
  SC_CTOR(ALU) {
    SC_METHOD(operate);
    sensitive << opcode << op1 << op2;
  }
};
#endif
