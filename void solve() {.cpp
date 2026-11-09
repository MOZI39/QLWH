void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    std::map<int, int> cnt, c;
    for (int i = 1; i <= n; i++) std::cin >> a[i], cnt[a[i]] ++;
	
    for (auto [x, y] : cnt) if (y % k) {
        std::cout << "0\n";
        return ;
    }

    c[a[1]] ++;
    i64 ans = 0;
    for (int l = 1, r = 1; l <= n; l ++) {
        while (r + 1 <= n && c[a[r + 1]] + 1 <= cnt[a[r + 1]] / k) {
            r ++;
            c[a[r]] ++;
        }

        ans += r - l + 1;
        c[a[l]] --;
    }
    std::cout << ans << '\n';
}