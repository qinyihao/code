#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define inv cout << "Invalid command" << endl
template <class T>
struct vec
{
    vector<T> a;
    int cnt;
    vec()
    {
        cnt = 0;
    }
    void clear()
    {
        cnt = 0, a.clear();
    }
    int size()
    {
        return cnt;
    }
    bool empty()
    {
        return cnt == 0;
    }
    void pub(T x)
    {
        a.push_back(x), cnt++;
    }
    T &operator[](int x)
    {
        return a[x - 1];
    }
    int find(T x)
    {
        for (int i = 0; i < cnt; i++)
            if (a[i] == x)
                return i + 1;

        return -1;
    }
};
int n = 10, m = 9, gameover = 0, turn = 1;
struct dot
{
    int x, y;
    dot(int x, int y) : x(x), y(y) {}
    bool operator==(dot b)
    {
        return x == b.x && y == b.y;
    }
};
struct chess
{
    string name, id;
    int x, y;
    vec<dot> pos;
    chess(string a, string b, int c, int d)
    {
        name = a, id = b, x = c, y = d;
    }
    chess(int c, int d)
    {
        x = c, y = d;
    }
    bool operator==(chess b)
    {
        return x == b.x && y == b.y;
    }
    bool check(int, int);
    bool check2(int, int);
    bool check3(int, int);
    void getmovepos();
    void opt()
    {
        cout << id << " " << name << ";";
    }
};
vec<chess> a;
bool chess::check(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}
bool chess::check2(int x, int y)
{
    if (!check(x, y))
        return 0;

    int tmp = a.find(chess(x, y));
    return !~tmp;
}
bool chess::check3(int x, int y)
{
    if (!check(x, y))
        return 0;

    int tmp = a.find(chess(x, y));
    return !~tmp || a[tmp].id != id;
}
const int Dx[] = {0, -1, 0, 0, 1, -1, -1, 1, 1},
          Dy[] = {0, 0, -1, 1, 0, -1, 1, -1, 1};
void chess::getmovepos()
{
    pos.clear();

    if (name == "captain")
    {
        for (int i = 1; i <= 4; i++)
        {
            if (check3(x + Dx[i], y + Dy[i]))
                pos.pub(dot(x + Dx[i], y + Dy[i]));
        }
    }
    else if (name == "guard")
    {
        for (int i = 5; i <= 8; i++)
        {
            if (check3(x + Dx[i], y + Dy[i]))
                pos.pub(dot(x + Dx[i], y + Dy[i]));
        }
    }
    else if (name == "elephant")
    {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (i && j)
                {
                    if (check2(x + i, y + j) && check3(x + i * 2, y + j * 2))
                        pos.pub(dot(x + i * 2, y + j * 2));
                }
    }
    else if (name == "horse")
    {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (i && j)
                {
                    if (check2(x + i, y) && check3(x + i * 2, y + j))
                        pos.pub(dot(x + i * 2, y + j));

                    if (check2(x, y + j) && check3(x + i, y + j * 2))
                        pos.pub(dot(x + i, y + j * 2));
                }
    }
    else if (name == "car")
    {
        for (int i = 1; i <= 4; i++)
        {
            int tmpx = x + Dx[i], tmpy = y + Dy[i];

            while (check2(tmpx, tmpy))
            {
                pos.pub(dot(tmpx, tmpy));
                tmpx += Dx[i], tmpy += Dy[i];
            }

            if (check3(tmpx, tmpy))
                pos.pub(dot(tmpx, tmpy));
        }
    }
    else if (name == "duck")
    {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (i && j)
                {
                    if (check2(x + i, y) && check2(x + i * 2, y + j) && check3(x + i * 3, y + j * 2))
                        pos.pub(dot(x + i * 3, y + j * 2));

                    if (check2(x, y + j) && check2(x + i, y + j * 2) && check3(x + i * 2, y + j * 3))
                        pos.pub(dot(x + i * 2, y + j * 3));
                }
    }
    else if (name == "soldier")
    {
        for (int i = 1; i <= 8; i++)
        {
            if (check3(x + Dx[i], y + Dy[i]))
                pos.pub(dot(x + Dx[i], y + Dy[i]));
        }
    }
}
void init()
{
    a.pub(chess("captain", "red", 0, 4));
    a.pub(chess("captain", "blue", 9, 4));

    a.pub(chess("car", "red", 0, 0));
    a.pub(chess("horse", "red", 0, 1));
    a.pub(chess("elephant", "red", 0, 2));
    a.pub(chess("guard", "red", 0, 3));
    
    a.pub(chess("guard", "red", 0, 5));
    a.pub(chess("elephant", "red", 0, 6));
    a.pub(chess("horse", "red", 0, 7));
    a.pub(chess("car", "red", 0, 8));
    a.pub(chess("duck", "red", 2, 0));
    a.pub(chess("duck", "red", 2, 8));
    a.pub(chess("soldier", "red", 3, 0));
    a.pub(chess("soldier", "red", 3, 2));
    a.pub(chess("soldier", "red", 3, 4));
    a.pub(chess("soldier", "red", 3, 6));
    a.pub(chess("soldier", "red", 3, 8));

    a.pub(chess("car", "blue", 9, 0));
    a.pub(chess("horse", "blue", 9, 1));
    a.pub(chess("elephant", "blue", 9, 2));
    a.pub(chess("guard", "blue", 9, 3));
    
    a.pub(chess("guard", "blue", 9, 5));
    a.pub(chess("elephant", "blue", 9, 6));
    a.pub(chess("horse", "blue", 9, 7));
    a.pub(chess("car", "blue", 9, 8));
    a.pub(chess("duck", "blue", 7, 0));
    a.pub(chess("duck", "blue", 7, 8));
    a.pub(chess("soldier", "blue", 6, 0));
    a.pub(chess("soldier", "blue", 6, 2));
    a.pub(chess("soldier", "blue", 6, 4));
    a.pub(chess("soldier", "blue", 6, 6));
    a.pub(chess("soldier", "blue", 6, 8));
}
const string Turns[] = {"?", "red", "blue"};
int mian(int x1, int y1, int x2, int y2)
{
    if (gameover)
        return inv, 0;

    int tmp = a.find(chess(x1, y1));

    if (!~tmp || a[tmp].id != Turns[turn])
        return inv, 0;

    a[tmp].getmovepos();

    if (!~a[tmp].pos.find(dot(x2, y2)))
        return inv, 0;

    a[tmp].opt();

    int to = a.find(chess(x2, y2));

    if (!~to)
        cout << "NA"
             << ";";
    else
    {
        if (to == 1 || to == 2)
            gameover = 1;

        a[to].opt();
        a[to].x = 114514, a[to].y = 1919810;
    }

    a[tmp].x = x2, a[tmp].y = y2;

    for (int i = 1; i <= a.cnt; i++)
        a[i].getmovepos();

    bool flag = 0;

    for (int i = 1; i <= a.cnt; i++)
        flag |= !!~a[i].pos.find(dot(a[1].x, a[1].y));

    for (int i = 1; i <= a.cnt; i++)
        flag |= !!~a[i].pos.find(dot(a[2].x, a[2].y));

    if (flag)
        cout << "yes"
             << ";";
    else
        cout << "no"
             << ";";

    if (gameover)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    turn ^= 3;
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    init();
    int q, x1, y1, x2, y2;
    cin >> q;

    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        mian(x1, y1, x2, y2);
    }

    return 0;
}