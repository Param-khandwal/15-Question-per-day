// WAP to use Switch find the area of traingle use formula(1/2*base*height) ,area of circle, area of square, and area of rectangle
#include <stdio.h>
int main()
{
    int Base, Height, Radius, Length, Breadth, Side, ch;
    float Are_Tri, Are_cir, Are_Rect, Are_Sq;

    printf("Enter the Choice which you want to Area\n 1.Area of Triangle\n  2.Area of Circle\n 3.Area of Recctgle\n 4.Area of Square\n");
    scanf("%d", &ch);

    switch (ch)
    {

    case 1:
        printf("Enter the Base and Height of Triangle \n ");
        scanf("%d %d", &Base, &Height);
        Are_Tri = (Base * Height) / 2;
        printf("The area of triangle is %f\n", Are_Tri);
        break;

    case 2:
        printf("Enter the Radius of Circle \n ");
        scanf("%d", &Radius);
        Are_cir = 3.14 * Radius * Radius;
        printf("The area of circle is %f", Are_cir);
        break;

    case 3:
        printf("Enter the Length and Breadth of Rectangle \n ");
        scanf("%d %d", &Length, &Breadth);
        Are_Rect = Length * Breadth;
        printf("Area of the rectangle is %f", Are_Rect);
        break;

    case 4:
        printf("Enter the side of a Square \n ");
        scanf("%d", &Side);
        Are_Sq = Side * Side;
        printf("%f", Are_Sq);
        break;

    default:
        printf("Please enter the  correct choice \n");
        break;
    }
    return 0;
}