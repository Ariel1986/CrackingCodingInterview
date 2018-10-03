/*
题目描述
请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
给定两个正整数int a,int b,同时给定一个int type代表运算的类型，1为求a ＊ b，0为求a ／ b，-1为求a － b。请返回计算的结果，保证数据合法且结果一定在int范围内。
测试样例：
1,2,1
返回：2
*/

class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        long long result = -1;
        switch (type) {
        case -1:
            result = minu(a, b);
            break;
        case 0:
            result = divid(a, b);
            break;
        case 1:
            result = multi(a, b);
            break;
        }

        return result;
    }
private:
    int negative(int a){
        int d = a < 0? 1 : -1;
        int result = 0;
        while(a != 0){
            result += d;
            a += d;
        }

        return result;
    }

    //减法： a-b = a + (-b)
    int minu(int a, int b){
        return a + negative(b);
    }

    //乘法： a*b = a+a+...+a, a自身叠加b次
    int multi(int a, int b){
        if(std::abs(a) < std::abs(b))
        {
            return multi(b, a);
        }

        long result = 0;
        for(int i = std::abs(b); i > 0; --i){
            result += a;
        }
        if(result > INT_MAX){
            return -1;
        }
        return b > 0? result : std::abs(result);
    }

    //除法：a/b=x; 令b连加，直到接近a的值，b连加的次数就是商
    int divid(int a, int b){
        int absa = std::abs(a);
        int absb = std::abs(b);
        int result = 0;
        int sum = 0;
        while(sum + absb <= absa){
            sum += absb;
            ++result;
        }

        if((a > 0 && b > 0) || (a < 0 && b < 0))
        {
            return result;
        }
        return negative(result);
    }
};
