#include <stdio.h>
#include <stdlib.h>


void search_rectangles(int **m, int R, int C, int index)
{
    int total = R * C;

    if (index >= total)
        return;


    if (index >= total) {
        search_rectangles(m, R, C, index + 1);
        return;
    }


    int r1 = index / C;
    int c1 = index % C;


    for (int j = index + 1; j < total; j++) {

        int r2 = j / C;
        int c2 = j % C;


        if (r1 < r2 && c1 < c2) {

            int v = m[r1][c1];

            if (m[r1][c2] == v &&
                m[r2][c1] == v &&
                m[r2][c2] == v) {

                printf(
                "Rectangle: (%d,%d) (%d,%d) value=%d\n",
                r1,c1,r2,c2,v);
            }
        }
    }


    search_rectangles(m, R, C, index + 1);
}


void valid_rectangle(int **m, int R, int C)
{
    if (m == NULL || R < 2 || C < 2)
        return;

    search_rectangles(m,R,C,0);
}
