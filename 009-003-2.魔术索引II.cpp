/*
题目描述
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个不下降序列，元素值可能相同，编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
测试样例：
[1,1,3,4,5]
返回：true
*/

/*method:
如下例：
-10 | -5 | 2 | 2 | 2 | 3 | 4 | 7 | 9 | 12 | 13 |
------------------------------------------------
 0  | 1  | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9  | 10 |
 -----------------------------------------------
 
 根据A[mid] < mid, 不能判断魔术索引在数组的哪一边。它有可能在数组右边，跟前面一样。或者，它可能在左侧。
 但是由A[5] = 3可知， A[4]肯定不是魔术索引。因为数组是递增有序的。
 所以得到一般判断模式：先比较A[midIndex]==midVal? 若不同，则按递归搜索左半部分和右半部分：
 左半部分：搜索从start到Math.min(midIndex - 1, midVal)的元素
 右半部分：搜索从Math.max(midIndex + 1, midVal)到end的元素
 
*/
//Code:
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        if(A.empty()) return false;

        return findMagicIndex(A, 0, A.size());
    }
private:
    bool findMagicIndex(vector<int> A, int start, int end) {
        if(start >= end) return false;
        
        int mid = start + (end - start) / 2;
        if(A[mid] == mid){
            return true;
        }
        
        //left
        if(findMagicIndex(A, start, std::min(mid - 1, A[mid]))){
            return true;
        }

        //right
        return findMagicIndex(A, std::max(mid - 1, A[mid]), end);
    }
};
