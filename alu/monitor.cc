#include "monitor.h"
#include <iostream>
using namespace std;
void monitor::monit() {
  cout<<"at "<<sc_time_stamp()<<" OPCODE is:"<< OPCODE<<" inputs are: | "<< OP1 <<" | "<< OP2<<" outputs are: | ";
  cout << RESULT << endl;
}
