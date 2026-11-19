#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM 1
#define MAX_NUM 69
#define PICK_COUNT 7
#define MAX_SETS 5

// 產生 7 個 1~69 不重複的亂數
void generate_lotto_set(int out[PICK_COUNT]) {
    int used[MAX_NUM + 1] = {0};
    int count = 0;

    while (count < PICK_COUNT) {
        int num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
        if (!used[num]) {
            used[num] = 1;
            out[count++] = num;
        }
    }
}

int main(void) {
    int n = 0;

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SETS) {
        printf("輸入無效，請輸入 1 到 5 之間的整數。\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        perror("無法建立 lotto.txt");
        return 1;
    }

    time_t now = time(NULL);
    char time_buf[64];
    snprintf(time_buf, sizeof(time_buf), "%s", ctime(&now));
    // 移除 ctime 字串結尾的換行符號 '\n'
    for (int i = 0; time_buf[i] != '\0'; i++) {
        if (time_buf[i] == '\n') {
            time_buf[i] = '\0';
            break;
        }
    }

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_buf);

    for (int set_idx = 1; set_idx <= MAX_SETS; set_idx++) {
        fprintf(fp, "[%d]: ", set_idx);
        if (set_idx <= n) {
            int nums[PICK_COUNT];
            generate_lotto_set(nums);
            for (int k = 0; k < PICK_COUNT; k++) {
                fprintf(fp, "%02d%s", nums[k], (k == PICK_COUNT - 1) ? "" : " ");
            }
        } else {
            for (int k = 0; k < PICK_COUNT; k++) {
                fprintf(fp, "--%s", (k == PICK_COUNT - 1) ? "" : " ");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
