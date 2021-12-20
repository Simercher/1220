#include <stdio.h>
#include <string.h>
// #include <Windows.h>
#define NUM 999

// char outbuf[1000];

struct Student
{
    char id[50];
    char name[50];
    int score1, score2, score3;
    double sum;
}student[NUM];


int main(void)
{
    char c;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %s %s %d %d %d", student[i].id, student[i].name, &student[i].score1, &student[i].score2, &student[i].score3);
    }

    printf("=====menu=====\nf:find specific student data\ns: show all student' data\nd: show the sorted student' data(high to low)\na: show the sorted student' data(low to high)\nb: show the average score value\nq: quit\n");
    printf("function choice: ");
    while(scanf(" %c", &c))
    {
        int FLAG = 0;
            switch (c)
        {
            case 'f':
            {
                char arr[999];
                int flag = 0;
                printf("Student' ID: ");
                scanf(" %s", arr);
                for(int i = 0; i < n; i++)
                {
                    if(strcmp(arr, student[i].id) == 0)
                    {
                        flag = 1;
                        printf("%s\t%6s  %3d\t%3d\t%3d\n", student[i].id, student[i].name, student[i].score1, student[i].score2, student[i].score3);
                    }
                }
                if(flag == 0)
                {
                    printf("No such student\n");
                }
            }
            break;
            case 's':
            {
                for(int i = 0; i < n; i++)
                {
                    printf("%s\t%6s  %3d\t%3d\t%3d\n", student[i].id, student[i].name, student[i].score1, student[i].score2, student[i].score3);
                }
            }
            break;
            case 'd':
            {
                int i, j;
                struct Student temp;
                // float sum[999];

                for(int i = 0; i < n; i++)
                {
                    student[i].sum = 0;
                    student[i].sum += student[i].score1;
                    student[i].sum += student[i].score2;
                    student[i].sum += student[i].score3;
                    student[i].sum /= 3;
                }
                
                // for(int i = 0; i < n; i++)
                // {
                //     printf("%f ", student[i].sum);
                // }
                // puts("");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (student[i].sum > student[j].sum)
                        {
                            temp = student[i];
                            student[i] = student[j];
                            student[j] = temp;
                        } 
                    }
                }

                for(int k = 0; k < n; k++)
                {
                    printf("%s\t%6s  %3d\t%3d\t%3d\n", student[k].id, student[k].name, student[k].score1, student[k].score2, student[k].score3);
                }
            }

            break;
            case 'a':
            {
                int i, j;
                struct Student temp;
                float sum[999];

                for(int i = 0; i < n; i++)
                {
                    student[i].sum = 0;
                    student[i].sum += student[i].score1;
                    student[i].sum += student[i].score2;
                    student[i].sum += student[i].score3;
                    student[i].sum /= 3;
                }
    
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (student[i].sum < student[j].sum)
                        {
                            temp = student[i];
                            student[i] = student[j];
                            student[j] = temp;
                        } 
                    }
                }

                for(int k = 0; k < n; k++)
                {
                    printf("%s\t%6s  %3d\t%3d\t%3d\n", student[k].id, student[k].name, student[k].score1, student[k].score2, student[k].score3);
                }
            }
                
            break;
            case 'b':
            {
                float sum[999];

                for(int i = 0; i < n; i++)
                {
                    sum[i] = 0;
                    sum[i] += student[i].score1 + student[i].score2 + student[i].score3;
                    sum[i] /= 3;
                }

                for(int j = 0; j < n; j++)
                {
                    printf("%f ", sum[j]);
                }
                puts("");

                for(int k = 0; k < n; k++)
                {
                    printf("%s\t%6s  %.2f\n", student[k].id, student[k].name, sum[k]);
                }
            }

            break;
            case 'q':
                FLAG = 1;
                break;
            
            default:
                printf("ERROR\n");
                break;
        }
        if(FLAG == 1)
        {
            break;
        }
        printf("\n\n=====menu=====\nf:find specific student data\ns: show all student' data\nd: show the sorted student' data(high to low)\na: show the sorted student' data(low to high)\nb: show the average score value\nq: quit\n");
        printf("function choice: ");
    }

    return 0;
}