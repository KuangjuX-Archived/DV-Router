#include <stdio.h>
#include "defs.h"


int connect_costs1[4] = { 1,  0,  1, 999 };

struct distance_table dt1;


/* students to write the following two routines, and maybe some others */


void rtinit1() {
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt1.costs[i][j] = 999;
    }
  }
  
  dt1.costs[1][0] = 1;
  dt1.costs[1][1] = 0;
  dt1.costs[1][2] = 1;
  dt1.costs[1][3] = 999;
  
  for(int i=0; i<4; i++) {
    if(connect_costs1[i] != 999 && i != 1) {
      struct rtpkt pkt;
      pkt.sourceid = 1;
      pkt.destid = i;
      pkt.mincost[0] = 1;
      pkt.mincost[1] = 0;
      pkt.mincost[2] = 1;
      pkt.mincost[3] = 999;

      tolayer2(pkt);
    }
  }
}


void rtupdate1(struct rtpkt *rcvdpkt) {
  int id = rcvdpkt->sourceid;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt1.costs[i][j] = min(dt1.costs[i][j], dt1.costs[i][id]+rcvdpkt->mincost[j]);
    }
  }

  // debug
  // printdt1(&dt1);
  printndt(&dt1, 1);

  for(int i=0; i<4; i++) {
    if(connect_costs1[i] != 999 && i != 1) {
      struct rtpkt pkt;
      pkt.sourceid = 1;
      pkt.destid = i;
      pkt.mincost[0] = dt1.costs[1][0];
      pkt.mincost[1] = dt1.costs[1][1];
      pkt.mincost[2] = dt1.costs[1][2];
      pkt.mincost[3] = dt1.costs[1][3];

      tolayer2(pkt);
    }
  }
}


void printdt1(struct distance_table* dtptr) {
  printf("             via   \n");
  printf("   D1 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);
  printf("     3|  %3d   %3d\n",dtptr->costs[3][0], dtptr->costs[3][2]);

}



void linkhandler1(int linkid, int newcost) {
  /* called when cost from 1 to linkid changes from current value to newcost*/
  /* You can leave this routine empty if you're an undergrad. If you want */
  /* to use this routine, you'll need to change the value of the LINKCHANGE */
  /* constant definition in prog3.c from 0 to 1 */
}

