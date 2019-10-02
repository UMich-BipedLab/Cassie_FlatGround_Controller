/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:11 GMT-04:00
 */

#ifdef MATLAB_MEX_FILE
#include <stdexcept>
#include <cmath>
/**
 * Copied from Wolfram Mathematica C Definitions file mdefs.hpp
 * Changed marcos to inline functions (Eric Cousineau)
 */
inline double Power(double x, double y) { return pow(x, y); }
inline double Sqrt(double x) { return sqrt(x); }

inline double Abs(double x) { return fabs(x); }

inline double Exp(double x) { return exp(x); }
inline double Log(double x) { return log(x); }

inline double Sin(double x) { return sin(x); }
inline double Cos(double x) { return cos(x); }
inline double Tan(double x) { return tan(x); }

inline double ArcSin(double x) { return asin(x); }
inline double ArcCos(double x) { return acos(x); }
inline double ArcTan(double x) { return atan(x); }

/* update ArcTan function to use atan2 instead. */
inline double ArcTan(double x, double y) { return atan2(y,x); }

inline double Sinh(double x) { return sinh(x); }
inline double Cosh(double x) { return cosh(x); }
inline double Tanh(double x) { return tanh(x); }

const double E	= 2.71828182845904523536029;
const double Pi = 3.14159265358979323846264;
const double Degree = 0.01745329251994329576924;


