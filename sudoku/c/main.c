#include <stdio.h>
#include <string.h>

int check_true(int table[9][9]) {
    int sumx = 0;
    int sumy = 0;
    for (int i = 0; i < 9; i++)
    {
        sumx = 0;
        sumy = 0;
        for (int j = 0; j < 9; j++)
        {
            sumx += table[i][j];
            sumy += table[j][i];
            printf("%d %d\n", i, j);
        }
        if (sumx != 45 || sumy != 45) {
            if (sumx != 45)
                printf("%d %d\n", sumx, sumy);        
            else printf("%d %d\n", sumy, sumx);
            return 0;
        }
    }
    return 1;
}

int print_table(int table[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int get_point(int table[9][9], int x, int y) {
    int point = 0;
    for(int i = 0; i < 9; i++) {
        if(i != y && table[x][i] != 0) point++;
        if(i != x &&table[i][y] != 0) point++;
        for(int j = 0; j < 9; j++) {
            if(table[i][j] != 0 && (table[i][j] == table[x][j] || table[i][j] == table[y][j])) point--;
        }
    }
    return point;
}

int check_point(int table[9][9], int x, int y, int value) {
    for(int i = 0; i < 9; i++) {
        if(table[x][i] == value) return 0;
        if(table[i][y] == value) return 0;
    }
    printf("check point: table[%d][%d] = %d\n", x, y, value);
    return 1;
}

int find_diff(int table[9][9], int x, int y) {
    int v = -1;
    int sumx = 0;
    int sumy = 0;
    int sam[2] = {-1, -1};
    for(int i = 1; i < 10; i++) {
        if(i - 1 != x)
        sumx += table[i - 1][y];
        if(i - 1 != y)
        sumy += table[x][i - 1];
        for(int j = 0; j < 9; j++) {
           if (check_point(table, x, j, i) == 1 && table[x][j] != i)
            {
                v = table[x][j];
                table[x][j] = i;
                return v;
            }
            if (check_point(table, j, y, i) == 1 && table[j][y] != i)
            {
                v = table[j][y];
                table[j][y] = i;
                return v;
            }
 
        }
    }
    print_table(table);
    int r = sumx - sumy;
    printf("r = %d\n", r);
    if (r < 0) r *= -1;
    for (int i = 0; i < 9; i++)
    {
        if (table[i][y] == r)
        {
            sam[0] = i;
            sam[1] = y;
            break;
        }
        if (table[x][i] == r)
        {
            sam[0] = x;
            sam[1] = i;
            break;
        }
    }
    printf("inf d %d %d\n", sam[0], sam[1]);
    return find_diff(table, sam[0], sam[1]);
}

int main()
{
    int table[9][9] = {
        {4, 3, 0, 8, 0, 0, 0, 2, 9},
        {0, 0, 2, 7, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 2, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 4, 5, 0, 2, 8, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 9, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 7, 6, 0, 0},
        {1, 9, 0, 0, 0, 5, 0, 7, 8},
    };
    int max[3] = {0, 0, 0};
    int tmp = 0;
    int sample = 0;

    for (int limit=0; limit < 100;limit++)
    {
        max[0] = -1;
        max[1] = -1;
        max[2] = -1;
         
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (table[i][j] == 0)
                {
                    tmp = get_point(table, i, j);
                    if (tmp >= max[0])
                    {
                        max[0] = tmp;
                        max[1] = i;
                        max[2] = j;
                    }
                }
            }
        }
        printf("max: table[%d][%d] = %d\n", max[1], max[2], max[0]);

        if(max[0] != -1)
            for (int i = 1; i < 11; i++)
            {
                printf("loop assign %d\n", i);
                if (i == 10)
                {
                    tmp = find_diff(table, max[1], max[2]);
                    if (tmp > 0)
                    {
                        printf("change diff [%d][%d] = %d\n", max[1], max[2], tmp);
                        table[max[1]][max[2]] = tmp;
                        break;
                    } else {
                        printf("change diff failed [%d][%d] = %d\n", max[1], max[2], tmp);
                        // table[max[1]][max[2]] = -1;
                        break;
                    }
                }
                sample = check_point(table, max[1], max[2], i);
                continue;
                if (sample == 1)
                {
                    table[max[1]][max[2]] = i;
                    printf("set table[%d][%d] = %d\n", max[1], max[2], i);
                    break;
                }
            }
        if (max[0] == -1)
            break;
    }
    print_table(table);
    printf("check true = %d\n ", check_true(table));
}

