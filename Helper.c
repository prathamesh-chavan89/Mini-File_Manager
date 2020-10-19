
#include"Header.h"

int CreateFile(char *FName)
{
    int fd = 0;

    fd = creat(FName, 0777);

    if (fd == -1)
    {
        printf("Error : Unable to create file or file already exist\n");
    }
    else
    {
        printf("File is sucessfully created with FD = %d\n", fd);
    }
    return fd;
}

int OpenFile(char *FName, int OMode)
{
    int fd = 0;

    fd = open(FName, OMode);

    if (fd == -1)
    {
        printf("Error : Unable to open file or file not exist\n");
        return -1;
    }
    else
    {
        printf("File is sucessfully opened with FD = %d\n", fd);
    }

    return fd;
}

void ReadFile(char *FName)
{
    int RChoise = 0, Bytes = 0, iRead = 0;
    int Ofd = 0, i = 0;
    char *Buff = NULL;

    Ofd = open(FName, O_RDONLY);

    printf("Select 1 option from below\n");
    printf("\t1. Read specific no of bytes from file\n");
    printf("\t2. Read whole file\n");
    printf("\t0. Exit to Main menu\n");
    scanf("%d", &RChoise);

    switch (RChoise)
    {
    case 1:
        printf("Enter Number of bytes to read\n");
        scanf("%d", &Bytes);

        Buff = (char *)malloc(Bytes);

        iRead = read(Ofd, Buff, Bytes);

        if (iRead == -1)
        {
            printf("Error : Unable to read data from file\n");
            free(Buff);
        }
        else if (iRead == 0)
        {
            printf("File is empty\n");
            free(Buff);
        }
        else
        {
            printf("Data read from file is :\n");
            printf("%s", Buff);
            printf("\n");
        }
        break;

    case 2:
        Buff = (char *)malloc(sizeof(char) * 256);
        printf("Data from file is :\n");
        while ((iRead = read(Ofd, Buff, sizeof(Buff))) != 0)
        {
            write(1, Buff, iRead);
        }
        free(Buff);
        break;
    } // End of switch case
    close(Ofd);
} // End of Function

void WriteFile(char *FName)
{
    int RChoise = 0, iWrite = 0, iPos = 0;
    int Ofd = 0;
    char Buff[256] = {'\0'};

    printf("Select 1 option from below\n");
    printf("\t1. write data into file from starting\n");
    printf("\t2. write data into file from starting and clear old data\n");
    printf("\t3. write data at end of file\n");
    printf("\t4. write data from specific position of file\n");
    printf("\t0. Exit to Main menu\n");
    scanf("%d", &RChoise);

    switch (RChoise)
    {
    case 1: //1. write data into file from starting

        Ofd = open(FName, O_WRONLY);

        printf("Enter data to write into file\n");
        scanf(" %[^'\n']s", Buff);

        iWrite = write(Ofd, Buff, strlen(Buff));

        if (iWrite == -1)
        {
            printf("Error : Unable to write data to file\n");
        }
        else
        {
            printf("Data has been sucessfully written into file\n");
        }
        break;

    case 2: //2. write data into file from starting and clear old data

        Ofd = open(FName, O_WRONLY | O_TRUNC);

        printf("Enter data to write into file\n");
        scanf(" %[^'\n']s", Buff);

        iWrite = write(Ofd, Buff, strlen(Buff));

        if (iWrite == -1)
        {
            printf("Error : Unable to write data to file\n");
        }
        else
        {
            printf("Data has been sucessfully written into file\n");
        }
        break;

    case 3: //3. write data at end of file

        Ofd = open(FName, O_WRONLY | O_APPEND);

        printf("Enter data to write into file\n");
        scanf(" %[^'\n']s", Buff);

        iWrite = write(Ofd, Buff, strlen(Buff));

        if (iWrite == -1)
        {
            printf("Error : Unable to write data to file\n");
        }
        else
        {
            printf("Data has been sucessfully written into file\n");
        }
        break;

    case 4: //4. write data from specific position of file\
        printf("Enter Position to write data from that position\n");
        scanf("%d", &iPos);

        Ofd = open(FName, O_WRONLY);
        lseek(Ofd, iPos, SEEK_SET);

        printf("Enter data to write into file\n");
        scanf(" %[^'\n']s", Buff);

        iWrite = write(Ofd, Buff, strlen(Buff));
        if(iWrite == -1)
        {
            printf("Error : Unable to write data to file\n");
        }
        else
        {
            printf("Data has been sucessfully written into file\n");
        }
        break;
    } // End of switch case
} // End of Function

void DeleteFile(char *FName)
{
    char Ch = '\0';

    printf("Are you sure you want to permanently delete '%s' ?\n", FName);
    printf("Enter choise y/n\n");
    scanf(" %c", &Ch);
    if (Ch == 'y' || Ch == 'Y')
    {
        unlink(FName);
        printf("File permanently deleted\n");
    }
    else
    {
        printf("File not deleted\n");
    }
}
