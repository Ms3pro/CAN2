void CAN0_INT_routine()
{ 
//receive_CAN0_message();
}
void initialiseCAN0()
{ 
uint8_t tryInit0 = 0;
START_INIT0: 
if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)                   
{
CAN0.setMode(MCP_NORMAL);
}
else
{
delay(100);
tryInit0++;
if (tryInit0<50){goto START_INIT0;} //retry 50 times before quiting init
}
}
void CAN1_INT_routine()
{ 
//receive_CAN1_message();
}
void initialiseCAN1()
{ 
uint8_t tryInit1 = 0;
START_INIT1: 
if(CAN1.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)                   
{
CAN1.setMode(MCP_NORMAL);
}
else
{
delay(100);
tryInit1++;
if (tryInit1<50){goto START_INIT1;} //retry 50 times before quiting init
}
}
//----------------------------------------------------------------------------------------
//void Send_CAN0_message(byte bcChan, uint16_t theaddress, byte *thedata)
//{
//byte sndStat = CAN0.sendMsgBuf(theaddress, 0, 8, thedata);    
//if(sndStat == CAN_OK)
   
//}
//----------------------------------------------------------------------------------------
//void Send_CAN1_message(byte bcChan, uint16_t theaddress, uint8_t *thedata)
//{
//byte sndStat = CAN1.sendMsgBuf(theaddress, 0, 8, thedata);
//if(sndStat == CAN_OK)

