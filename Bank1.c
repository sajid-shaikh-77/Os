// Banker's Algorithm Slot1

#include <stdio.h>
int A[10][10], M[10][10], N[10][10], Av[10], Safe[10], Finish[10], nor, nop;
void AcceptData(int X[][10])
{
    int i, j;
    for (i = 0; i < nop; i++)
    {
        printf("P%d\n", i);
        for (j = 0; j < nor; j++)
        {
            printf("%c: ", 65 + j);
            scanf("%d", &X[i][j]);
        }
    }
}
void AcceptAvailability()
{
    int i;
    for (i = 0; i < nor; i++)
    {
        printf("%c: ", 65 + i);
        scanf("%d", &Av[i]);
    }
}
void DisplayData()
{
    int i, j;
    printf("\n\tAllocation\t\tMax\t\tNeed\n");
    printf("\t");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < nor; j++)
            printf("%4c", 65 + j);
        printf("\t");
    }
    for (i = 0; i < nop; i++)
    {
        printf("\nP%d\t", i);
        for (j = 0; j < nor; j++)
            printf("%4d", A[i][j]);
        printf("\t");
        for (j = 0; j < nor; j++)
            printf("%4d", M[i][j]);
        printf("\t");
        for (j = 0; j < nor; j++)
            printf("%4d", N[i][j]);
    }
    printf("\nAvailable\n");
    for (j = 0; j < nor; j++)
        printf("%4d", Av[j]);
}

void CalcNeed()
{
    int i, j;
    for (i = 0; i < nop; i++)
        for (j = 0; j < nor; j++)
            N[i][j] = M[i][j] - A[i][j];
}

void main()
{
    printf("\nEnter No.of Processes & No.of Resources: ");
    scanf("%d %d", &nop, &nor);
    printf("Enter Allocation\n");
    AcceptData(A);
    printf("Enter Max Requirement\n");
    AcceptData(M);
    printf("Enter Availability\n");
    AcceptAvailability();
    CalcNeed();
    DisplayData();
}
