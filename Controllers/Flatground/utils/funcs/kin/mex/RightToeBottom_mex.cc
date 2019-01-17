/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:19 GMT-04:00
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
  double t1252;
  double t1402;
  double t1407;
  double t1404;
  double t1410;
  double t1287;
  double t1327;
  double t1329;
  double t1332;
  double t1356;
  double t1405;
  double t1426;
  double t1427;
  double t1431;
  double t1472;
  double t1475;
  double t1476;
  double t1254;
  double t1482;
  double t1485;
  double t1496;
  double t1502;
  double t1504;
  double t1506;
  double t1513;
  double t1526;
  double t1534;
  double t1535;
  double t1555;
  double t1556;
  double t1557;
  double t1565;
  double t1568;
  double t1569;
  double t1573;
  double t1579;
  double t1581;
  double t1584;
  double t1601;
  double t1605;
  double t1609;
  double t1612;
  double t1613;
  double t1615;
  double t1620;
  double t1624;
  double t1625;
  double t1626;
  double t1631;
  double t1632;
  double t1634;
  double t1637;
  double t1638;
  double t1639;
  double t1642;
  double t1646;
  double t1648;
  double t1649;
  double t1659;
  double t1660;
  double t1662;
  double t1665;
  double t1666;
  double t1669;
  double t1673;
  double t1678;
  double t1680;
  double t1682;
  double t1690;
  double t1691;
  double t1693;
  double t1330;
  double t1351;
  double t1352;
  double t1362;
  double t1400;
  double t1437;
  double t1438;
  double t1445;
  double t1466;
  double t1479;
  double t1480;
  double t1481;
  double t1707;
  double t1708;
  double t1709;
  double t1711;
  double t1712;
  double t1713;
  double t1512;
  double t1520;
  double t1525;
  double t1715;
  double t1716;
  double t1717;
  double t1552;
  double t1553;
  double t1554;
  double t1571;
  double t1576;
  double t1577;
  double t1719;
  double t1721;
  double t1723;
  double t1731;
  double t1732;
  double t1734;
  double t1588;
  double t1595;
  double t1600;
  double t1616;
  double t1621;
  double t1622;
  double t1737;
  double t1738;
  double t1739;
  double t1741;
  double t1743;
  double t1744;
  double t1628;
  double t1629;
  double t1630;
  double t1640;
  double t1643;
  double t1644;
  double t1747;
  double t1748;
  double t1750;
  double t1753;
  double t1755;
  double t1756;
  double t1652;
  double t1654;
  double t1656;
  double t1670;
  double t1675;
  double t1676;
  double t1759;
  double t1760;
  double t1761;
  double t1763;
  double t1764;
  double t1765;
  double t1685;
  double t1687;
  double t1688;
  double t1767;
  double t1768;
  double t1769;
  double t1771;
  double t1772;
  double t1773;
  double t1787;
  double t1788;
  double t1789;
  double t1791;
  double t1792;
  double t1793;
  double t1799;
  double t1800;
  double t1801;
  double t1803;
  double t1804;
  double t1805;
  double t1807;
  double t1808;
  double t1809;
  double t1811;
  double t1812;
  double t1813;
  double t1815;
  double t1816;
  double t1817;
  double t1819;
  double t1820;
  double t1821;
  double t1823;
  double t1824;
  double t1825;
  double t1827;
  double t1828;
  double t1829;
  double t1831;
  double t1832;
  double t1833;
  t1252 = Cos(var1[3]);
  t1402 = Cos(var1[5]);
  t1407 = Sin(var1[3]);
  t1404 = Sin(var1[4]);
  t1410 = Sin(var1[5]);
  t1287 = Cos(var1[14]);
  t1327 = -1.*t1287;
  t1329 = 1. + t1327;
  t1332 = Sin(var1[14]);
  t1356 = Sin(var1[13]);
  t1405 = t1252*t1402*t1404;
  t1426 = t1407*t1410;
  t1427 = t1405 + t1426;
  t1431 = Cos(var1[13]);
  t1472 = -1.*t1402*t1407;
  t1475 = t1252*t1404*t1410;
  t1476 = t1472 + t1475;
  t1254 = Cos(var1[4]);
  t1482 = t1356*t1427;
  t1485 = t1431*t1476;
  t1496 = t1482 + t1485;
  t1502 = Cos(var1[15]);
  t1504 = -1.*t1502;
  t1506 = 1. + t1504;
  t1513 = Sin(var1[15]);
  t1526 = t1431*t1427;
  t1534 = -1.*t1356*t1476;
  t1535 = t1526 + t1534;
  t1555 = t1287*t1252*t1254;
  t1556 = t1332*t1496;
  t1557 = t1555 + t1556;
  t1565 = Cos(var1[16]);
  t1568 = -1.*t1565;
  t1569 = 1. + t1568;
  t1573 = Sin(var1[16]);
  t1579 = t1513*t1535;
  t1581 = t1502*t1557;
  t1584 = t1579 + t1581;
  t1601 = t1502*t1535;
  t1605 = -1.*t1513*t1557;
  t1609 = t1601 + t1605;
  t1612 = Cos(var1[17]);
  t1613 = -1.*t1612;
  t1615 = 1. + t1613;
  t1620 = Sin(var1[17]);
  t1624 = -1.*t1573*t1584;
  t1625 = t1565*t1609;
  t1626 = t1624 + t1625;
  t1631 = t1565*t1584;
  t1632 = t1573*t1609;
  t1634 = t1631 + t1632;
  t1637 = Cos(var1[18]);
  t1638 = -1.*t1637;
  t1639 = 1. + t1638;
  t1642 = Sin(var1[18]);
  t1646 = t1620*t1626;
  t1648 = t1612*t1634;
  t1649 = t1646 + t1648;
  t1659 = t1612*t1626;
  t1660 = -1.*t1620*t1634;
  t1662 = t1659 + t1660;
  t1665 = Cos(var1[19]);
  t1666 = -1.*t1665;
  t1669 = 1. + t1666;
  t1673 = Sin(var1[19]);
  t1678 = -1.*t1642*t1649;
  t1680 = t1637*t1662;
  t1682 = t1678 + t1680;
  t1690 = t1637*t1649;
  t1691 = t1642*t1662;
  t1693 = t1690 + t1691;
  t1330 = -0.049*t1329;
  t1351 = -0.135*t1332;
  t1352 = 0. + t1330 + t1351;
  t1362 = 0.135*t1356;
  t1400 = 0. + t1362;
  t1437 = -1.*t1431;
  t1438 = 1. + t1437;
  t1445 = -0.135*t1438;
  t1466 = 0. + t1445;
  t1479 = -0.135*t1329;
  t1480 = 0.049*t1332;
  t1481 = 0. + t1479 + t1480;
  t1707 = t1402*t1407*t1404;
  t1708 = -1.*t1252*t1410;
  t1709 = t1707 + t1708;
  t1711 = t1252*t1402;
  t1712 = t1407*t1404*t1410;
  t1713 = t1711 + t1712;
  t1512 = -0.09*t1506;
  t1520 = 0.049*t1513;
  t1525 = 0. + t1512 + t1520;
  t1715 = t1356*t1709;
  t1716 = t1431*t1713;
  t1717 = t1715 + t1716;
  t1552 = -0.049*t1506;
  t1553 = -0.09*t1513;
  t1554 = 0. + t1552 + t1553;
  t1571 = -0.049*t1569;
  t1576 = -0.21*t1573;
  t1577 = 0. + t1571 + t1576;
  t1719 = t1431*t1709;
  t1721 = -1.*t1356*t1713;
  t1723 = t1719 + t1721;
  t1731 = t1287*t1254*t1407;
  t1732 = t1332*t1717;
  t1734 = t1731 + t1732;
  t1588 = -0.21*t1569;
  t1595 = 0.049*t1573;
  t1600 = 0. + t1588 + t1595;
  t1616 = -0.2707*t1615;
  t1621 = 0.0016*t1620;
  t1622 = 0. + t1616 + t1621;
  t1737 = t1513*t1723;
  t1738 = t1502*t1734;
  t1739 = t1737 + t1738;
  t1741 = t1502*t1723;
  t1743 = -1.*t1513*t1734;
  t1744 = t1741 + t1743;
  t1628 = -0.0016*t1615;
  t1629 = -0.2707*t1620;
  t1630 = 0. + t1628 + t1629;
  t1640 = 0.0184*t1639;
  t1643 = -0.7055*t1642;
  t1644 = 0. + t1640 + t1643;
  t1747 = -1.*t1573*t1739;
  t1748 = t1565*t1744;
  t1750 = t1747 + t1748;
  t1753 = t1565*t1739;
  t1755 = t1573*t1744;
  t1756 = t1753 + t1755;
  t1652 = -0.7055*t1639;
  t1654 = -0.0184*t1642;
  t1656 = 0. + t1652 + t1654;
  t1670 = -1.1135*t1669;
  t1675 = 0.0216*t1673;
  t1676 = 0. + t1670 + t1675;
  t1759 = t1620*t1750;
  t1760 = t1612*t1756;
  t1761 = t1759 + t1760;
  t1763 = t1612*t1750;
  t1764 = -1.*t1620*t1756;
  t1765 = t1763 + t1764;
  t1685 = -0.0216*t1669;
  t1687 = -1.1135*t1673;
  t1688 = 0. + t1685 + t1687;
  t1767 = -1.*t1642*t1761;
  t1768 = t1637*t1765;
  t1769 = t1767 + t1768;
  t1771 = t1637*t1761;
  t1772 = t1642*t1765;
  t1773 = t1771 + t1772;
  t1787 = t1254*t1402*t1356;
  t1788 = t1431*t1254*t1410;
  t1789 = t1787 + t1788;
  t1791 = t1431*t1254*t1402;
  t1792 = -1.*t1254*t1356*t1410;
  t1793 = t1791 + t1792;
  t1799 = -1.*t1287*t1404;
  t1800 = t1332*t1789;
  t1801 = t1799 + t1800;
  t1803 = t1513*t1793;
  t1804 = t1502*t1801;
  t1805 = t1803 + t1804;
  t1807 = t1502*t1793;
  t1808 = -1.*t1513*t1801;
  t1809 = t1807 + t1808;
  t1811 = -1.*t1573*t1805;
  t1812 = t1565*t1809;
  t1813 = t1811 + t1812;
  t1815 = t1565*t1805;
  t1816 = t1573*t1809;
  t1817 = t1815 + t1816;
  t1819 = t1620*t1813;
  t1820 = t1612*t1817;
  t1821 = t1819 + t1820;
  t1823 = t1612*t1813;
  t1824 = -1.*t1620*t1817;
  t1825 = t1823 + t1824;
  t1827 = -1.*t1642*t1821;
  t1828 = t1637*t1825;
  t1829 = t1827 + t1828;
  t1831 = t1637*t1821;
  t1832 = t1642*t1825;
  t1833 = t1831 + t1832;
  p_output1[0]=0. + t1252*t1254*t1352 + t1400*t1427 + t1466*t1476 + t1481*t1496 - 0.1305*(-1.*t1252*t1254*t1332 + t1287*t1496) + t1525*t1535 + t1554*t1557 + t1577*t1584 + t1600*t1609 + t1622*t1626 + t1630*t1634 + t1644*t1649 + t1656*t1662 + t1676*t1682 + t1688*t1693 + 0.0306*(t1673*t1682 + t1665*t1693) - 1.1312*(t1665*t1682 - 1.*t1673*t1693) + var1[0];
  p_output1[1]=0. + t1254*t1352*t1407 + t1400*t1709 + t1466*t1713 + t1481*t1717 - 0.1305*(-1.*t1254*t1332*t1407 + t1287*t1717) + t1525*t1723 + t1554*t1734 + t1577*t1739 + t1600*t1744 + t1622*t1750 + t1630*t1756 + t1644*t1761 + t1656*t1765 + t1676*t1769 + t1688*t1773 + 0.0306*(t1673*t1769 + t1665*t1773) - 1.1312*(t1665*t1769 - 1.*t1673*t1773) + var1[1];
  p_output1[2]=0. + t1254*t1400*t1402 - 1.*t1352*t1404 + t1254*t1410*t1466 + t1481*t1789 - 0.1305*(t1332*t1404 + t1287*t1789) + t1525*t1793 + t1554*t1801 + t1577*t1805 + t1600*t1809 + t1622*t1813 + t1630*t1817 + t1644*t1821 + t1656*t1825 + t1676*t1829 + t1688*t1833 + 0.0306*(t1673*t1829 + t1665*t1833) - 1.1312*(t1665*t1829 - 1.*t1673*t1833) + var1[2];
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

#include "RightToeBottom_mex.hh"

namespace SymExpression
{

void RightToeBottom_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
