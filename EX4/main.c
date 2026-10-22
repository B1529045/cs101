#include <stdio.h>

int main(void)
{
    FILE *fp;

    int arr1[] = {0, 1, 2};
    char arr2[] = {'A', 'B', 'C'};
    float arr3[] = {1.1f, 1.2f, 1.3f};

    int read_arr1[3];
    char read_arr2[3];
    float read_arr3[3];

    fp = fopen("a.bin", "wb");

    if (fp == NULL) {
        perror("無法開啟檔案");
        return 1;
    }

    fwrite(arr1, sizeof(int), 3, fp);
    fwrite(arr2, sizeof(char), 3, fp);
    fwrite(arr3, sizeof(float), 3, fp);

    fclose(fp);

    fp = fopen("a.bin", "rb");

    if (fp == NULL) {
        perror("無法讀取檔案");
        return 1;
    }

    if (fread(read_arr1, sizeof(int), 3, fp) != 3 ||
        fread(read_arr2, sizeof(char), 3, fp) != 3 ||
        fread(read_arr3, sizeof(float), 3, fp) != 3) {
        printf("讀取檔案失敗！\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);


    for (int i = 0; i < 3; i++) {
        printf("%d ", read_arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%c ", read_arr2[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%f ", read_arr3[i]);
    }
    printf("\n");

        return 0;
}