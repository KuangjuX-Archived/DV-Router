#include <stdio.h>
#include "node.h"

struct distance_table dt2;
int connect_cost2[4] = {3, 1, 0, 2};

/* students to write the following two routines, and maybe some others */

void rtinit2() {
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      // init distance table
      dt2.costs[i][j] = 999;
    }
  }

  dt2.costs[2][0] = 3;
  dt2.costs[2][1] = 1;
  dt2.costs[2][2] = 0;
  dt2.costs[2][3] = 2;

  for(int i=0; i<4; i++) {
    if(connect_cost2[i] != 999 && i != 2) {
      struct rtpkt pkt;
      pkt.sourceid = 2;
      pkt.destid = 3;
      pkt.mincost[0] = 3;
      pkt.mincost[1] = 1;
      pkt.mincost[2] = 0;
      pkt.mincost[3] = 2;

      tolayer2(pkt);
    }
  }
}


void rtupdate2(struct rtpkt *rcvdpkt) {
  int id = rcvdpkt->sourceid;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt2.costs[i][j] = min(dt2.costs[i][j], dt2.costs[i][id]+rcvdpkt->mincost[j]);
    }
  }

  // debug
  // printdt2(&dt2);
  printndt(&dt2, 2);

  for(int i=0; i<4; i++) {
    if(connect_cost2[i] != 999 && i != 2 ) {
      struct rtpkt pkt;
      pkt.sourceid = 2;
      pkt.destid = i;
      pkt.mincost[0] = dt2.costs[2][0];
      pkt.mincost[1] = dt2.costs[2][1];
      pkt.mincost[2] = dt2.costs[2][2];
      pkt.mincost[3] = dt2.costs[2][3];

      tolayer2(pkt);
    }
  }
}


void printdt2(struct distance_table* dtptr) {
  printf("                via     \n");
  printf("   D2 |    0     1    3 \n");
  printf("  ----|-----------------\n");
  printf("     0|  %3d   %3d   %3d\n",dtptr->costs[0][0],
	 dtptr->costs[0][1],dtptr->costs[0][3]);
  printf("dest 1|  %3d   %3d   %3d\n",dtptr->costs[1][0],
	 dtptr->costs[1][1],dtptr->costs[1][3]);
  printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][0],
	 dtptr->costs[3][1],dtptr->costs[3][3]);
}