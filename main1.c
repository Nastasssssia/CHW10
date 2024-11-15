#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.

 */

#define MAX_LENGTH 1000

void swap_adjacent_pairs_preserve_spaces(const char *input_file, const char *output_file)
{
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (in == NULL || out == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[MAX_LENGTH];
    char result[MAX_LENGTH];
    int index = 0;
    int i = 0;

    if (fgets(line, MAX_LENGTH, in) != NULL)
    {
        int length = strlen(line);

        while (i < length)
        {
            if (line[i] != ' ' && i + 1 < length && line[i + 1] != ' ')
            {
                // Меняем местами два соседних символа
                result[index++] = line[i + 1];
                result[index++] = line[i];
                i += 2;
            }
            else
            {
                // Если пробел или нет пары, просто добавляем символ
                result[index++] = line[i];
                i++;
            }
        }

        result[index] = '\0';
    }

    fclose(in);

    fprintf(out, "%s", result);
    fclose(out);
}

int main()
{
    swap_adjacent_pairs_preserve_spaces("input.txt", "output1.txt");
    return 0;
}
