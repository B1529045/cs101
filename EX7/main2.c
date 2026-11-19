#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 128
#define BOOK_COUNT 6

typedef struct Books {
    int id;
    int price;
    char title[MAX_TITLE];
} book_t;

void list_books(book_t books[], int count) {
    printf("%-5s %-8s %s\n", "ID", "Price", "Title");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-8d %s\n", books[i].id, books[i].price, books[i].title);
    }
}

void total_price(book_t books[], int count) {
    long long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += books[i].price;
    }
    printf("------------------------------------------------------------\n");
    printf("Total Price: %lld\n", sum);
}

int main(void) {
    book_t books[BOOK_COUNT] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    // 將書籍資料寫入二進位檔 Book.bin
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        perror("Failed to open Book.bin for writing");
        return 1;
    }
    fwrite(books, sizeof(book_t), BOOK_COUNT, fp);
    fclose(fp);

    // 從 Book.bin 讀回資料（確保檔案內容正確）
    book_t loaded_books[BOOK_COUNT];
    FILE *rfp = fopen("Book.bin", "rb");
    if (rfp == NULL) {
        perror("Failed to open Book.bin for reading");
        return 1;
    }
    size_t read_count = fread(loaded_books, sizeof(book_t), BOOK_COUNT, rfp);
    fclose(rfp);

    // 輸出書籍資料與計算總價
    list_books(loaded_books, (int)read_count);
    total_price(loaded_books, (int)read_count);

    return 0;
}
