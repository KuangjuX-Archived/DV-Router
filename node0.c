#include <stdio.h>
#include "defs.h"

struct distance_table dt0;

int connect_cost0[4] = {0, 1, 3, 7};

/* students to write the following two routines, and maybe some others */

void rtinit0() {
  // initialize distance table 0;
  // printf("node0 :\n");
  // printndt(&dt0, 0);
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt0.costs[i][j] = 999;
    }
  }
  dt0.costs[0][0] = connect_cost0[0];
  dt0.costs[0][1] = connect_cost0[1];
  dt0.costs[0][2] = connect_cost0[2];
  dt0.costs[0][3] = connect_cost0[3];
  // printndt(&dt0, 0);

  for(int i=0; i<4; i++) {
    if(connect_cost0[i] != 999 && i != 0) {
      struct rtpkt pkt;
      pkt.sourceid = 0;
      pkt.destid = i;
      pkt.mincost[0] = connect_cost0[0];
      pkt.mincost[1] = connect_cost0[1];
      pkt.mincost[2] = connect_cost0[2];
      pkt.mincost[3] = connect_cost0[3];

      tolayer2(pkt);
    }
  }
}


void rtupdate0(struct rtpkt* rcvdpkt) {
  int id = rcvdpkt->sourceid;

  // udpate distance table0.
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      dt0.costs[i][j] = min(dt0.costs[i][j], dt0.costs[i][id]+rcvdpkt->mincost[j]);
    }
  }

  // debug
  // printdt0(&dt0);
  // printndt(&dt0, 0);

  for(int i=0; i<4; i++) {
    if(connect_cost0[i] != 999 && i != 0) {
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
  // dt0.costs[0][linkid] = newcost;
  connect_cost0[linkid] = newcost;
  rtinit0();
  rtinit1();
  rtinit2();
  rtinit3();
}
