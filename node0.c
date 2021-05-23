#include <stdio.h>
#include "node.h"

struct distance_table dt0;

/* students to write the following two routines, and maybe some others */

void rtinit0() {
  // initialize distance table 0;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt0.costs[i][j] = 999;
    }
  }
  dt0.costs[0][0] = 0;
  dt0.costs[0][1] = 1;
  dt0.costs[0][2] = 3;
  dt0.costs[0][3] = 7;

  struct rtpkt pkt_to_1;
  pkt_to_1.sourceid = 0;
  pkt_to_1.destid = 1;
  pkt_to_1.mincost[0] = 0;
  pkt_to_1.mincost[1] = 1;
  pkt_to_1.mincost[2] = 3;
  pkt_to_1.mincost[3] = 7;

  struct rtpkt pkt_to_2;
  pkt_to_2.sourceid = 0;
  pkt_to_2.destid = 2;
  pkt_to_2.mincost[0] = 0;
  pkt_to_2.mincost[1] = 1;
  pkt_to_2.mincost[2] = 3;
  pkt_to_2.mincost[3] = 7;

  struct rtpkt pkt_to_3;
  pkt_to_3.sourceid = 0;
  pkt_to_3.destid = 3;
  pkt_to_3.mincost[0] = 0;
  pkt_to_3.mincost[1] = 1;
  pkt_to_3.mincost[2] = 3;
  pkt_to_3.mincost[3] = 7;

  tolayer2(pkt_to_1);
  tolayer2(pkt_to_2);
  tolayer2(pkt_to_3);
}


void rtupdate0(struct rtpkt* rcvdpkt) {
  int id = rcvdpkt->sourceid;

  // udpate distance table0.
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt0.costs[i][j] = min(dt0.costs[i][j], dt0.costs[i][id]+rcvdpkt->mincost[j]);
    }
  }

  for(int i=0; i<4; i++) {
    if(dt0.costs[0][i] != 999 && i != 0) {
      struct rtpkt pkt;
      pkt.sourceid = 0;
      pkt.destid = i;
      pkt.mincost[0] = dt0.costs[0][0];
      pkt.mincost[1] = dt0.costs[0][1];
      pkt.mincost[2] = dt0.costs[0][2];
      pkt.mincost[3] = dt0.costs[0][3];

      tolayer2(pkt);
    }
  }

}


void printdt0(struct distance_table* dtptr)  
{
  printf("                via     \n");
  printf("   D0 |    1     2    3 \n");
  printf("  ----|-----------------\n");
  printf("     1|  %3d   %3d   %3d\n",dtptr->costs[1][1],
	 dtptr->costs[1][2],dtptr->costs[1][3]);
  printf("dest 2|  %3d   %3d   %3d\n",dtptr->costs[2][1],
	 dtptr->costs[2][2],dtptr->costs[2][3]);
  printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][1],
	 dtptr->costs[3][2],dtptr->costs[3][3]);
}

void linkhandler0(int linkid, int newcost) {
  /* called when cost from 0 to linkid changes from current value to newcost*/
  /* You can leave this routine empty if you're an undergrad. If you want */
  /* to use this routine, you'll need to change the value of the LINKCHANGE */
  /* constant definition in prog3.c from 0 to 1 */

}
