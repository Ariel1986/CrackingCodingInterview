/*
题目描述
有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
给定一个数int k，请返回第k个数。保证k小于等于100。
测试样例：
3
返回：7
*/

/*method:
1) 初始化array和队列：Q3，Q5，Q7
2） 将1插入array
3）分别将1*3， 1*5，1*7插入Q3，Q5，Q7
4）令x为Q3，Q5，Q7中的最小值。将x添加到array尾部
5）若x存在于：
  1)):Q3,将x*3，x*5，x*7放入Q3，Q5，Q7，从Q3移除x
  2)):Q5,将x*5，x*7放入Q5和Q7，从Q5移除x
  3)):Q7,将x*7放入Q7，从Q7移除x
6）重复4-6.
*/

//Code:
class KthNumber {
public:
    int findKth(int k) {
    if(k <= 0) return -1;
    
    std::queue<int> que3;
    std::queue<int> que5;
    std::queue<int> que7;
    std::vector<int> vec{1};
    
    que3.emplace(3);
    que5.emplace(5);
    que7.emplace(7);

    for(int i = 0; i < k; ++i){
        vec.emplace_back(std::min(std::min(que3.front(), que5.front()), que7.front()));
        if(vec.back() == que3.front()){
            que3.emplace(que3.front() * 3);
            que5.emplace(que3.front() * 5);
            que7.emplace(que3.front() * 7);
            que3.pop();
        }
        if(vec.back() == que5.front()){
            que5.emplace(que5.front() * 5);
            que7.emplace(que5.front() * 7);
            que5.pop();
        }
        if(vec.back() == que7.front()){
            que7.emplace(que7.front() * 7);
            que7.pop();
        }
    }
    
    return vec.back();
    }
};
