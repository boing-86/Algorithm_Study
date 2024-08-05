#include <stdio.h>
#define MAX 55


int main() {

	int m, n, min, ans = 99999999;
	char arr[MAX][MAX] = { 0, };

	scanf("%d%d", &m, &n);

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			scanf(" %c", &arr[x][y]);
		}
	}

	for (int a = 0; a <= m - 8; a++) {
		for (int b = 0; b <= n - 8; b++) {
			int num1 = 0, num2 = 0;
			//num1 : W홀수, B짝수
			//num2 : W짝수, B홀수
			for (int i = a; i < a + 8; i++) {
				for (int j = b; j < b + 8; j++) {
					if (arr[i][j] == 'W') {
						if ((i + j) % 2 == 0)
							num1++;
						else
							num2++;
					}
					
					else {
						if ((i + j) % 2 == 0)
							num2++;
						else
							num1++;
					}
				}
			}
			min = num1 < num2 ? num1 : num2;
			ans = ans < min ? ans : min;
		}
	}
	printf("%d", ans);
}