#endif

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *var1)
{
  double t1127;
  double t1105;
  double t1129;
  double t1107;
  double t1131;
  double t1027;
  double t1126;
  double t1137;
  double t1175;
  double t1179;
  double t1180;
  double t1182;
  double t1185;
  double t1220;
  double t1241;
  double t1247;
  double t1251;
  double t1206;
  double t1212;
  double t1213;
  double t1256;
  double t1301;
  double t1309;
  double t1310;
  double t1321;
  double t1288;
  double t1295;
  double t1300;
  double t1327;
  double t1328;
  double t1329;
  double t1340;
  double t1343;
  double t1344;
  double t1348;
  double t1354;
  double t1356;
  double t1359;
  double t1376;
  double t1380;
  double t1384;
  double t1387;
  double t1388;
  double t1390;
  double t1395;
  double t1399;
  double t1400;
  double t1401;
  double t1406;
  double t1407;
  double t1409;
  double t1412;
  double t1413;
  double t1414;
  double t1417;
  double t1421;
  double t1423;
  double t1424;
  double t1434;
  double t1435;
  double t1437;
  double t1440;
  double t1441;
  double t1444;
  double t1448;
  double t1453;
  double t1455;
  double t1457;
  double t1465;
  double t1466;
  double t1468;
  double t1029;
  double t1062;
  double t1102;
  double t1104;
  double t1201;
  double t1202;
  double t1481;
  double t1482;
  double t1483;
  double t1485;
  double t1486;
  double t1487;
  double t1250;
  double t1252;
  double t1254;
  double t1257;
  double t1260;
  double t1271;
  double t1489;
  double t1490;
  double t1491;
  double t1316;
  double t1322;
  double t1325;
  double t1330;
  double t1331;
  double t1332;
  double t1346;
  double t1351;
  double t1352;
  double t1501;
  double t1502;
  double t1503;
  double t1506;
  double t1507;
  double t1509;
  double t1363;
  double t1370;
  double t1375;
  double t1391;
  double t1396;
  double t1397;
  double t1512;
  double t1513;
  double t1514;
  double t1516;
  double t1518;
  double t1519;
  double t1403;
  double t1404;
  double t1405;
  double t1415;
  double t1418;
  double t1419;
  double t1522;
  double t1523;
  double t1525;
  double t1528;
  double t1530;
  double t1531;
  double t1427;
  double t1429;
  double t1431;
  double t1445;
  double t1450;
  double t1451;
  double t1534;
  double t1535;
  double t1536;
  double t1538;
  double t1539;
  double t1540;
  double t1460;
  double t1462;
  double t1463;
  double t1542;
  double t1543;
  double t1544;
  double t1546;
  double t1547;
  double t1548;
  double t1561;
  double t1562;
  double t1563;
  double t1570;
  double t1571;
  double t1572;
  double t1574;
  double t1575;
  double t1576;
  double t1578;
  double t1579;
  double t1580;
  double t1582;
  double t1583;
  double t1584;
  double t1586;
  double t1587;
  double t1588;
  double t1590;
  double t1591;
  double t1592;
  double t1594;
  double t1595;
  double t1596;
  double t1598;
  double t1599;
  double t1600;
  double t1602;
  double t1603;
  double t1604;
  double t1606;
  double t1607;
  double t1608;
  t1127 = Cos(var1[3]);
  t1105 = Cos(var1[5]);
  t1129 = Sin(var1[4]);
  t1107 = Sin(var1[3]);
  t1131 = Sin(var1[5]);
  t1027 = Cos(var1[6]);
  t1126 = -1.*t1105*t1107;
  t1137 = t1127*t1129*t1131;
  t1175 = t1126 + t1137;
  t1179 = t1127*t1105*t1129;
  t1180 = t1107*t1131;
  t1182 = t1179 + t1180;
  t1185 = Sin(var1[6]);
  t1220 = Cos(var1[7]);
  t1241 = -1.*t1220;
  t1247 = 1. + t1241;
  t1251 = Sin(var1[7]);
  t1206 = t1027*t1175;
  t1212 = t1182*t1185;
  t1213 = t1206 + t1212;
  t1256 = Cos(var1[4]);
  t1301 = Cos(var1[8]);
  t1309 = -1.*t1301;
  t1310 = 1. + t1309;
  t1321 = Sin(var1[8]);
  t1288 = t1127*t1256*t1220;
  t1295 = t1213*t1251;
  t1300 = t1288 + t1295;
  t1327 = t1027*t1182;
  t1328 = -1.*t1175*t1185;
  t1329 = t1327 + t1328;
  t1340 = Cos(var1[9]);
  t1343 = -1.*t1340;
  t1344 = 1. + t1343;
  t1348 = Sin(var1[9]);
  t1354 = t1301*t1300;
  t1356 = t1329*t1321;
  t1359 = t1354 + t1356;
  t1376 = t1301*t1329;
  t1380 = -1.*t1300*t1321;
  t1384 = t1376 + t1380;
  t1387 = Cos(var1[10]);
  t1388 = -1.*t1387;
  t1390 = 1. + t1388;
  t1395 = Sin(var1[10]);
  t1399 = -1.*t1348*t1359;
  t1400 = t1340*t1384;
  t1401 = t1399 + t1400;
  t1406 = t1340*t1359;
  t1407 = t1348*t1384;
  t1409 = t1406 + t1407;
  t1412 = Cos(var1[11]);
  t1413 = -1.*t1412;
  t1414 = 1. + t1413;
  t1417 = Sin(var1[11]);
  t1421 = t1395*t1401;
  t1423 = t1387*t1409;
  t1424 = t1421 + t1423;
  t1434 = t1387*t1401;
  t1435 = -1.*t1395*t1409;
  t1437 = t1434 + t1435;
  t1440 = Cos(var1[12]);
  t1441 = -1.*t1440;
  t1444 = 1. + t1441;
  t1448 = Sin(var1[12]);
  t1453 = -1.*t1417*t1424;
  t1455 = t1412*t1437;
  t1457 = t1453 + t1455;
  t1465 = t1412*t1424;
  t1466 = t1417*t1437;
  t1468 = t1465 + t1466;
  t1029 = -1.*t1027;
  t1062 = 1. + t1029;
  t1102 = 0.135*t1062;
  t1104 = 0. + t1102;
  t1201 = -0.135*t1185;
  t1202 = 0. + t1201;
  t1481 = t1127*t1105;
  t1482 = t1107*t1129*t1131;
  t1483 = t1481 + t1482;
  t1485 = t1105*t1107*t1129;
  t1486 = -1.*t1127*t1131;
  t1487 = t1485 + t1486;
  t1250 = 0.135*t1247;
  t1252 = 0.049*t1251;
  t1254 = 0. + t1250 + t1252;
  t1257 = -0.049*t1247;
  t1260 = 0.135*t1251;
  t1271 = 0. + t1257 + t1260;
  t1489 = t1027*t1483;
  t1490 = t1487*t1185;
  t1491 = t1489 + t1490;
  t1316 = -0.049*t1310;
  t1322 = -0.09*t1321;
  t1325 = 0. + t1316 + t1322;
  t1330 = -0.09*t1310;
  t1331 = 0.049*t1321;
  t1332 = 0. + t1330 + t1331;
  t1346 = -0.049*t1344;
  t1351 = -0.21*t1348;
  t1352 = 0. + t1346 + t1351;
  t1501 = t1256*t1220*t1107;
  t1502 = t1491*t1251;
  t1503 = t1501 + t1502;
  t1506 = t1027*t1487;
  t1507 = -1.*t1483*t1185;
  t1509 = t1506 + t1507;
  t1363 = -0.21*t1344;
  t1370 = 0.049*t1348;
  t1375 = 0. + t1363 + t1370;
  t1391 = -0.2707*t1390;
  t1396 = 0.0016*t1395;
  t1397 = 0. + t1391 + t1396;
  t1512 = t1301*t1503;
  t1513 = t1509*t1321;
  t1514 = t1512 + t1513;
  t1516 = t1301*t1509;
  t1518 = -1.*t1503*t1321;
  t1519 = t1516 + t1518;
  t1403 = -0.0016*t1390;
  t1404 = -0.2707*t1395;
  t1405 = 0. + t1403 + t1404;
  t1415 = 0.0184*t1414;
  t1418 = -0.7055*t1417;
  t1419 = 0. + t1415 + t1418;
  t1522 = -1.*t1348*t1514;
  t1523 = t1340*t1519;
  t1525 = t1522 + t1523;
  t1528 = t1340*t1514;
  t1530 = t1348*t1519;
  t1531 = t1528 + t1530;
  t1427 = -0.7055*t1414;
  t1429 = -0.0184*t1417;
  t1431 = 0. + t1427 + t1429;
  t1445 = -1.1135*t1444;
  t1450 = 0.0216*t1448;
  t1451 = 0. + t1445 + t1450;
  t1534 = t1395*t1525;
  t1535 = t1387*t1531;
  t1536 = t1534 + t1535;
  t1538 = t1387*t1525;
  t1539 = -1.*t1395*t1531;
  t1540 = t1538 + t1539;
  t1460 = -0.0216*t1444;
  t1462 = -1.1135*t1448;
  t1463 = 0. + t1460 + t1462;
  t1542 = -1.*t1417*t1536;
  t1543 = t1412*t1540;
  t1544 = t1542 + t1543;
  t1546 = t1412*t1536;
  t1547 = t1417*t1540;
  t1548 = t1546 + t1547;
  t1561 = t1256*t1027*t1131;
  t1562 = t1256*t1105*t1185;
  t1563 = t1561 + t1562;
  t1570 = -1.*t1220*t1129;
  t1571 = t1563*t1251;
  t1572 = t1570 + t1571;
  t1574 = t1256*t1105*t1027;
  t1575 = -1.*t1256*t1131*t1185;
  t1576 = t1574 + t1575;
  t1578 = t1301*t1572;
  t1579 = t1576*t1321;
  t1580 = t1578 + t1579;
  t1582 = t1301*t1576;
  t1583 = -1.*t1572*t1321;
  t1584 = t1582 + t1583;
  t1586 = -1.*t1348*t1580;
  t1587 = t1340*t1584;
  t1588 = t1586 + t1587;
  t1590 = t1340*t1580;
  t1591 = t1348*t1584;
  t1592 = t1590 + t1591;
  t1594 = t1395*t1588;
  t1595 = t1387*t1592;
  t1596 = t1594 + t1595;
  t1598 = t1387*t1588;
  t1599 = -1.*t1395*t1592;
  t1600 = t1598 + t1599;
  t1602 = -1.*t1417*t1596;
  t1603 = t1412*t1600;
  t1604 = t1602 + t1603;
  t1606 = t1412*t1596;
  t1607 = t1417*t1600;
  t1608 = t1606 + t1607;
  p_output1[0]=0. + t1104*t1175 + t1182*t1202 + t1213*t1254 + 0.1305*(t1213*t1220 - 1.*t1127*t1251*t1256) + t1127*t1256*t1271 + t1300*t1325 + t1329*t1332 + t1352*t1359 + t1375*t1384 + t1397*t1401 + t1405*t1409 + t1419*t1424 + t1431*t1437 + t1451*t1457 + t1463*t1468 + 0.0306*(t1448*t1457 + t1440*t1468) - 1.1312*(t1440*t1457 - 1.*t1448*t1468) + var1[0];
  p_output1[1]=0. + t1107*t1256*t1271 + t1104*t1483 + t1202*t1487 + t1254*t1491 + 0.1305*(-1.*t1107*t1251*t1256 + t1220*t1491) + t1325*t1503 + t1332*t1509 + t1352*t1514 + t1375*t1519 + t1397*t1525 + t1405*t1531 + t1419*t1536 + t1431*t1540 + t1451*t1544 + t1463*t1548 + 0.0306*(t1448*t1544 + t1440*t1548) - 1.1312*(t1440*t1544 - 1.*t1448*t1548) + var1[1];
  p_output1[2]=0. + t1104*t1131*t1256 + t1105*t1202*t1256 - 1.*t1129*t1271 + t1254*t1563 + 0.1305*(t1129*t1251 + t1220*t1563) + t1325*t1572 + t1332*t1576 + t1352*t1580 + t1375*t1584 + t1397*t1588 + t1405*t1592 + t1419*t1596 + t1431*t1600 + t1451*t1604 + t1463*t1608 + 0.0306*(t1448*t1604 + t1440*t1608) - 1.1312*(t1440*t1604 - 1.*t1448*t1608) + var1[2];
}



#ifdef MATLAB_MEX_FILE

#include "mex.h"
/*
 * Main function
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  size_t mrows, ncols;

  double *var1;
  double *p_output1;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (var1).");
    }
  else if( nlhs > 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 20 && ncols == 1) && 
      !(mrows == 1 && ncols == 20))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var1 is wrong.");
    }

  /*  Assign pointers to each input.  */
  var1 = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var1);


}

#else // MATLAB_MEX_FILE

#include "LeftToeBottom_mex.hh"

namespace SymExpression
{

void LeftToeBottom_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
