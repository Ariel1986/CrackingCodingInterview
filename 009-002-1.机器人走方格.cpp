/*
题目描述
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
测试样例：
2,2
返回：2
*/

class Robot {
public:
    int countWays(int x, int y) {
    	if(x <= 0 || y <= 0){
            return 0;
        }
        std::vector<std::vector<int>> vec(x, std::vector<int>(y, 1));

        for(int i = 1; i < x; ++i){
            for(int j = 1; j < y; ++j){
                vec[i][j] = vec[i][j-1] + vec[i-1][j];
            }
        }
        return vec.back().back();
    }
};
