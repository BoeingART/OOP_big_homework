#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <list>

using namespace std;
/*!
棋盘的状态节点
*/
struct tag_state{
	char mask[5][4];  //棋盘图案,下标为shapes的取值，-1为空白
	char pos[10];     //10个shape对象的左上角位置。行乘以4加列，取值0-19
	vector<int> neib; //邻接表，为status的下标
	std::string text; //索引键，为棋盘的可读图案
};

//10 种形状
static const int shapes[10][4][2] = {
	{{ 0, 0},{ 1, 0},{ 0, 1},{ 1, 1}},//曹操，正方形2x2
	{{ 0, 0},{ 1, 0},{-1,-1},{-1,-1}},//赵云等武将，竖矩形2x1
	{{ 0, 0},{ 1, 0},{-1,-1},{-1,-1}},//赵云等武将，竖矩形2x1
	{{ 0, 0},{ 1, 0},{-1,-1},{-1,-1}},//赵云等武将，竖矩形2x1
	{{ 0, 0},{ 1, 0},{-1,-1},{-1,-1}},//赵云等武将，竖矩形2x1
	{{ 0, 0},{ 0, 1},{-1,-1},{-1,-1}},//关羽，，横矩形，1x2
	{{ 0, 0},{-1,-1},{-1,-1},{-1,-1}},//小卒，单块。
	{{ 0, 0},{-1,-1},{-1,-1},{-1,-1}},//小卒，单块。
	{{ 0, 0},{-1,-1},{-1,-1},{-1,-1}},//小卒，单块。
	{{ 0, 0},{-1,-1},{-1,-1},{-1,-1}} //小卒，单块。
};
//上述10个方块的可读代字
static const char shapName [] = "CAAAABZZZZ";
//状态全图
static vector<tag_state> status;
//状态索引，用于从棋盘布局找到状态。
static unordered_map<string,int> all_status_pos;
//最短结果存储变量
static list<int> bestpath;

//初始化状态转移图，第一步，生成所有图节点
int make_status();
//初始化状态转移图，第二步，生成邻接表
void move_blocks();
//计算一次结果
void search_cal(string start);
//初始化函数，只用运行一次，可以反复解算
void init_cal()
{
    printf ("Init status table...");
    int nStatus = make_status();
	printf ("Ok!\nLink Graph...");
    move_blocks();
    puts("Ok!\n");
	printf ("total status = %d\n" , nStatus);
	printf ("----------------------\n");
}
//效率测试
void benchmark()
{
    srand(time(0));
    const int cstatus = all_status_pos.size();
    clock_t start_clk = clock();
    const int tests = 10000;
    for (int i=0;i<tests;++i)
    {
        long long sd = 21371 * ((long long )(rand())) + 23117* (long long )(rand()) ;
        long long mk = sd%cstatus;
        search_cal(status[mk].text);
    }
    clock_t end_clk = clock();
    double cost = 1.0 * (end_clk - start_clk)/CLOCKS_PER_SEC;
    printf ("Avg speed = %.2lf puzzles/s",tests/cost);
}

string char2key(const char buf[/*20*/])
{
    std::string s;
    for (int i=0;i<5;++i)
    {
        for (int j=0;j<4;++j)
            s += toupper(buf[i*4+j]);
        s+= "\n";
    }
    return s;
}

int main()
{
    init_cal();
    //1. example
    char buf[] = {
        "ACCA"
        "ACCA"
        "ABBA"
        "ASSA"
        "ZZZZ"
    };

    std::string s = char2key(buf);
    printf ("Cal\n%s\n...",s.c_str());
    search_cal(s);

    if (bestpath.size())
    {
        int i = 0;
        for (auto p = bestpath.begin();p!=bestpath.end();++i,++p)
        {
            printf ("Step %d:\n",(int)i);
            puts(status[*p].text.c_str());
        }
    }
    else
        puts ("\nNo Valid results.\n");
    puts ("\nbentch mark...\n");

    //2. example
    //性能测试
   // benchmark();


    //3. 用户输入
    bool exit_m = false;
    do{
        puts ("\nPlease Input 20 Chars and press Enter:");
        puts ("C=2x2 A=2x1 B=1x2 Z=1x1 S=Space, 'exit' to Exit.");
        char input[256];
        fgets(input,255,stdin);
        if (input[0]=='E' || input[0]=='e' )
            exit_m = true;
        else
        {
            s = char2key(input);
            printf ("Cal\n%s\n...",s.c_str());
            search_cal(s);
            if (bestpath.size())
            {
                int i = 0;
                for (auto p = bestpath.begin();p!=bestpath.end();++i,++p)
                {
                    printf ("Step %d:\n",(int)i);
                    puts(status[*p].text.c_str());
                }
            }
            else
                puts ("\nNo Valid results.\n");
        }
    }while (!exit_m);


	return 0;
}


