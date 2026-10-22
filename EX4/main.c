#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 5, 7, 9};
    char arr3[] = {'A', 'B', 'C', 'D'};

    int read_arr1[5];
    int read_arr2[3];
    char read_arr3[4];

    fp = fopen("a.bin", "wb+");
    if (fp == NULL) {
        perror("無法開啟檔案");
        return 1;
    }

    fwrite(arr1, sizeof(int), 5, fp);
    fwrite(arr2, sizeof(int), 5, fp);
    fwrite(arr3, sizeof(char), 4, fp);

    fclose(fp);

    fp = fopen("a.bin", "rb+");
    if (fp == NULL) {
        perror("無法讀取檔案");
        return 1;
    }

    if (fread(read_arr1, sizeof(int), 5, fp) != 5 ||
        fread(read_arr2, sizeof(int), 5, fp) != 5 ||
        fread(read_arr3, sizeof(char), 4, fp) != 4) {
        printf("讀取檔案失敗！\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    // 5. 輸出讀取到的陣列
    printf("第一個陣列（int）：\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", read_arr1[i]);
    }

    printf("\n\n第二個陣列（float）：\n");
    for (int i = 0; i < 5; i++) {
        printf("%.d ", read_arr2[i]);
    }

    printf("\n\n第三個陣列（char）：\n");
    for (int i = 0; i < 4; i++) {
        printf("%c ", read_arr3[i]);
    }

    printf("\n");

    return 0;
}
