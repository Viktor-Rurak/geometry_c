#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include "geometry.c"

void get_prism_volume() {
    double length, width, height;
    printf("Введіть довжину, ширину і висоту призми: ");
    scanf("%lf %lf %lf", &length, &width, &height);
    double volume = volume_prism(length, width, height);
    if (volume != -1) {
        printf("Об'єм прямокутний паралелепіпед: %.2f\n", volume);
    }
}

void get_pyramid_volume() {
    double base_area, height;
    int n;
    double length;
    while (1){
        printf("Введіть кількість сторін фігури яка знаходиться в основі піраміди\n");
        scanf("%d", &n);
        if (n < 3) {
            printf("Кількість сторін повинна бути не меншою за 3\n");
            continue;
        }
        printf("Введіть довжину сторони: ");
        scanf("%lf", &length);
        if (length > 0 && n > 0) {
            break;
        }
        printf("Невірні розміри для піраміди\n");
    }
    printf("Введіть висоту піраміди: ");
    scanf("%lf", &height);
    base_area = (n * pow(length, 2)) / (4 * tan(M_PI / n));
    double volume = volume_pyramid(base_area, height);
    if (volume != -1) {
        printf("Об'єм піраміди: %.2f\n", volume);
    }
}

void get_cylinder_volume() {
    double radius, height;
    printf("Введіть радіус основи і висоту циліндра: ");
    scanf("%lf %lf", &radius, &height);
    double volume = volume_cylinder(radius, height);
    if (volume != -1) {
        printf("Об'єм циліндра: %.2f\n", volume);
    }
}

void get_sphere_volume() {
    double radius;
    printf("Введіть радіус кулі: ");
    scanf("%lf", &radius);
    double volume = volume_sphere(radius);
    if (volume != -1) {
        printf("Об'єм кулі: %.2f\n", volume);
    }
}

void get_tore_volume() {
    double radius, Rradius;
    printf("Введіть внутрішній радіус тора: ");
    scanf("%lf", &radius);
    printf("Введіть зовнішній радіус тора: ");
    scanf("%lf", &Rradius);
    double volume = volume_tore(radius, Rradius);
    if (volume != -1) {
        printf("Об'єм тора: %.2f\n", volume);
    }
}

void get_cone_volume() {
    double radius, height;
    printf("Введіть радіус основи і висоту конуса: ");
    scanf("%lf %lf", &radius, &height);
    double volume = volume_cone(radius, height);
    if (volume != -1) {
        printf("Об'єм конуса: %.2f\n", volume);
    }
}
void get_cut_piramide() {
    double base_area1, base_area2, height;
    int n1, n2;
    double length1, length2;

    while (1){
        printf("Введіть кількість сторін нижньої основи зрізаної піраміди\n");
        scanf("%d", &n1);
        if (n1 < 3) {
            printf("Кількість сторін повинна бути не меншою за 3\n");
            continue;
        }
        printf("Введіть довжину сторони нижньої основи: ");
        scanf("%lf", &length1);
        if (length1 > 0 && n1 > 0) {
            break;
        }
        printf("Невірні розміри для зрізаної піраміди\n");
    }

    while (1){
        printf("Введіть кількість сторін верхньої основи зрізаної піраміди\n");
        scanf("%d", &n2);
        if (n2 < 3) {
            printf("Кількість сторін повинна бути не меншою за 3\n");
            continue;
        }
        printf("Введіть довжину сторони верхньої основи: ");
        scanf("%lf", &length2);
        if (length2 > 0 && n2 > 0) {
            break;
        }
        printf("Невірні розміри для зрізаної піраміди\n");
    }

    printf("Введіть висоту зрізаної піраміди: ");
    scanf("%lf", &height);

    base_area1 = (n1 * pow(length1, 2)) / (4 * tan(M_PI / n1));
    base_area2 = (n2 * pow(length2, 2)) / (4 * tan(M_PI / n2));

    double volume = volume_cut_piramide(base_area1, base_area2, height);
    if (volume != -1) {
        printf("Об'єм зрізаної піраміди: %.2f\n", volume);
    }
}


int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    SetConsoleCP(65001); // встановлення кодування UTF-8 в потік введення
    SetConsoleOutputCP(65001); // встановлення кодування UTF-8 в потік виведення

    int choice;
    while (1) {
        printf("\nОберіть фігуру для обчислення об'єму:\n");
        printf("1. Прямокутна призма\n");
        printf("2. Піраміда\n");
        printf("3. Циліндр\n");
        printf("4. Куля\n");
        printf("5. Тор\n");
        printf("6. Конус\n");
        printf("7. Зрізана піраміда\n");
        printf("8. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_prism_volume();
                break;
            case 2:
                get_pyramid_volume();
                break;
            case 3:
                get_cylinder_volume();
                break;
            case 4:
                get_sphere_volume();
                break;
            case 5:
                get_tore_volume();
                break;
            case 6:
                get_cone_volume();
                break;
            case 7:
                get_cut_piramide();
            case 8:
                return 0; // Вихід з програми
            default:
                printf("Невірний вибір.\n");
        }
    }
    return 0;
}
