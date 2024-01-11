#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int n, m;
int ans[MAX];

void func(int level, int num);

int main() {
	scanf("%d%d", &n, &m);
	func(0, 1);
}

void func(int level, int num) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}

	for (int i = num; i <= n; i++) {
		ans[level] = i;
		func(level + 1, i+1);
	}
}
