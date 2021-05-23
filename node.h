#ifndef _NODE_H_
#define _NODE_H_

/* a rtpkt is the packet sent from one routing update process to
   another via the call tolayer3() */
struct rtpkt {
  int sourceid;       /* id of sending router sending this pkt */
  int destid;         /* id of router to which pkt being sent 
                         (must be an immediate neighbor) */
  int mincost[4];    /* min cost to node 0 ... 3 */
};

struct distance_table 
{
  int costs[4][4];
};

struct event {
   float evtime;           /* event time */
   int evtype;             /* event type code */
   int eventity;           /* entity where event occurs */
   struct rtpkt *rtpktptr; /* ptr to packet (if any) assoc w/ this event */
   struct event *prev;
   struct event *next;
};

extern int TRACE;
extern int YES;
extern int NO;

/* fuctions define */
// node0.c
void rtinit0();
void rtupdate0(struct rtpkt* rcvdpkt);
void printdt0(struct distance_table* dtptr);
void linkhandler0(int linkid, int newcost);

// node1.c
void rtinit1();
void rtupdate1(struct rtpkt *rcvdpkt);
void printdt1(struct distance_table* dtptr);
void linkhandler1(int linkid, int newcost);

// node2.c
void rtinit2();
void rtupdate2(struct rtpkt *rcvdpkt);
void printdt2(struct distance_table *dtptr);

// node3.c
void rtinit3();
void rtupdate3(struct rtpkt* rcvdpkt);
void printdt3(struct distance_table* dtptr);

// main.c
void creatertpkt(struct rtpkt *initrtpkt, int srcid, int destid, int mincosts[]);
void init();
float jimsrand();
void insertevent(struct event *p);
void printevlist();
void tolayer2(struct rtpkt packet);

#endif
