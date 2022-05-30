// Write an OS program to implement FCFS Disk Scheduling algorithm
//****************************************************************
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    // logic for FCFS disk scheduling

    for (i = 0; i < n; i++)
    {
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        initial = RQ[i];
    }
    printf("Total head moment is %d", TotalHeadMoment);
    return 0;
}

// *****************************************************************************
// Enter the number of Requests
// 8
// Enter the Requests sequence
// 98
// 183
// 41
// 122
// 14
// 124
// 65
// 67
// Enter initial head position
// 53
// Total head moment is 632