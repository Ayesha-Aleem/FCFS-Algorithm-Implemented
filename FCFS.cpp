#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NUM 100

typedef struct
{
    int p;
    int brusturnaround_time;
    int waiting_time;
    int turnaround_time;
} Process;

void print_table(Process p[], int n);
void print_gantt_chart(Process p[], int n);

int main()
{
    Process p[NUM];
    int i, j, n;
    int sum_waiting_time = 0, sum_turnaround_time;
    printf("Enter total number of process: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        //initially process is zero so
        p[i].p = i+1;
        printf("P[%d] : ", i+1);
        //getting burst time for each elemnt
        scanf("%d", &p[i].brusturnaround_time);
        //initally both are zero
        p[i].waiting_time = p[i].turnaround_time = 0;
    }

    //as in fcfs both are equal so finish time will be equal to bursttime
    p[0].turnaround_time = p[0].brusturnaround_time;
    //calculating 
    for(i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].brusturnaround_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].brusturnaround_time;
    }

    for(i=0; i<n; i++) {
            sum_waiting_time += p[i].waiting_time;
            sum_turnaround_time += p[i].turnaround_time;
    }

    // print table
    puts(""); // Empty line
    print_table(p, n);
    puts(""); // Empty Line
    printf("Total Waiting Time      : %-2d\n", sum_waiting_time);
    printf("Average Waiting Time    : %-2.2lf\n", (double)sum_waiting_time / (double) n);
    printf("Total Turnaround Time   : %-2d\n", sum_turnaround_time);
    printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);

    // print Gantt chart
    puts(""); // Empty line
    puts("          GANTT CHART          ");
    puts("          ***          ");
    print_gantt_chart(p, n);
    return 0;
}


void print_table(Process p[], int n)
{
    int i;

    printf("+*+*+*+***+\n");
    printf("| p | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("+*+*+*+***+\n");

    for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].p, p[i].brusturnaround_time, p[i].waiting_time, p[i].turnaround_time );
        puts(".....................................................");
    }

}

void print_gantt_chart(Process p[], int n)
{
    int i, j;
	    printf(" ");
	    for(i=0; i<n; i++) {
	        for(j=0; j<p[i].brusturnaround_time; j++) printf("--");
	        printf(" ");
	    }
	    printf("\n|");
	    
	    for(i=0; i<n; i++) {
	        for(j=0; j<p[i].brusturnaround_time - 1; j++) printf(" ");
	        printf("P%d", p[i].p);
	        for(j=0; j<p[i].brusturnaround_time - 1; j++) printf(" ");
	        printf("|");
	    }
	    printf("\n ");
	    for(i=0; i<n; i++) {
	        for(j=0; j<p[i].brusturnaround_time; j++) printf("--");
	        printf(" ");
	    }
	    printf("\n");
	
	    printf("0");
	    for(i=0; i<n; i++) {
	        for(j=0; j<p[i].brusturnaround_time; j++) printf("  ");
	        if(p[i].turnaround_time > 9) printf("\b");
	        printf("%d", p[i].turnaround_time);
	
	    }
	    printf("\n");
    getch();
}
