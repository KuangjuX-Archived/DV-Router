#include <stdio.h>
#include "node.h"

struct distance_table dt3;
int connect_costs4[4] = {7, 999, 2, 0};

/* students to write the following two routines, and maybe some others */

void rtinit3() {
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt3.costs[i][j] = 999;
    }
  }

  dt3.costs[3][0] = 7;
  dt3.costs[3][1] = 999;
  dt3.costs[3][2] = 2;
  dt3.costs[3][3] = 0;

  for(int i=0; i<4; i++) {
    if(connect_costs4[i] != 999 && i != 3) {
      struct rtpkt pkt;
      pkt.sourceid = 3;
      pkt.destid = i;
      pkt.mincost[0] = 7;
      pkt.mincost[1] = 999;
      pkt.mincost[2] = 2;
      pkt.mincost[3] = 0;

      tolayer2(pkt);
    }
  }

}


void rtupdate3(struct rtpkt* rcvdpkt) {
  int id = rcvdpkt->sourceid;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt3.costs[i][j] = min(dt3.costs[i][j], dt3.costs[i][id]+rcvdpkt->mincost[j]);
    }
  }

  // debug
  // printdt3(&dt3);
  printndt(&dt3, 3);

  for(int i=0; i<4; i++) {
    if(connect_costs4[i] != 999 && i != 3 ) {
      struct rtpkt pkt;
      pkt.sourceid = 3;
      pkt.destid = i;
      pkt.mincost[0] = dt3.costs[3][0];
      pkt.mincost[1] = dt3.costs[3][1];
      pkt.mincost[2] = dt3.costs[3][2];
      pkt.mincost[3] = dt3.costs[3][3];

      tolayer2(pkt);
    }
  }
}


void printdt3(struct distance_table* dtptr) {
  printf("             via     \n");
  printf("   D3 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 1|  %3d   %3d\n",dtptr->costs[1][0], dtptr->costs[1][2]);
  printf("     2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);

}






