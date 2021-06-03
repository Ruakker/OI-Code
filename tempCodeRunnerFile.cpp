void tarjan(int u, int rt) {
// 	p[u].dfn = p[u].low = ++totp;
// 	int child = 0;
// 	for (int v : e[u]) {
// 		if (p[v].dfn) {
// 			upd(p[u].low, p[v].dfn);
// 			continue;
// 		}
// 		tarjan(v, u);
// 		upd(p[u].low, p[v].low);
// 		if (p[v].low >= p[u].dfn && u != rt)
// 			iscut[u] = 1;
// 		if (u == rt)
// 			child++;
// 	}
// 	if (child >= 2 && u == rt)
// 		iscut[u] = 1;
// }