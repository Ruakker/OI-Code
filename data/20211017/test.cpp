void tarjan(int u) {
    low[u] = dfn[u] = ++timestamp;
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = to[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u]) cnt++;
        } else
            low[u] = min(low[u], dfn[j]);
    }
    if (u != root) cnt++;
    ans = max(ans, cnt);
}
