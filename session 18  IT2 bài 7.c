#include <stdio.h>
#include <string.h>


struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void displayStudents(struct Student students[], int count) {
    printf("\nDanh sách sinh viên:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void deleteStudent(struct Student students[], int *count) {
    char nameToDelete[50];
    printf("\n nhap ten sinh vien can xoa : ");
    getchar(); 
    fgets(nameToDelete, sizeof(nameToDelete), stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = '\0';

    int found = 0; 

    for (int i = 0; i < *count; i++) {
        if (strcmp(students[i].name, nameToDelete) == 0) {
            found = 1;

            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;
            printf(" da xoa sinh vien : %s\n", nameToDelete);
            break;
        }
    }

    if (!found) {
        printf("khong tim thay sinh vien co ten : %s\n", nameToDelete);
    }
}

int main() {

    struct Student students[50] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van C", 22, "0912345678"},
        {4, "Pham Thi D", 23, "0909876543"},
        {5, "Hoang Van E", 24, "0934567890"}
    };

    int studentCount = 5;

    displayStudents(students, studentCount);

    deleteStudent(students, &studentCount);

    displayStudents(students, studentCount);

    return 0;
}

