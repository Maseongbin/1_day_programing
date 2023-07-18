#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define RAD2DEG(x) x * 180 / M_PI
#define DEG2RAD(x) x / 180 * M_PI

typedef struct
{
    double x;
    double y;
    double theta;
} Pose2D; 

typedef struct
{
    double x;
    double y;
} Point2D; 

double angle_degree;
double angle_radian;

Pose2D base_link_origin;
Point2D base_link_Point2D, base_link_map_Point2D;

double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

void set_rotation_matrix_inverse(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);

    Rotation_matrix_inverse[0][0] = cos(angle_radian);   Rotation_matrix_inverse[0][1] = sin(angle_radian);
    Rotation_matrix_inverse[1][0] = -sin(angle_radian);   Rotation_matrix_inverse[1][1] = cos(angle_radian);
}


void set_rotation_matrix(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);

    Rotation_matrix[0][0] = cos(angle_radian);   Rotation_matrix[0][1] = -sin(angle_radian);
    Rotation_matrix[1][0] = sin(angle_radian);   Rotation_matrix[1][1] = cos(angle_radian);
}

/*
void TF_base_link_base_link_map(Point2D base_link_Point2D, Point2D* base_link_map_Point2D, Pose2D base_link_origin)
{
    double x_diff = base_link_Point2D.x - base_link_origin.x;
    double y_diff = base_link_Point2D.y - base_link_origin.y;
    base_link_map_Point2D->x = Rotation_matrix[0][0] * x_diff + Rotation_matrix[0][1] * y_diff;
    base_link_map_Point2D->y = Rotation_matrix[1][0] * x_diff + Rotation_matrix[1][1] * y_diff;
}
*/

void TF_base_link_base_link_map()
{
    printf("\n\n");
    printf("%6.3lf  %6.3lf\n", base_link_Point2D.x, base_link_Point2D.y);
    printf("%6.3lf  %6.3lf\n", base_link_map_Point2D.x, base_link_map_Point2D.y);
    printf("%6.3lf  %6.3lf  %6.3lf\n", base_link_origin, base_link_origin.y, base_link_origin.theta);
}


int main()
{
    base_link_origin.x = 1.0;
    base_link_origin.y = 2.0;
    base_link_origin.theta = 90;

    base_link_Point2D.x = 1;
    base_link_Point2D.y = 1;

    base_link_map_Point2D.x = 0.1;
    base_link_map_Point2D.y = 0.1;

    set_rotation_matrix(base_link_origin.theta);

    printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
    printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);

    TF_base_link_base_link_map();

    //printf("%6.3lf  %6.3lf\n", base_link_Point2D.x, base_link_Point2D.y);
    //printf("%6.3lf  %6.3lf\n", base_link_map_Point2D.x, base_link_map_Point2D.y);
    //printf("%6.3lf  %6.3lf  %6.3lf\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);

    return 0;
}