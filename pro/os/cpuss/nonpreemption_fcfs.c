//비선점 fcfs scheduling system

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROCESSCOUNT 5

#define BTMAX 50
#define ATMAX 5
#define PMAX 3

int Process_count = 0;

double sumAT = 0, sumBT = 0;

typedef struct PROCESS{

    int pid;
    int BT;
    int AT;
    int Priority;

}PROCESS;

typedef struct QUEUE{

    int _pid;
    int _BT;
    int _AT;
    int _Priority;
    struct QUEUE *prev;
    struct QUEUE *next;

}QUEUE;


PROCESS makeProcess(){

    PROCESS ret;

    ret.pid = Process_count++;
    ret.BT = 1 + rand()%BTMAX;
    ret.AT = rand()%ATMAX;
    ret.Priority = 1 + rand()%PMAX;

    return ret;
}

PROCESS sortAT(PROCESS arr[PROCESSCOUNT]){
    int i, j;
    for(i = 0; i<PROCESSCOUNT; ++i){
        for(j = i+1; j<PROCESSCOUNT; ++j){
            if(arr[i].AT>arr[j].AT){
                PROCESS temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int schedule(QUEUE *head){

    QUEUE *curr = head->next;
    while(curr != 0){
        QUEUE *temp = curr->next;
        if(sumBT < curr->_AT){
            sumAT = sumAT;
            sumBT = sumBT + curr->_BT;
        }
        else{
            sumAT = sumAT + sumBT - curr->_AT;
            sumBT = sumBT + curr->_BT;
        }
        free(curr);
        curr = temp;
    }
}

void addQueue(QUEUE *cpu, PROCESS *temp){

    QUEUE *new = malloc(sizeof(QUEUE));
    new->_pid = temp->pid;
    new->_AT = temp->AT;
    new->_BT = temp->BT;
    new->_Priority = temp->Priority;

    if(cpu->next == 0){

        cpu->next= new;
        new->prev = cpu;
        new->next = 0;
    }
    else{

        QUEUE *curr = cpu->next;
        QUEUE *before = curr;

        while(curr != 0){
            before = curr;
            curr = curr->next;
        }
        before->next = new;
        new->prev = before;
        new->next = 0;
    }
}

void printProcess(PROCESS arr[PROCESSCOUNT]){
    int i;
    for(i = 0; i<PROCESSCOUNT; ++i){
        printf("pid : %d\n", arr[i].pid);
        printf("AT : %d\n", arr[i].AT);
        printf("BT : %d\n", arr[i].BT);
        printf("Pri : %d\n", arr[i].Priority);
        puts("");
    }
}

int main() {

    puts("fcfs ss");

    PROCESS arr[PROCESSCOUNT];
    srand(time(NULL));

    int i = 0;
    for(i = 0; i<PROCESSCOUNT; ++i){
        arr[i] = makeProcess();
    }

    puts("now state");
    printProcess(arr);

    sortAT(arr);

    puts("after sorting (AT)");
    printProcess(arr);

    QUEUE *cpu = malloc(sizeof(QUEUE));
    cpu->next = 0;


    for(i=0; i<PROCESSCOUNT; i++){
        addQueue(cpu, arr + i);
    }

    schedule(cpu);

    puts("total AT");
    printf("total Process : %d\n", PROCESSCOUNT);
    printf("sumAT : %.0lf\n", sumAT);
    printf("average AT : %lf", sumAT / PROCESSCOUNT);
    free(cpu);
    return 0;
}
