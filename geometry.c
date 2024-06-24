#include <stdio.h>
#include <math.h>

// Прямокутна призма
double volume_prism(double length, double width, double height) {
    if (length <= 0 || width <= 0 || height <= 0) {
        printf("Невірні розміри для призми\n");
        return -1;
    }
    return length * width * height;
}

// Піраміда
double volume_pyramid(double base_area, double height) {
    if (height <= 0) {
        printf("Невірні розміри для піраміди\n");
        return -1;
    }
    return (base_area * height) / 3;
}

// Циліндр
double volume_cylinder(double radius, double height) {
    if (radius <= 0 || height <= 0) {
        printf("Невірні розміри для циліндра\n");
        return -1;
    }
    return M_PI * radius * radius * height;
}

// Куля
double volume_sphere(double radius) {
    if (radius <= 0) {
        printf("Невірний радіус для кулі\n");
        return -1;
    }
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

// Тор
double volume_tore(double radius, double Rradius) {
    if (radius <= 0 || Rradius <= radius) {
        printf("Невірно введені розміри тора\n");
        return -1;
    }
    return 2 * pow(M_PI, 2) * Rradius * pow(radius, 2);
}

// Конус
double volume_cone(double radius, double height) {
    if (radius <= 0 || height <= 0) {
        printf("Невірні розміри для конуса\n");
        return -1;
    }
    return (M_PI * pow(radius, 2) * height) / 3;
}
//Зрізана піраміда
double volume_cut_piramide(double base_area1, double base_area2, double height) {
    if (base_area1 <= 0 || base_area2 <= 0 || height <= 0) {
        printf("Невірні розміри для зрізаної піраміди\n");
        return -1;
    }
    return (height / 3) * (base_area1 + base_area2 + sqrt(base_area1 * base_area2));
}