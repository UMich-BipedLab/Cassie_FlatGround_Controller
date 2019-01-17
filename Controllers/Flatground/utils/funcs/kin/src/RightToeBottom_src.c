/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:20 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RightToeBottom_src.h"

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
  double t1330;
  double t1479;
  double t1482;
  double t1480;
  double t1485;
  double t1354;
  double t1362;
  double t1400;
  double t1426;
  double t1466;
  double t1481;
  double t1501;
  double t1512;
  double t1525;
  double t1547;
  double t1550;
  double t1551;
  double t1351;
  double t1556;
  double t1560;
  double t1571;
  double t1577;
  double t1579;
  double t1581;
  double t1588;
  double t1601;
  double t1609;
  double t1610;
  double t1630;
  double t1631;
  double t1632;
  double t1640;
  double t1643;
  double t1644;
  double t1648;
  double t1654;
  double t1656;
  double t1659;
  double t1676;
  double t1680;
  double t1684;
  double t1687;
  double t1688;
  double t1690;
  double t1695;
  double t1699;
  double t1700;
  double t1701;
  double t1706;
  double t1707;
  double t1709;
  double t1711;
  double t1712;
  double t1714;
  double t1716;
  double t1723;
  double t1724;
  double t1726;
  double t1732;
  double t1735;
  double t1737;
  double t1740;
  double t1741;
  double t1744;
  double t1748;
  double t1753;
  double t1755;
  double t1757;
  double t1765;
  double t1766;
  double t1768;
  double t1405;
  double t1427;
  double t1429;
  double t1475;
  double t1477;
  double t1526;
  double t1535;
  double t1541;
  double t1546;
  double t1553;
  double t1554;
  double t1555;
  double t1782;
  double t1783;
  double t1784;
  double t1786;
  double t1787;
  double t1788;
  double t1587;
  double t1595;
  double t1600;
  double t1790;
  double t1791;
  double t1793;
  double t1627;
  double t1628;
  double t1629;
  double t1646;
  double t1651;
  double t1652;
  double t1795;
  double t1796;
  double t1797;
  double t1806;
  double t1807;
  double t1809;
  double t1663;
  double t1670;
  double t1675;
  double t1691;
  double t1696;
  double t1697;
  double t1812;
  double t1813;
  double t1814;
  double t1816;
  double t1818;
  double t1819;
  double t1703;
  double t1704;
  double t1705;
  double t1715;
  double t1718;
  double t1719;
  double t1822;
  double t1823;
  double t1825;
  double t1828;
  double t1830;
  double t1831;
  double t1728;
  double t1729;
  double t1731;
  double t1745;
  double t1750;
  double t1751;
  double t1834;
  double t1835;
  double t1836;
  double t1838;
  double t1839;
  double t1840;
  double t1760;
  double t1762;
  double t1763;
  double t1842;
  double t1843;
  double t1844;
  double t1846;
  double t1847;
  double t1848;
  double t1862;
  double t1863;
  double t1864;
  double t1866;
  double t1867;
  double t1868;
  double t1874;
  double t1875;
  double t1876;
  double t1878;
  double t1879;
  double t1880;
  double t1882;
  double t1883;
  double t1884;
  double t1886;
  double t1887;
  double t1888;
  double t1890;
  double t1891;
  double t1892;
  double t1894;
  double t1895;
  double t1896;
  double t1898;
  double t1899;
  double t1900;
  double t1902;
  double t1903;
  double t1904;
  double t1906;
  double t1907;
  double t1908;
  t1330 = Cos(var1[3]);
  t1479 = Cos(var1[5]);
  t1482 = Sin(var1[3]);
  t1480 = Sin(var1[4]);
  t1485 = Sin(var1[5]);
  t1354 = Cos(var1[14]);
  t1362 = -1.*t1354;
  t1400 = 1. + t1362;
  t1426 = Sin(var1[14]);
  t1466 = Sin(var1[13]);
  t1481 = t1330*t1479*t1480;
  t1501 = t1482*t1485;
  t1512 = t1481 + t1501;
  t1525 = Cos(var1[13]);
  t1547 = -1.*t1479*t1482;
  t1550 = t1330*t1480*t1485;
  t1551 = t1547 + t1550;
  t1351 = Cos(var1[4]);
  t1556 = t1466*t1512;
  t1560 = t1525*t1551;
  t1571 = t1556 + t1560;
  t1577 = Cos(var1[15]);
  t1579 = -1.*t1577;
  t1581 = 1. + t1579;
  t1588 = Sin(var1[15]);
  t1601 = t1525*t1512;
  t1609 = -1.*t1466*t1551;
  t1610 = t1601 + t1609;
  t1630 = t1354*t1330*t1351;
  t1631 = t1426*t1571;
  t1632 = t1630 + t1631;
  t1640 = Cos(var1[16]);
  t1643 = -1.*t1640;
  t1644 = 1. + t1643;
  t1648 = Sin(var1[16]);
  t1654 = t1588*t1610;
  t1656 = t1577*t1632;
  t1659 = t1654 + t1656;
  t1676 = t1577*t1610;
  t1680 = -1.*t1588*t1632;
  t1684 = t1676 + t1680;
  t1687 = Cos(var1[17]);
  t1688 = -1.*t1687;
  t1690 = 1. + t1688;
  t1695 = Sin(var1[17]);
  t1699 = -1.*t1648*t1659;
  t1700 = t1640*t1684;
  t1701 = t1699 + t1700;
  t1706 = t1640*t1659;
  t1707 = t1648*t1684;
  t1709 = t1706 + t1707;
  t1711 = Cos(var1[18]);
  t1712 = -1.*t1711;
  t1714 = 1. + t1712;
  t1716 = Sin(var1[18]);
  t1723 = t1695*t1701;
  t1724 = t1687*t1709;
  t1726 = t1723 + t1724;
  t1732 = t1687*t1701;
  t1735 = -1.*t1695*t1709;
  t1737 = t1732 + t1735;
  t1740 = Cos(var1[19]);
  t1741 = -1.*t1740;
  t1744 = 1. + t1741;
  t1748 = Sin(var1[19]);
  t1753 = -1.*t1716*t1726;
  t1755 = t1711*t1737;
  t1757 = t1753 + t1755;
  t1765 = t1711*t1726;
  t1766 = t1716*t1737;
  t1768 = t1765 + t1766;
  t1405 = -0.049*t1400;
  t1427 = -0.135*t1426;
  t1429 = 0. + t1405 + t1427;
  t1475 = 0.135*t1466;
  t1477 = 0. + t1475;
  t1526 = -1.*t1525;
  t1535 = 1. + t1526;
  t1541 = -0.135*t1535;
  t1546 = 0. + t1541;
  t1553 = -0.135*t1400;
  t1554 = 0.049*t1426;
  t1555 = 0. + t1553 + t1554;
  t1782 = t1479*t1482*t1480;
  t1783 = -1.*t1330*t1485;
  t1784 = t1782 + t1783;
  t1786 = t1330*t1479;
  t1787 = t1482*t1480*t1485;
  t1788 = t1786 + t1787;
  t1587 = -0.09*t1581;
  t1595 = 0.049*t1588;
  t1600 = 0. + t1587 + t1595;
  t1790 = t1466*t1784;
  t1791 = t1525*t1788;
  t1793 = t1790 + t1791;
  t1627 = -0.049*t1581;
  t1628 = -0.09*t1588;
  t1629 = 0. + t1627 + t1628;
  t1646 = -0.049*t1644;
  t1651 = -0.21*t1648;
  t1652 = 0. + t1646 + t1651;
  t1795 = t1525*t1784;
  t1796 = -1.*t1466*t1788;
  t1797 = t1795 + t1796;
  t1806 = t1354*t1351*t1482;
  t1807 = t1426*t1793;
  t1809 = t1806 + t1807;
  t1663 = -0.21*t1644;
  t1670 = 0.049*t1648;
  t1675 = 0. + t1663 + t1670;
  t1691 = -0.2707*t1690;
  t1696 = 0.0016*t1695;
  t1697 = 0. + t1691 + t1696;
  t1812 = t1588*t1797;
  t1813 = t1577*t1809;
  t1814 = t1812 + t1813;
  t1816 = t1577*t1797;
  t1818 = -1.*t1588*t1809;
  t1819 = t1816 + t1818;
  t1703 = -0.0016*t1690;
  t1704 = -0.2707*t1695;
  t1705 = 0. + t1703 + t1704;
  t1715 = 0.0184*t1714;
  t1718 = -0.7055*t1716;
  t1719 = 0. + t1715 + t1718;
  t1822 = -1.*t1648*t1814;
  t1823 = t1640*t1819;
  t1825 = t1822 + t1823;
  t1828 = t1640*t1814;
  t1830 = t1648*t1819;
  t1831 = t1828 + t1830;
  t1728 = -0.7055*t1714;
  t1729 = -0.0184*t1716;
  t1731 = 0. + t1728 + t1729;
  t1745 = -1.1135*t1744;
  t1750 = 0.0216*t1748;
  t1751 = 0. + t1745 + t1750;
  t1834 = t1695*t1825;
  t1835 = t1687*t1831;
  t1836 = t1834 + t1835;
  t1838 = t1687*t1825;
  t1839 = -1.*t1695*t1831;
  t1840 = t1838 + t1839;
  t1760 = -0.0216*t1744;
  t1762 = -1.1135*t1748;
  t1763 = 0. + t1760 + t1762;
  t1842 = -1.*t1716*t1836;
  t1843 = t1711*t1840;
  t1844 = t1842 + t1843;
  t1846 = t1711*t1836;
  t1847 = t1716*t1840;
  t1848 = t1846 + t1847;
  t1862 = t1351*t1479*t1466;
  t1863 = t1525*t1351*t1485;
  t1864 = t1862 + t1863;
  t1866 = t1525*t1351*t1479;
  t1867 = -1.*t1351*t1466*t1485;
  t1868 = t1866 + t1867;
  t1874 = -1.*t1354*t1480;
  t1875 = t1426*t1864;
  t1876 = t1874 + t1875;
  t1878 = t1588*t1868;
  t1879 = t1577*t1876;
  t1880 = t1878 + t1879;
  t1882 = t1577*t1868;
  t1883 = -1.*t1588*t1876;
  t1884 = t1882 + t1883;
  t1886 = -1.*t1648*t1880;
  t1887 = t1640*t1884;
  t1888 = t1886 + t1887;
  t1890 = t1640*t1880;
  t1891 = t1648*t1884;
  t1892 = t1890 + t1891;
  t1894 = t1695*t1888;
  t1895 = t1687*t1892;
  t1896 = t1894 + t1895;
  t1898 = t1687*t1888;
  t1899 = -1.*t1695*t1892;
  t1900 = t1898 + t1899;
  t1902 = -1.*t1716*t1896;
  t1903 = t1711*t1900;
  t1904 = t1902 + t1903;
  t1906 = t1711*t1896;
  t1907 = t1716*t1900;
  t1908 = t1906 + t1907;
  p_output1[0]=0. + t1330*t1351*t1429 + t1477*t1512 + t1546*t1551 + t1555*t1571 - 0.1305*(-1.*t1330*t1351*t1426 + t1354*t1571) + t1600*t1610 + t1629*t1632 + t1652*t1659 + t1675*t1684 + t1697*t1701 + t1705*t1709 + t1719*t1726 + t1731*t1737 + t1751*t1757 + t1763*t1768 + 0.0306*(t1748*t1757 + t1740*t1768) - 1.1312*(t1740*t1757 - 1.*t1748*t1768) + var1[0];
  p_output1[1]=0. + t1351*t1429*t1482 + t1477*t1784 + t1546*t1788 + t1555*t1793 - 0.1305*(-1.*t1351*t1426*t1482 + t1354*t1793) + t1600*t1797 + t1629*t1809 + t1652*t1814 + t1675*t1819 + t1697*t1825 + t1705*t1831 + t1719*t1836 + t1731*t1840 + t1751*t1844 + t1763*t1848 + 0.0306*(t1748*t1844 + t1740*t1848) - 1.1312*(t1740*t1844 - 1.*t1748*t1848) + var1[1];
  p_output1[2]=0. + t1351*t1477*t1479 - 1.*t1429*t1480 + t1351*t1485*t1546 + t1555*t1864 - 0.1305*(t1426*t1480 + t1354*t1864) + t1600*t1868 + t1629*t1876 + t1652*t1880 + t1675*t1884 + t1697*t1888 + t1705*t1892 + t1719*t1896 + t1731*t1900 + t1751*t1904 + t1763*t1908 + 0.0306*(t1748*t1904 + t1740*t1908) - 1.1312*(t1740*t1904 - 1.*t1748*t1908) + var1[2];
}



void RightToeBottom_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
