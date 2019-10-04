#include "cassie_slrt_data_t.h"
#include <stddef.h>
#include <string.h>

static DiagnosticCodes convert_to_enum_DiagnosticCodes(short u);
static DiagnosticCodes convert_to_enum_DiagnosticCodes(short u)
{
  DiagnosticCodes y;
  if (u == 0) {
    y = EMPTY;
  } else if (u == 5) {
    y = LEFT_HIP_NOT_CALIB;
  } else if (u == 6) {
    y = LEFT_KNEE_NOT_CALIB;
  } else if (u == 7) {
    y = RIGHT_HIP_NOT_CALIB;
  } else if (u == 8) {
    y = RIGHT_KNEE_NOT_CALIB;
  } else if (u == 10) {
    y = ETHERCAT_GENERIC;
  } else if (u == 11) {
    y = ETHERCAT_HOTCONNECT;
  } else if (u == 200) {
    y = LOW_BATTERY_CHARGE;
  } else if (u == 205) {
    y = HIGH_CPU_TEMP;
  } else if (u == 210) {
    y = HIGH_VTM_TEMP;
  } else if (u == 215) {
    y = HIGH_ELMO_DRIVE_TEMP;
  } else if (u == 220) {
    y = HIGH_STATOR_TEMP;
  } else if (u == 221) {
    y = LOW_ELMO_LINK_VOLTAGE;
  } else if (u == 225) {
    y = HIGH_BATTERY_TEMP;
  } else if (u == 230) {
    y = RADIO_DATA_BAD;
  } else if (u == 231) {
    y = RADIO_SIGNAL_BAD;
  } else if (u == 235) {
    y = BMS_DATA_BAD;
  } else if (u == 236) {
    y = VECTORNAV_DATA_BAD;
  } else if (u == 240) {
    y = VPE_GYRO_SATURATION;
  } else if (u == 241) {
    y = VPE_MAG_SATURATION;
  } else if (u == 242) {
    y = VPE_ACC_SATURATION;
  } else if (u == 245) {
    y = VPE_ATTITUDE_BAD;
  } else if (u == 246) {
    y = VPE_ATTITUDE_NOT_TRACKING;
  } else if (u == 400) {
    y = ETHERCAT_DC_ERROR;
  } else if (u == 410) {
    y = ETHERCAT_ERROR;
  } else if (u == 411) {
    y = ETHERCAT_SCANBUS;
  } else if (u == 590) {
    y = LOAD_CALIB_DATA_ERROR;
  } else if (u == 600) {
    y = CRITICAL_BATTERY_CHARGE;
  } else if (u == 605) {
    y = CRITICAL_CPU_TEMP;
  } else if (u == 610) {
    y = CRITICAL_VTM_TEMP;
  } else if (u == 615) {
    y = CRITICAL_ELMO_DRIVE_TEMP;
  } else if (u == 620) {
    y = CRITICAL_STATOR_TEMP;
  } else if (u == 625) {
    y = CRITICAL_BATTERY_TEMP;
  } else if (u == 630) {
    y = TORQUE_LIMIT_REACHED;
  } else if (u == 635) {
    y = JOINT_LIMIT_REACHED;
  } else if (u == 640) {
    y = ENCODER_FAILURE;
  } else if (u == 645) {
    y = SPRING_FAILURE;
  } else if (u == 700) {
    y = MEDULLA_HANG;
  } else if (u == 704) {
    y = CPU_OVERLOAD;
  } else if (u == 710) {
    y = SOFT_SHUTDOWN_ENABLED;
  } else if (u == 715) {
    y = SOFT_START_ENABLED;
  } else if (u == 720) {
    y = SAFE_TORQUE_OFF_ENABLED;
  } else if (u == 725) {
    y = NAN_DRIVE_TORQUE;
  } else if (u == 730) {
    y = INF_DRIVE_TORQUE;
  } else if (u == 735) {
    y = APPLICATION_STOPPED;
  } else {
    y = EMPTY;
  }

  return y;
}





