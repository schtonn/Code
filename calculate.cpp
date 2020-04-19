#include "iostream"
using namespace std;
#define N 1010
#define lson id << 1
#define rson id << 1 | 1
#define mod 10301
int a[N], b[N], n, m, op, x, y, k;
int base1[3][3] = {
	{1, 1, 2},
	{0, 1, 0},
	{0, 1, 1}};
int base2[3][3] = {
	{1, 0, 0},
	{1, 1, 2},
	{1, 0, 1}};
struct matrix
{
	int v[3][3];
	int x, y;
} c1, c2;
struct node
{
	int l, r;
	matrix sum, lazy;
} t[4 * N];
ostream &operator<<(ostream &ous, matrix a)
{
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			ous << a.v[i][j] << ' ';
		}
		ous << endl;
	}
	return ous;
}
bool check(matrix a)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i == j && a.v[i][j] != 1) || (i != j && a.v[i][j] != 0))
				return 1;
		}
	}
	return 0;
}
void clear(matrix &a)
{
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			if (i == j)
				a.v[i][j] = 1;
			else
				a.v[i][j] = 0;
		}
	}
}
matrix operator+(matrix a, matrix b)
{
	matrix c;
	if (a.x != b.x || a.y != b.y)
		return c;
	int x = a.x, y = a.y;
	c.x = x;
	c.y = y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			c.v[i][j] = (a.v[i][j] + b.v[i][j]) % mod;
		}
	}
	return c;
}
matrix operator*(matrix a, matrix b)
{
	matrix c;
	if (a.y != b.x)
		return c;
	int x = a.x, y = b.y, z = a.y;
	c.x = x;
	c.y = y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			c.v[i][j] = 0;
			for (int k = 0; k < z; k++)
			{
				c.v[i][j] = (c.v[i][j] + a.v[i][k] * b.v[k][j] + mod) % mod;
			}
		}
	}
	return c;
}
matrix &operator*=(matrix &a, matrix n)
{
	a = a * n;
	return a;
}
void update(int id)
{
	t[id].sum = (t[lson].lazy * t[lson].sum) + (t[rson].lazy * t[rson].sum);
}
void pushdown(int id)
{
	if (check(t[id].lazy))
	{
		t[lson].lazy = t[id].lazy * t[lson].lazy;
		t[rson].lazy = t[id].lazy * t[rson].lazy;
		t[id].sum = t[id].lazy * t[id].sum;
		clear(t[id].lazy);
	}
}
void buildtree(int id, int l, int r)
{
	t[id].l = l;
	t[id].r = r;
	t[id].lazy.x = t[id].lazy.y = 3;
	clear(t[id].lazy);
	t[id].sum.x = 3;
	t[id].sum.y = 1;
	if (l == r)
	{
		t[id].sum.v[0][0] = (a[l] * a[l]) % mod;
		t[id].sum.v[1][0] = (b[l] * b[l]) % mod;
		t[id].sum.v[2][0] = (a[l] * b[l]) % mod;
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(lson, l, mid);
	buildtree(rson, mid + 1, r);
	update(id);
}
void change1(int id, int l, int r)
{
	if (t[id].l >= l && t[id].r <= r)
	{
		t[id].lazy = c1 * t[id].lazy;
		return;
	}
	pushdown(id);
	if (t[lson].r >= r)
		change1(lson, l, r);
	else if (t[rson].l <= l)
		change1(rson, l, r);
	else
	{
		change1(lson, l, t[lson].r);
		change1(rson, t[rson].l, r);
	}
	update(id);
}
void change2(int id, int l, int r)
{
	if (t[id].l >= l && t[id].r <= r)
	{
		t[id].lazy = c2 * t[id].lazy;
		return;
	}
	pushdown(id);
	if (t[lson].r >= r)
		change2(lson, l, r);
	else if (t[rson].l <= l)
		change2(rson, l, r);
	else
	{
		change2(lson, l, t[lson].r);
		change2(rson, t[rson].l, r);
	}
	update(id);
}
matrix query(int id, int l, int r)
{
	if (t[id].l >= l && t[id].r <= r)
	{
		return t[id].lazy * t[id].sum;
	}
	pushdown(id);
	if (t[lson].r >= r)
		return query(lson, l, r);
	else if (t[rson].l <= l)
		return query(rson, l, r);
	else
	{
		return (query(lson, l, t[lson].r)) + (query(rson, t[rson].l, r));
	}
}
void init()
{
	for (int i = 0; i < c1.x; i++)
	{
		for (int j = 0; j < c1.y; j++)
		{
			c1.v[i][j] = base1[i][j];
		}
	}
	for (int i = 0; i < c2.x; i++)
	{
		for (int j = 0; j < c2.y; j++)
		{
			c2.v[i][j] = base2[i][j];
		}
	}
}
int main()
{
	freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);
	c1.x = c1.y = c2.x = c2.y = 3;
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		a[i] %= mod;
		b[i] %= mod;
	}
	buildtree(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		cin >> op >> x >> y;
		if (op == 1)
			change1(1, x, y);
		else if (op == 2)
			change2(1, x, y);
		else
			cout << query(1, x, y).v[2][0] % mod << endl;
	}
	return 0;
}
