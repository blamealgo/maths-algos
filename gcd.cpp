/*
    gcd(2u, 2v)     = 2 * gcd(u, v)
    gcd(2u, 2v + 1) = gcd(u, 2v + 1)
    gcd(-u, v)      = gcd(u, v)
    gcd(u, v)       = gcd((u - v) / 2, v), при u > v и не кратных 2 
*/
int gcd(int u, int v){
    int t, diff;
    if (u == 0 || v == 0)
        return u | v;
    for (t = 0; ((u | v) & 1) == 0; ++t) {
        u >>= 1;
        v >>= 1;
    }
    while ((u & 1) == 0)
        u >>= 1;
    do {
        while ((v & 1) == 0)
            v >>= 1;
        if (u < v) {
            v -= u;
        } else {
            diff = u - v;
            u = v;
            v = diff;
        }
        v >>= 1;
     } while (v != 0);
     return u << t;
}
