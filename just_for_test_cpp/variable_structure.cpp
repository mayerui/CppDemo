#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int BUF_SIZE = 100;

struct s_one
{
    int s_one_cnt;
    char *s_one_buf;
};

struct s_two
{
    int s_two_cnt;
    char s_two_buf[0];
};

struct s_three
{
    int s_three_cnt;
    char s_three_buf[1];
};

int main()
{
    //赋值用
    const char *tmp_buf = "abcdefghijklmnopqrstuvwxyz";
    int ntmp_buf_size = strlen(tmp_buf);

    //<1>注意s_one 与s_two的大小的不同
    cout << "sizeof(s_one) = " << sizeof(s_one) << endl;     //8 (32bit)    16(64bit)
    cout << "sizeof(s_two) = " << sizeof(s_two) << endl;     //4
    cout << "sizeof(s_three) = " << sizeof(s_three) << endl; //5-->8结构体对齐
    cout << endl;

    //为buf分配100个字节大小的空间
    int ntotal_stwo_len = sizeof(s_two) + (1 + ntmp_buf_size) * sizeof(char);
    int ntotal_sthree_len = sizeof(s_three) + ntmp_buf_size * sizeof(char);

    //给s_one buf赋值
    s_one *p_sone = (s_one *)malloc(sizeof(s_one));
    memset(p_sone, 0, sizeof(s_one));
    p_sone->s_one_buf = (char *)malloc(1 + ntmp_buf_size);
    memset(p_sone->s_one_buf, 0, 1 + ntmp_buf_size);
    memcpy(p_sone->s_one_buf, tmp_buf, ntmp_buf_size);

    //给s_two buf赋值
    s_two *p_stwo = (s_two *)malloc(ntotal_stwo_len);
    memset(p_stwo, 0, ntotal_stwo_len);
    p_stwo->s_two_cnt = ntmp_buf_size;
    memcpy((char *)(p_stwo->s_two_buf), tmp_buf, ntmp_buf_size); //不用加偏移量，直接拷贝!

    //给s_three_buf赋值
    s_three *p_sthree = (s_three *)malloc(ntotal_sthree_len);
    memset(p_sthree, 0, ntotal_sthree_len);
    memcpy((char *)(p_sthree->s_three_buf), tmp_buf, ntmp_buf_size);

    cout << "p_sone->s_one_buf = " << p_sone->s_one_buf << endl;

    cout << "p_stwo->s_two_buf = ";
    for (int i = 0; i<p_stwo->s_two_cnt; ++i)
    {
        static char *pc = p_stwo->s_two_buf;
        cout<< *pc++;
    }
    cout << endl;
    cout << "p_sthree->s_three_buf = " << p_sthree->s_three_buf << endl; //不用加偏移量，直接拷贝!
    cout << endl;

    //<2>注意s_one 与s_two释放的不同！
    if (NULL != p_sone->s_one_buf)
    {
        free(p_sone->s_one_buf);
        p_sone->s_one_buf = NULL;

        if (NULL != p_sone)
        {
            free(p_sone);
            p_sone = NULL;
        }
        cout << "free(p_sone) successed!" << endl;
    }

    if (NULL != p_stwo)
    {
        free(p_stwo);
        p_stwo = NULL;

        cout << "free(p_stwo) successed!" << endl;
    }

    if (NULL != p_sthree)
    {
        free(p_sthree);
        p_sthree = NULL;

        cout << "free(p_sthree) successed!" << endl;
    }

    getchar();

    return 0;
}
