#define __MAIN_C__

#include <stdint.h>
#include <stdbool.h>

// Define the raw base address values for the i/o devices

#define AHB_SW_BASE                             0x40000000
#define AHB_OUT_BASE                            0x50000000

// Define pointers with correct type for access to 32-bit i/o devices
//
// The locations in the devices can then be accessed as:
//    SW_REGS[0]
//    SW_REGS[1]
//    SW_REGS[2]
//    OUT_REGS[0]
//    OUT_REGS[1]
//
volatile uint32_t* SW_REGS = (volatile uint32_t*) AHB_SW_BASE;
volatile uint32_t* OUT_REGS = (volatile uint32_t*) AHB_OUT_BASE;

#include <stdint.h>

//////////////////////////////////////////////////////////////////
// Functions provided to access i/o devices
//////////////////////////////////////////////////////////////////
// bv1
void write_out_0(uint32_t value_0) {

  OUT_REGS[0] = value_0;

}
//bv2
void write_out_1(uint32_t value_1) {

  OUT_REGS[1] = value_1;

}
//bv3
void write_out_2(uint32_t value_2) {

  OUT_REGS[2] = value_2;

}
//tv1
void write_out_3(uint32_t value_3) {

  OUT_REGS[3] = value_3;

}
// tv2
void write_out_4(uint32_t value_4) {

  OUT_REGS[4] = value_4;

}
//tv3
void write_out_5(uint32_t value_5) {

  OUT_REGS[5] = value_5;

}
//BCO
void write_out_6(uint32_t value_6) {

  OUT_REGS[6] = value_6;

}
//TCO
void write_out_7(uint32_t value_7) {

  OUT_REGS[7] = value_7;

}
void set_out_invalid(void) {
  
  OUT_REGS[7] = 0;
  OUT_REGS[6] = 0;
  OUT_REGS[5] = 0;
  OUT_REGS[4] = 0;	
  OUT_REGS[3] = 0;
  OUT_REGS[2] = 0;
  OUT_REGS[1] = 0;
  OUT_REGS[0] = 0;

}

uint32_t read_out(void) {

  return OUT_REGS[0];
  return OUT_REGS[1];
  return OUT_REGS[2];
  return OUT_REGS[3];  
  return OUT_REGS[4];  
  return OUT_REGS[5];  
  return OUT_REGS[6];  
  return OUT_REGS[7];  
}

uint32_t read_switches(int addr) {

  return SW_REGS[addr];

}

bool check_switches(int addr) {

  int status, switches_ready;
  
  status = SW_REGS[2];
  
  // use the addr value to select one bit of the status register
  switches_ready = (status >> addr) & 1;
  
  return (switches_ready == 1);

}

void wait_for_any_switch_data(void) {

  // this is a 'busy wait'

  //  ( it should only be used if there is nothing
  //   else for the embedded system to do )

  while ( SW_REGS[2] == 0 );
  
  return;

}


//////////////////////////////////////////////////////////////////
// Main Function
//////////////////////////////////////////////////////////////////

int main(void) {

while(1) {
  write_out_0( 0x64 ); //x1
  write_out_1( 0x65 );//y1
  write_out_2( 0x66 );//x2
  write_out_3( 0x67 );// y2  
  write_out_4( 0x68 );
  write_out_5( 0x69 );
  write_out_6( 0x70 );
  write_out_7( 0x71 );
}
    


}