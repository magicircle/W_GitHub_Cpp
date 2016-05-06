#include <stdio.h>
int get_gcd(int u, int v){
	int t;
	while (u > 0) {
		if (u < v) {
			t = u; u = v; v = t;
		}
		u = u - v;
	}
	return v;
}

int gcd_modulus(int u, int v){
	int t;
	while (v > 0) {
		t = u%v;
		u = v;
		v = t;
	}
	return u;
}

int gcd_recursion(int u, int v) {
	if (v == 0) {
		return u;
	}
	else {
		return gcd_recursion(v, u%v);
	}
}

void main(void)
{
	int u, v;
	int gcd;

	u = 220;
	v = 1200000;

	gcd = get_gcd(u, v);
	printf("%d  %d  GCD result = %d\n", u, v, gcd);

	gcd = gcd_modulus(u, v);
	printf("%d  %d  GCD result = %d\n", u, v, gcd);

	gcd = gcd_recursion(u, v);
	printf("%d  %d  GCD result = %d\n", u, v, gcd);

}