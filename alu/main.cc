#include <systemc.h>
#include "alu.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
  sc_signal<sc_uint<3>> s_opcode;
  sc_signal<sc_uint<4>> s_op1, s_op2;
  sc_signal<bool> s_carry;

  sc_signal<sc_uint<4>> s_result;

  ALU alu("alu");
  driver dri("driver");

  alu.OPCODE(s_opcode);
  alu.OP1(s_op1);
  alu.OP2(s_op2);
  alu.RESULT(s_result);
  alu.CARRY(s_carry);
  
  dri.OPCODE(s_opcode);
  dri.OP1(s_op1);
  dri.OP2(s_op2);

  monitor mon("monior");
  mon.OPCODE(s_opcode);
  mon.OP1(s_op1);
  mon.OP2(s_op2);
  mon.RESULT(s_result);

  sc_start(50, SC_NS);
}
