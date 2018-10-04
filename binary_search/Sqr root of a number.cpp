long long f(int x) {
    return (long long)x * x;
}

int square_root(int x) {
    int left = 0, right = x;
    while (left < right) {
        int mid = (left + right) / 2;
        if (f(mid) <= x) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}