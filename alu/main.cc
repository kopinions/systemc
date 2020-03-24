#include <systemc.h>
#include "alu.h"

int sc_main(int argc, char* argv[]){
  sc_signal<sc_uint<3>> s_opcode;
  sc_signal<sc_uint<4>> s_op1, s_op2;
  sc_signal<bool> s_carry;

  sc_signal<sc_uint<4>> s_result;

  ALU alu();
}