//}
//---------------------------------------------------------------------------------------------
void receive_CAN0_message()
{
if(!digitalRead(CAN0_INT))                         // If CAN0_INT pin is low, read receive buffer
{
CAN0.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
if((rxId & 0x80000000) == 0x80000000);     // Determine if ID is standard (11 bits) or extended (29 bits)
//else
//sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);
//if((rxId & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
//sprintf(msgString, " REMOTE REQUEST FRAME");
//} else {
//for(byte i = 0; i<len; i++){
//sprintf(msgString, " 0x%.2X", rxBuf[i]);
}
switch (rxId) {
//≪************************************************************************************************************************************************************************************≫//
//≪***************************************************************************[<<< GPIO_1_ADC-CAN >>>]*********************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 625: // dash broadcasting group
ADC17 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 626: // dash broadcasting group
ADC18 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 627: // dash broadcasting group
ADC19 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 628: // dash broadcasting group
ADC20 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 629: // dash broadcasting group
ADC21 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 630: // dash broadcasting group
ADC22 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 631: // dash broadcasting group
ADC23 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 632: // dash broadcasting group
ADC24 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 633: // dash broadcasting group
ADC25 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 634: // dash broadcasting group
ADC26 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 635: // dash broadcasting group
ADC27 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 636: // dash broadcasting group
ADC28 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 637: // dash broadcasting group
ADC29 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 638: // dash broadcasting group
ADC30 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 639: // dash broadcasting group
ADC31 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 640: // dash broadcasting group
ADC32 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪************************************************************************************************************************************************************************************≫//
//≪***************************************************************************[<<< GPIO_2_ADC-CAN >>>]*********************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 451: // dash broadcasting group
ADC33 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 452: // dash broadcasting group
ADC34 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 453: // dash broadcasting group
ADC35 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 454: // dash broadcasting group
ADC36 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 455: // dash broadcasting group
ADC37 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 456: // dash broadcasting group
ADC38 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 457: // dash broadcasting group
ADC39 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 458: // dash broadcasting group
ADC40 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 459: // dash broadcasting group
ADC41 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 460: // dash broadcasting group
ADC42 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 461: // dash broadcasting group
ADC43 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 462: // dash broadcasting group
ADC44 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 463: // dash broadcasting group
ADC45 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 464: // dash broadcasting group
ADC46 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
//≪************************************************************************************************************************************************************************************≫//
case 465: // dash broadcasting group
ADC47 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪*************************************************************************************************************************************************************************************≫//
case 466: // dash broadcasting group
ADC48 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
break;
//≪************************************************************************************************************************************************************************************≫//
case 1520: // dash broadcasting group
seconds = (float)(word(rxBuf[0], rxBuf[1]));  //Seconds ECU has been on
pw1 = (float)(word(rxBuf[2], rxBuf[3]));      //Main pulsewidth bank 1
pw2 = (float)(word(rxBuf[4], rxBuf[5]));      //Main pulsewidth bank 2
rpm = (float)(word(rxBuf[6], rxBuf[7]));      //Engine RPM
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1521: // dash broadcasting group
adv_deg  = (float)(word(rxBuf[0], rxBuf[1]));    //Final ignition spark advance
squirt = (float)(word(rxBuf[2],   rxBuf[3]));    //Bitfield of batch fire injector events
engine = (float)(word(rxBuf[4],   rxBuf[5]));    //Bitfield of engine status
afrtgt1 = (float)(word(rxBuf[6],  rxBuf[7]));    //Bank 1 AFR target
afrtgt2 = (float)(word(rxBuf[8],  rxBuf[9]));    //Bank 1 AFR target
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1522: // dash broadcasting group
baro = (float)(word(rxBuf[0], rxBuf[1]));   //Barometric pressure
MAP = (float)(word(rxBuf[2],  rxBuf[3]));   //Manifold air pressure
mat = (float)(word(rxBuf[4],  rxBuf[5]));   //Manifold air temperature
CLT = (float)(word(rxBuf[6],  rxBuf[7]));   //Coolant temperature
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1523: // dash broadcasting group
tps = (float)(word(rxBuf[0], rxBuf[1]));   //Throttle position
BATT = (float)(word(rxBuf[2], rxBuf[3]));  //Battery voltage
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1524: // dash broadcasting group
KNOCK = (float)(word(rxBuf[0], rxBuf[1]));  //Indication of knock input
EGOC1 = (float)(word(rxBuf[2], rxBuf[3]));  //EGO bank 1 correction
EGOC2 = (float)(word(rxBuf[4], rxBuf[5]));  //EGO bank 2 correction
AIRC = (float)(word(rxBuf[6], rxBuf[7]));   //Air density correction
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1525: // dash broadcasting group  
TPSaccel  = (float)(word(rxBuf[0], rxBuf[1]));   //TPS-based acceleration
TPSfuelcut = (float)(word(rxBuf[2], rxBuf[3]));  //TPS-based fuel cut
WARMUPCOR = (float)(word(rxBuf[4], rxBuf[5]));   //Warmup correction
BAROCOR = (float)(word(rxBuf[6], rxBuf[7]));     //Barometric fuel correction
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1526: // dash broadcasting group
TOTALCOR = (float)(word(rxBuf[0], rxBuf[1]));     //Total fuel correction
VE1 = (float)(word(rxBuf[2], rxBuf[3]));          //VE table/bank 1
VE2 = (float)(word(rxBuf[4], rxBuf[5]));          //VE table/bank 2
IDLESTEPNUM = (float)(word(rxBuf[6], rxBuf[7]));  //Stepper idle step number
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1527: // dash broadcasting group
goldADVANCE = (float)(word(rxBuf[0], rxBuf[1]));  //Cold advance
TPSdot = (float)(word(rxBuf[2], rxBuf[3]));       //Rate of change of TPS
MAPdot = (float)(word(rxBuf[4], rxBuf[5]));       //Rate of change of MAP
RPMdot = (float)(word(rxBuf[6], rxBuf[7]));       //Rate of change of RPM
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1528: // dash broadcasting group

fuelload = (float)(word(rxBuf[2], rxBuf[3]));   //Load' used for fuel table lookup
fuelcor = (float)(word(rxBuf[4], rxBuf[5]));    //Adjustment to fuel from Flex

break;
//≪*************************************************************************************************************************************************************************************≫//
case 1529: // dash broadcasting group
dwell = (float)(word(rxBuf[0], rxBuf[1]));      //Main ignition dwell
dwell_trl = (float)(word(rxBuf[2], rxBuf[3]));  //Trailing ignition dwell
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1530: // dash broadcasting group
status1 = (float)(word(rxBuf[0], rxBuf[1]));    //ECU status bitfield 1
status2 = (float)(word(rxBuf[2], rxBuf[3]));    //ECU status bitfield 2
status3 = (float)(word(rxBuf[4], rxBuf[5]));    //ECU status bitfield 3
status6 = (float)(word(rxBuf[6], rxBuf[7]));    //ECU status bitfield 6
status7 = (float)(word(rxBuf[8], rxBuf[9]));    //ECU status bitfield 7
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1531: // dash broadcasting group
fuelload2 = (float)(word(rxBuf[0], rxBuf[1]));   //Load' used for modifier fuel table lookup
ignload = (float)(word(rxBuf[2], rxBuf[3]));     //Load' used for ignition table lookup
ignload2 = (float)(word(rxBuf[4], rxBuf[5]));    //Load' used for modifier ignition table lookup
airtemp = (float)(word(rxBuf[6], rxBuf[7]));     //Estimated intake air temperature
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1532: // dash broadcasting group
wallfuel1 = (float)(word(rxBuf[0], rxBuf[1]));   //Calculated volume of fuel on intake walls from EAE - channel 1
wallfuel2 = (float)(word(rxBuf[2], rxBuf[3]));   //Calculated volume of fuel on intake walls from EAE - channel 2                    
break;
//≪*************************************************************************************************************************************************************************************≫//

//≪************************************************************************************************************************************************************************************≫//
case 1537: // dash broadcasting group
boost_targ_1 = (float)(word(rxBuf[0], rxBuf[1]));  //Target boost - channel 1
boost_targ_2 = (float)(word(rxBuf[2], rxBuf[3]));  //Target boost - channel 2
boostduty  = (float)(word(rxBuf[4], rxBuf[5]));    //Duty cycle on boost solenoid 1
boostduty2 = (float)(word(rxBuf[6], rxBuf[7]));    //Duty cycle on boost solenoid 2
maf_volts = (float)(word(rxBuf[6], rxBuf[7]));     //MAF voltage
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1538: // dash broadcasting group
pwseq1 = (float)(word(rxBuf[0], rxBuf[1])); //Sequential pulsewidth for cyl #1
pwseq2 = (float)(word(rxBuf[2], rxBuf[3])); //Sequential pulsewidth for cyl #2
pwseq3 = (float)(word(rxBuf[4], rxBuf[5])); //Sequential pulsewidth for cyl #3
pwseq4 = (float)(word(rxBuf[6], rxBuf[7])); //Sequential pulsewidth for cyl #4
break;
//≪************************************************************************************************************************************************************************************≫//
case 1539: // dash broadcasting group
pwseq5 = (float)(word(rxBuf[0], rxBuf[1])); //Sequential pulsewidth for cyl #5
pwseq6 = (float)(word(rxBuf[2], rxBuf[3])); //Sequential pulsewidth for cyl #6

break;
//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//
case 1547: // dash broadcasting group
canpwmin1 = (float)(word(rxBuf[0], rxBuf[1])); //PWM period 1 from remote board
canpwmin2 = (float)(word(rxBuf[2], rxBuf[3])); //PWM period 2 from remote board
canpwmin3 = (float)(word(rxBuf[4], rxBuf[5])); //PWM period 3 from remote board
canpwmin4 = (float)(word(rxBuf[6], rxBuf[7])); //PWM period 4 from remote board
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1548: // dash broadcasting group
afrload = (float)(word(rxBuf[0], rxBuf[1]));          //Load' used for AFR table lookups"
eaeload = (float)(word(rxBuf[2], rxBuf[3]));          //Load' used for EAE calc
tpsadc = (float)(word(rxBuf[4], rxBuf[5]));           //ADC count from TPS
cl_idle_targ_rpm = (float)(word(rxBuf[6], rxBuf[7])); //Closed-loop idle target RPM
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1549: // dash broadcasting group
EAEfcor1 = (float)(word(rxBuf[0], rxBuf[1])); //Fuel correction from EAE - channel 1 
EAEfcor2 = (float)(word(rxBuf[2], rxBuf[3])); //Fuel correction from EAE - channel 2
VSS1dot = (float)(word(rxBuf[4], rxBuf[5]));  //Rate of change of VSS1
VSS2dot = (float)(word(rxBuf[6], rxBuf[7]));  //Rate of change of VSS2
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1550: // dash broadcasting group

stream_level = (float)(word(rxBuf[6], rxBuf[7])); //Volume level on audio input
water_duty = (float)(word(rxBuf[8], rxBuf[9]));   //Duty cycle to water injection solenoid
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1551: // dash broadcasting group
AFR1 = (float)(word(rxBuf[0], rxBuf[1]));   //AFR cyl #1
AFR2 = (float)(word(rxBuf[2], rxBuf[3]));   //AFR cyl #2
AFR3 = (float)(word(rxBuf[4], rxBuf[5]));   //AFR cyl #3
AFR4 = (float)(word(rxBuf[6], rxBuf[7]));   //AFR cyl #4
AFR5 = (float)(word(rxBuf[8], rxBuf[9]));   //AFR cyl #5
AFR6 = (float)(word(rxBuf[10], rxBuf[11])); //AFR cyl #6
AFR7 = (float)(word(rxBuf[12], rxBuf[13])); //AFR cyl #7
AFR8 = (float)(word(rxBuf[14], rxBuf[15])); //AFR cyl #8
break;
//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//
case 1553: // dash broadcasting group
duty_pwm1 = (float)(word(rxBuf[0], rxBuf[1]));      //Generic PWM duty 1
duty_pwm2 = (float)(word(rxBuf[2], rxBuf[3]));      //Generic PWM duty 2
duty_pwm3 = (float)(word(rxBuf[4], rxBuf[5]));      //Generic PWM duty 3
duty_pwm4 = (float)(word(rxBuf[6], rxBuf[7]));      //Generic PWM duty 4
duty_pwm5 = (float)(word(rxBuf[8], rxBuf[9]));      //Generic PWM duty 5
duty_pwm6 = (float)(word(rxBuf[10], rxBuf[11]));    //Generic PWM duty 6
duty_pwm7 = (float)(word(rxBuf[12], rxBuf[13]));    //Generic PWM duty 7
duty_pwm8 = (float)(word(rxBuf[14], rxBuf[15]));    //Generic PWM duty 8
gear = (float)(word(rxBuf[16], rxBuf[17]));         //Current gear selected
status8 = (float)(word(rxBuf[18], rxBuf[19]));      //ECU status bitfield 8
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1554: // dash broadcasting group
EGOv1 = (float)(word(rxBuf[0], rxBuf[1])); //Voltage from O2 cyl #1
EGOv2 = (float)(word(rxBuf[2], rxBuf[3])); //Voltage from O2 cyl #2
EGOv3 = (float)(word(rxBuf[4], rxBuf[5])); //Voltage from O2 cyl #3
EGOv4 = (float)(word(rxBuf[6], rxBuf[7])); //Voltage from O2 cyl #4
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1555: // dash broadcasting group
EGOv5 = (float)(word(rxBuf[0], rxBuf[1])); //Voltage from O2 cy5 #5
EGOv6 = (float)(word(rxBuf[2], rxBuf[3])); //Voltage from O2 cy6 #6

break; 
//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//
case 1558: // dash broadcasting group
EGOcor1 = (float)(word(rxBuf[0], rxBuf[1])); //EGO correction cyl#1
EGOcor2 = (float)(word(rxBuf[2], rxBuf[3])); //EGO correction cyl#2
EGOcor3 = (float)(word(rxBuf[4], rxBuf[5])); //EGO correction cyl#3
EGOcor4 = (float)(word(rxBuf[6], rxBuf[7])); //EGO correction cyl#4
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1559: // dash broadcasting group
EGOcor5 = (float)(word(rxBuf[0], rxBuf[1])); //EGO correction cyl#5
EGOcor6 = (float)(word(rxBuf[2], rxBuf[3])); //EGO correction cyl#6

break; 
//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//
case 1562: // dash broadcasting group
VSS1 = (float)(word(rxBuf[0], rxBuf[1])); //Vehicle speed 1
VSS2 = (float)(word(rxBuf[2], rxBuf[3])); //Vehicle speed 2
VSS1 = (float)(word(rxBuf[4], rxBuf[5])); //Vehicle speed 3
VSS1 = (float)(word(rxBuf[6], rxBuf[7])); //Vehicle speed 4
break; 
//≪*************************************************************************************************************************************************************************************≫//
case 1563: // dash broadcasting group
synccnt = (float)(word(rxBuf[0], rxBuf[1]));      //Sync-loss counter
syncreason = (float)(word(rxBuf[2], rxBuf[3]));   //Sync-loss reason code
sd_filenum = (float)(word(rxBuf[4], rxBuf[5]));   //SDcard file number
sd_error = (float)(word(rxBuf[6], rxBuf[7]));     //SDcard error number
sd_phase = (float)(word(rxBuf[8], rxBuf[9]));     //SDcard internal code
sd_status = (float)(word(rxBuf[10], rxBuf[11]));  //SDcard status bitfield
timing_err = (float)(word(rxBuf[12], rxBuf[13])); //Calculated error in ignition timing
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1564: // dash broadcasting group
vvt_ang1 = (float)(word(rxBuf[0], rxBuf[1])); //VVT actual angle 1
vvt_ang2 = (float)(word(rxBuf[2], rxBuf[3])); //VVT actual angle 2
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1565: // dash broadcasting group
vvt_target1 = (float)(word(rxBuf[0], rxBuf[1])); //VVT target angle 1
vvt_target2 = (float)(word(rxBuf[2], rxBuf[3])); //VVT target angle 2
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1566: // dash broadcasting group
vvt_duty1 = (float)(word(rxBuf[0], rxBuf[1]));         //VVT solenoid duty cycle 1
vvt_duty2 = (float)(word(rxBuf[2], rxBuf[3]));         //VVT solenoid duty cycle 2
vvt_duty3 = (float)(word(rxBuf[4], rxBuf[5]));         //VVT solenoid duty cycle 3
vvt_duty4 = (float)(word(rxBuf[6], rxBuf[7]));         //VVT solenoid duty cycle 4
inj_timing_pri = (float)(word(rxBuf[8], rxBuf[9]));    //Injection Timing Angle (Primary)
inj_timing_sec = (float)(word(rxBuf[10], rxBuf[11]));  //Injection Timing Angle (Secondary)
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1567: // dash broadcasting group
fuel_pct = (float)(word(rxBuf[0], rxBuf[1]));  //Ethanol content of fuel from Flex sensor
tps_accel = (float)(word(rxBuf[2], rxBuf[3])); //TPSdot based accel
SS1 = (float)(word(rxBuf[4], rxBuf[5]));       //Shaft Speed 1
SS2 = (float)(word(rxBuf[6], rxBuf[7]));       //Shaft Speed 2
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1568: // dash broadcasting group
knock_cyl1 = (float)(word(rxBuf[0], rxBuf[1]));      //Knock % cyl #1
knock_cyl2 = (float)(word(rxBuf[2], rxBuf[3]));      //Knock % cyl #2
knock_cyl3 = (float)(word(rxBuf[4], rxBuf[5]));      //Knock % cyl #3
knock_cyl4 = (float)(word(rxBuf[6], rxBuf[7]));      //Knock % cyl #4
knock_cyl5 = (float)(word(rxBuf[8], rxBuf[9]));      //Knock % cyl #5
knock_cyl6 = (float)(word(rxBuf[10], rxBuf[11]));    //Knock % cyl #6

break;
//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//
case 1570: // dash broadcasting group
map_accel = (float)(word(rxBuf[0], rxBuf[1]));     //MAPdot based accel"
total_accel = (float)(word(rxBuf[2], rxBuf[3]));   //Total accel
launch_timer = (float)(word(rxBuf[4], rxBuf[5]));  //Timer for timed-launch retard
launch_retard = (float)(word(rxBuf[6], rxBuf[7])); //Launch retard
break;
//≪*************************************************************************************************************************************************************************************≫//

//≪*************************************************************************************************************************************************************************************≫//
case 1572: // dash broadcasting group
canin1 = (float)(word(rxBuf[0], rxBuf[1]));     //CAN input 1 bitfield (CAN port 1 on MS2)
canin2 = (float)(word(rxBuf[2], rxBuf[3]));     //CAN input 2 bitfield (CAN port 2 on MS2)
canout = (float)(word(rxBuf[4], rxBuf[5]));     //CAN output 1 bitfield (CAN port 3 on MS2)
knk_rtd = (float)(word(rxBuf[6], rxBuf[7]));    //Knock retard
fuelflow = (float)(word(rxBuf[8], rxBuf[9]));   //Average fuel flow
fuelcons = (float)(word(rxBuf[10], rxBuf[11])); //Average fuel consumption
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1573: // dash broadcasting group
fuel_press1 = (float)(word(rxBuf[0], rxBuf[1])); //Fuel pressure 1
fuel_press2 = (float)(word(rxBuf[2], rxBuf[3])); //Fuel pressure 2
fuel_temp1 = (float)(word(rxBuf[4], rxBuf[5]));  //Fuel temperature 1
fuel_temp2 = (float)(word(rxBuf[6], rxBuf[7]));  //Fuel temperature 2
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1574: // dash broadcasting group
batt_cur = (float)(word(rxBuf[0], rxBuf[1]));     //Battery current (alternator system)
fp_duty = (float)(word(rxBuf[2], rxBuf[3]));      //Fuel pump output duty
alt_duty = (float)(word(rxBuf[4], rxBuf[5]));     //Alternator field output duty
load_duty = (float)(word(rxBuf[6], rxBuf[7]));    //Alternator measured load-sense duty
alt_targv = (float)(word(rxBuf[8], rxBuf[9]));    //Alternator target voltage
cel_status = (float)(word(rxBuf[10], rxBuf[11])); //CEL status bitfield 1
break;
//≪************************************************************************************************************************************************************************************≫//
case 1575: // dash broadcasting group
looptime = (float)(word(rxBuf[0], rxBuf[1]));      //Main code loop execution time
fueltemp_cor = (float)(word(rxBuf[2], rxBuf[3]));  //Fuel temperature correction
fuelpress_cor = (float)(word(rxBuf[4], rxBuf[5])); //Fuel pressure correction
ltt_cor = (float)(word(rxBuf[6], rxBuf[7]));       //Long term trim correction
sp1 = (float)(word(rxBuf[8], rxBuf[9]));           //Unused
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1576: // dash broadcasting group
tc_retard = (float)(word(rxBuf[0], rxBuf[1]));   //Traction control retard
cel_retard = (float)(word(rxBuf[2], rxBuf[3]));  //CEL retard
fc_retard = (float)(word(rxBuf[4], rxBuf[5]));   //Fuel-cut (overrun) retard
als_addfuel = (float)(word(rxBuf[6], rxBuf[7])); //ALS added fuel
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1577: // dash broadcasting group
base_advance = (float)(word(rxBuf[0], rxBuf[1]));     //Base timing from tables
idle_cor_advance = (float)(word(rxBuf[2], rxBuf[3])); //Idle correction advance
mat_retard = (float)(word(rxBuf[4], rxBuf[5]));       //MAT retard
flex_advance = (float)(word(rxBuf[6], rxBuf[7]));     //Flex advance
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1578: // dash broadcasting group
adv1 = (float)(word(rxBuf[0], rxBuf[1])); //Timing lookup from table 1
adv2 = (float)(word(rxBuf[2], rxBuf[3])); //Timing lookup from table 2
adv3 = (float)(word(rxBuf[4], rxBuf[5])); //Timing lookup from table 3
adv4 = (float)(word(rxBuf[6], rxBuf[7])); //Timing lookup from table 4
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1579: // dash broadcasting group
revlim_retard = (float)(word(rxBuf[0], rxBuf[1])); //Rev-limiter 'soft' retard
als_timing = (float)(word(rxBuf[2], rxBuf[3]));    //ALS timing change
ext_advance = (float)(word(rxBuf[4], rxBuf[5]));   //External advance (e.g. trans)
deadtime1 = (float)(word(rxBuf[6], rxBuf[7]));     //Injector deadtime in use (#1)
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1580: // dash broadcasting group
launch_timing = (float)(word(rxBuf[0], rxBuf[1]));    //Launch control timing
step3_timing = (float)(word(rxBuf[2], rxBuf[3]));     //3-step timing
vsslaunch_retard = (float)(word(rxBuf[4], rxBuf[5])); //Wheel-speed based launch retard
cel_status2 = (float)(word(rxBuf[6], rxBuf[7]));      //CEL status bitfield 2
break;
//≪*************************************************************************************************************************************************************************************≫//
case 1583: // dash broadcasting group
generic_pid_duty1 = (float)(word(rxBuf[0], rxBuf[1])); //Generic closed-loop duty 1
generic_pid_duty2 = (float)(word(rxBuf[2], rxBuf[3])); //Generic closed-loop duty 2
break;
//≪*************************************************************************************************************************************************************************************≫//
}
}
//---------------------------------------------------------------------------------------------
void receive_CAN1_message()
{
}
//----------------------------------------------------------------------------------------------  
