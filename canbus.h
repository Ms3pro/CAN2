#ifndef CANBUS_H
#define CANBUS_H

#define CAN0_ACTIVE     1         // 0 == DISABLED , 1 == ENABLED
#define CAN0_RATE       500       // eg 500 == 500kbps
//#define CAN0_STD_EXT    0         // 0 == STD 11bit , 1 == EXT 29bit
const int CAN0_INT = 3; // Прерывание на пине 2         // Set INT to pin 2
#define CAN0_CS         53        // Set CS to pin 11

#define CAN1_ACTIVE     1         // 0 == DISABLED , 1 == ENABLED
#define CAN1_RATE       500       // eg 500 == 500kbps
#define CAN1_STD_EXT    0         // 0 == STD 11bit , 1 == EXT 29bit
const int CAN1_INT = 2; // Прерывание на пине 2         // Set INT to pin 3
#define CAN1_CS         53        // Set CS to pin 12

void CAN0_INT_routine();
void CAN1_INT_routine();
void initialiseCAN0();
void initialiseCAN1();
void Send_CAN0_message(uint16_t theaddress, byte *thedata);
void Send_CAN1_message(uint16_t theaddress, byte *thedata);
void receive_CAN0_message();
void receive_CAN1_message();

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];

uint8_t senddata[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

//≪************************************************************************************************************************************************************************************≫//

unsigned int textCounter = 0;
//≪************************************************************************************************************************************************************************************≫//
//≪***************************************************************************[<<< GPIO_1-2 CAN >>>]***********************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
int ADC17, ADC18, ADC19, ADC20, ADC21, ADC22, ADC23, ADC24, ADC25, ADC26, ADC27, ADC28, ADC29, ADC30, ADC31, ADC32, ADC33, ADC34, ADC35, ADC36, ADC37, ADC38, ADC39, ADC40, ADC41, ADC42, 
//17___________________________________________________________________________________________________________________________________________________________________________________//  
 ADC43, ADC44, ADC45, ADC46, ADC47, ADC48,      DGIN29, DGIN30, DGIN31, DGIN32, DGIN33, DGIN34, DGIN35, DGIN36, DGIN37, DGIN38, DGIN39, DGIN40, DGIN41, DGIN42, DGIN43, DGIN44, DGIN45,    
//18___________________________________________________________________________________________________________________________________________________________________________________//
 DGIN46, DGIN47, DGIN48, DGIN49, DGIN50, DGIN51, DGIN52, DGIN53, DGIN54, DGIN55, DGIN56,      DIGOUT12, DIGOUT13, DIGOUT14, DIGOUT15, DIGOUT16, DIGOUT17, DIGOUT18, DIGOUT19, DIGOUT20,  
//19___________________________________________________________________________________________________________________________________________________________________________________//
 DIGOUT21, DIGOUT22, DIGOUT23, DIGOUT24, DIGOUT25, DIGOUT26, DIGOUT27, DIGOUT28, DIGOUT29, DIGOUT30, DIGOUT31, DIGOUT32, DIGOUT33,
//20___________________________________________________________________________________________________________________________________________________________________________________//
//≪*************************************************************************************************************************************************************************************≫//
//≪***************************************************************************[<<< MEGASQUIRT CAN >>>]**********************************************************************************≫//
//≪*************************************************************************************************************************************************************************************≫//
//1________________________________________________________________________________________________________________________________________________________________________________________//
 seconds,pw1,pw2,rpm,adv_deg,squirt,engine,afrtgt1,afrtgt2,baro,MAP,mat,tps, CLT, BATT, KNOCK, EGOC1, EGOC2, AIRC,TPSaccel, TPSfuelcut, WARMUPCOR, BAROCOR, TOTALCOR, VE1, VE2,
//2________________________________________________________________________________________________________________________________________________________________________________________//
 IDLESTEPNUM,goldADVANCE,TPSdot,MAPdot,RPMdot,MAFload,fuelload,fuelcor,MAF,dwell,dwell_trl,status1,status2,status3,status6,status7,fuelload2,ignload,ignload2,airtemp,
//3________________________________________________________________________________________________________________________________________________________________________________________//
 wallfuel1,wallfuel2,sensors1,sensors2,sensors3,sensors4,sensors5,sensors6,sensors7,sensors8,sensors9,sensors10,sensors11,sensors12,sensors13,sensors14,sensors15,sensors16,
//4________________________________________________________________________________________________________________________________________________________________________________________//
 boost_targ_1,boost_targ_2,boostduty,boostduty2,maf_volts,pwseq1,pwseq2,pwseq3,pwseq4,pwseq5,pwseq6,pwseq7,pwseq8,pwseq9,pwseq10,pwseq11,pwseq12,pwseq13,pwseq14,pwseq15,pwseq16,
//5________________________________________________________________________________________________________________________________________________________________________________________//
 egt7,egt8,egt9,egt10,egt11,egt12,egt13,egt14,egt15,egt16,n2o_addfuel,n2o_retard,nitrous1_duty,nitrous2_duty,nitrous_timer_out,canpwmin1,canpwmin2,
//6________________________________________________________________________________________________________________________________________________________________________________________//
 canpwmin3,canpwmin4,afrload,eaeload,tpsadc,cl_idle_targ_rpm,EAEfcor1,EAEfcor2,VSS1dot,VSS2dot,accelx,accely,accelz,stream_level,water_duty,
//7________________________________________________________________________________________________________________________________________________________________________________________//
 AFR1,AFR2,AFR3,AFR4,AFR5,AFR6,AFR7,AFR8,AFR9,AFR10,AFR11,AFR12,AFR13,AFR14,AFR15,AFR16,duty_pwm1,duty_pwm2,duty_pwm3,duty_pwm4,duty_pwm5,duty_pwm6,duty_pwm7,duty_pwm8,gear,status8,
//8________________________________________________________________________________________________________________________________________________________________________________________//
 EGOv1,EGOv2,EGOv3,EGOv4,EGOv5,EGOv6,EGOcor1,EGOcor2,EGOcor3,EGOcor4,EGOcor5,EGOcor6,
//9________________________________________________________________________________________________________________________________________________________________________________________//
 EGOcor9,EGOcor10,EGOcor11,EGOcor12,EGOcor13,EGOcor14,EGOcor15,EGOcor16,VSS1,VSS2,VSS3,VSS4,synccnt,syncreason,sd_filenum,sd_error,sd_phase,sd_status,timing_err,
//10_______________________________________________________________________________________________________________________________________________________________________________________//
 vvt_ang1,vvt_ang2,vvt_ang3,vvt_ang4,vvt_target1,vvt_target2,vvt_target3,vvt_target4,vvt_duty1,vvt_duty2,vvt_duty3,vvt_duty4,inj_timing_pri,inj_timing_sec,fuel_pct,tps_accel,SS1,SS2,
//11_______________________________________________________________________________________________________________________________________________________________________________________//
 knock_cyl1,knock_cyl2,knock_cyl3,knock_cyl4,knock_cyl5,knock_cyl6,
//12_______________________________________________________________________________________________________________________________________________________________________________________//
 map_accel,total_accel,launch_timer,launch_retard,porta,portb,porteh,portk,portmj,portp,portt,cel_errorcode,canin1,canin2,canout,knk_rtd,fuelflow,fuelcons,fuel_press1,fuel_press2,
//13_______________________________________________________________________________________________________________________________________________________________________________________//
 fuel_temp1,fuel_temp2,batt_cur,fp_duty,alt_duty,load_duty,alt_targv,cel_status,looptime,fueltemp_cor,fuelpress_cor,ltt_cor,sp1,tc_retard,cel_retard,fc_retard,als_addfuel,base_advance,
//14_______________________________________________________________________________________________________________________________________________________________________________________//
 idle_cor_advance,mat_retard,flex_advance,adv1,adv2,adv3,adv4,revlim_retard,als_timing,ext_advance,deadtime1,launch_timing,step3_timing,vsslaunch_retard,cel_status2,
//15_______________________________________________________________________________________________________________________________________________________________________________________//
 generic_pid_duty1,generic_pid_duty2;
//16_______________________________________________________________________________________________________________________________________________________________________________________//      

#endif