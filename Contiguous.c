/* ------------- Contiguous File Allocation -------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct freelist
{
    int start;
    int size;
    struct freelist *next;
};

struct usedlist
{
    char fname[10];
    int fstart;
    int fsize;
};

struct freelist *head = NULL, *new = NULL, *temp, *prev, *temp1;
struct usedlist dir_ent[10];
int dir_index = 0;

main()
{
    int ch, i;
    char filename[10];
    create();
    do
    {
        printf("\n*****menu*******\n");
        printf("1.Create file\n");
        // printf("2. delete File\n");
        printf("2. Show Free and Used Block list\n");
        printf("3. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            allocate();
            break;
        case 2:
            printf("\nThe free list is");
            printf("\nStartBlock\tSize\n");
            for (temp = head; temp != NULL; temp = temp->next)
            {
                printf("%d", temp->start);
                printf("\t%d\n", temp->size);
            }
            printf("The used list is");
            printf("\nFilename\tStart\tLength\n");
            for (i = 0; i < dir_index; i++)
            {
                printf("%s\t%d\t\t%d\n", dir_ent[i].fname, dir_ent[i].fstart, dir_ent[i].fsize);
            }
            break;
        case 3:
            exit(0);
            break;
        }
    } while (ch != 3);
}
create()
{
    int no_of_blocks;
    printf("Enter number of blocks\n");
    scanf("%d", &no_of_blocks);
    new = (struct freelist *)malloc(sizeof(struct freelist));
    head = new;
    new->start = 0;
    new->size = no_of_blocks;
    new->next = NULL;
}

allocate()
{
    int s, allocated = 0;
    char filename[10];
    printf("enter file name \n");
    scanf("%s", filename);
    printf("enter size of a file in blocks\n");
    scanf("%d", &s);
    for (temp = head; temp != NULL;)
    {
        if (temp->size < s)
            temp = temp->next;

        else
        {
            temp->size -= s;
            strcpy(dir_ent[dir_index].fname, filename);
            dir_ent[dir_index].fstart = temp->start;
            temp->start += s;
            dir_ent[dir_index].fsize = s;
            dir_index++;
            allocated = 1;
            break;
        }
        if (temp == NULL && allocated == 0)
            printf("Disk space not available\n");
    }
}
