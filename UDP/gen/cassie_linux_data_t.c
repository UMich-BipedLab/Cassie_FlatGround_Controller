#include "cassie_linux_data_t.h"
#include <stddef.h>
#include <string.h>





void pack_cassie_linux_data_t(const cassie_linux_data_t *bus, unsigned char
  bytes[326])
{
  int x;
  unsigned char y[40];
  float b_x[10];
  unsigned char b_y[18];
  short c_x[9];
  unsigned char c_y[4];
  float d_x;
  unsigned char d_y[4];
  unsigned char e_y[4];
  unsigned char f_y[40];
  unsigned char g_y[40];
  unsigned char h_y[4];
  unsigned char i_y[12];
  float e_x[3];
  unsigned char j_y[80];
  float f_x[20];
  unsigned char k_y[80];
  for (x = 0; x < 10; x++) {
    b_x[x] = (float)bus->userInputs.torque[x];
  }

  memcpy((void *)&y[0], (void *)&b_x[0], (unsigned int)((size_t)40 * sizeof
          (unsigned char)));
  for (x = 0; x < 9; x++) {
    c_x[x] = bus->userInputs.telemetry[x];
  }

  memcpy((void *)&b_y[0], (void *)&c_x[0], (unsigned int)((size_t)18 * sizeof
          (unsigned char)));
  x = bus->control.type;
  memcpy((void *)&c_y[0], (void *)&x, (unsigned int)((size_t)4 * sizeof(unsigned
           char)));
  d_x = (float)bus->control.Kff1;
  memcpy((void *)&d_y[0], (void *)&d_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  d_x = (float)bus->control.Kff2;
  memcpy((void *)&e_y[0], (void *)&d_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  for (x = 0; x < 10; x++) {
    b_x[x] = (float)bus->control.motorPositionsDesired[x];
  }

  memcpy((void *)&f_y[0], (void *)&b_x[0], (unsigned int)((size_t)40 * sizeof
          (unsigned char)));
  for (x = 0; x < 10; x++) {
    b_x[x] = (float)bus->control.motorVelocitiesDesired[x];
  }

  memcpy((void *)&g_y[0], (void *)&b_x[0], (unsigned int)((size_t)40 * sizeof
          (unsigned char)));
  x = bus->inekf.enabled;
  memcpy((void *)&h_y[0], (void *)&x, (unsigned int)((size_t)4 * sizeof(unsigned
           char)));
  for (x = 0; x < 3; x++) {
    e_x[x] = (float)bus->inekf.velocity[x];
  }

  memcpy((void *)&i_y[0], (void *)&e_x[0], (unsigned int)((size_t)12 * sizeof
          (unsigned char)));
  for (x = 0; x < 20; x++) {
    f_x[x] = (float)bus->state.q[x];
  }

  memcpy((void *)&j_y[0], (void *)&f_x[0], (unsigned int)((size_t)80 * sizeof
          (unsigned char)));
  for (x = 0; x < 20; x++) {
    f_x[x] = (float)bus->state.dq[x];
  }

  memcpy((void *)&k_y[0], (void *)&f_x[0], (unsigned int)((size_t)80 * sizeof
          (unsigned char)));
  for (x = 0; x < 40; x++) {
    bytes[x] = y[x];
  }

  for (x = 0; x < 18; x++) {
    bytes[x + 40] = b_y[x];
  }

  for (x = 0; x < 4; x++) {
    bytes[x + 58] = c_y[x];
    bytes[x + 62] = d_y[x];
    bytes[x + 66] = e_y[x];
  }

  for (x = 0; x < 40; x++) {
    bytes[x + 70] = f_y[x];
    bytes[x + 110] = g_y[x];
  }

  for (x = 0; x < 4; x++) {
    bytes[x + 150] = h_y[x];
  }

  for (x = 0; x < 12; x++) {
    bytes[x + 154] = i_y[x];
  }

  for (x = 0; x < 80; x++) {
    bytes[x + 166] = j_y[x];
    bytes[x + 246] = k_y[x];
  }
}

void unpack_cassie_linux_data_t(const unsigned char bytes[326],
  cassie_linux_data_t *bus)
{
  int i;
  float y[10];
  unsigned char x[40];
  double t3_torque[10];
  short t3_telemetry[9];
  unsigned char b_x[18];
  int b_y;
  unsigned char c_x[4];
  float c_y;
  float d_y;
  float e_y[3];
  unsigned char d_x[12];
  unsigned char e_x[80];
  float f_y[20];
  double t0_q[20];
  for (i = 0; i < 40; i++) {
    x[i] = bytes[i];
  }

  memcpy((void *)&y[0], (void *)&x[0], (unsigned int)((size_t)10 * sizeof(float)));
  for (i = 0; i < 10; i++) {
    t3_torque[i] = y[i];
  }

  for (i = 0; i < 18; i++) {
    b_x[i] = bytes[i + 40];
  }

  memcpy((void *)&t3_telemetry[0], (void *)&b_x[0], (unsigned int)((size_t)9 *
          sizeof(short)));
  memcpy(&bus->userInputs.torque[0], &t3_torque[0], 10U * sizeof(double));
  for (i = 0; i < 9; i++) {
    bus->userInputs.telemetry[i] = t3_telemetry[i];
  }

  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 58];
  }

  memcpy((void *)&b_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(int)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 62];
  }

  memcpy((void *)&c_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 66];
  }

  memcpy((void *)&d_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 40; i++) {
    x[i] = bytes[i + 70];
  }

  memcpy((void *)&y[0], (void *)&x[0], (unsigned int)((size_t)10 * sizeof(float)));
  for (i = 0; i < 10; i++) {
    t3_torque[i] = y[i];
  }

  for (i = 0; i < 40; i++) {
    x[i] = bytes[i + 110];
  }

  memcpy((void *)&y[0], (void *)&x[0], (unsigned int)((size_t)10 * sizeof(float)));
  bus->control.type = b_y;
  bus->control.Kff1 = c_y;
  bus->control.Kff2 = d_y;
  for (i = 0; i < 10; i++) {
    bus->control.motorPositionsDesired[i] = t3_torque[i];
    bus->control.motorVelocitiesDesired[i] = y[i];
  }

  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 150];
  }

  memcpy((void *)&b_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(int)));
  for (i = 0; i < 12; i++) {
    d_x[i] = bytes[i + 154];
  }

  memcpy((void *)&e_y[0], (void *)&d_x[0], (unsigned int)((size_t)3 * sizeof
          (float)));
  bus->inekf.enabled = b_y;
  for (i = 0; i < 3; i++) {
    bus->inekf.velocity[i] = e_y[i];
  }

  memcpy(&e_x[0], &bytes[166], 80U * sizeof(unsigned char));
  memcpy((void *)&f_y[0], (void *)&e_x[0], (unsigned int)((size_t)20 * sizeof
          (float)));
  for (i = 0; i < 20; i++) {
    t0_q[i] = f_y[i];
  }

  memcpy(&e_x[0], &bytes[246], 80U * sizeof(unsigned char));
  memcpy((void *)&f_y[0], (void *)&e_x[0], (unsigned int)((size_t)20 * sizeof
          (float)));
  for (i = 0; i < 20; i++) {
    bus->state.q[i] = t0_q[i];
    bus->state.dq[i] = f_y[i];
  }
}
