#include <stdio.h>
#include "node.h"

struct distance_table dt3;

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

  struct rtpkt pkt_to_0;
  pkt_to_0.sourceid = 3;
  pkt_to_0.destid = 0;
  pkt_to_0.mincost[0] = 7;
  pkt_to_0.mincost[1] = 999;
  pkt_to_0.mincost[2] = 2;
  pkt_to_0.mincost[3] = 0;

  struct rtpkt pkt_to_2;
  pkt_to_2.sourceid = 3;
  pkt_to_2.destid = 2;
  pkt_to_2.mincost[0] = 7;
  pkt_to_2.mincost[1] = 999;
  pkt_to_2.mincost[2] = 2;
  pkt_to_2.mincost[3] = 0;

  tolayer2(pkt_to_0);
  tolayer2(pkt_to_2);

}


void rtupdate3(struct rtpkt* rcvdpkt) {
  int id = rcvdpkt->sourceid;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt3.costs[i][j] = min(dt3.costs[i][j], dt3.costs[i][id]+rcvdpkt->mincost[j]);
    }
  }

  for(int i=0; i<4; i++) {
    if(dt3.costs[2][i] != 999 && i != 3 ) {
      struct rtpkt pkt;
      pkt.sourceid = 3;
      pkt.destid = i;
      pkt.mincost[0] = dt3.costs[3][0];
      pkt.mincost[1] = dt3.costs[3][1];
      pkt.mincost[2] = dt3.costs[3][2];
      pkt.mincost[3] = dt3.costs[3][3];
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






