/*
题目描述
有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。请实现一个方法，计算小孩有多少种上楼的方式。为了防止溢出，请将结果Mod 1000000007
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
测试样例：
1
返回：1
*/

class GoUpstairs {
public:
    int countWays(int n) {
        if(n < 0) return 0;
        std::vector<long> vec(n, 0);
        vec[0] = 1;
        vec[1] = 2;
        vec[2] = 4;

        const int modVal = 1000000007;
        auto tmp = vec[2] % modVal;
        cout<< tmp << endl;
        for(int i = 4; i <= n; ++i){
            vec[i-1] = ((vec[i-2] + vec[i-3]) % modVal + vec[i-4] % modVal) %modVal;
        }

        return vec[n-1];
    }
};
