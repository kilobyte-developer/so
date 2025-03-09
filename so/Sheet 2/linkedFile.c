#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct dir
{
    char fname[20];
    int start;
    struct dir *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, fb, bit[MAX];

void init()
{
    int i;
    printf("\nEnter total no. of disk blocks: ");
    scanf("%d", &n);

    fb = n;

    // Initialize bit array with 0
    for (i = 0; i < n; i++)
        bit[i] = 0;

    // Randomly mark 10 blocks as bad (-2)
    for (i = 0; i < 10;)
    {
        int k = rand() % n;
        if (bit[k] == 0)
        {
            bit[k] = -2; // Bad Block
            fb--;
            i++;
        }
    }
}

void show_bitvector()
{
    printf("\nBit Vector: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

void show_dir()
{
    NODE *p = first;
    printf("\nFile\tChain\n");
    while (p != NULL)
    {
        printf("%s\t", p->fname);
        int i = p->start;
        while (i != -1)
        {
            printf("%d -> ", i);
            i = bit[i];
        }
        printf("NULL\n");
        p = p->next;
    }
}

void create()
{
    char fname[20];
    int nob, i, j;

    printf("\nEnter file name: ");
    scanf("%s", fname);
    printf("Enter number of blocks: ");
    scanf("%d", &nob);

    if (nob > fb)
    {
        printf("Not enough free blocks!\n");
        return;
    }

    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->fname, fname);
    p->next = NULL;

    for (i = 0; i < n; i++)
    {
        if (bit[i] == 0)
        {
            p->start = i;
            break;
        }
    }

    fb -= nob;
    j = i + 1;
    nob--;

    while (nob > 0)
    {
        if (bit[j] == 0)
        {
            bit[i] = j;
            i = j;
            nob--;
        }
        j++;
    }
    bit[i] = -1;

    if (first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        last = p;
    }

    printf("File '%s' created successfully!\n", fname);
}

void deleteFile()
{
    char fname[20];
    printf("\nEnter file name to delete: ");
    scanf("%s", fname);

    NODE *p = first, *q = NULL;
    while (p != NULL && strcmp(p->fname, fname) != 0)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("File not found!\n");
        return;
    }

    int i = p->start, nob = 0;
    while (i != -1)
    {
        nob++;
        int temp = i;
        i = bit[i];
        bit[temp] = 0; // Mark Free
    }
    fb += nob;

    if (p == first)
        first = first->next;
    else if (p == last)
    {
        last = q;
        last->next = NULL;
    }
    else
        q->next = p->next;

    free(p);
    printf("File deleted successfully!\n");
}

int main()
{
    int ch;
    init();
    while (1)
    {
        printf("\n1. Show Bit Vector");
        printf("\n2. Create File");
        printf("\n3. Show Directory");
        printf("\n4. Delete File");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            show_bitvector();
            break;
        case 2:
            create();
            break;
        case 3:
            show_dir();
            break;
        case 4:
            deleteFile();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
