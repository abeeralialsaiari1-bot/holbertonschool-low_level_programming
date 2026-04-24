#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
    unsigned int i, sum = 0;
    char *username;
    char lookup[] = "A-CHRDw87lNSMayT7Zgj049Vu6t1uOfmaS9ndS9pEwEpSj9NmS9n";
    /* تم استخراج المصفوفة والعملية الحسابية عبر تحليل ملف crackme5 */

    if (argc != 2)
        return (1);

    username = argv[1];
    for (i = 0; i < strlen(username); i++)
        sum += username[i];

    /* الخوارزمية التي يبحث عنها البرنامج هي (sum ^ 79) & 63 */
    printf("%c", lookup[(sum ^ 79) & 63]);
    return (0);
}
