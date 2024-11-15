#include <stdio.h>
#include <string.h>
#define SIZE 10001

/*
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
*/

void input(char *strIn)
{
    FILE *in = fopen("input.txt", "r");
    if (in == NULL)
    {
        perror("Error opening input file");
        return;
    }
    fgets(strIn, SIZE, in);
    size_t len = strlen(strIn);
    if (len > 0 && strIn[len - 1] == '\n')
    {
        strIn[len - 1] = '\0'; // Убираем символ новой строки
    }
    fclose(in);
}

void extension(char *strExt, char *buffer)
{
    int has_extension = 0;
    for (int i = strlen(strExt) - 1; i >= 0; i--)
    {
        if (strExt[i] == '/')
        {
            break; // Нет расширения
        }
        else if (strExt[i] == '.')
        {
            memcpy(buffer, strExt, i); // Копируем строку до точки
            buffer[i] = '\0';          // Завершаем строку
            strcat(buffer, ".html");   // Добавляем ".html"
            has_extension = 1;
            break;
        }
    }
    if (!has_extension)
    {
        strcpy(buffer, strExt);
        strcat(buffer, ".html");
    }
}

void output(char *strOut)
{
    FILE *out = fopen("output3.txt", "w");
    if (out == NULL)
    {
        perror("Error opening output file");
        return;
    }
    fprintf(out, "%s", strOut);
    fclose(out);
}

int main()
{
    char str[SIZE], strFinal[SIZE];
    input(str);
    extension(str, strFinal);
    output(strFinal);
    return 0;
}
