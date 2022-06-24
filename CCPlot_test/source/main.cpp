#include <QApplication>

#include "ccplot.h"

#include "ccplotangularvelocity.h"
#include "ccplotbendmoment.h"
#include "ccploticeresistence.h"
#include "ccplotshipacc.h"
#include "ccplotshipangle.h"
#include "ccplotshipdisplacement.h"
#include "ccplotshipvelocity.h"
#include "ccplotforcexy.h"
#include "ccplotforcez.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

//  CCPlotAngularVelocity cpa(nullptr);
//  cpa.makeGraph();
//  cpa.show();
//  QMap<QString, bool> mp1;
//  mp1[QString::fromLocal8Bit("横摇")] = true;
//  mp1[QString::fromLocal8Bit("纵摇")] = true;
//  mp1[QString::fromLocal8Bit("艏摇")] = true;
//  cpa.update(mp1);


//  CCPlotBendMoment cpb(nullptr);
//  cpb.makeGraph();
//  cpb.show();
//  QMap<QString, bool> mp2;
//  mp2[QString::fromLocal8Bit("M_yz")] = true;
//  mp2[QString::fromLocal8Bit("M_xz")] = true;
//  mp2[QString::fromLocal8Bit("M_xy")] = true;
//  cpb.update(mp2);


//  CCPlotIceResistence cpi(nullptr);
//  cpi.makeGraph();
//  cpi.show();
//  QMap<QString, bool> mp3;
//  mp3[QString::fromLocal8Bit("纵向")] = true;
//  mp3[QString::fromLocal8Bit("横向")] = true;
//  mp3[QString::fromLocal8Bit("垂向")] = true;
//  cpi.update(mp3);


//  CCPlotShipAcc cps(nullptr);
//  cps.makeGraph();
//  cps.show();
//  QMap<QString, bool> mp4;
//  mp4[QString::fromLocal8Bit("surge")] = true;
//  mp4[QString::fromLocal8Bit("sway")] = true;
//  mp4[QString::fromLocal8Bit("heave")] = true;
//  mp4[QString::fromLocal8Bit("roll")] = true;
//  mp4[QString::fromLocal8Bit("pitch")] = true;
//  mp4[QString::fromLocal8Bit("yaw")] = true;
//  cps.update(mp4);


//  CCPlotShipAngle cpsa(nullptr);
//  cpsa.makeGraph();
//  cpsa.show();
//  QMap<QString, bool> mp5;
//  mp5[QString::fromLocal8Bit("横摇")] = true;
//  mp5[QString::fromLocal8Bit("纵摇")] = true;
//  mp5[QString::fromLocal8Bit("艏摇")] = true;
//  cpsa.update(mp5);


//  CCPlotShipDisplacement cpsd(nullptr);
//  cpsd.makeGraph();
//  cpsd.show();
//  QMap<QString, bool> mp6;
//  mp6[QString::fromLocal8Bit("纵向")] = true;
//  mp6[QString::fromLocal8Bit("横向")] = true;
//  mp6[QString::fromLocal8Bit("垂向")] = true;
//  cpsd.update(mp6);


//  CCPlotShipVelocity cpv(nullptr);
//  cpv.makeGraph();
//  cpv.show();
//  QMap<QString, bool> mp7;
//  mp7[QString::fromLocal8Bit("纵向")] = true;
//  mp7[QString::fromLocal8Bit("横向")] = true;
//  mp7[QString::fromLocal8Bit("垂向")] = true;
//  cpv.update(mp7);


  CCPlotForceXY cpfxy(nullptr);
  cpfxy.show();
  cpfxy.makeGraph();

  CCPlotForceZ cpfz(nullptr);
  cpfz.show();
  cpfz.makeGraph();

  return a.exec();
}
