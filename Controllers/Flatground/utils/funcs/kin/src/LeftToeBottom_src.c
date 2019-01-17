/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:12 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "LeftToeBottom_src.h"

#ifdef _MSC_VER
  #define INLINE __forceinline /* use __forceinline (VC++ specific) */
#else
  #define INLINE inline        /* use standard inline */
#endif

/**
 * Copied from Wolfram Mathematica C Definitions file mdefs.hpp
 * Changed marcos to inline functions (Eric Cousineau)
 */
INLINE double Power(double x, double y) { return pow(x, y); }
INLINE double Sqrt(double x) { return sqrt(x); }

INLINE double Abs(double x) { return fabs(x); }

INLINE double Exp(double x) { return exp(x); }
INLINE double Log(double x) { return log(x); }

INLINE double Sin(double x) { return sin(x); }
INLINE double Cos(double x) { return cos(x); }
INLINE double Tan(double x) { return tan(x); }

INLINE double Csc(double x) { return 1.0/sin(x); }
INLINE double Sec(double x) { return 1.0/cos(x); }

INLINE double ArcSin(double x) { return asin(x); }
INLINE double ArcCos(double x) { return acos(x); }
//INLINE double ArcTan(double x) { return atan(x); }

/* update ArcTan function to use atan2 instead. */
INLINE double ArcTan(double x, double y) { return atan2(y,x); }

INLINE double Sinh(double x) { return sinh(x); }
INLINE double Cosh(double x) { return cosh(x); }
INLINE double Tanh(double x) { return tanh(x); }

