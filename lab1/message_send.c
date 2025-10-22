#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>
#include "message_queue.h"

int main()
{
    int msqid = init_queue();
    struct mbuf msg; /* Message buffer for msgsnd() */
    char *str;
    str = "Message 1";
    int msgLen = strlen(str);
    msg.mtype = 100;
    memcpy(msg.mtext, str, msgLen);

    if (msgsnd(msqid, &msg, msgLen, 0) == -1) {
        fprintf(stderr, "%d\n", errno);
        exit(EXIT_FAILURE);
    }
}
