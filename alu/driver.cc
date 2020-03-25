#include "driver.h"

void driver::drive() {
  z=x=y=0;
  for (int i=0; i<8; i++) {
    y++;
    OPCODE.write(z);
    OP1.write(x);
    OP2.write(y);
    z++;
    wait(5, SC_NS);
  }
}
