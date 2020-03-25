#include <systemc.h>
#include "alu.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
  sc_signal<sc_uint<3>> s_opcode;
  sc_signal<sc_uint<4>> s_op1, s_op2;
  sc_signal<bool> s_carry, s_zero;

  sc_signal<sc_uint<4>> s_result;

  ALU alu("alu");
  driver dri("driver");

  alu.OPCODE(s_opcode);
  alu.OP1(s_op1);
  alu.OP2(s_op2);
  alu.RESULT(s_result);
  alu.ZERO(s_zero);
  alu.CARRY(s_carry);
  
  dri.OPCODE(s_opcode);
  dri.OP1(s_op1);
  dri.OP2(s_op2);

  monitor mon("monior");
  mon.OPCODE(s_opcode);
  mon.OP1(s_op1);
  mon.OP2(s_op2);
  mon.RESULT(s_result);

  sc_trace_file *fp = sc_create_vcd_trace_file("vcd_trace");
  fp->set_time_unit(1, SC_NS);

  sc_trace(fp, s_opcode, "OPCODE");
  sc_trace(fp, s_op1, "OP1");
  sc_trace(fp, s_op2, "OP2");
  sc_trace(fp, s_carry, "CARRY");
  sc_trace(fp, s_zero, "ZERO");
  sc_trace(fp, s_result, "RESULT");

  sc_start(50, SC_NS);
  sc_close_vcd_trace_file(fp);
  return 0;
}
