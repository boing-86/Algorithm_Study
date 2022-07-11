#include <stdio.h>
#define MAX 1025

arr[MAX][MAX] = { 0, };

void main() {
	
	int n, m, num, x1, x2, y1, y2, ans;

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &num);
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
		}
	}

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	} 누적합 배열 확인*/

	while (m--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
		printf("%d\n", ans);
	}
}