#define E 2.71828182845904523536029
#define Pi 3.14159265358979323846264
#define Degree 0.01745329251994329576924

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *var1)
{
  double t1202;
  double t1180;
  double t1204;
  double t1182;
  double t1206;
  double t1102;
  double t1201;
  double t1212;
  double t1250;
  double t1254;
  double t1255;
  double t1257;
  double t1260;
  double t1295;
  double t1316;
  double t1322;
  double t1326;
  double t1281;
  double t1287;
  double t1288;
  double t1331;
  double t1376;
  double t1384;
  double t1385;
  double t1396;
  double t1363;
  double t1370;
  double t1375;
  double t1402;
  double t1403;
  double t1404;
  double t1415;
  double t1418;
  double t1419;
  double t1423;
  double t1429;
  double t1431;
  double t1434;
  double t1451;
  double t1455;
  double t1459;
  double t1462;
  double t1463;
  double t1465;
  double t1470;
  double t1474;
  double t1475;
  double t1476;
  double t1481;
  double t1482;
  double t1484;
  double t1487;
  double t1488;
  double t1489;
  double t1492;
  double t1496;
  double t1498;
  double t1499;
  double t1509;
  double t1510;
  double t1512;
  double t1515;
  double t1516;
  double t1519;
  double t1523;
  double t1528;
  double t1530;
  double t1532;
  double t1540;
  double t1541;
  double t1543;
  double t1104;
  double t1137;
  double t1177;
  double t1179;
  double t1276;
  double t1277;
  double t1556;
  double t1557;
  double t1558;
  double t1560;
  double t1561;
  double t1562;
  double t1325;
  double t1327;
  double t1329;
  double t1332;
  double t1335;
  double t1346;
  double t1564;
  double t1565;
  double t1566;
  double t1391;
  double t1397;
  double t1400;
  double t1405;
  double t1406;
  double t1407;
  double t1421;
  double t1426;
  double t1427;
  double t1576;
  double t1577;
  double t1578;
  double t1581;
  double t1582;
  double t1584;
  double t1438;
  double t1445;
  double t1450;
  double t1466;
  double t1471;
  double t1472;
  double t1587;
  double t1588;
  double t1589;
  double t1591;
  double t1593;
  double t1594;
  double t1478;
  double t1479;
  double t1480;
  double t1490;
  double t1493;
  double t1494;
  double t1597;
  double t1598;
  double t1600;
  double t1603;
  double t1605;
  double t1606;
  double t1502;
  double t1504;
  double t1506;
  double t1520;
  double t1525;
  double t1526;
  double t1609;
  double t1610;
  double t1611;
  double t1613;
  double t1614;
  double t1615;
  double t1535;
  double t1537;
  double t1538;
  double t1617;
  double t1618;
  double t1619;
  double t1621;
  double t1622;
  double t1623;
  double t1636;
  double t1637;
  double t1638;
  double t1645;
  double t1646;
  double t1647;
  double t1649;
  double t1650;
  double t1651;
  double t1653;
  double t1654;
  double t1655;
  double t1657;
  double t1658;
  double t1659;
  double t1661;
  double t1662;
  double t1663;
  double t1665;
  double t1666;
  double t1667;
  double t1669;
  double t1670;
  double t1671;
  double t1673;
  double t1674;
  double t1675;
  double t1677;
  double t1678;
  double t1679;
  double t1681;
  double t1682;
  double t1683;
  t1202 = Cos(var1[3]);
  t1180 = Cos(var1[5]);
  t1204 = Sin(var1[4]);
  t1182 = Sin(var1[3]);
  t1206 = Sin(var1[5]);
  t1102 = Cos(var1[6]);
  t1201 = -1.*t1180*t1182;
  t1212 = t1202*t1204*t1206;
  t1250 = t1201 + t1212;
  t1254 = t1202*t1180*t1204;
  t1255 = t1182*t1206;
  t1257 = t1254 + t1255;
  t1260 = Sin(var1[6]);
  t1295 = Cos(var1[7]);
  t1316 = -1.*t1295;
  t1322 = 1. + t1316;
  t1326 = Sin(var1[7]);
  t1281 = t1102*t1250;
  t1287 = t1257*t1260;
  t1288 = t1281 + t1287;
  t1331 = Cos(var1[4]);
  t1376 = Cos(var1[8]);
  t1384 = -1.*t1376;
  t1385 = 1. + t1384;
  t1396 = Sin(var1[8]);
  t1363 = t1202*t1331*t1295;
  t1370 = t1288*t1326;
  t1375 = t1363 + t1370;
  t1402 = t1102*t1257;
  t1403 = -1.*t1250*t1260;
  t1404 = t1402 + t1403;
  t1415 = Cos(var1[9]);
  t1418 = -1.*t1415;
  t1419 = 1. + t1418;
  t1423 = Sin(var1[9]);
  t1429 = t1376*t1375;
  t1431 = t1404*t1396;
  t1434 = t1429 + t1431;
  t1451 = t1376*t1404;
  t1455 = -1.*t1375*t1396;
  t1459 = t1451 + t1455;
  t1462 = Cos(var1[10]);
  t1463 = -1.*t1462;
  t1465 = 1. + t1463;
  t1470 = Sin(var1[10]);
  t1474 = -1.*t1423*t1434;
  t1475 = t1415*t1459;
  t1476 = t1474 + t1475;
  t1481 = t1415*t1434;
  t1482 = t1423*t1459;
  t1484 = t1481 + t1482;
  t1487 = Cos(var1[11]);
  t1488 = -1.*t1487;
  t1489 = 1. + t1488;
  t1492 = Sin(var1[11]);
  t1496 = t1470*t1476;
  t1498 = t1462*t1484;
  t1499 = t1496 + t1498;
  t1509 = t1462*t1476;
  t1510 = -1.*t1470*t1484;
  t1512 = t1509 + t1510;
  t1515 = Cos(var1[12]);
  t1516 = -1.*t1515;
  t1519 = 1. + t1516;
  t1523 = Sin(var1[12]);
  t1528 = -1.*t1492*t1499;
  t1530 = t1487*t1512;
  t1532 = t1528 + t1530;
  t1540 = t1487*t1499;
  t1541 = t1492*t1512;
  t1543 = t1540 + t1541;
  t1104 = -1.*t1102;
  t1137 = 1. + t1104;
  t1177 = 0.135*t1137;
  t1179 = 0. + t1177;
  t1276 = -0.135*t1260;
  t1277 = 0. + t1276;
  t1556 = t1202*t1180;
  t1557 = t1182*t1204*t1206;
  t1558 = t1556 + t1557;
  t1560 = t1180*t1182*t1204;
  t1561 = -1.*t1202*t1206;
  t1562 = t1560 + t1561;
  t1325 = 0.135*t1322;
  t1327 = 0.049*t1326;
  t1329 = 0. + t1325 + t1327;
  t1332 = -0.049*t1322;
  t1335 = 0.135*t1326;
  t1346 = 0. + t1332 + t1335;
  t1564 = t1102*t1558;
  t1565 = t1562*t1260;
  t1566 = t1564 + t1565;
  t1391 = -0.049*t1385;
  t1397 = -0.09*t1396;
  t1400 = 0. + t1391 + t1397;
  t1405 = -0.09*t1385;
  t1406 = 0.049*t1396;
  t1407 = 0. + t1405 + t1406;
  t1421 = -0.049*t1419;
  t1426 = -0.21*t1423;
  t1427 = 0. + t1421 + t1426;
  t1576 = t1331*t1295*t1182;
  t1577 = t1566*t1326;
  t1578 = t1576 + t1577;
  t1581 = t1102*t1562;
  t1582 = -1.*t1558*t1260;
  t1584 = t1581 + t1582;
  t1438 = -0.21*t1419;
  t1445 = 0.049*t1423;
  t1450 = 0. + t1438 + t1445;
  t1466 = -0.2707*t1465;
  t1471 = 0.0016*t1470;
  t1472 = 0. + t1466 + t1471;
  t1587 = t1376*t1578;
  t1588 = t1584*t1396;
  t1589 = t1587 + t1588;
  t1591 = t1376*t1584;
  t1593 = -1.*t1578*t1396;
  t1594 = t1591 + t1593;
  t1478 = -0.0016*t1465;
  t1479 = -0.2707*t1470;
  t1480 = 0. + t1478 + t1479;
  t1490 = 0.0184*t1489;
  t1493 = -0.7055*t1492;
  t1494 = 0. + t1490 + t1493;
  t1597 = -1.*t1423*t1589;
  t1598 = t1415*t1594;
  t1600 = t1597 + t1598;
  t1603 = t1415*t1589;
  t1605 = t1423*t1594;
  t1606 = t1603 + t1605;
  t1502 = -0.7055*t1489;
  t1504 = -0.0184*t1492;
  t1506 = 0. + t1502 + t1504;
  t1520 = -1.1135*t1519;
  t1525 = 0.0216*t1523;
  t1526 = 0. + t1520 + t1525;
  t1609 = t1470*t1600;
  t1610 = t1462*t1606;
  t1611 = t1609 + t1610;
  t1613 = t1462*t1600;
  t1614 = -1.*t1470*t1606;
  t1615 = t1613 + t1614;
  t1535 = -0.0216*t1519;
  t1537 = -1.1135*t1523;
  t1538 = 0. + t1535 + t1537;
  t1617 = -1.*t1492*t1611;
  t1618 = t1487*t1615;
  t1619 = t1617 + t1618;
  t1621 = t1487*t1611;
  t1622 = t1492*t1615;
  t1623 = t1621 + t1622;
  t1636 = t1331*t1102*t1206;
  t1637 = t1331*t1180*t1260;
  t1638 = t1636 + t1637;
  t1645 = -1.*t1295*t1204;
  t1646 = t1638*t1326;
  t1647 = t1645 + t1646;
  t1649 = t1331*t1180*t1102;
  t1650 = -1.*t1331*t1206*t1260;
  t1651 = t1649 + t1650;
  t1653 = t1376*t1647;
  t1654 = t1651*t1396;
  t1655 = t1653 + t1654;
  t1657 = t1376*t1651;
  t1658 = -1.*t1647*t1396;
  t1659 = t1657 + t1658;
  t1661 = -1.*t1423*t1655;
  t1662 = t1415*t1659;
  t1663 = t1661 + t1662;
  t1665 = t1415*t1655;
  t1666 = t1423*t1659;
  t1667 = t1665 + t1666;
  t1669 = t1470*t1663;
  t1670 = t1462*t1667;
  t1671 = t1669 + t1670;
  t1673 = t1462*t1663;
  t1674 = -1.*t1470*t1667;
  t1675 = t1673 + t1674;
  t1677 = -1.*t1492*t1671;
  t1678 = t1487*t1675;
  t1679 = t1677 + t1678;
  t1681 = t1487*t1671;
  t1682 = t1492*t1675;
  t1683 = t1681 + t1682;
  p_output1[0]=0. + t1179*t1250 + t1257*t1277 + t1288*t1329 + 0.1305*(t1288*t1295 - 1.*t1202*t1326*t1331) + t1202*t1331*t1346 + t1375*t1400 + t1404*t1407 + t1427*t1434 + t1450*t1459 + t1472*t1476 + t1480*t1484 + t1494*t1499 + t1506*t1512 + t1526*t1532 + t1538*t1543 + 0.0306*(t1523*t1532 + t1515*t1543) - 1.1312*(t1515*t1532 - 1.*t1523*t1543) + var1[0];
  p_output1[1]=0. + t1182*t1331*t1346 + t1179*t1558 + t1277*t1562 + t1329*t1566 + 0.1305*(-1.*t1182*t1326*t1331 + t1295*t1566) + t1400*t1578 + t1407*t1584 + t1427*t1589 + t1450*t1594 + t1472*t1600 + t1480*t1606 + t1494*t1611 + t1506*t1615 + t1526*t1619 + t1538*t1623 + 0.0306*(t1523*t1619 + t1515*t1623) - 1.1312*(t1515*t1619 - 1.*t1523*t1623) + var1[1];
  p_output1[2]=0. + t1179*t1206*t1331 + t1180*t1277*t1331 - 1.*t1204*t1346 + t1329*t1638 + 0.1305*(t1204*t1326 + t1295*t1638) + t1400*t1647 + t1407*t1651 + t1427*t1655 + t1450*t1659 + t1472*t1663 + t1480*t1667 + t1494*t1671 + t1506*t1675 + t1526*t1679 + t1538*t1683 + 0.0306*(t1523*t1679 + t1515*t1683) - 1.1312*(t1515*t1679 - 1.*t1523*t1683) + var1[2];
}



void LeftToeBottom_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
