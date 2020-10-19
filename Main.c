/*
        Mini File Manager By Prathamesh Chavan
*/

#include"Header.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error : Invalid number of arguments\n");
        return -1;
    }

    char FMode[10] = {'\0'};

    int Choise = 1, iRet = 0, Mode = 0;

    while (Choise)
    {
        printf("Enter your choise : \n");
        printf("1. Create file\n");
        printf("2. Open File in selected mode\n");
        printf("3. Read data from file\n");
        printf("4. Write data into file\n");
        printf("5. Permanantly delete file\n");
        printf("0. Exit\n");

        scanf("%d", &Choise);

        switch (Choise)
        {
        case 1: //1. Create file
            CreateFile(argv[1]);
            break;

        case 2: //2. Open File in selected mode
            printf("Enter Mode in which you want to open file\n");
            scanf("%s", FMode);

            if (FMode == "read" || FMode == "Read")
            {
                Mode = O_RDONLY;
            }
            else if (FMode == "Write" || FMode == "write")
            {
                Mode = O_WRONLY;
            }
            else if (FMode == "RW" || FMode == "rw")
            {
                Mode = O_RDWR;
            }

            OpenFile(argv[1], Mode);
            break;

        case 3: //3. Read data from file
            ReadFile(argv[1]);
            break;

        case 4: //4. Write data into file
            WriteFile(argv[1]);
            break;

        case 5: //5. Permanantly delete file
            DeleteFile(argv[1]);
            break;

        case 0: //5. Exit
            printf("Thank you for using our application.\n");
            break;
        }
    }
    return 0;
}
