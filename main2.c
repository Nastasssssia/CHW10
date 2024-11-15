#include <stdio.h>
#include <string.h>

/*
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
 */

#define MAX_LENGTH 1000

void remove_extra_spaces(const char *input_file, const char *output_file)
{
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (in == NULL || out == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[MAX_LENGTH];
    char cleaned_line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, in) != NULL)
    {
        int i = 0, j = 0;

        while (line[i] == ' ')
        {
            i++;
        }

        while (line[i] != '\0')
        {
            if (line[i] == ' ' && line[i + 1] == ' ')
            {
                i++;
            }
            else
            {
                cleaned_line[j++] = line[i++];
            }
        }

        // Убедимся, что строка заканчивается символом конца строки
        if (j > 0 && cleaned_line[j - 1] == '\n')
        {
            cleaned_line[j - 1] = '\0'; // Убираем \n, чтобы не добавлять лишнюю строку
        }
        else
        {
            cleaned_line[j] = '\0';
        }

        fprintf(out, "%s\n", cleaned_line);
    }

    fclose(in);
    fclose(out);
}

int main()
{
    remove_extra_spaces("input.txt", "output2.txt");
    return 0;
}
