#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define RAD2DEG(x)   x*180/M_PI
#define DEG2RAD(x)   x/180*M_PI

typedef struct
{
    double x; // point_x

    double y; // point_y

    double yaw; // ȸ�� ����

} Pose2D;

typedef struct
{
    double x;

    double y;

} Point2D;

typedef struct
{
    double x;

    double y;

    double z;

} Point3D;

Pose2D    base_link_origin;   // base_link�� ���� pose2D
Pose2D    utm_link_origin;   // utm_link�� ���� pose2D

Point2D    waypoint_utm[15];
Point2D    waypoint_utm_relative[15];    // ��� ��ǥ
Point2D    waypoint_map_relative[15];   // ��� ��ǥ
Point2D    waypoint_utm_datum;          // utm ���� ��ǥ

Point2D    base_link_Point2D, base_link_map_Point2D;

double waypoint_angle_utm[15] = { 0.0 };
double waypoint_angle_map[15] = { 0.0 };

double angle_degree;
double angle_radian;

double Rotation_matrix_point[2][2];     // ����     ȸ���ϴ� ȸ�� ���
double Rotation_matrix_axis[2][2];      // ��ǥ���� ȸ���ϴ� ȸ�� ���

int initialize_waypoint(void)  // waypoint�� �ʱ�ȭ �ϱ� ���� �Լ�
{
    waypoint_utm[0] = { 403165.834539,  4129142.66722 };
    waypoint_utm[1] = { 403163.074411,  4129144.66310 };
    waypoint_utm[2] = { 403168.006126,  4129155.70202 };
    waypoint_utm[3] = { 403171.552590,  4129159.62227 };
    waypoint_utm[4] = { 403175.499272,  4129163.65995 };
    waypoint_utm[5] = { 403188.494255,  4129175.23815 };
    waypoint_utm[6] = { 403192.579036,  4129177.42123 };
    waypoint_utm[7] = { 403195.456870,  4129178.70838 };
    waypoint_utm[8] = { 403196.654117,  4129182.60031 };
    waypoint_utm[9] = { 403188.253848,  4129179.74587 };
    waypoint_utm[10] = { 403183.344647,  4129175.25328 };
    waypoint_utm[11] = { 403178.839622,  4129171.98767 };
    waypoint_utm[12] = { 403174.786097,  4129167.14121 };
    waypoint_utm[13] = { 403172.102604,  4129165.03072 };
    waypoint_utm[14] = { 403167.683418,  4129166.12481 };

    waypoint_utm_datum = waypoint_utm[0];

    for (int i = 0; i < 15; i++)
    {
        waypoint_utm_relative[i].x = waypoint_utm[i].x - waypoint_utm_datum.x;
        waypoint_utm_relative[i].y = waypoint_utm[i].y - waypoint_utm_datum.y;
        printf("utm : %2d   X : %6.2lf   Y : %6.2lf \n", i, waypoint_utm[i].x, waypoint_utm[i].y);
    }

    printf("\n\n\n");

    for (int i = 0; i < 15; i++)
    {
        printf("utm(r) : %2d   X : %6.2lf   Y : %6.2lf \n", i, waypoint_utm_relative[i].x, waypoint_utm_relative[i].y);
    }

    utm_link_origin.x = 0.0;   utm_link_origin.y = 0.0;   utm_link_origin.yaw = -90.0;

    return 1;
}

void set_rotation_matrix_axis(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);

    Rotation_matrix_axis[0][0] = cos(angle_radian);   Rotation_matrix_axis[0][1] = sin(angle_radian);
    Rotation_matrix_axis[1][0] = -sin(angle_radian);    Rotation_matrix_axis[1][1] = cos(angle_radian);
}

void set_rotation_matrix_point(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);

    Rotation_matrix_point[0][0] = cos(angle_radian);   Rotation_matrix_point[0][1] = -sin(angle_radian);
    Rotation_matrix_point[1][0] = sin(angle_radian);    Rotation_matrix_point[1][1] = cos(angle_radian);
}

void TF_utm_map(Point2D utm_point2d, Point2D* map_point2d, Pose2D utm_origin)
{
    // ���� ��ȯ utm ��ǥ�� 90���� �ð�������� ȸ���ϸ� map ��ǥ�� ��

    set_rotation_matrix_axis(-utm_origin.yaw); // ���� ��ȯ utm ��ǥ�� 90���� �ð�������� ȸ���ϸ� map ��ǥ�� ��
    map_point2d->x = utm_point2d.x * Rotation_matrix_axis[0][0] + utm_point2d.y * Rotation_matrix_axis[0][1];
    map_point2d->y = utm_point2d.x * Rotation_matrix_axis[1][0] + utm_point2d.y * Rotation_matrix_axis[1][1];

    printf("utm[%6.2lf, %6.3lf] ----> map[%6.3lf, %6.3lf]\n", utm_point2d.x, utm_point2d.x, map_point2d->x, map_point2d->y);
}

void calculate_waypoint_angle_utm(void)
{
    for (int i = 1; i < 15; i++)
    {
        double d_x, d_y, angle;

        d_x = waypoint_utm_relative[i].x - waypoint_utm_relative[i - 1].x;
        d_y = waypoint_utm_relative[i].y - waypoint_utm_relative[i - 1].y;

        angle = atan2(d_y, d_x);
        printf("wp[%2d]   line angle[utm] %6.3lf\n", i, RAD2DEG(angle));
    }
}

void calculate_waypoint_angle_map(void)
{
    for (int i = 1; i < 15; i++)
    {
        double d_x, d_y, angle;

        d_x = waypoint_map_relative[i].x - waypoint_map_relative[i - 1].x;
        d_y = waypoint_map_relative[i].y - waypoint_map_relative[i - 1].y;

        angle = atan2(d_y, d_x);
        printf("wp[%2d]   line angle[map] %6.3lf\n", i, RAD2DEG(angle));
    }
}

int main(void)
{
    initialize_waypoint();
    for (int i = 0; i < 15; i++)
    {
        TF_utm_map(waypoint_utm_relative[i], &waypoint_map_relative[i], utm_link_origin);
    }

    calculate_waypoint_angle_utm();
    calculate_waypoint_angle_map();

    return 0;
}