//回溯法产生所有合理状态（棋盘）
int make_status()
{
    //状态缓存
	tag_state st;
	for (int i=0;i<20;++i)
		st.mask[i/4][i%4] = -1;
	for (int i=0;i<10;++i)
        st.pos[i] = 0;
    //i控制当前摆放第几个形状
	int i = 0;
	bool finished = false;
	while (!finished)
	{
	    //从当前形状的位置取值(0-19)变换到行列
		const int cr = st.pos[i] / 4;
		const int cc = st.pos[i] % 4;
		bool can_place = true;
		//测试是否可以在 i 位置放置
		for (int j=0;j<4 && can_place;++j)
		{
			if (shapes[i][j][0]<0 || shapes[i][j][1] < 0)
				break;//形状的偏移已经跑完
			const int tr = cr + shapes[i][j][0];
			const int tc = cc + shapes[i][j][1];
			if (tr >=5 ||tc >=4)
                can_place = false;//形状超出棋盘
			else if (st.mask[tr][tc]>=0)
				can_place = false;//形状覆盖他人
		}
		//放置并继续
		if (can_place)
		{
			for (int j=0;j<4;++j)
			{
				if (shapes[i][j][0]<0 || shapes[i][j][1] < 0)
					break;//形状的偏移已经跑完
				const int tr = cr + shapes[i][j][0];
				const int tc = cc + shapes[i][j][1];
				st.mask[tr][tc] = i;//在棋盘标记当前形状位置
			}
			if (i<9)
			{
				++i;
				continue;//继续摆放下一个形状
			}
			//产生供快速形状检索和打印的索引字符串
			string m;
			for (int r = 0;r < 5; ++r)
			{
				for (int c = 0;c <4;++c)
				{
					if (st.mask[r][c]>=0)
						m += (shapName[(int)st.mask[r][c]]);
					else
						m += ('S');
				}
				m+="\n";
			}
			st.text = m;
			//当前形状是否已经被记录？
			if (all_status_pos.find(m)==all_status_pos.end())
            {
                all_status_pos[m] = status.size();
                status.push_back(st);//记录
            }

			//清除当前状态，准备步进摆放位置
			for (int j=0;j<4;++j)
			{
				if (shapes[i][j][0]<0 || shapes[i][j][1] < 0)
					break;//形状的偏移已经跑完
				const int tr = cr + shapes[i][j][0];
				const int tc = cc + shapes[i][j][1];
				st.mask[tr][tc] = -1;
			}
		}

		//推进摆放状态
		++st.pos[i];
        //判断若摆放状态已全部尝试，要回溯前一个形状继续摆放
		while (st.pos[i]>=20 && i>0)
		{
			st.pos[i] = 0;
			//回溯
			--i;
			const int er = st.pos[i] / 4;
			const int ec = st.pos[i] % 4;
			//清除
			for (int j=0;j<4;++j)
			{
				if (shapes[i][j][0]<0 || shapes[i][j][1] < 0)
					break;//形状的偏移已经跑完
				const int tr = er + shapes[i][j][0];
				const int tc = ec + shapes[i][j][1];
				st.mask[tr][tc] = -1;
			}
			++st.pos[i];
		}
		if (i==0)
		{
			if (st.pos[i]>=20)
				finished = true;
		}
	}


	return status.size();
}
//对找到的状态，建立邻接表
void move_blocks()
{
    size_t sz = status.size();
    for (size_t p = 0; p < sz; ++p)
    {
        tag_state & s = status[p];
        for (int i=0;i<10;++i)//方块循环
        {
            const int r = s.pos[i] / 4;
            const int c = s.pos[i] % 4;
            const int mv[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (int j=0;j<4;j++)//挪动走向循环
            {
                const int nr = r + mv[j][0];
                const int nc = c + mv[j][1];
                if (nr >=5 || nr <0 || nc >=4 || nc < 0)
                    continue;
                for (int k=0;k<4 ;++k)
                {
                   if (shapes[i][k][0]<0 || shapes[i][k][1] < 0)
                        break;//形状的偏移已经跑完
                    const int tr = r + shapes[i][k][0];
                    const int tc = c + shapes[i][k][1];
                    s.mask[tr][tc] = -1;
                }
                bool can_place = true;
                //测试是否可以在 i 位置放置
                for (int k=0;k<4 && can_place;++k)
                {
                    if (shapes[i][k][0]<0 || shapes[i][k][1] < 0)
                        break;//形状的偏移已经跑完
                    const int tr = nr + shapes[i][k][0];
                    const int tc = nc + shapes[i][k][1];
                    if (tr >=5 ||tc >=4)
                        can_place = false;
                    else if (s.mask[tr][tc]>=0)
                        can_place = false;
                }
                if (can_place)//追加邻接表
                {
                    for (int k=0;k<4 ;++k)
                    {
                        if (shapes[i][k][0]<0 || shapes[i][k][1] < 0)
                            break;//形状的偏移已经跑完
                        const int tr = nr + shapes[i][k][0];
                        const int tc = nc + shapes[i][k][1];
                        s.mask[tr][tc] = i;
                    }
                    string m;
                    for (int ir = 0;ir < 5; ++ir)
                    {
                        for (int ic = 0;ic <4;++ic)
                        {
                            if (s.mask[ir][ic]>=0)
                                m += (shapName[(int)s.mask[ir][ic]]);
                            else
                                m += ('S');
                        }
                        m+="\n";
                    }
                    if (all_status_pos.find(m)==all_status_pos.end())
                    {
                        printf ("%s not find.\n",m.c_str());
                    }
                    else
                        s.neib.push_back(all_status_pos[m]);

                    for (int k=0;k<4 ;++k)
                    {
                        if (shapes[i][k][0]<0 || shapes[i][k][1] < 0)
                            break;//形状的偏移已经跑完
                        const int tr = nr + shapes[i][k][0];
                        const int tc = nc + shapes[i][k][1];
                        s.mask[tr][tc] = -1;
                    }
                }
                for (int k=0;k<4 ;++k)
                {
                    if (shapes[i][k][0]<0 || shapes[i][k][1] < 0)
                        break;//形状的偏移已经跑完
                    const int tr = r + shapes[i][k][0];
                    const int tc = c + shapes[i][k][1];
                    s.mask[tr][tc] = i;
                }
            }
        }
    }

}
//广度优先搜索
void search_cal(string start)
{
    if (all_status_pos.find(start)==all_status_pos.end())
    {
        printf ("Invalid input shape.\n");
        return;
    }

    const int nStart = all_status_pos[start];
    //遍历标记，不会重复遍历节点。
    vector<int> mark;
    const size_t nsz = status.size();
    for (size_t i=0;i<nsz;++i)
        mark.push_back(0);

    //广度优先队列1，记录发现的节点下标
    std::vector<int> wfs_vec;
    //广度优先队列2，记录节点父亲的下标
    std::vector<int> wfs_from;
    //初始化
    wfs_vec.push_back(nStart);
    wfs_from.push_back(-1);
    mark[nStart] = 1;

    int curr_test = 0;
    bestpath.clear();
    while (curr_test < (int)wfs_vec.size())
    {
        //判断是否结束
        const int n = wfs_vec[curr_test];
        if (status[n].mask[4][1] == 0 && status[n].mask[4][2] == 0 )
        {//曹操到达出口
            while (curr_test>=0)
            {
                bestpath.push_front(wfs_vec[curr_test]);
                curr_test = wfs_from[curr_test];
            }
            break;
        }
        //追加所有邻接邻居
        const size_t nebs = status[n].neib.size();
        for (size_t z = 0; z<nebs;++z)
        {
            const int nx = status[n].neib[z];
            if (mark[nx]==0)
            {
                wfs_vec.push_back(nx);
                wfs_from.push_back(curr_test);
                mark[nx] = 1;
            }
        }
        ++curr_test;
    }



}


