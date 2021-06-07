/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: AOM.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 07-Jun-2021 01:15:16
 */

/* Include Files */
#include "AOM.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double q1
 *                double q2
 *                double q3
 *                double q1d
 *                double q2d
 *                double q3d
 *                double q1p
 *                double q2p
 *                double q3p
 *                double q1pp
 *                double q2pp
 *                double q3pp
 *                double t
 *                double epop
 *                double u[3]
 * Return Type  : void
 */
void AOM(double q1, double q2, double q3, double q1d, double q2d, double q3d,
         double q1p, double q2p, double q3p, double q1pp, double q2pp,
         double q3pp, double t, double epop, double u[3])
{
  static const signed char a[9] = {10, 0, 0, 0, 10, 0, 0, 0, 10};
  static const signed char b_a[9] = {100, 0, 0, 0, 100, 0, 0, 0, 100};
  double Mq[9];
  double b_q2p[9];
  double b_Mq[3];
  double b_q1p[3];
  double b_q1pp[3];
  double c_q2p[3];
  double Mq_tmp;
  double Mq_tmp_tmp;
  double b_Mq_tmp;
  double b_Mq_tmp_tmp;
  double c_Mq_tmp;
  double d_Mq_tmp;
  double e_Mq_tmp;
  double e_idx_0;
  double e_idx_1;
  double e_idx_2;
  double f_Mq_tmp;
  double g_Mq_tmp;
  double h_Mq_tmp;
  double i_Mq_tmp;
  double j_Mq_tmp;
  double k_Mq_tmp;
  double l_Mq_tmp;
  double m_Mq_tmp;
  int i;
  Mq_tmp_tmp = 2.0 * q2 + 2.0 * q3;
  Mq_tmp = sin(Mq_tmp_tmp);
  b_Mq_tmp = cos(Mq_tmp_tmp);
  c_Mq_tmp = cos(2.0 * q2);
  d_Mq_tmp = sin(q2);
  Mq_tmp_tmp = q2 + q3;
  e_Mq_tmp = sin(Mq_tmp_tmp);
  f_Mq_tmp = cos(q2);
  g_Mq_tmp = cos(q3);
  h_Mq_tmp = sin(q3);
  i_Mq_tmp = sin(2.0 * q2);
  b_Mq_tmp_tmp = 2.0 * q2 + q3;
  j_Mq_tmp = sin(b_Mq_tmp_tmp);
  k_Mq_tmp = cos(b_Mq_tmp_tmp);
  l_Mq_tmp = cos(Mq_tmp_tmp);
  Mq[0] =
      ((((((((((((3.265481663888969E+15 * c_Mq_tmp / 1.8446744073709552E+19 -
                  8.205946264988645E+15 * Mq_tmp / 1.8446744073709552E+19) -
                 2.63674806892459E+14 * b_Mq_tmp / 5.7646075230342349E+17) -
                4.184215030302065E+15 * i_Mq_tmp / 9.2233720368547758E+18) -
               3.3138422806914606E+14 * h_Mq_tmp / 1.152921504606847E+18) -
              2.294198502017165E+14 * Mq_tmp / 1.152921504606847E+18) +
             0.5427 * b_Mq_tmp / 2000.0) -
            3.3138422806914606E+14 * j_Mq_tmp / 1.152921504606847E+18) +
           0.0011745500000000001) +
          0.00027134999999999995) +
         2.3491000000000004 * c_Mq_tmp / 2000.0) +
        0.7839 * k_Mq_tmp / 1000.0) +
       0.7839 * g_Mq_tmp / 1000.0) +
      0.00571084823829;
  Mq[3] = ((((2.838835145611323E+15 * d_Mq_tmp / 9.2233720368547758E+18 -
              3.117807916074061E+15 * f_Mq_tmp / 9.2233720368547758E+18) -
             1.266753801116703E+15 * l_Mq_tmp / 2.305843009213694E+18) +
            6.310642948597741E+15 * e_Mq_tmp / 4.6116860184273879E+18) -
           1.3949125226644206E+14 * d_Mq_tmp / 7.2057594037927936E+16) -
          2.7982269607936634E+14 * e_Mq_tmp / 2.8823037615171174E+17;
  b_Mq_tmp_tmp = 1.266753801116703E+15 * cos(q2 + q3) / 2.305843009213694E+18;
  m_Mq_tmp = 6.310642948597741E+15 * sin(q2 + q3) / 4.6116860184273879E+18;
  Mq_tmp_tmp = 2.7982269607936634E+14 * sin(q2 + q3) / 2.8823037615171174E+17;
  e_idx_0 = (m_Mq_tmp - b_Mq_tmp_tmp) - Mq_tmp_tmp;
  Mq[6] = e_idx_0;
  Mq[1] = ((((2.838835145611323E+15 * sin(q2) / 9.2233720368547758E+18 -
              6.310084434083227E+15 * f_Mq_tmp / 1.8446744073709552E+19) -
             b_Mq_tmp_tmp) +
            m_Mq_tmp) -
           1.3949125226644206E+14 * sin(q2) / 7.2057594037927936E+16) -
          Mq_tmp_tmp;
  Mq[4] = (((67.0 * g_Mq_tmp * 0.13 * 0.09 / 500.0 + 0.0023491000000000002) -
            2.549109446685739E+15 * h_Mq_tmp * 0.13 / 5.7646075230342349E+17) +
           0.00054269999999999991) +
          0.0064686696694999995;
  b_Mq_tmp_tmp = 3.3138422806914606E+14 * sin(q3) / 1.152921504606847E+18;
  Mq[7] = (((8.71 * g_Mq_tmp * 0.09 / 1000.0 + 0.00054269999999999991) -
            5.7239093939216138E+14 * g_Mq_tmp / 5.7646075230342349E+17) -
           b_Mq_tmp_tmp) +
          0.0046911547852;
  Mq[2] = e_idx_0;
  Mq[5] = (((8.71 * cos(q3) * 0.09 / 1000.0 + 0.00054269999999999991) +
            5.7239093939216138E+14 * cos(q3) / 5.7646075230342349E+17) -
           b_Mq_tmp_tmp) +
          0.0046911547852;
  Mq[8] = 0.0052338547852;
  e_idx_0 = q1 - q1d;
  e_idx_1 = q2 - q2d;
  e_idx_2 = q3 - q3d;
  b_q2p[0] =
      -q2p * ((((((((139.0 * i_Mq_tmp * 0.016900000000000002 / 2000.0 +
                     67.0 * j_Mq_tmp * 0.13 * 0.09 / 1000.0) +
                    2.549109446685739E+15 * k_Mq_tmp * 0.13 /
                        1.152921504606847E+18) +
                   67.0 * Mq_tmp * 0.0081 / 2000.0) +
                  2.549109446685739E+15 * b_Mq_tmp * 0.09 /
                      1.152921504606847E+18) +
                 8.205946264988645E+15 * b_Mq_tmp / 1.8446744073709552E+19) -
                2.63674806892459E+14 * Mq_tmp / 5.7646075230342349E+17) +
               4.184215030302065E+15 * c_Mq_tmp / 9.2233720368547758E+18) +
              3.265481663888969E+15 * i_Mq_tmp / 1.8446744073709552E+19) -
      q3p * (((((((8.205946264988645E+15 * cos(2.0 * q2 + 2.0 * q3) /
                       1.8446744073709552E+19 -
                   2.63674806892459E+14 * sin(2.0 * q2 + 2.0 * q3) /
                       5.7646075230342349E+17) +
                  3.3138422806914606E+14 * g_Mq_tmp / 2.305843009213694E+18) +
                 2.294198502017165E+14 * b_Mq_tmp / 1.152921504606847E+18) +
                0.5427 * Mq_tmp / 2000.0) +
               3.3138422806914606E+14 * k_Mq_tmp / 2.305843009213694E+18) +
              0.7839 * j_Mq_tmp / 2000.0) +
             0.7839 * h_Mq_tmp / 2000.0);
  m_Mq_tmp =
      q1p * ((((((((139.0 * sin(2.0 * q2) * 0.016900000000000002 / 2000.0 +
                    67.0 * sin(2.0 * q2 + q3) * 0.13 * 0.09 / 1000.0) +
                   2.549109446685739E+15 * cos(2.0 * q2 + q3) * 0.13 /
                       1.152921504606847E+18) +
                  67.0 * sin(2.0 * q2 + 2.0 * q3) * 0.0081 / 2000.0) +
                 2.549109446685739E+15 * cos(2.0 * q2 + 2.0 * q3) * 0.09 /
                     1.152921504606847E+18) +
                8.205946264988645E+15 * cos(2.0 * q2 + 2.0 * q3) /
                    1.8446744073709552E+19) -
               2.63674806892459E+14 * sin(2.0 * q2 + 2.0 * q3) /
                   5.7646075230342349E+17) +
              4.184215030302065E+15 * cos(2.0 * q2) / 9.2233720368547758E+18) +
             3.265481663888969E+15 * sin(2.0 * q2) / 1.8446744073709552E+19);
  b_q2p[3] =
      (q3p * ((6.310642948597741E+15 * l_Mq_tmp / 4.6116860184273879E+18 +
               1.266753801116703E+15 * e_Mq_tmp / 2.305843009213694E+18) -
              2.7982269607936634E+14 * l_Mq_tmp / 2.8823037615171174E+17) -
       m_Mq_tmp) +
      q2p * (((((2.838835145611323E+15 * f_Mq_tmp / 1.8446744073709552E+19 +
                 3.117807916074061E+15 * d_Mq_tmp / 1.8446744073709552E+19) +
                6.310642948597741E+15 * cos(q2 + q3) / 9.2233720368547758E+18) +
               1.266753801116703E+15 * sin(q2 + q3) / 4.6116860184273879E+18) -
              1.3949125226644206E+14 * f_Mq_tmp / 1.4411518807585587E+17) -
             2.7982269607936634E+14 * cos(q2 + q3) / 5.7646075230342349E+17);
  Mq_tmp_tmp =
      q1p *
      (((((((8.205946264988645E+15 * cos(2.0 * q2 + 2.0 * q3) /
                 1.8446744073709552E+19 -
             2.63674806892459E+14 * sin(2.0 * q2 + 2.0 * q3) /
                 5.7646075230342349E+17) +
            3.3138422806914606E+14 * cos(q3) / 2.305843009213694E+18) +
           2.294198502017165E+14 * cos(2.0 * q2 + 2.0 * q3) /
               1.152921504606847E+18) +
          0.5427 * Mq_tmp / 2000.0) +
         3.3138422806914606E+14 * cos(2.0 * q2 + q3) / 2.305843009213694E+18) +
        0.7839 * sin(2.0 * q2 + q3) / 2000.0) +
       0.7839 * sin(q3) / 2000.0);
  b_q2p[6] =
      (q2p * ((6.310642948597741E+15 * cos(q2 + q3) / 4.6116860184273879E+18 +
               1.266753801116703E+15 * sin(q2 + q3) / 2.305843009213694E+18) -
              2.7982269607936634E+14 * cos(q2 + q3) / 2.8823037615171174E+17) +
       q3p * ((6.310642948597741E+15 * cos(q2 + q3) / 4.6116860184273879E+18 +
               1.266753801116703E+15 * sin(q2 + q3) / 2.305843009213694E+18) -
              2.7982269607936634E+14 * cos(q2 + q3) / 2.8823037615171174E+17)) -
      Mq_tmp_tmp;
  b_q2p[1] =
      m_Mq_tmp + 7.4468601935105E+13 * d_Mq_tmp * q2p / 3.6893488147419103E+19;
  m_Mq_tmp = 3.3138422806914606E+14 * cos(q3) / 1.152921504606847E+18 +
             0.7839 * sin(q3) / 1000.0;
  b_q2p[4] = -q3p * m_Mq_tmp;
  b_q2p[7] = -q2p * m_Mq_tmp - 0.13 * q3p *
                                   ((3.1863868083571738E+17 * g_Mq_tmp -
                                     1.1007518065233873E+18 * h_Mq_tmp) +
                                    8.6901458409741082E+17 * h_Mq_tmp) /
                                   1.4411518807585587E+20;
  b_q2p[2] = Mq_tmp_tmp;
  b_q2p[5] = q2p * m_Mq_tmp -
             5.7239093939216138E+14 * h_Mq_tmp * q3p / 5.7646075230342349E+17;
  b_q2p[8] = 0.0;
  b_q1p[0] = 0.0;
  b_q1p[1] = -0.66708000000000012 * (0.13 * f_Mq_tmp + 0.09 * l_Mq_tmp) -
             0.0918216 * f_Mq_tmp;
  b_q1p[2] = -0.060037200000000006 * l_Mq_tmp;
  Mq_tmp_tmp = e_idx_0 - epop;
  b_Mq_tmp_tmp = e_idx_1 - epop;
  m_Mq_tmp = e_idx_2 - epop;
  for (i = 0; i < 3; i++) {
    c_q2p[i] = (b_q2p[i] * q1p + b_q2p[i + 3] * q2p) + b_q2p[i + 6] * q3p;
    b_Mq[i] = (Mq[i] * q1pp + Mq[i + 3] * q2pp) + Mq[i + 6] * q3pp;
    b_q1pp[i] = (((double)a[i] * Mq_tmp_tmp + (double)a[i + 3] * b_Mq_tmp_tmp) +
                 (double)a[i + 6] * m_Mq_tmp) /
                t;
  }
  Mq_tmp_tmp = b_q1pp[0];
  b_Mq_tmp_tmp = b_q1pp[1];
  m_Mq_tmp = b_q1pp[2];
  for (i = 0; i < 3; i++) {
    b_q1pp[i] = ((double)b_a[i] * e_idx_0 + (double)b_a[i + 3] * e_idx_1) +
                (double)b_a[i + 6] * e_idx_2;
    u[i] = ((b_Mq[i] + c_q2p[i]) + b_q1p[i]) -
           ((Mq[i] * Mq_tmp_tmp + Mq[i + 3] * b_Mq_tmp_tmp) +
            Mq[i + 6] * m_Mq_tmp);
  }
  Mq_tmp_tmp = b_q1pp[0];
  b_Mq_tmp_tmp = b_q1pp[1];
  m_Mq_tmp = b_q1pp[2];
  for (i = 0; i < 3; i++) {
    u[i] -=
        (Mq[i] * Mq_tmp_tmp + Mq[i + 3] * b_Mq_tmp_tmp) + Mq[i + 6] * m_Mq_tmp;
  }
}

/*
 * File trailer for AOM.c
 *
 * [EOF]
 */
