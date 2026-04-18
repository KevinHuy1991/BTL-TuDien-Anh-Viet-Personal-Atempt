#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tudien.h"

// 1. Hàm ti?n ích: Xóa phím Enter (kí t? \n) b? th?a khi dùng fgets
void xoaXuongDong(char* str) {
    str[strcspn(str, "\n")] = 0;
}

// 2. Hàm ti?n ích: D?n rác b? nh? d?m (ch?ng trôi l?nh khi nh?p s? xong chuy?n sang nh?p ch?)
void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 3. Hàm thêm t? m?i
void themTu(Node** head, char* tuAnh, char* nghiaViet) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, tuAnh);
    strcpy(newNode->meaning, nghiaViet);
    
    // Thêm vào d?u danh sách
    newNode->next = *head;
    *head = newNode;
}

// 4. Hàm hi?n th?
void inTuDien(Node* head) {
    if (head == NULL) {
        printf("Tu dien dang trong!\n");
        return;
    }
    Node* temp = head;
    printf("\n%-20s | %s\n", "TU TIENG ANH", "NGHIA TIENG VIET");
    printf("--------------------------------------------------\n");
    while (temp != NULL) {
        printf("%-20s | %s\n", temp->word, temp->meaning);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}

// 5. Hàm tìm ki?m
void timKiemTu(Node* head, char* tuAnh) {
    Node* temp = head;
    while (temp != NULL) {
        // Hàm strcasecmp giúp so sánh không phân bi?t hoa thu?ng (Apple = apple)
        if (strcasecmp(temp->word, tuAnh) == 0) {
            printf("=> Ket qua: %s nghia la '%s'\n", temp->word, temp->meaning);
            return;
        }
        temp = temp->next;
    }
    printf("=> Khong tim thay tu '%s' trong tu dien.\n", tuAnh);
}

// 6. Hàm Ð?c d? li?u t? File (B?n nâng c?p T? d?ng sinh thu vi?n)
void docTuDienTuFile(Node** head, const char* tenFile) {
    FILE* f = fopen(tenFile, "r");
    
    // N?u chua có file, t? d?ng t?o file và n?p t? v?ng m?c d?nh
    if (f == NULL) {
        printf("=> Lan chay dau tien: Dang tao thu vien mac dinh...\n");
        f = fopen(tenFile, "w");
        if (f != NULL) {
            fprintf(f, "Hello|Xin chao\n");
            fprintf(f, "Apple|Qua tao\n");
            fprintf(f, "Banana|Qua chuoi\n");
            fprintf(f, "Computer|May tinh\n");
            fprintf(f, "Software|Phan mem\n");
            fprintf(f, "Student|Sinh vien\n");
            fprintf(f, "Teacher|Giao vien\n");
            fprintf(f, "University|Truong dai hoc\n");
            fprintf(f, "Programming|Lap trinh\n");
            fprintf(f, "Algorithm|Thuat toan\n");
            fprintf(f, "Data Structure|Cau truc du lieu\n");
            fprintf(f, "Dictionary|Tu dien\n");
            fprintf(f, "Love|Tinh yeu\n");
            fprintf(f, "Family|Gia dinh\n");
            fprintf(f, "Money|Tien bac\n");
            fclose(f);
        }
        // M? l?i file d? d?c sau khi dã t?o xong
        f = fopen(tenFile, "r");
    }
    
    char dong[300];
    // Ð?c t?ng dòng trong file và n?p vào danh sách liên k?t
    while (fgets(dong, sizeof(dong), f)) {
        xoaXuongDong(dong);
        // C?t chu?i b?i d?u g?ch d?ng '|'
        char* tuAnh = strtok(dong, "|");
        char* nghiaViet = strtok(NULL, "|");
        
        if (tuAnh != NULL && nghiaViet != NULL) {
            themTu(head, tuAnh, nghiaViet);
        }
    }
    fclose(f);
    printf("=> Da tai thanh cong thu vien tu vung!\n");
}

// 7. Hàm Ghi d? li?u ra File
void ghiTuDienRaFile(Node* head, const char* tenFile) {
    FILE* f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Loi: Khong the luu file!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        // Luu theo d?nh d?ng: TuTiengAnh|NghiaTiengViet
        fprintf(f, "%s|%s\n", temp->word, temp->meaning);
        temp = temp->next;
    }
    fclose(f);
    printf("Da luu toan bo du lieu vao '%s'.\n", tenFile);
}

// 8. Hàm gi?i phóng b? nh? (Quy t?c b?t bu?c c?a môn h?c)
void giaiPhongBoNho(Node** head) {
    Node* temp = *head;
    Node* next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