void pack_cassie_slrt_data_t(const cassie_slrt_data_t *bus, unsigned char bytes
  [701])
{
  int i0;
  unsigned char y[24];
  int x[6];
  int b_x[21];
  unsigned char b_y[84];
  float c_x;
  unsigned char c_y[4];
  unsigned int d_x;
  unsigned char d_y[4];
  unsigned char e_y[4];
  unsigned char f_y[4];
  unsigned char g_y[48];
  float e_x[12];
  unsigned char h_y[4];
  unsigned char i_y[16];
  float f_x[4];
  unsigned char j_y[64];
  float g_x[16];
  unsigned short h_x;
  unsigned char k_y[2];
  unsigned char l_y[4];
  unsigned char m_y[4];
  unsigned char n_y[12];
  float i_x[3];
  unsigned char o_y[12];
  unsigned char p_y[12];
  unsigned char q_y[16];
  unsigned char r_y[2];
  unsigned char s_y[4];
  unsigned char t_y[2];
  unsigned char u_y[4];
  unsigned char v_y[4];
  unsigned char w_y[4];
  unsigned char x_y[4];
  unsigned char y_y[4];
  unsigned char ab_y[4];
  unsigned char bb_y[4];
  unsigned char cb_y[2];
  unsigned char db_y[4];
  unsigned char eb_y[4];
  unsigned char fb_y[4];
  unsigned char gb_y[4];
  unsigned char hb_y[4];
  unsigned char ib_y[4];
  unsigned char jb_y[4];
  unsigned char kb_y[2];
  unsigned char lb_y[4];
  unsigned char mb_y[4];
  unsigned char nb_y[4];
  unsigned char ob_y[4];
  unsigned char pb_y[4];
  unsigned char qb_y[4];
  unsigned char rb_y[4];
  unsigned char sb_y[2];
  unsigned char tb_y[4];
  unsigned char ub_y[4];
  unsigned char vb_y[4];
  unsigned char wb_y[4];
  unsigned char xb_y[4];
  unsigned char yb_y[4];
  unsigned char ac_y[4];
  unsigned char bc_y[2];
  unsigned char cc_y[4];
  unsigned char dc_y[4];
  unsigned char ec_y[4];
  unsigned char fc_y[4];
  unsigned char gc_y[4];
  unsigned char hc_y[4];
  unsigned char ic_y[4];
  unsigned char jc_y[4];
  unsigned char kc_y[4];
  unsigned char lc_y[4];
  unsigned char mc_y[4];
  unsigned char nc_y[4];
  unsigned char oc_y[4];
  unsigned char pc_y[2];
  unsigned char qc_y[2];
  unsigned char rc_y[4];
  unsigned char sc_y[4];
  unsigned char tc_y[4];
  unsigned char uc_y[4];
  unsigned char vc_y[4];
  unsigned char wc_y[4];
  unsigned char xc_y[4];
  unsigned char yc_y[2];
  unsigned char ad_y[4];
  unsigned char bd_y[4];
  unsigned char cd_y[4];
  unsigned char dd_y[4];
  unsigned char ed_y[4];
  unsigned char fd_y[4];
  unsigned char gd_y[4];
  unsigned char hd_y[2];
  unsigned char id_y[4];
  unsigned char jd_y[4];
  unsigned char kd_y[4];
  unsigned char ld_y[4];
  unsigned char md_y[4];
  unsigned char nd_y[4];
  unsigned char od_y[4];
  unsigned char pd_y[2];
  unsigned char qd_y[4];
  unsigned char rd_y[4];
  unsigned char sd_y[4];
  unsigned char td_y[4];
  unsigned char ud_y[4];
  unsigned char vd_y[4];
  unsigned char wd_y[4];
  unsigned char xd_y[2];
  unsigned char yd_y[4];
  unsigned char ae_y[4];
  unsigned char be_y[4];
  unsigned char ce_y[4];
  unsigned char de_y[4];
  unsigned char ee_y[4];
  unsigned char fe_y[4];
  unsigned char ge_y[4];
  unsigned char he_y[4];
  unsigned char ie_y[4];
  unsigned char je_y[4];
  unsigned char ke_y[4];
  unsigned char le_y[4];
  unsigned char me_y[2];
  unsigned char ne_y[8];
  short j_x[4];
  unsigned char oe_y[4];
  for (i0 = 0; i0 < 6; i0++) {
    x[i0] = bus->outputs.pelvis.targetPc.etherCatStatus[i0];
  }

  memcpy((void *)&y[0], (void *)&x[0], (unsigned int)((size_t)24 * sizeof
          (unsigned char)));
  memcpy(&b_x[0], &bus->outputs.pelvis.targetPc.etherCatNotifications[0], 21U *
         sizeof(int));
  memcpy((void *)&b_y[0], (void *)&b_x[0], (unsigned int)((size_t)84 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.targetPc.taskExecutionTime;
  memcpy((void *)&c_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  d_x = bus->outputs.pelvis.targetPc.overloadCounter;
  memcpy((void *)&d_y[0], (void *)&d_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.targetPc.cpuTemperature;
  memcpy((void *)&e_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.battery.stateOfCharge;
  memcpy((void *)&f_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 12; i0++) {
    e_x[i0] = (float)bus->outputs.pelvis.battery.voltage[i0];
  }

  memcpy((void *)&g_y[0], (void *)&e_x[0], (unsigned int)((size_t)48 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.battery.current;
  memcpy((void *)&h_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 4; i0++) {
    f_x[i0] = (float)bus->outputs.pelvis.battery.temperature[i0];
  }

  memcpy((void *)&i_y[0], (void *)&f_x[0], (unsigned int)((size_t)16 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 16; i0++) {
    g_x[i0] = (float)bus->outputs.pelvis.radio.channel[i0];
  }

  memcpy((void *)&j_y[0], (void *)&g_x[0], (unsigned int)((size_t)64 * sizeof
          (unsigned char)));
  h_x = bus->outputs.pelvis.vectorNav.vpeStatus;
  memcpy((void *)&k_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.vectorNav.pressure;
  memcpy((void *)&l_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.vectorNav.temperature;
  memcpy((void *)&m_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 3; i0++) {
    i_x[i0] = (float)bus->outputs.pelvis.vectorNav.magneticField[i0];
  }

  memcpy((void *)&n_y[0], (void *)&i_x[0], (unsigned int)((size_t)12 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 3; i0++) {
    i_x[i0] = (float)bus->outputs.pelvis.vectorNav.angularVelocity[i0];
  }

  memcpy((void *)&o_y[0], (void *)&i_x[0], (unsigned int)((size_t)12 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 3; i0++) {
    i_x[i0] = (float)bus->outputs.pelvis.vectorNav.linearAcceleration[i0];
  }

  memcpy((void *)&p_y[0], (void *)&i_x[0], (unsigned int)((size_t)12 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 4; i0++) {
    f_x[i0] = (float)bus->outputs.pelvis.vectorNav.orientation[i0];
  }

  memcpy((void *)&q_y[0], (void *)&f_x[0], (unsigned int)((size_t)16 * sizeof
          (unsigned char)));
  h_x = bus->outputs.pelvis.medullaCpuLoad;
  memcpy((void *)&r_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.pelvis.vtmTemperature;
  memcpy((void *)&s_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.leftLeg.hipRollDrive.statusWord;
  memcpy((void *)&t_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.position;
  memcpy((void *)&u_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.velocity;
  memcpy((void *)&v_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.torque;
  memcpy((void *)&w_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.driveTemperature;
  memcpy((void *)&x_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.dcLinkVoltage;
  memcpy((void *)&y_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.torqueLimit;
  memcpy((void *)&ab_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipRollDrive.gearRatio;
  memcpy((void *)&bb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.leftLeg.hipYawDrive.statusWord;
  memcpy((void *)&cb_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.position;
  memcpy((void *)&db_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.velocity;
  memcpy((void *)&eb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.torque;
  memcpy((void *)&fb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.driveTemperature;
  memcpy((void *)&gb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.dcLinkVoltage;
  memcpy((void *)&hb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.torqueLimit;
  memcpy((void *)&ib_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipYawDrive.gearRatio;
  memcpy((void *)&jb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.leftLeg.hipPitchDrive.statusWord;
  memcpy((void *)&kb_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.position;
  memcpy((void *)&lb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.velocity;
  memcpy((void *)&mb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.torque;
  memcpy((void *)&nb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.driveTemperature;
  memcpy((void *)&ob_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.dcLinkVoltage;
  memcpy((void *)&pb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.torqueLimit;
  memcpy((void *)&qb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.hipPitchDrive.gearRatio;
  memcpy((void *)&rb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.leftLeg.kneeDrive.statusWord;
  memcpy((void *)&sb_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.position;
  memcpy((void *)&tb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.velocity;
  memcpy((void *)&ub_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.torque;
  memcpy((void *)&vb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.driveTemperature;
  memcpy((void *)&wb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.dcLinkVoltage;
  memcpy((void *)&xb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.torqueLimit;
  memcpy((void *)&yb_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.kneeDrive.gearRatio;
  memcpy((void *)&ac_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.leftLeg.footDrive.statusWord;
  memcpy((void *)&bc_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.position;
  memcpy((void *)&cc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.velocity;
  memcpy((void *)&dc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.torque;
  memcpy((void *)&ec_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.driveTemperature;
  memcpy((void *)&fc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.dcLinkVoltage;
  memcpy((void *)&gc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.torqueLimit;
  memcpy((void *)&hc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footDrive.gearRatio;
  memcpy((void *)&ic_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.shinJoint.position;
  memcpy((void *)&jc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.shinJoint.velocity;
  memcpy((void *)&kc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.tarsusJoint.position;
  memcpy((void *)&lc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.tarsusJoint.velocity;
  memcpy((void *)&mc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footJoint.position;
  memcpy((void *)&nc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.leftLeg.footJoint.velocity;
  memcpy((void *)&oc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.leftLeg.medullaCpuLoad;
  memcpy((void *)&pc_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  h_x = bus->outputs.rightLeg.hipRollDrive.statusWord;
  memcpy((void *)&qc_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.position;
  memcpy((void *)&rc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.velocity;
  memcpy((void *)&sc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.torque;
  memcpy((void *)&tc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.driveTemperature;
  memcpy((void *)&uc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.dcLinkVoltage;
  memcpy((void *)&vc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.torqueLimit;
  memcpy((void *)&wc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipRollDrive.gearRatio;
  memcpy((void *)&xc_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.rightLeg.hipYawDrive.statusWord;
  memcpy((void *)&yc_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.position;
  memcpy((void *)&ad_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.velocity;
  memcpy((void *)&bd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.torque;
  memcpy((void *)&cd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.driveTemperature;
  memcpy((void *)&dd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.dcLinkVoltage;
  memcpy((void *)&ed_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.torqueLimit;
  memcpy((void *)&fd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipYawDrive.gearRatio;
  memcpy((void *)&gd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.rightLeg.hipPitchDrive.statusWord;
  memcpy((void *)&hd_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.position;
  memcpy((void *)&id_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.velocity;
  memcpy((void *)&jd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.torque;
  memcpy((void *)&kd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.driveTemperature;
  memcpy((void *)&ld_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.dcLinkVoltage;
  memcpy((void *)&md_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.torqueLimit;
  memcpy((void *)&nd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.hipPitchDrive.gearRatio;
  memcpy((void *)&od_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.rightLeg.kneeDrive.statusWord;
  memcpy((void *)&pd_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.position;
  memcpy((void *)&qd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.velocity;
  memcpy((void *)&rd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.torque;
  memcpy((void *)&sd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.driveTemperature;
  memcpy((void *)&td_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.dcLinkVoltage;
  memcpy((void *)&ud_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.torqueLimit;
  memcpy((void *)&vd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.kneeDrive.gearRatio;
  memcpy((void *)&wd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.rightLeg.footDrive.statusWord;
  memcpy((void *)&xd_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.position;
  memcpy((void *)&yd_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.velocity;
  memcpy((void *)&ae_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.torque;
  memcpy((void *)&be_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.driveTemperature;
  memcpy((void *)&ce_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.dcLinkVoltage;
  memcpy((void *)&de_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.torqueLimit;
  memcpy((void *)&ee_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footDrive.gearRatio;
  memcpy((void *)&fe_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.shinJoint.position;
  memcpy((void *)&ge_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.shinJoint.velocity;
  memcpy((void *)&he_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.tarsusJoint.position;
  memcpy((void *)&ie_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.tarsusJoint.velocity;
  memcpy((void *)&je_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footJoint.position;
  memcpy((void *)&ke_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->outputs.rightLeg.footJoint.velocity;
  memcpy((void *)&le_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  h_x = bus->outputs.rightLeg.medullaCpuLoad;
  memcpy((void *)&me_y[0], (void *)&h_x, (unsigned int)((size_t)2 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 4; i0++) {
    j_x[i0] = bus->outputs.messages[i0];
  }

  memcpy((void *)&ne_y[0], (void *)&j_x[0], (unsigned int)((size_t)8 * sizeof
          (unsigned char)));
  c_x = (float)bus->t;
  memcpy((void *)&oe_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 24; i0++) {
    bytes[i0] = y[i0];
  }

  memcpy(&bytes[24], &b_y[0], 84U * sizeof(unsigned char));
  bytes[120] = bus->outputs.pelvis.battery.dataGood;
  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 108] = c_y[i0];
    bytes[i0 + 112] = d_y[i0];
    bytes[i0 + 116] = e_y[i0];
    bytes[i0 + 121] = f_y[i0];
  }

  for (i0 = 0; i0 < 48; i0++) {
    bytes[i0 + 125] = g_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 173] = h_y[i0];
  }

  for (i0 = 0; i0 < 16; i0++) {
    bytes[i0 + 177] = i_y[i0];
  }

  bytes[193] = bus->outputs.pelvis.radio.radioReceiverSignalGood;
  bytes[194] = bus->outputs.pelvis.radio.receiverMedullaSignalGood;
  memcpy(&bytes[195], &j_y[0], sizeof(unsigned char) << 6);
  bytes[259] = bus->outputs.pelvis.vectorNav.dataGood;
  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 260] = k_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 262] = l_y[i0];
    bytes[i0 + 266] = m_y[i0];
  }

  for (i0 = 0; i0 < 12; i0++) {
    bytes[i0 + 270] = n_y[i0];
    bytes[i0 + 282] = o_y[i0];
    bytes[i0 + 294] = p_y[i0];
  }

  for (i0 = 0; i0 < 16; i0++) {
    bytes[i0 + 306] = q_y[i0];
  }

  bytes[322] = bus->outputs.pelvis.medullaCounter;
  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 323] = r_y[i0];
  }

  bytes[325] = bus->outputs.pelvis.bleederState;
  bytes[326] = bus->outputs.pelvis.leftReedSwitchState;
  bytes[327] = bus->outputs.pelvis.rightReedSwitchState;
  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 328] = s_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 332] = t_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 334] = u_y[i0];
    bytes[i0 + 338] = v_y[i0];
    bytes[i0 + 342] = w_y[i0];
    bytes[i0 + 346] = x_y[i0];
    bytes[i0 + 350] = y_y[i0];
    bytes[i0 + 354] = ab_y[i0];
    bytes[i0 + 358] = bb_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 362] = cb_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 364] = db_y[i0];
    bytes[i0 + 368] = eb_y[i0];
    bytes[i0 + 372] = fb_y[i0];
    bytes[i0 + 376] = gb_y[i0];
    bytes[i0 + 380] = hb_y[i0];
    bytes[i0 + 384] = ib_y[i0];
    bytes[i0 + 388] = jb_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 392] = kb_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 394] = lb_y[i0];
    bytes[i0 + 398] = mb_y[i0];
    bytes[i0 + 402] = nb_y[i0];
    bytes[i0 + 406] = ob_y[i0];
    bytes[i0 + 410] = pb_y[i0];
    bytes[i0 + 414] = qb_y[i0];
    bytes[i0 + 418] = rb_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 422] = sb_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 424] = tb_y[i0];
    bytes[i0 + 428] = ub_y[i0];
    bytes[i0 + 432] = vb_y[i0];
    bytes[i0 + 436] = wb_y[i0];
    bytes[i0 + 440] = xb_y[i0];
    bytes[i0 + 444] = yb_y[i0];
    bytes[i0 + 448] = ac_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 452] = bc_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 454] = cc_y[i0];
    bytes[i0 + 458] = dc_y[i0];
    bytes[i0 + 462] = ec_y[i0];
    bytes[i0 + 466] = fc_y[i0];
    bytes[i0 + 470] = gc_y[i0];
    bytes[i0 + 474] = hc_y[i0];
    bytes[i0 + 478] = ic_y[i0];
    bytes[i0 + 482] = jc_y[i0];
    bytes[i0 + 486] = kc_y[i0];
    bytes[i0 + 490] = lc_y[i0];
    bytes[i0 + 494] = mc_y[i0];
    bytes[i0 + 498] = nc_y[i0];
    bytes[i0 + 502] = oc_y[i0];
  }

  bytes[506] = bus->outputs.leftLeg.medullaCounter;
  bytes[509] = bus->outputs.leftLeg.reedSwitchState;
  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 507] = pc_y[i0];
    bytes[i0 + 510] = qc_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 512] = rc_y[i0];
    bytes[i0 + 516] = sc_y[i0];
    bytes[i0 + 520] = tc_y[i0];
    bytes[i0 + 524] = uc_y[i0];
    bytes[i0 + 528] = vc_y[i0];
    bytes[i0 + 532] = wc_y[i0];
    bytes[i0 + 536] = xc_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 540] = yc_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 542] = ad_y[i0];
    bytes[i0 + 546] = bd_y[i0];
    bytes[i0 + 550] = cd_y[i0];
    bytes[i0 + 554] = dd_y[i0];
    bytes[i0 + 558] = ed_y[i0];
    bytes[i0 + 562] = fd_y[i0];
    bytes[i0 + 566] = gd_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 570] = hd_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 572] = id_y[i0];
    bytes[i0 + 576] = jd_y[i0];
    bytes[i0 + 580] = kd_y[i0];
    bytes[i0 + 584] = ld_y[i0];
    bytes[i0 + 588] = md_y[i0];
    bytes[i0 + 592] = nd_y[i0];
    bytes[i0 + 596] = od_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 600] = pd_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 602] = qd_y[i0];
    bytes[i0 + 606] = rd_y[i0];
    bytes[i0 + 610] = sd_y[i0];
    bytes[i0 + 614] = td_y[i0];
    bytes[i0 + 618] = ud_y[i0];
    bytes[i0 + 622] = vd_y[i0];
    bytes[i0 + 626] = wd_y[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 630] = xd_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 632] = yd_y[i0];
    bytes[i0 + 636] = ae_y[i0];
    bytes[i0 + 640] = be_y[i0];
    bytes[i0 + 644] = ce_y[i0];
    bytes[i0 + 648] = de_y[i0];
    bytes[i0 + 652] = ee_y[i0];
    bytes[i0 + 656] = fe_y[i0];
    bytes[i0 + 660] = ge_y[i0];
    bytes[i0 + 664] = he_y[i0];
    bytes[i0 + 668] = ie_y[i0];
    bytes[i0 + 672] = je_y[i0];
    bytes[i0 + 676] = ke_y[i0];
    bytes[i0 + 680] = le_y[i0];
  }

  bytes[684] = bus->outputs.rightLeg.medullaCounter;
  for (i0 = 0; i0 < 2; i0++) {
    bytes[i0 + 685] = me_y[i0];
  }

  bytes[687] = bus->outputs.rightLeg.reedSwitchState;
  bytes[688] = bus->outputs.isCalibrated;
  for (i0 = 0; i0 < 8; i0++) {
    bytes[i0 + 689] = ne_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 697] = oe_y[i0];
  }
}

void unpack_cassie_slrt_data_t(const unsigned char bytes[701],
  cassie_slrt_data_t *bus)
{
  int i;
  int t23_etherCatStatus[6];
  unsigned char x[24];
  unsigned char b_x[84];
  int t23_etherCatNotifications[21];
  float y;
  unsigned char c_x[4];
  unsigned int b_y;
  float c_y;
  int t19_targetPc_etherCatStatus[6];
  float d_y;
  float e_y[12];
  unsigned char d_x[48];
  double t22_voltage[12];
  float f_y;
  float g_y[4];
  unsigned char e_x[16];
  double t22_temperature[4];
  unsigned char f_x[64];
  double t19_battery_temperature[4];
  float h_y[16];
  double t19_radio_channel[16];
  unsigned short i_y;
  unsigned char g_x[2];
  float j_y;
  float k_y;
  float l_y[3];
  unsigned char h_x[12];
  double t20_magneticField[3];
  double t20_angularVelocity[3];
  double t20_linearAcceleration[3];
  double t19_vectorNav_magneticField[3];
  double t19_vectorNav_angularVelocity[3];
  double t19_vectorNav_orientation[4];
  double t19_vectorNav_linearAcceleration[3];
  unsigned short m_y;
  float n_y;
  double t0_pelvis_battery_temperature[4];
  unsigned short o_y;
  float p_y;
  float q_y;
  float r_y;
  float s_y;
  float t_y;
  float u_y;
  float v_y;
  unsigned short w_y;
  float x_y;
  float y_y;
  float ab_y;
  float bb_y;
  float cb_y;
  float db_y;
  float eb_y;
  unsigned short fb_y;
  float gb_y;
  float hb_y;
  float ib_y;
  float jb_y;
  float kb_y;
  float lb_y;
  float mb_y;
  unsigned short nb_y;
  float ob_y;
  float pb_y;
  float qb_y;
  float rb_y;
  float sb_y;
  float tb_y;
  float ub_y;
  unsigned short vb_y;
  float wb_y;
  float xb_y;
  float yb_y;
  float ac_y;
  float bc_y;
  float cc_y;
  float dc_y;
  float ec_y;
  float fc_y;
  float gc_y;
  float hc_y;
  float ic_y;
  float jc_y;
  unsigned short kc_y;
  unsigned short lc_y;
  float mc_y;
  float nc_y;
  float oc_y;
  float pc_y;
  float qc_y;
  float rc_y;
  float sc_y;
  unsigned short tc_y;
  float uc_y;
  float vc_y;
  float wc_y;
  float xc_y;
  float yc_y;
  float ad_y;
  float bd_y;
  unsigned short cd_y;
  float dd_y;
  float ed_y;
  float fd_y;
  float gd_y;
  float hd_y;
  float id_y;
  float jd_y;
  unsigned short kd_y;
  float ld_y;
  float md_y;
  float nd_y;
  float od_y;
  float pd_y;
  float qd_y;
  float rd_y;
  unsigned short sd_y;
  float td_y;
  float ud_y;
  float vd_y;
  float wd_y;
  float xd_y;
  float yd_y;
  float ae_y;
  float be_y;
  float ce_y;
  float de_y;
  float ee_y;
  float fe_y;
  float ge_y;
  unsigned short he_y;
  short ie_y[4];
  unsigned char i_x[8];
  DiagnosticCodes t0_messages[4];
  for (i = 0; i < 24; i++) {
    x[i] = bytes[i];
  }

  memcpy((void *)&t23_etherCatStatus[0], (void *)&x[0], (unsigned int)((size_t)6
          * sizeof(int)));
  memcpy(&b_x[0], &bytes[24], 84U * sizeof(unsigned char));
  memcpy((void *)&t23_etherCatNotifications[0], (void *)&b_x[0], (unsigned int)
         ((size_t)21 * sizeof(int)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 108];
  }

  memcpy((void *)&y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 112];
  }

  memcpy((void *)&b_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned int)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 116];
  }

  memcpy((void *)&c_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 6; i++) {
    t19_targetPc_etherCatStatus[i] = t23_etherCatStatus[i];
  }

  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 121];
  }

  memcpy((void *)&d_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 48; i++) {
    d_x[i] = bytes[i + 125];
  }

  memcpy((void *)&e_y[0], (void *)&d_x[0], (unsigned int)((size_t)12 * sizeof
          (float)));
  for (i = 0; i < 12; i++) {
    t22_voltage[i] = e_y[i];
  }

  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 173];
  }

  memcpy((void *)&f_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 16; i++) {
    e_x[i] = bytes[i + 177];
  }

  memcpy((void *)&g_y[0], (void *)&e_x[0], (unsigned int)((size_t)4 * sizeof
          (float)));
  for (i = 0; i < 4; i++) {
    t22_temperature[i] = g_y[i];
  }

  for (i = 0; i < 4; i++) {
    t19_battery_temperature[i] = t22_temperature[i];
  }

  memcpy(&f_x[0], &bytes[195], sizeof(unsigned char) << 6);
  memcpy((void *)&h_y[0], (void *)&f_x[0], (unsigned int)((size_t)16 * sizeof
          (float)));
  for (i = 0; i < 16; i++) {
    t19_radio_channel[i] = h_y[i];
  }

  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 260];
  }

  memcpy((void *)&i_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 262];
  }

  memcpy((void *)&j_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 266];
  }

  memcpy((void *)&k_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 12; i++) {
    h_x[i] = bytes[i + 270];
  }

  memcpy((void *)&l_y[0], (void *)&h_x[0], (unsigned int)((size_t)3 * sizeof
          (float)));
  for (i = 0; i < 3; i++) {
    t20_magneticField[i] = l_y[i];
  }

  for (i = 0; i < 12; i++) {
    h_x[i] = bytes[i + 282];
  }

  memcpy((void *)&l_y[0], (void *)&h_x[0], (unsigned int)((size_t)3 * sizeof
          (float)));
  for (i = 0; i < 3; i++) {
    t20_angularVelocity[i] = l_y[i];
  }

  for (i = 0; i < 12; i++) {
    h_x[i] = bytes[i + 294];
  }

  memcpy((void *)&l_y[0], (void *)&h_x[0], (unsigned int)((size_t)3 * sizeof
          (float)));
  for (i = 0; i < 3; i++) {
    t20_linearAcceleration[i] = l_y[i];
  }

  for (i = 0; i < 16; i++) {
    e_x[i] = bytes[i + 306];
  }

  memcpy((void *)&g_y[0], (void *)&e_x[0], (unsigned int)((size_t)4 * sizeof
          (float)));
  for (i = 0; i < 4; i++) {
    t22_temperature[i] = g_y[i];
  }

  for (i = 0; i < 3; i++) {
    t19_vectorNav_magneticField[i] = t20_magneticField[i];
    t19_vectorNav_angularVelocity[i] = t20_angularVelocity[i];
    t19_vectorNav_linearAcceleration[i] = t20_linearAcceleration[i];
  }

  for (i = 0; i < 4; i++) {
    t19_vectorNav_orientation[i] = t22_temperature[i];
  }

  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 323];
  }

  memcpy((void *)&m_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 328];
  }

  memcpy((void *)&n_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 6; i++) {
    t23_etherCatStatus[i] = t19_targetPc_etherCatStatus[i];
  }

  for (i = 0; i < 4; i++) {
    t0_pelvis_battery_temperature[i] = t19_battery_temperature[i];
  }

  for (i = 0; i < 3; i++) {
    t20_magneticField[i] = t19_vectorNav_magneticField[i];
    t20_angularVelocity[i] = t19_vectorNav_angularVelocity[i];
    t20_linearAcceleration[i] = t19_vectorNav_linearAcceleration[i];
  }

  for (i = 0; i < 4; i++) {
    t22_temperature[i] = t19_vectorNav_orientation[i];
  }

  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 332];
  }

  memcpy((void *)&o_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 334];
  }

  memcpy((void *)&p_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 338];
  }

  memcpy((void *)&q_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 342];
  }

  memcpy((void *)&r_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 346];
  }

  memcpy((void *)&s_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 350];
  }

  memcpy((void *)&t_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 354];
  }

  memcpy((void *)&u_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 358];
  }

  memcpy((void *)&v_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 362];
  }

  memcpy((void *)&w_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 364];
  }

  memcpy((void *)&x_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 368];
  }

  memcpy((void *)&y_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 372];
  }

  memcpy((void *)&ab_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 376];
  }

  memcpy((void *)&bb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 380];
  }

  memcpy((void *)&cb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 384];
  }

  memcpy((void *)&db_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 388];
  }

  memcpy((void *)&eb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 392];
  }

  memcpy((void *)&fb_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 394];
  }

  memcpy((void *)&gb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 398];
  }

  memcpy((void *)&hb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 402];
  }

  memcpy((void *)&ib_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 406];
  }

  memcpy((void *)&jb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 410];
  }

  memcpy((void *)&kb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 414];
  }

  memcpy((void *)&lb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 418];
  }

  memcpy((void *)&mb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 422];
  }

  memcpy((void *)&nb_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 424];
  }

  memcpy((void *)&ob_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 428];
  }

  memcpy((void *)&pb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 432];
  }

  memcpy((void *)&qb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 436];
  }

  memcpy((void *)&rb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 440];
  }

  memcpy((void *)&sb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 444];
  }

  memcpy((void *)&tb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 448];
  }

  memcpy((void *)&ub_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 452];
  }

  memcpy((void *)&vb_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 454];
  }

  memcpy((void *)&wb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 458];
  }

  memcpy((void *)&xb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 462];
  }

  memcpy((void *)&yb_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 466];
  }

  memcpy((void *)&ac_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 470];
  }

  memcpy((void *)&bc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 474];
  }

  memcpy((void *)&cc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 478];
  }

  memcpy((void *)&dc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 482];
  }

  memcpy((void *)&ec_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 486];
  }

  memcpy((void *)&fc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 490];
  }

  memcpy((void *)&gc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 494];
  }

  memcpy((void *)&hc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 498];
  }

  memcpy((void *)&ic_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 502];
  }

  memcpy((void *)&jc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 507];
  }

  memcpy((void *)&kc_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 510];
  }

  memcpy((void *)&lc_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 512];
  }

  memcpy((void *)&mc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 516];
  }

  memcpy((void *)&nc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 520];
  }

  memcpy((void *)&oc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 524];
  }

  memcpy((void *)&pc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 528];
  }

  memcpy((void *)&qc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 532];
  }

  memcpy((void *)&rc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 536];
  }

  memcpy((void *)&sc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 540];
  }

  memcpy((void *)&tc_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 542];
  }

  memcpy((void *)&uc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 546];
  }

  memcpy((void *)&vc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 550];
  }

  memcpy((void *)&wc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 554];
  }

  memcpy((void *)&xc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 558];
  }

  memcpy((void *)&yc_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 562];
  }

  memcpy((void *)&ad_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 566];
  }

  memcpy((void *)&bd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 570];
  }

  memcpy((void *)&cd_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 572];
  }

  memcpy((void *)&dd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 576];
  }

  memcpy((void *)&ed_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 580];
  }

  memcpy((void *)&fd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 584];
  }

  memcpy((void *)&gd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 588];
  }

  memcpy((void *)&hd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 592];
  }

  memcpy((void *)&id_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 596];
  }

  memcpy((void *)&jd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 600];
  }

  memcpy((void *)&kd_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 602];
  }

  memcpy((void *)&ld_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 606];
  }

  memcpy((void *)&md_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 610];
  }

  memcpy((void *)&nd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 614];
  }

  memcpy((void *)&od_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 618];
  }

  memcpy((void *)&pd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 622];
  }

  memcpy((void *)&qd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 626];
  }

  memcpy((void *)&rd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 630];
  }

  memcpy((void *)&sd_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 632];
  }

  memcpy((void *)&td_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 636];
  }

  memcpy((void *)&ud_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 640];
  }

  memcpy((void *)&vd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 644];
  }

  memcpy((void *)&wd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 648];
  }

  memcpy((void *)&xd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 652];
  }

  memcpy((void *)&yd_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 656];
  }

  memcpy((void *)&ae_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 660];
  }

  memcpy((void *)&be_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 664];
  }

  memcpy((void *)&ce_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 668];
  }

  memcpy((void *)&de_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 672];
  }

  memcpy((void *)&ee_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 676];
  }

  memcpy((void *)&fe_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 680];
  }

  memcpy((void *)&ge_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  for (i = 0; i < 2; i++) {
    g_x[i] = bytes[i + 685];
  }

  memcpy((void *)&he_y, (void *)&g_x[0], (unsigned int)((size_t)1 * sizeof
          (unsigned short)));
  for (i = 0; i < 8; i++) {
    i_x[i] = bytes[i + 689];
  }

  memcpy((void *)&ie_y[0], (void *)&i_x[0], (unsigned int)((size_t)4 * sizeof
          (short)));
  for (i = 0; i < 4; i++) {
    t0_messages[i] = convert_to_enum_DiagnosticCodes(ie_y[i]);
  }

  for (i = 0; i < 6; i++) {
    bus->outputs.pelvis.targetPc.etherCatStatus[i] = t23_etherCatStatus[i];
  }

  memcpy(&bus->outputs.pelvis.targetPc.etherCatNotifications[0],
         &t23_etherCatNotifications[0], 21U * sizeof(int));
  bus->outputs.pelvis.targetPc.taskExecutionTime = y;
  bus->outputs.pelvis.targetPc.overloadCounter = b_y;
  bus->outputs.pelvis.targetPc.cpuTemperature = c_y;
  bus->outputs.pelvis.battery.dataGood = (bytes[120] != 0);
  bus->outputs.pelvis.battery.stateOfCharge = d_y;
  memcpy(&bus->outputs.pelvis.battery.voltage[0], &t22_voltage[0], 12U * sizeof
         (double));
  bus->outputs.pelvis.battery.current = f_y;
  for (i = 0; i < 4; i++) {
    bus->outputs.pelvis.battery.temperature[i] = t0_pelvis_battery_temperature[i];
  }

  bus->outputs.pelvis.radio.radioReceiverSignalGood = (bytes[193] != 0);
  bus->outputs.pelvis.radio.receiverMedullaSignalGood = (bytes[194] != 0);
  memcpy(&bus->outputs.pelvis.radio.channel[0], &t19_radio_channel[0], sizeof
         (double) << 4);
  bus->outputs.pelvis.vectorNav.dataGood = (bytes[259] != 0);
  bus->outputs.pelvis.vectorNav.vpeStatus = i_y;
  bus->outputs.pelvis.vectorNav.pressure = j_y;
  bus->outputs.pelvis.vectorNav.temperature = k_y;
  for (i = 0; i < 3; i++) {
    bus->outputs.pelvis.vectorNav.magneticField[i] = t20_magneticField[i];
    bus->outputs.pelvis.vectorNav.angularVelocity[i] = t20_angularVelocity[i];
    bus->outputs.pelvis.vectorNav.linearAcceleration[i] =
      t20_linearAcceleration[i];
  }

  bus->outputs.pelvis.medullaCounter = bytes[322];
  bus->outputs.pelvis.medullaCpuLoad = m_y;
  bus->outputs.pelvis.bleederState = (bytes[325] != 0);
  bus->outputs.pelvis.leftReedSwitchState = (bytes[326] != 0);
  bus->outputs.pelvis.rightReedSwitchState = (bytes[327] != 0);
  bus->outputs.pelvis.vtmTemperature = n_y;
  bus->outputs.leftLeg.hipRollDrive.statusWord = o_y;
  bus->outputs.leftLeg.hipRollDrive.position = p_y;
  bus->outputs.leftLeg.hipRollDrive.velocity = q_y;
  bus->outputs.leftLeg.hipRollDrive.torque = r_y;
  bus->outputs.leftLeg.hipRollDrive.driveTemperature = s_y;
  bus->outputs.leftLeg.hipRollDrive.dcLinkVoltage = t_y;
  bus->outputs.leftLeg.hipRollDrive.torqueLimit = u_y;
  bus->outputs.leftLeg.hipRollDrive.gearRatio = v_y;
  bus->outputs.leftLeg.hipYawDrive.statusWord = w_y;
  bus->outputs.leftLeg.hipYawDrive.position = x_y;
  bus->outputs.leftLeg.hipYawDrive.velocity = y_y;
  bus->outputs.leftLeg.hipYawDrive.torque = ab_y;
  bus->outputs.leftLeg.hipYawDrive.driveTemperature = bb_y;
  bus->outputs.leftLeg.hipYawDrive.dcLinkVoltage = cb_y;
  bus->outputs.leftLeg.hipYawDrive.torqueLimit = db_y;
  bus->outputs.leftLeg.hipYawDrive.gearRatio = eb_y;
  bus->outputs.leftLeg.hipPitchDrive.statusWord = fb_y;
  bus->outputs.leftLeg.hipPitchDrive.position = gb_y;
  bus->outputs.leftLeg.hipPitchDrive.velocity = hb_y;
  bus->outputs.leftLeg.hipPitchDrive.torque = ib_y;
  bus->outputs.leftLeg.hipPitchDrive.driveTemperature = jb_y;
  bus->outputs.leftLeg.hipPitchDrive.dcLinkVoltage = kb_y;
  bus->outputs.leftLeg.hipPitchDrive.torqueLimit = lb_y;
  bus->outputs.leftLeg.hipPitchDrive.gearRatio = mb_y;
  bus->outputs.leftLeg.kneeDrive.statusWord = nb_y;
  bus->outputs.leftLeg.kneeDrive.position = ob_y;
  bus->outputs.leftLeg.kneeDrive.velocity = pb_y;
  bus->outputs.leftLeg.kneeDrive.torque = qb_y;
  bus->outputs.leftLeg.kneeDrive.driveTemperature = rb_y;
  bus->outputs.leftLeg.kneeDrive.dcLinkVoltage = sb_y;
  bus->outputs.leftLeg.kneeDrive.torqueLimit = tb_y;
  bus->outputs.leftLeg.kneeDrive.gearRatio = ub_y;
  bus->outputs.leftLeg.footDrive.statusWord = vb_y;
  bus->outputs.leftLeg.footDrive.position = wb_y;
  bus->outputs.leftLeg.footDrive.velocity = xb_y;
  bus->outputs.leftLeg.footDrive.torque = yb_y;
  bus->outputs.leftLeg.footDrive.driveTemperature = ac_y;
  bus->outputs.leftLeg.footDrive.dcLinkVoltage = bc_y;
  bus->outputs.leftLeg.footDrive.torqueLimit = cc_y;
  bus->outputs.leftLeg.footDrive.gearRatio = dc_y;
  bus->outputs.leftLeg.shinJoint.position = ec_y;
  bus->outputs.leftLeg.shinJoint.velocity = fc_y;
  bus->outputs.leftLeg.tarsusJoint.position = gc_y;
  bus->outputs.leftLeg.tarsusJoint.velocity = hc_y;
  bus->outputs.leftLeg.footJoint.position = ic_y;
  bus->outputs.leftLeg.footJoint.velocity = jc_y;
  bus->outputs.leftLeg.medullaCounter = bytes[506];
  bus->outputs.leftLeg.medullaCpuLoad = kc_y;
  bus->outputs.leftLeg.reedSwitchState = (bytes[509] != 0);
  bus->outputs.rightLeg.hipRollDrive.statusWord = lc_y;
  bus->outputs.rightLeg.hipRollDrive.position = mc_y;
  bus->outputs.rightLeg.hipRollDrive.velocity = nc_y;
  bus->outputs.rightLeg.hipRollDrive.torque = oc_y;
  bus->outputs.rightLeg.hipRollDrive.driveTemperature = pc_y;
  bus->outputs.rightLeg.hipRollDrive.dcLinkVoltage = qc_y;
  bus->outputs.rightLeg.hipRollDrive.torqueLimit = rc_y;
  bus->outputs.rightLeg.hipRollDrive.gearRatio = sc_y;
  bus->outputs.rightLeg.hipYawDrive.statusWord = tc_y;
  bus->outputs.rightLeg.hipYawDrive.position = uc_y;
  bus->outputs.rightLeg.hipYawDrive.velocity = vc_y;
  bus->outputs.rightLeg.hipYawDrive.torque = wc_y;
  bus->outputs.rightLeg.hipYawDrive.driveTemperature = xc_y;
  bus->outputs.rightLeg.hipYawDrive.dcLinkVoltage = yc_y;
  bus->outputs.rightLeg.hipYawDrive.torqueLimit = ad_y;
  bus->outputs.rightLeg.hipYawDrive.gearRatio = bd_y;
  bus->outputs.rightLeg.hipPitchDrive.statusWord = cd_y;
  bus->outputs.rightLeg.hipPitchDrive.position = dd_y;
  bus->outputs.rightLeg.hipPitchDrive.velocity = ed_y;
  bus->outputs.rightLeg.hipPitchDrive.torque = fd_y;
  bus->outputs.rightLeg.hipPitchDrive.driveTemperature = gd_y;
  bus->outputs.rightLeg.hipPitchDrive.dcLinkVoltage = hd_y;
  bus->outputs.rightLeg.hipPitchDrive.torqueLimit = id_y;
  bus->outputs.rightLeg.hipPitchDrive.gearRatio = jd_y;
  bus->outputs.rightLeg.kneeDrive.statusWord = kd_y;
  bus->outputs.rightLeg.kneeDrive.position = ld_y;
  bus->outputs.rightLeg.kneeDrive.velocity = md_y;
  bus->outputs.rightLeg.kneeDrive.torque = nd_y;
  bus->outputs.rightLeg.kneeDrive.driveTemperature = od_y;
  bus->outputs.rightLeg.kneeDrive.dcLinkVoltage = pd_y;
  bus->outputs.rightLeg.kneeDrive.torqueLimit = qd_y;
  bus->outputs.rightLeg.kneeDrive.gearRatio = rd_y;
  bus->outputs.rightLeg.footDrive.statusWord = sd_y;
  bus->outputs.rightLeg.footDrive.position = td_y;
  bus->outputs.rightLeg.footDrive.velocity = ud_y;
  bus->outputs.rightLeg.footDrive.torque = vd_y;
  bus->outputs.rightLeg.footDrive.driveTemperature = wd_y;
  bus->outputs.rightLeg.footDrive.dcLinkVoltage = xd_y;
  bus->outputs.rightLeg.footDrive.torqueLimit = yd_y;
  bus->outputs.rightLeg.footDrive.gearRatio = ae_y;
  bus->outputs.rightLeg.shinJoint.position = be_y;
  bus->outputs.rightLeg.shinJoint.velocity = ce_y;
  bus->outputs.rightLeg.tarsusJoint.position = de_y;
  bus->outputs.rightLeg.tarsusJoint.velocity = ee_y;
  bus->outputs.rightLeg.footJoint.position = fe_y;
  bus->outputs.rightLeg.footJoint.velocity = ge_y;
  bus->outputs.rightLeg.medullaCounter = bytes[684];
  bus->outputs.rightLeg.medullaCpuLoad = he_y;
  bus->outputs.rightLeg.reedSwitchState = (bytes[687] != 0);
  bus->outputs.isCalibrated = (bytes[688] != 0);
  for (i = 0; i < 4; i++) {
    bus->outputs.pelvis.vectorNav.orientation[i] = t22_temperature[i];
    bus->outputs.messages[i] = t0_messages[i];
    c_x[i] = bytes[i + 697];
  }

  memcpy((void *)&y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->t = y;
}
